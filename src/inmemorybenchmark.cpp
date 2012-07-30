/**
 * This is code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */
#include <getopt.h>
#include <tr1/memory>
#include <iomanip>
#include <time.h>
#include <limits>
#include "codecfactory.h"
#include "maropuparser.h"
#include "util.h"
#include "ztimer.h"
#include "cpubenchmark.h"
#include "deltautil.h"
#include "stringutil.h"



using namespace std;

static struct option long_options[] = {
        { "codecs", required_argument, 0, 'c' }, { "splitlongarrays", no_argument, 0, 'S' },{ 0, 0, 0, 0 } };

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
    size_t MAXCOUNTER = std::numeric_limits<std::size_t>::max();
    if (argc < 2) {
        message(argv[0]);
        return -1;
    }
    bool splitlongarrays = false;
    size_t MINLENGTH = 1;
    vector < shared_ptr<IntegerCODEC> > tmp = CODECFactory::allSchemes();// the default
    vector<algostats> myalgos;
    for (auto i = tmp.begin(); i != tmp.end(); ++i)
        myalgos.push_back(algostats(*i));
    int c;
    while (1) {
        int option_index = 0;
        c = getopt_long(argc, argv, "Sc:", long_options, &option_index);
        if (c == -1)
            break;
        switch (c) {
        case 'S' :
             splitlongarrays = true;
             break;
        case 'c':
        {   myalgos.clear();
            string codecsstr(optarg);
            if (codecsstr.compare("NONE") != 0) {
                vector < string > codecslst = split(codecsstr, ",:;");
                for (auto i = codecslst.begin(); i != codecslst.end(); ++i) {
                    cout << "# pretty name = " << *i << endl;
                    myalgos.push_back(
                            algostats(CODECFactory::getFromName(*i)));
                    cout << "# added '" << myalgos.back().name() << "'" << endl;
                }
            }
        }
            break;
        default:
        cerr << "unrecognized flag" << endl;
        break;

        }
    }

    if (argc - optind < 1) {
        cerr << "  you must specify a file " << endl;
        return -1;
    }
    string filename = argv[optind];

    cout << "# parsing " << filename << endl;
    MaropuGapReader reader(filename);

    vector<uint32_t, cacheallocator> rawdata;
    reader.open();
    size_t counter = 0;
    const size_t MAXBLOCKSIZE = 104857600;// 400 MB
    while (counter < MAXCOUNTER) {
        // collecting the data up to MAXBLOCKSIZE integers
        vector < vector<uint32_t, cacheallocator> > datas;
        size_t datastotalsize = 0;
	    cout<<"# Filling up a block "<<endl;
        while (reader.loadIntegers(rawdata)) {
            if (rawdata.size() < MINLENGTH)
                continue;
            ++counter;
            datastotalsize += rawdata.size();
            datas.push_back(rawdata);
            if (counter >= MAXCOUNTER) {
                cout << "#breaking early" << endl;
                break;
            }
            if (datastotalsize >= MAXBLOCKSIZE)
                break;
        }
        if(datastotalsize == 0) break;
        cout<<"# read "<<  std::setprecision(3)  << datastotalsize * 4 / (1024.0 * 1024.0) << " MB "<<endl;
	cout<<"# processing block"<<endl;
	    if(splitlongarrays) splitLongArrays(datas);
	    Delta::process(myalgos, datas, true,false, false, false, true);        // done collecting data, now allocating memory
    }
    reader.close();
    cout<<"# build summary..."<<endl;
    summarize(myalgos);

}
