/**
 * This is code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */

#include <tr1/memory>
#include <iomanip>
#include <time.h>
#include "codecfactory.h"
#include "maropuparser.h"
#include "util.h"
#include "ztimer.h"
#include "cpubenchmark.h"
#include "deltaio.h"

using namespace std;

struct simplealgostats {

    algostats(shared_ptr<IntegerCODEC> & a) :
    comptime(0), decomptime(0),
    compressedsizeinints(0), totalints(0), algo(a) {
    }
    string name() {
        return algo->name();
    }
    string name(size_t k) {
        string n = algo->name();
        char space = ' ';
        n.resize(k, space);
        return n;
    }

    double comptime;
    double decomptime;
    double compressedsizeinints;
    double totalints;
    shared_ptr<IntegerCODEC> algo;

};

static struct option long_options[] = {
        { "codecs", required_argument, 0, 'c' }, { 0, 0, 0, 0 } };

void message(const char * prog) {
    cerr << " usage : " << prog << " scheme  maropubinaryfile " << endl;
    cerr << "By default, is assumes that the original data is made of "
        "sorted distinct integers." << endl;
    cerr << "Use the --codecs flag to specify the schemes." << endl;
    cerr << " schemes include:" << endl;
    vector < string > all = CODECFactory::allNames();
    for (auto i = all.begin(); i != all.end(); ++i) {
        cerr << *i << endl;
    }

}

int main(int argc, char **argv) {
    uint32_t MAXCOUNTER = 1U << 31;
    if (argc < 4) {
        message(argv[0]);
        return -1;
    }
    vector < shared_ptr<IntegerCODEC> > tmp = CODECFactory::allSchemes();// the default
    vector<simplealgostats> myalgos;
    for (auto i = tmp.begin(); i != tmp.end(); ++i)
        myalgos.push_back(algostats(*i));
    int c;
    while (1) {
        int option_index = 0;
        c = getopt_long(argc, argv, "c:", long_options, &option_index);
        if (c == -1)
            break;
        switch (c) {
        case 'c':
            myalgos.clear();
            string codecsstr(optarg);
            if (codecsstr.compare("NONE") != 0) {
                vector < string > codecslst = split(codecsstr, ",:;");
                for (auto i = codecslst.begin(); i != codecslst.end(); ++i) {
                    cout << "# pretty name = " << *i << endl;
                    myalgos.push_back(
                            simplealgostats(CODECFactory::getFromName(*i)));
                    cout << "# added '" << myalgos.back().name() << "'" << endl;
                }
            }

            break;

        }
        default:
        cerr << "unrecognized flag" << endl;
        break;
    }

    if (argc - optind < 2) {
        cerr << "  you must specify a file " << endl;
        return -1;
    }
    string filename = argv[optind];

    cout << "# parsing " << filename << endl;
    MaropuGapReader reader(filename);

    vector<uint32_t, cacheallocator> rawdata;
    reader.open();
    size_t counter = 0;
    size_t integers = 0;
    CPUTimer cpuz;
    EntropyRecorder er;
    const uint32_t MAXBLOCKSIZE = 104857600;// 400 MB
    while (counter < MAXCOUNTER) {
        // collecting the data up to MAXBLOCKSIZE integers
        vector < vector<uint32_t, cacheallocator> > &datas;
        uint32_t datastotalsize = 0;
        while (reader.loadIntegers(rawdata)) {
            if (rawdata.size() < MINLENGTH)
                continue;
            ++counter;
            integers += rawdata.size();
            datastotalsize += rawdata.size();
            datas.push_back(rawdata);
            er.eat(&rawdata[0], rawdata.size());
            if (counter >= MAXCOUNTER) {
                cout << "#breaking early" << endl;
                break;
            }
            if (datastotalsize >= MAXBLOCKSIZE)
                break;
        }
        // done collecting data, now allocating memory
        vector < vector<uint32_t, cacheallocator> > recovered(datas.size());
        vector < vector<uint32_t, cacheallocator> > outs(datas.size());
        vector < size_t > outsize(datas.size());
        for (size_t k = 0; k < datas.size(); ++k) {
            recovered[k].reserve(data[k].size() + 1024);
            recovered[k].resize(data[k].size());
            outs[k].resize(data[k].size() + 1024);
            outsize.push_back(outs[k].size());
        }
        // now compressing/uncompressing
        for (size_t i = 0; i < myalgos.size(); ++i) {
            for (size_t k = 0; k < datas.size(); ++k) {
                outsize[k] = outs[k].capacity();
            }
            // first compressing
            cpuz.reset();
            for (int k = 0; k < datas.size(); ++k) {
                vector<uint32_t, cacheallocator> & data = data[k];
                for (size_t j = data.size() - 1; j > 0; --j) {
                    data[j] = data[j] - data[j - 1] - 1;
                }
                myalgos[i].algo->encodeArray(&data[1], data.size() - 1,
                        &outs[k], outsize[k]);
            }
            myalgos[i].comptime += cpuz.split();
            myalgos[i].compressedsizeinints += outsize[i] + 1;// + 1 because of value 0
            myalgos[i].totalints += data.size();
            // next uncompressing
            cpuz.reset();
            for (int k = 0; k < datas.size(); ++k) {
                vector<uint32_t, cacheallocator> & r = recovereds[k];
                r[0] = data[k][0];
                size_t s = recovered[k].size();
                vector<uint32_t, cacheallocator> & compresseddata = outs[k];
                myalgos[i].algo->decodeArray(&outs[k], outsize[k], &r[1], s);
                for (size_t i = 1; i < r.size(); ++i) {
                    r[i] = r[i] + r[i - 1] + 1;
                }
                if (s + 1 != datas[k].size()) {
                    cerr << "expected to find a size of " << datas[k].size()
                            << " but got " << (s + 1) << endl;
                    return -1;
                }
            }
            myalgos[i].decomptime += cpuz.split();
        }

    }
    reader.close();
    cout << "# integers = " << integers << endl;
    cout << "# arrays = " << counter << endl;

    cout << "# shannon databits" << endl;

    cout << std::setprecision(4) << er.computeShannon() << "\t";
    cout << std::setprecision(4) << er.computeDataBits() << "\t";
    cout << endl;

    cout
            << "# compression speed (mis), uncompression speed (mis), bits per int"
            << endl;
    for (simplealgostats sstats : v) {
        cout << v.name(40)<<"\t"<<totalints/comptime<<"\t"<<totalints/decomptime<<"\t"<<compressedsizeinints*32.0/totalints<<endl;
    }

}
