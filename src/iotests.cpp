/**
 * This is code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */

#include <getopt.h>
#include <string.h>
#include <time.h>
#include <tr1/memory>
#include <iomanip>
#include "maropuparser.h"
#include "ztimer.h"
#include "cpubenchmark.h"
#include "codecfactory.h"
#include "entropy.h"
#include "stringutil.h"

using namespace std;

/***
 * Main purpose of iotests.cpp is to make sure that the various
 * schemes are correct. D. Lemire uses it as a form of unit testing.
 */

class Results {
public:
    double timespentcompressing;
    double timespentdecompressing;
    uint64_t totalcompressedsize;
    uint64_t numberofintegers;
    double clockcyclesspentcompressing;
    double clockcyclesspentdecompressing;

    Results() :
        timespentcompressing(0), timespentdecompressing(0),
                totalcompressedsize(0), numberofintegers(0),
                clockcyclesspentcompressing(0),
                clockcyclesspentdecompressing(0) {
    }
};
enum {
    SHORT, LONG, NORMAL, MODULO
};

static struct option long_options[] = { { "short", no_argument, 0, 's' }, {
        "-modulo", no_argument, 0, 'm' }, { "long", no_argument, 0, 'l' }, {
        "codecs", required_argument, 0, 'c' }, { 0, 0, 0, 0 } };

void message(const char * prog) {
    cout << " usage : "<<prog<<" maropubinaryfile " << endl;
    cout
            << " possible flags: --short, --long, --modulo, --codecs [scheme1,scheme2] "
            << endl;
    cout<<"Note that the --codecs flag must appear before the other flags."<<endl;

}

int main(int argc, char **argv) {
    string filename;
    int mode = NORMAL;
    int diff = NORMAL;
    vector < shared_ptr<IntegerCODEC> > myalgos = CODECFactory::allSchemes();
    const uint32_t threshold = (1U << 22);
    int c;
    while (1) {
        int option_index = 0;
        c = getopt_long(argc, argv, "c:", long_options, &option_index);
        if (c == -1)
            break;
        switch (c) {
        case 'c': {
            myalgos.clear();
            string codecsstr(optarg);
            vector < string > codecslst = split(codecsstr, ",:;");
            for (auto i = codecslst.begin(); i != codecslst.end(); ++i) {
                cout << "# pretty name = " << *i << endl;
                myalgos.push_back(CODECFactory::getFromName(*i));
                cout << "# added" << myalgos.back()->name() << endl;
            }
        }
            break;
        case 's':
            mode = SHORT;
            cout << "# mode == short " << threshold << endl;
            break;
        case 'm':
            cout << "# diff == modulo " << endl;
            diff = MODULO;
            break;
        case 'l':
            cout << "# mode == long " << threshold << endl;
            mode = LONG;
            break;
        default:
            abort();
            break;
        }
    }
    if (optind >= argc) {
        message(argv[0]);
        return 0;
    }
    filename = argv[optind];

    cout << "# parsing " << filename << endl;
    cout << "#";
    cout << " N  entropy databits(entropy) ";
    for (vector<shared_ptr<IntegerCODEC> >::iterator i = myalgos.begin(); i
            != myalgos.end(); ++i) {
        cout << (**i).name() << "\t";
    }
    cout << endl;

    cout
            << "# for each scheme we give compression speed (million int./s, nano s/ int,  cpu cycle/integer) decompression speed and bits per integer"
            << endl;

    vector<Results> results(myalgos.size());

    vector < uint32_t > data;
    vector < uint32_t > rawdata;
    vector<uint32_t> out, recovered;
    WallClockTimer z;
    CPUBenchmark cpu;
    MaropuGapReader reader(filename);
    reader.open();
    EntropyRecorder er;
    uint32_t counter = 0;
    while (reader.loadIntegers(rawdata)) {
        if ((mode == LONG) and (rawdata.size() < threshold))
            continue;
        if ((mode == SHORT) and (rawdata.size() >= threshold))
            continue;
        ++counter;
        data.resize(rawdata.size() - 1);
        if (diff == NORMAL) {

            for (size_t i = 0; i < data.size(); ++i) {
                if (rawdata[i + 1] < rawdata[i])
                    cerr << "we have a problem, doc Ids not sorted" << endl;
                data[i] = rawdata[i + 1] - rawdata[i];
            }
        } else {
            assert(diff == MODULO);
            const uint32_t b = maxbits(rawdata.begin(), rawdata.end());
            for (size_t i = 0; i < data.size(); ++i) {
                data[i] = (rawdata[i + 1] - rawdata[i]) % (1U << b);
            }
        }
        const size_t N = data.size();
        er.eat(&data[0], data.size());
        vector<Results>::iterator j = results.begin();
        for (vector<shared_ptr<IntegerCODEC> >::iterator i = myalgos.begin(); i
                != myalgos.end(); ++i, ++j) {
            j->numberofintegers += N;
            IntegerCODEC & c = **i;
            size_t nvalue;
            out.clear();
            out.resize(data.size() * 2 + 2048);
	    uint32_t *aligned_buffer = reinterpret_cast<uint32_t *>(padTo64bytes( reinterpret_cast<uint8_t *>(&out)));  // ofk
            z.reset();
            cpu.start();
            nvalue = out.size();
            c.encodeArray(&data[0], data.size(), /* &out[0] */ aligned_buffer, nvalue);
            j->clockcyclesspentcompressing += cpu.stop();
            const uint64_t comptime = z.split();
            j->timespentcompressing += comptime;
            out.resize(nvalue);
            recovered.clear();
            recovered.resize(data.size() + 2048, 0);
            z.reset();
            cpu.start();
            size_t recoveredsize = recovered.size();
            c.decodeArray(/*&out[0]*/ aligned_buffer, out.size(), &recovered[0], recoveredsize);
            if (recoveredsize != data.size()) {
                cerr << "expected recovered length of " << data.size()
                        << " but got " << recoveredsize << endl;
                cerr << c.name() << endl;
                throw logic_error("we have a bug");
            }
            // making sure nobody is cheating:
            for (size_t k = recoveredsize; k < recovered.size(); ++k)
                recovered[k] = 0;
            recovered.resize(data.size());
            j->clockcyclesspentdecompressing += cpu.stop();
            const uint64_t decomptime = z.split();
            j->timespentdecompressing += decomptime;
            j->totalcompressedsize += out.size();
            if (recovered != data) {
                cerr << c.name() << endl;
                throw logic_error("we have a bug");
            }
        }
    }
    cout << er.totallength << " ";
    cout << std::setprecision(4) << er.computeShannon() << " "
            << er.computeDataBits() << "\t";
    for (vector<Results>::const_iterator j = results.begin(); j
            != results.end(); ++j) {
        cout << std::setprecision(4) << j->numberofintegers * 1.0
                / j->timespentcompressing << " " << j->timespentcompressing
                * 1000.0 / j->numberofintegers << " "
                << j->clockcyclesspentcompressing / j->numberofintegers << " "
                << j->numberofintegers * 1.0 / j->timespentdecompressing
                << " " << j->timespentdecompressing * 1000.0
                / j->numberofintegers << " "
                << j->clockcyclesspentdecompressing / j->numberofintegers
                << " " << j->totalcompressedsize * 32.0 / j->numberofintegers
                << "\t\t";
    }
    cout << endl;
    cout << "# processed " << counter << " arrays" << endl;
}

