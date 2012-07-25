/**
 * This is code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */

#ifndef DELTAUTIL_H_
#define DELTAUTIL_H_
#include "common.h"
#include "codecs.h"
#include "memutil.h"
#include "entropy.h"



struct algostats {

    algostats(shared_ptr<IntegerCODEC> & a) :
        compspeed(), decompspeed(),
                bitsperint(), algo(a),
                decomptime(), comptime(), output(),input(){
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

    // maps from name to results
    double decomptime, comptime, output,input;

};
void summarize(vector<algostats> & v, string prefix ="#") {
    if (v.empty())
        return;
    cout << "# building summary " << endl;
    size_t N = v[0].bitsperint.size();
    for (size_t k = 0; k < N; ++k) {
        cout << "###################" << endl;
        if (N > 1)
            cout << "#test " << (k + 1) << " of " << N << endl;
        cout << "#wall clock (comp mis, decomp mis, bits per int)" << endl;
        cout << "#" << endl;
        for (auto i = v.begin(); i != v.end(); ++i) {
            cout << prefix << std::setprecision(4) << i->name(40) << " \t "
                    << i->compspeed.at(k) << " \t " << i->decompspeed.at(k) << " \t "
                    << i->bitsperint.at(k) << endl;
        }
        cout << prefix  << endl << prefix << endl;
    }
    for(algostats a : v) {
        if( (a.comptime != 0) and (a.decomptime !=0) and (a.input != 0)) {
            cout << " " << std::setprecision(4) << a.name(40) << " \t "
                    << a.input / a.comptime << " \t " << a.input / a.decomptime << " \t "
                    << a.output * 32 / a.input << endl;
        }
    }
}

/**
 * This class encodes and decode data using
 * an existing IntegerCODEC and delta coding.
 * It organizes the data by pages to avoid cache
 * misses.
 */
class Delta {
public:

    /**
     * This modifies the input.
     */
    static void encode(IntegerCODEC & c, uint32_t *in, const size_t length,
            uint32_t * out, size_t &nvalue) {
        delta(in,length);
        out[0] = in[0];
        c.encodeArray(in + 1, length - 1, out + 1, nvalue);
        nvalue += 1;
    }

    //  by D. Lemire
     template<class T>
     static void delta(T * data, const size_t size) {
         if (size == 0)
             throw runtime_error("delta coding impossible with no value!");

          for (size_t i = size - 1; i > 0; --i) {
                     data[i] -= data[i - 1];
          }
     }

    //  by D. Lemire
    template<class T>
    static void inverseDelta(T * data, const size_t size) {
        if (size == 0)
            return;
        size_t i = 1;
        for (; i < size - 1; i += 2) {
            data[i] += data[i - 1];
            data[i + 1] += data[i];
        }
        for (; i != size; ++i) {
            data[i] += data[i - 1];
        }
    }

    //  Original designed by Vasily Volkov, improved by D. Lemire
    template<class T>
    static void fastinverseDelta(T * data, const size_t size) {
        if (size == 0)
            return;
        const size_t UnrollQty = 4;
        size_t sz0 = (size / UnrollQty) * UnrollQty; // equal to 0, if size < UnrollQty
        size_t i = 1;
        if (sz0 >= UnrollQty) {
            T a = data[0];
            for (; i < sz0 - UnrollQty; i += UnrollQty) {
                a = data[i] += a;
                a = data[i + 1] += a;
                a = data[i + 2] += a;
                a = data[i + 3] += a;
            }
        }
        for (; i != size; ++i) {
            data[i] += data[i - 1];
        }
    }

    static const uint32_t * decode(IntegerCODEC & c, const uint32_t *in,
            const size_t length, uint32_t *out, size_t & nvalue) {
        out[0] = in[0];
        const uint32_t * finalin = c.decodeArray(in + 1, length - 1, out + 1,
                nvalue);
        nvalue += 1;
        fastinverseDelta(out, nvalue);
        return finalin;
    }



    // a convenience function
    static void process(vector<algostats> & myalgos,
            const vector<vector<uint32_t, cacheallocator> > & datas, const bool needtodelta,
            const bool fulldisplay, const bool displayhistogram, const bool computeentropy, const bool cumulative, const string prefix = "") {
        enum {verbose = false};
        if(datas.empty() or myalgos.empty()) return;
        if(needtodelta) {
            if(verbose) cout<<"# delta coding requested... checking whether we have sorted arrays...";
            for(auto x : datas) {
                if(x.size() > 0)
                    for (size_t k = 1; k < x.size(); ++k) {
                        if(x[k]<x[k-1]) {
                            cerr<<"Delta coding requested, but data is not sorted!"<<endl;
                            cerr<<"Aborting!"<<endl;
                            return;
                        }
                     }
            }
            if(verbose) cout<<" arrays are indeed sorted. Good."<<endl;
        } else {
            if(verbose) cout<<"# compressing the arrays themselves, no delta coding applied."<<endl;
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
                if(verbose) cout<<"# I verified that the arrays are not sorted so simple delta coding is unapplicable."<<endl;
            }

        }
        if (displayhistogram) {
            BitWidthHistoGram hist;
            for (auto i = datas.begin(); i != datas.end(); ++i)
                hist.eatIntegers(*i);
            hist.display("#");
        }
        if (fulldisplay) cout << "#";
        if (fulldisplay and computeentropy)
            cout << " entropy  databits(entropy) ";

