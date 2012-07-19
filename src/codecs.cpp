/**
 * This is code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */

#include <getopt.h>
#include <string.h>
#include <time.h>
#include <cstdlib>
#include <ctype.h>
#include <memory>
#include <iomanip>
#include "codecfactory.h"
#include "ztimer.h"
#include "synthetic.h"
#include "cpubenchmark.h"
#include "stringutil.h"
#include "entropy.h"
#include "memutil.h"
#include "deltautil.h"

struct algostats {

    algostats(shared_ptr<IntegerCODEC> & a) :
        compspeed(), decompspeed(), 
                bitsperint(), algo(a) {
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
    vector<double> compspeed;
    vector<double> decompspeed;
    vector<double> bitsperint;
    shared_ptr<IntegerCODEC> algo;

};
void summarize(vector<algostats> v) {
    if (v.empty())
        return;
    for (size_t k = 0; k < 10; ++k)
        cout << "#" << endl;
    cout << "# building summary " << endl;
    size_t N = v[0].bitsperint.size();
    for (size_t k = 0; k < N; ++k) {
        cout << "###################" << endl;
        if (N > 1)
            cout << "#test " << (k + 1) << " of " << N << endl;
        cout << "#wall clock (comp mis, decomp mis, bits per int)" << endl;
        cout << "#" << endl;
        for (auto i = v.begin(); i != v.end(); ++i)
            cout << "# " << std::setprecision(4) << i->name(40) << " \t "
                    << i->compspeed[k] << " \t " << i->decompspeed[k] << " \t "
                    << i->bitsperint[k] << endl;
        cout << "#" << endl;
    }
}

using namespace std;

void process(vector<algostats> & myalgos,
        const vector<vector<uint32_t, cacheallocator> > & datas, const bool needtodelta,
        const bool fulldisplay, const bool displayhistogram, const bool computeentropy, const string prefix = "") {
    if(needtodelta) {
        cout<<"# delta coding requested... checking whether we have sorted arrays...";
        for(auto x : datas)
             for (size_t k = 1; k < x.size(); ++k) {
                if(x[k]<x[k-1]) {
                    cerr<<"Delta coding requested, but data is not sorted!"<<endl;
                    cerr<<"Aborting!"<<endl;
                    return;
                }
             }
        cout<<" arrays are indeed sorted. Good."<<endl;
    } else {
        cout<<"# compressing the arrays themselves, no delta coding applied."<<endl;
        // we check whether it could have been applied...
        bool sorted = true;
#pragma GCC diagnostic ignored "-Wunsafe-loop-optimizations" // otherwise I get bogus warning
        for(auto & x : datas)
            if(sorted and (x.size()>=1))
                    for (size_t k = 1; k < x.size(); ++k) {
                        if(x[k]<x[k-1]) {
                            sorted = false;
                            break;
                        }
                    }
#pragma GCC diagnostic pop
        if(sorted) {
            cout<<"#\n#\n# you are providing sorted arrays, but you are not requesting delta coding. Are you sure?\n#\n#\n"<<endl;
        } else {
            cout<<"# I verified that the arrays are not sorted so simple delta coding is unapplicable."<<endl;
        }

    }
    if (displayhistogram) {
        BitWidthHistoGram hist;
        for (auto i = datas.begin(); i != datas.end(); ++i)
            hist.eatIntegers(*i);
        hist.display("#");
    }
    cout << "#";
    if (fulldisplay and computeentropy)
        cout << " entropy  databits(entropy) ";

    for (auto i = myalgos.begin(); i != myalgos.end(); ++i) {
        cout << (*i).name() << "\t";
    }
    cout << endl;
    if (fulldisplay)
        cout
                << "# for each scheme we give compression speed (million int./s)"
                    " decompression speed and bits per integer" << endl;
    else
        cout
                << "# for each scheme we give compression time (clock cycles per integer),"
                    " decompression time and bits per integer" << endl;
    EntropyRecorder er;
    if(computeentropy) {
         for (uint k = 0; k < datas.size(); ++k)
           er.eat(&datas[k][0], datas[k].size());
         cout << "# generated " << er.totallength << " integers" << endl;
    }
    cout << prefix << "\t";
    if(computeentropy and fulldisplay)
        cout << std::setprecision(4) << er.computeShannon() << "\t";
    if (computeentropy and fulldisplay)
        cout << std::setprecision(4) << er.computeDataBits() << "\t";

    WallClockTimer z;
    for (auto i = myalgos.begin(); i != myalgos.end(); ++i) {
        IntegerCODEC & c = *(i->algo);
        size_t nvalue;
        size_t totallength = 0;
        size_t maxlength = 0;
        for (size_t k = 0; k < datas.size(); ++k) {
            auto & data = datas[k];
            totallength += data.size();
            if(maxlength < data.size()) maxlength = data.size();
         }
        vector<uint32_t, cacheallocator> outs(2 * maxlength + 1024);
        vector<uint32_t, cacheallocator> recovereds(maxlength + 1024);
        size_t totalcompressed = 0;
        uint64_t timemsdecomp = 0;
        uint64_t timemscomp = 0;
        for (size_t k = 0; k < datas.size(); ++k) {
            vector<uint32_t, cacheallocator> backupdata (datas[k]); // making a copy to be safe
            backupdata.reserve(backupdata.size() + 1024);
            assert(datas[k].size() == backupdata.size());
            nvalue = outs.size();// theoretically usafe

            z.reset();
            if (needtodelta) {
                    Delta::encode(c,&backupdata[0],backupdata.size(),&outs[0],nvalue);
            } else {
                c.encodeArray(&backupdata[0], backupdata.size(), &outs[0], nvalue);
            }
            timemscomp += z.split();
            totalcompressed += nvalue;

            size_t recoveredsize = backupdata.size();

            z.reset();
            if (needtodelta) {
                    Delta::decode(c,&outs[0],nvalue,&recovereds[0],recoveredsize);
             } else {
                    c.decodeArray(&outs[0], outs.size(),
                                    &recovereds[0], recoveredsize);

            }
            timemsdecomp += z.split();
            if(recoveredsize!= datas[k].size()) {
                cerr<<" expected size of "<<datas[k].size()<<" got "<<recoveredsize<<endl;
                throw logic_error("arrays don't have same size: bug.");
            }
            if (!equal(datas[k].begin(),datas[k].end(), recovereds.begin()))  {
                throw logic_error("we have a bug");
            }

        }
        i->compspeed.push_back(totallength * 1.0 / timemscomp);
        if (fulldisplay)
            cout << std::setprecision(4) << totallength * 1.0 / timemscomp
                    << "\t";
        //if (fulldisplay)
        //    cout << std::setprecision(4) << timemscomp * 1000.0
        //            / totallength << "\t";
        i->decompspeed.push_back(totallength * 1.0 / timemsdecomp);
        if (fulldisplay)
            cout << std::setprecision(4) << totallength * 1.0 / timemsdecomp
                    << "\t";
        //if (fulldisplay)
        //    cout << std::setprecision(4) << timemsdecomp * 1000.0
        //            / totallength << "\t";
        cout << std::setprecision(4) << totalcompressed * 32.0 / totallength
                << "\t";
        i->bitsperint.push_back(totalcompressed * 32.0 / totallength);
        cout << "\t";
    }
    cout << endl;
}

static struct option long_options[] = { { "uniformsparseclassic", no_argument,
        0, 0 }, { "displayhistogram", no_argument, 0, 'H' }, {
        "uniformdenseclassic", no_argument, 0, 0 }, { "clustersparseclassic",
        no_argument, 0, 0 }, { "clusterdenseclassic", no_argument, 0, 0 }, {
        "uniformsparse", no_argument, 0, 0 }, { "uniformdense", no_argument, 0,
        0 }, { "clustersparse", no_argument, 0, 0 }, { "clusterdense",
        no_argument, 0, 0 }, { "zipfian1", no_argument, 0, 0 }, { "zipfian2",
        no_argument, 0, 0 }, { "vclusterdynamic", no_argument, 0, 0 }, {
        "crazyclusterdynamic", no_argument, 0, 0 }, { "clusterdynamicsmall",
        no_argument, 0, 0 }, { "uniformdynamicsmall", no_argument, 0, 0 },{ "clusterdynamic",
        no_argument, 0, 0 }, { "uniformdynamic", no_argument, 0, 0 },{ "clusterdynamicpredelta",
                no_argument, 0, 0 }, { "uniformdynamicpredelta", no_argument, 0, 0 }, {
        "sillyuniformdynamic", no_argument, 0, 0 }, { "codecs",
        required_argument, 0, 'c' }, { "short", no_argument, 0, 's' }, { 0, 0,
        0, 0 } };

void message() {
    int c = 0;
    cout << "You must select one of these options:" << endl;
    while (long_options[c].name != 0) {
        if ((strcmp(long_options[c].name, "codecs") == 0) or ((strcmp(
                long_options[c].name, "short") == 0)))
            ++c;
        else
            cout << "--" << long_options[c++].name << endl;
    }
    cout << "the --codecs flag takes as an argument"
        " a comma-separated list of schemes chosen among those:" << endl;
    vector < string > all = CODECFactory::allNames();
    for (auto i = all.begin(); i != all.end(); ++i) {
        cerr << *i;
        if (i + 1 == all.end())
            cout << endl;
        else
            cout << ",";
    }
    cout << "(or give NONE instead of a list)" << endl;
    cout << "The --displayhistogram flag must appear before the other flags."
            << endl;
    cout << "Note that the --codecs flag must appear before the other flags."
            << endl;
    cout << "You can get a more concise output by using the --short flag."
            << endl;

}

int main(int argc, char **argv) {
    srand(10);//time(NULL));
    bool fulldisplay = true;
    bool displayhistogram = false;
    bool computeentropy = false;

    vector < shared_ptr<IntegerCODEC> > tmp = CODECFactory::allSchemes();// the default
    vector<algostats> myalgos;
    for (auto & i  : tmp)
        myalgos.push_back(algostats(i));
    int c;
    while (1) {
        int option_index = 0;
        c = getopt_long(argc, argv, "ec:", long_options, &option_index);
        if (c == -1)
            break;
        switch (c) {
        case 'c': {
            myalgos.clear();
            string codecsstr(optarg);
            if (codecsstr.compare("NONE") != 0) {
                vector < string > codecslst = split(codecsstr, ",:;");
                for (auto i = codecslst.begin(); i != codecslst.end(); ++i) {
                    cout << "# pretty name = " << *i << endl;
                    myalgos.push_back(algostats(CODECFactory::getFromName(*i)));
                    cout << "# added '" << myalgos.back().name() << "'" << endl;
                }
            }
        }
            break;
        case 'e':
            computeentropy = true;
            break;
        case 'H':
            displayhistogram = true;
            break;
        case 's':
            fulldisplay = false;
            break;
        case 0: {
            if (optind < argc) {
                cout << "There are some trailing flags...?" << endl;
                message();
                return 0;
            }
            const char * parameter = long_options[option_index].name;
            cout << "# found " << parameter << endl;
            if (strcmp(parameter, "zipfian1") == 0) {
                const uint32_t N = 4194304 * 16;
                vector < vector<uint32_t, cacheallocator> > datas;
                cout << "# zipfian 1 data generation..." << endl;
                for (uint k = 0; k < (1U << 1); ++k)
                    datas.push_back(generateZipfianArray32(N, 1.0, 1U << 20));
                process(myalgos, datas, false, fulldisplay, displayhistogram, computeentropy);
                summarize(myalgos);
                return 0;
            } else if (strcmp(parameter, "zipfian2") == 0) {
                const uint32_t N = 4194304 * 16;
                vector < vector<uint32_t, cacheallocator> > datas;
                for (uint k = 0; k < (1U << 1); ++k)
                    cout << "# zipfian 2 data generation..." << endl;
                datas.push_back(generateZipfianArray32(N, 2.0, 1U << 20));
                process(myalgos, datas, false, fulldisplay, displayhistogram, computeentropy);
                summarize(myalgos);
                return 0;
            } else if (strcmp(parameter, "uniformdenseclassic") == 0) {
                cout << "# dense uniform data generation..." << endl;
                vector < vector<uint32_t, cacheallocator> > datas;
                UniformDataGenerator clu;
                for (uint k = 0; k < (1U << 5); ++k)
                    datas.push_back(
                                    clu.generateUniform((1U << 18) ,
                                            1U << 27));
                cout << "# generated " << datas.size() << " arrays" << endl;
                process(myalgos, datas, true, fulldisplay, displayhistogram, computeentropy);
                summarize(myalgos);
                return 0;
            } else if (strcmp(parameter, "uniformsparseclassic") == 0) {
                cout << "# sparse uniform data generation..." << endl;
                vector < vector<uint32_t, cacheallocator> > datas;
                UniformDataGenerator clu;
                for (uint k = 0; k < (1U << 14); ++k)// by original paper should be 1U<<19
                    datas.push_back(
                                    clu.generateUniform((1U << 9) ,
                                            1U << 27));
                cout << "# generated " << datas.size() << " arrays" << endl;
                process(myalgos, datas, true, fulldisplay, displayhistogram, computeentropy);
                summarize(myalgos);
                return 0;
            } else if (strcmp(parameter, "clusterdenseclassic") == 0) {
                cout << "# dense cluster data generation..." << endl;
                vector < vector<uint32_t, cacheallocator> > datas;
                ClusteredDataGenerator clu;
                for (uint k = 0; k < (1U << 5); ++k)// by original paper should be 1U<<10
                    datas.push_back(
                                    clu.generateClustered((1U << 18) ,
                                            1U << 27));
                cout << "# generated " << datas.size() << " arrays" << endl;
                process(myalgos, datas, true, fulldisplay, displayhistogram, computeentropy);
                summarize(myalgos);
                return 0;
            } else if (strcmp(parameter, "clustersparseclassic") == 0) {
                cout << "# sparse cluster data generation..." << endl;
                vector < vector<uint32_t, cacheallocator> > datas;
                ClusteredDataGenerator clu;
                for (uint k = 0; k < (1U << 14); ++k)// by original paper should be 1U<<19
                    datas.push_back(
                                    clu.generateClustered((1U << 9) ,
                                            1U << 27));
                cout << "# generated " << datas.size() << " arrays" << endl;
                process(myalgos, datas, true, fulldisplay, displayhistogram, computeentropy);
                summarize(myalgos);
                return 0;
            } else if (strcmp(parameter, "uniformdense") == 0) {
                cout << "# dense uniform data generation..." << endl;
                vector < vector<uint32_t, cacheallocator> > datas;
                UniformDataGenerator clu;
                for (uint k = 0; k < (1U << 3); ++k)// by original paper should be 1U<<10
                    datas.push_back(
                                    clu.generateUniform((1U << 22) ,
                                            1U << 29));
                cout << "# generated " << datas.size() << " arrays" << endl;
                process(myalgos, datas, true, fulldisplay, displayhistogram, computeentropy);
                summarize(myalgos);
                return 0;
            } else if (strcmp(parameter, "uniformsparse") == 0) {
                cout << "# sparse uniform data generation..." << endl;
                vector < vector<uint32_t, cacheallocator> > datas;
                UniformDataGenerator clu;
                for (uint k = 0; k < (1U << 13); ++k)
                    datas.push_back(
                                    clu.generateUniform((1U << 12) ,
                                            1U << 29));
                cout << "# generated " << datas.size() << " arrays" << endl;
                process(myalgos, datas, true, fulldisplay, displayhistogram, computeentropy);
                summarize(myalgos);
                return 0;
            } else if (strcmp(parameter, "clusterdense") == 0) {
                cout << "# dense cluster data generation..." << endl;
                vector < vector<uint32_t, cacheallocator> > datas;
                ClusteredDataGenerator clu;
                for (uint k = 0; k < 1; ++k)
                    datas.push_back(
                                    clu.generateClustered((1U << 23) ,
                                            1U << 26));
                cout << "# generated " << datas.size() << " arrays" << endl;
                process(myalgos, datas, true, fulldisplay, displayhistogram, computeentropy);
                summarize(myalgos);
                return 0;
            } else if (strcmp(parameter, "clustersparse") == 0) {
                cout << "# sparse cluster data generation..." << endl;
                vector < vector<uint32_t, cacheallocator> > datas;
                ClusteredDataGenerator clu;
                for (uint k = 0; k < (1U << 13); ++k)
                    datas.push_back(
                                    clu.generateClustered((1U << 12) ,
                                            1U << 26));
                cout << "# generated " << datas.size() << " arrays" << endl;
                process(myalgos, datas, true, fulldisplay, displayhistogram, computeentropy);
                summarize(myalgos);
                return 0;
            } else if (strcmp(parameter, "clusterdynamic") == 0) {
                cout << "# dynamic clustered data generation..." << endl;
                ClusteredDataGenerator clu;
                for (uint32_t K = 10; K <= 25; K += 5) {
                    vector < vector<uint32_t, cacheallocator> > datas;
                    for (uint k = 0; k < (1U << (25 - K)); ++k)
                        datas.push_back(
                                        clu.generateClustered(
                                                (1U << K) , 1U << 29));
                    cout << "# generated " << datas.size() << " arrays" << endl;
                    cout << "# their size is  " << (1U << K) << endl;
                    const uint32_t p = 29 - K;
                    ostringstream convert;
                    convert << p;
                    process(myalgos, datas, true, fulldisplay, displayhistogram, computeentropy,
                            convert.str());
                }
                summarize(myalgos);
                return 0;
            } else if (strcmp(parameter, "uniformdynamic") == 0) {
                cout << "# sparse uniform data generation..." << endl;
                UniformDataGenerator clu;
                for (uint32_t K = 10; K <= 25; K += 5) {
                    vector < vector<uint32_t, cacheallocator> > datas;
                    for (uint k = 0; k < (1U << (25 - K)); ++k)
                        datas.push_back(
                                        clu.generateUniform((1U << K) ,
                                                1U << 29));
                    cout << "# generated " << datas.size() << " arrays" << endl;
                    cout << "# their size is  " << (1U << K) << endl;
                    const uint32_t p = 29 - K;
                    ostringstream convert;
                    convert << p;
                    process(myalgos, datas, true, fulldisplay, displayhistogram, computeentropy,
                            convert.str());
                }
                summarize(myalgos);
                return 0;
            } else if (strcmp(parameter, "clusterdynamicsmall") == 0) {
                cout << "# dynamic clustered data generation..." << endl;
                ClusteredDataGenerator clu;
                for (uint32_t K = 10; K <= 20; K += 5) {
                    vector < vector<uint32_t, cacheallocator> > datas;
                    for (uint k = 0; k < (1U << (20 - K)); ++k)
                        datas.push_back(
                                        clu.generateClustered(
                                                (1U << K) , 1U << 29));
                    cout << "# generated " << datas.size() << " arrays" << endl;
                    cout << "# their size is  " << (1U << K) << endl;
                    const uint32_t p = 29 - K;
                    ostringstream convert;
                    convert << p;
                    process(myalgos, datas, true, fulldisplay, displayhistogram, computeentropy,
                            convert.str());
                }
                summarize(myalgos);
                return 0;
            } else if (strcmp(parameter, "uniformdynamicsmall") == 0) {
                cout << "# sparse uniform data generation..." << endl;
                UniformDataGenerator clu;
                for (uint32_t K = 10; K <= 20; K += 5) {
                    vector < vector<uint32_t, cacheallocator> > datas;
                    for (uint k = 0; k < (1U << (20 - K)); ++k)
                        datas.push_back(
                                        clu.generateUniform((1U << K) ,
                                                1U << 29));
                    cout << "# generated " << datas.size() << " arrays" << endl;
                    cout << "# their size is  " << (1U << K) << endl;
                    const uint32_t p = 29 - K;
                    ostringstream convert;
                    convert << p;
                    process(myalgos, datas, true, fulldisplay, displayhistogram, computeentropy,
                            convert.str());
                }
                summarize(myalgos);
                return 0;
             } else if (strcmp(parameter, "clusterdynamicpredelta") == 0) {
                cout << "# dynamic clustered data generation..." << endl;
                ClusteredDataGenerator clu;
                for (uint32_t K = 10; K <= 25; K += 5) {
                    vector < vector<uint32_t, cacheallocator> > datas;
                    for (uint k = 0; k < (1U << (25 - K)); ++k)
                        datas.push_back(
                                diffs(
                                        clu.generateClustered(
                                                (1U << K) , 1U << 29), false));
                    cout << "# generated " << datas.size() << " arrays and applied delta coding" << endl;
                    cout << "# their size is  " << (1U << K) << endl;
                    const uint32_t p = 29 - K;
                    ostringstream convert;
                    convert << p;
                    process(myalgos, datas, false, fulldisplay, displayhistogram, computeentropy,
                            convert.str());
                }
                summarize(myalgos);
                return 0;
            } else if (strcmp(parameter, "uniformdynamicpredelta") == 0) {
                cout << "# sparse uniform data generation..." << endl;
                UniformDataGenerator clu;
                for (uint32_t K = 10; K <= 25; K += 5) {
                    vector < vector<uint32_t, cacheallocator> > datas;
                    for (uint k = 0; k < (1U << (25 - K)); ++k)
                        datas.push_back(
                                diffs(
                                        clu.generateUniform((1U << K) ,
                                                1U << 29), false));
                    cout << "# generated " << datas.size() << " arrays and applied delta coding" << endl;
                    cout << "# their size is  " << (1U << K) << endl;
                    const uint32_t p = 29 - K;
                    ostringstream convert;
                    convert << p;
                    process(myalgos, datas, false, fulldisplay, displayhistogram, computeentropy,
                            convert.str());
                }
                summarize(myalgos);
                return 0;
            } else {
                cerr << "Support for " << parameter << " was not found."
                        << endl;
            }
            break;
        }
        default:
            /* You won't actually get here. */
            break;
        }

    }
    message();
    return 0;

}
