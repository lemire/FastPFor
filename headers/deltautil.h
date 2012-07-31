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

/**
 * This file is made of various convenient functions and structures.
 * It is not necessarily very reusable though.
 */

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
 * This takes every vector and replaces it, if
 * needed by a series of vectors having max
 * size MAXSIZE. If a vector has size less than
 * or equal to MAXSIZE, it remains unchanged.
 */
template <class T>
void splitLongArrays(vector<T> & datas, size_t MAXSIZE = 65536 + 1) {// choosing a power of two + 1 as the default
    // possibly inefficient
    for(size_t i = 0 ; i < datas.size() ; ++i) {
          if(datas[i].size()>MAXSIZE) {
              const size_t howmany = (datas[i].size()+MAXSIZE-1)/MAXSIZE - 1;
              datas.reserve(datas.size()+howmany);     
              for(size_t j = 0; j < howmany; ++j) {
                  size_t begin = (j+1)*MAXSIZE;
                  size_t end = (j+2)*MAXSIZE;
                  if(end > datas[i].size()) end = datas[i].size();
                  assert(datas[i].begin()+end<=datas[i].end());
                  datas.push_back(T(datas[i].begin()+begin,datas[i].begin()+end));
              }
              datas[i].resize(MAXSIZE);
          }
     }
    // for safety, we check the result:
    for(size_t i = 0 ; i < datas.size() ; ++i) {
        assert(datas[i].size()<=MAXSIZE);
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
    template <class container>
    static void process(vector<algostats> & myalgos,
            const vector<container > & datas, const bool needtodelta,
            const bool fulldisplay, const bool displayhistogram, const bool computeentropy,
            const bool cumulative, const string prefix = "") {
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
            container outs(4 * maxlength + 1024);
            container recovereds(maxlength + 1024 + 64);
            size_t totalcompressed = 0;
            uint64_t timemsdecomp = 0;
            uint64_t timemscomp = 0;
            for (size_t k = 0; k < datas.size(); ++k) {
                if(datas[k].empty()) continue;
                container backupdata (datas[k]); // making a copy to be safe
                backupdata.reserve(backupdata.size() + 1024);
                uint32_t * outp = &outs[0];
                nvalue = outs.size();
                while(needPaddingTo64bytes(outp + (needtodelta ? 1 : 0))) {
                    --nvalue;
                    outp++;
                }


                z.reset();
                if (needtodelta) {
                    encode(c,&backupdata[0],backupdata.size(),outp,nvalue);
                } else {
                    c.encodeArray(&backupdata[0], backupdata.size(), outp, nvalue);
                }
                const uint64_t elapsedcomp = z.split();
                if((elapsedcomp < 5) and (!alreadywarnedaboutsmallarray)) {
                    cerr<<"# your arrays are too small for accurate timing? Recorded elapsed time = "<< elapsedcomp << " mu s"<<endl;
                    alreadywarnedaboutsmallarray = true;
                }
                timemscomp += elapsedcomp;
                totalcompressed += nvalue;

                size_t recoveredsize = backupdata.size();
                uint32_t * recov = &recovereds[0];
                while(needPaddingTo64bytes(recov + (needtodelta ? 1 : 0))) {
                    recov++;
                }
                z.reset();
                if (needtodelta) {
                        decode(c,outp,nvalue,recov,recoveredsize);
                 } else {
                        c.decodeArray(outp, nvalue,
                                recov, recoveredsize);

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
                if (!equal(datas[k].begin(),datas[k].end(), recov))  {
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