        if (fulldisplay) {
            for (auto i = myalgos.begin(); i != myalgos.end(); ++i) {
                cout << (*i).name() << "\t";
            }
            cout << endl;
        }
        if (fulldisplay)
            cout
                    << "# for each scheme we give compression speed (million int./s)"
                        " decompression speed and bits per integer" << endl;
        EntropyRecorder er;
        if(computeentropy) {
             for (uint k = 0; k < datas.size(); ++k)
               if(!datas[k].empty()) er.eat(&datas[k][0], datas[k].size());
             if (fulldisplay)    cout << "# generated " << er.totallength << " integers" << endl;
        }
        if (fulldisplay)cout  << prefix << "\t";
        if(computeentropy and fulldisplay)
            cout << std::setprecision(4) << er.computeShannon() << "\t";
        if (computeentropy and fulldisplay)
            cout << std::setprecision(4) << er.computeDataBits() << "\t";
        bool alreadywarnedaboutsmallarray = false;
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
            vector<uint32_t, cacheallocator> outs(4 * maxlength + 1024);
            vector<uint32_t, cacheallocator> recovereds(maxlength + 1024);
            size_t totalcompressed = 0;
            uint64_t timemsdecomp = 0;
            uint64_t timemscomp = 0;
            for (size_t k = 0; k < datas.size(); ++k) {
                if(datas[k].empty()) continue;
                vector<uint32_t, cacheallocator> backupdata (datas[k]); // making a copy to be safe
                backupdata.reserve(backupdata.size() + 1024);
                nvalue = outs.size();

                z.reset();
                if (needtodelta) {
                    encode(c,&backupdata[0],backupdata.size(),&outs[0],nvalue);
                } else {
                    c.encodeArray(&backupdata[0], backupdata.size(), &outs[0], nvalue);
                }
                const uint64_t elapsedcomp = z.split();
                if((elapsedcomp < 5) and (!alreadywarnedaboutsmallarray)) {
                    cerr<<"# your arrays are too small for accurate timing? Recorded elapsed time = "<< elapsedcomp << " mu s"<<endl;
                    alreadywarnedaboutsmallarray = true;
                }
                timemscomp += elapsedcomp;
                totalcompressed += nvalue;

                size_t recoveredsize = backupdata.size();

                z.reset();
                if (needtodelta) {
                        decode(c,&outs[0],nvalue,&recovereds[0],recoveredsize);
                 } else {
                        c.decodeArray(&outs[0], nvalue,
                                        &recovereds[0], recoveredsize);

                }
                const uint64_t elapseddecomp = z.split();
                if((elapseddecomp < 5) and (!alreadywarnedaboutsmallarray)) {
                    cerr<<"# your arrays are too small for accurate timing? Recorded elapsed time = "<< elapsedcomp << " mu s"<<endl;
                    alreadywarnedaboutsmallarray = true;
                }
                timemsdecomp += elapseddecomp;
                if(recoveredsize!= datas[k].size()) {
                    cerr<<" expected size of "<<datas[k].size()<<" got "<<recoveredsize<<endl;
                    throw logic_error("arrays don't have same size: bug.");
                }
                if (!equal(datas[k].begin(),datas[k].end(), recovereds.begin()))  {
                    throw logic_error("we have a bug");
                }

            }
            if(cumulative)
                i->comptime += timemscomp;
            else
                i->compspeed.push_back(totallength * 1.0 / timemscomp);
            if (fulldisplay)
                cout << std::setprecision(4) << totallength * 1.0 / timemscomp
                        << "\t";
            if(cumulative)
                i->decomptime += timemsdecomp;
            else
                i->decompspeed.push_back(totallength * 1.0 / timemsdecomp);
            if (fulldisplay)
                cout << std::setprecision(4) << totallength * 1.0 / timemsdecomp
                        << "\t";
            if (fulldisplay)cout << std::setprecision(4) << totalcompressed * 32.0 / totallength
                    << "\t";
            if(cumulative) {
                i->output += totalcompressed;
                i->input += totallength;
            } else
                i->bitsperint.push_back(totalcompressed * 32.0 / totallength);
            if (fulldisplay) cout << "\t";
        }
        if (fulldisplay) cout << endl;
    }


};

#endif /* DELTAUTIL_H_ */
