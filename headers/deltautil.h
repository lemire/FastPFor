/**
 * This code is released under the
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
#include "ztimer.h"
/**
 * This file is made of various convenient functions and structures.
 * It is not necessarily very reusable though.
 */
struct algostats {

    algostats(shared_ptr<IntegerCODEC> & a, bool simd = false) :
        compspeed(), decompspeed(), bitsperint(), algo(a), decomptime(),
                comptime(), output(), input(), SIMDDeltas(simd) {
    }
    string name() {
        // if SIMDDeltas is "true", we prepend @
        if (SIMDDeltas) {
            ostringstream convert;
            convert << "@" << algo->name();
            return convert.str();
        }
        return algo->name();
    }
    string name(size_t k) {
        string n = name();
        char space = ' ';
        n.resize(k, space);
        return n;
    }
    vector<double> compspeed;
    vector<double> decompspeed;
    vector<double> bitsperint;
    shared_ptr<IntegerCODEC> algo;

    // maps from name to results
    double decomptime, comptime, output, input;
    bool SIMDDeltas;
};
void summarize(vector<algostats> & v, string prefix = "#") {
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
                    << i->compspeed.at(k) << " \t " << i->decompspeed.at(k)
                    << " \t " << i->bitsperint.at(k) << endl;
        }
        cout << prefix << endl << prefix << endl;
    }
for(algostats a : v) {
    if( (a.comptime != 0) && (a.decomptime !=0) && (a.input != 0)) {
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
template<class T>
void splitLongArrays(vector<T> & datas, size_t MAXSIZE = 65536 ) {
    // possibly inefficient
    for (size_t i = 0; i < datas.size(); ++i) {
        if (datas[i].size() > MAXSIZE) {
            const size_t howmany = (datas[i].size() + MAXSIZE - 1) / MAXSIZE
                    - 1;
            datas.reserve(datas.size() + howmany);
            for (size_t j = 0; j < howmany; ++j) {
                size_t begin = (j + 1) * MAXSIZE;
                size_t end = (j + 2) * MAXSIZE;
                if (end > datas[i].size())
                    end = datas[i].size();
                assert(datas[i].begin() + end <= datas[i].end());
                datas.push_back(
                        T(datas[i].begin() + begin, datas[i].begin() + end));
            }
            datas[i].resize(MAXSIZE);
        }
    }
    // for safety, we check the result:
    for (size_t i = 0; i < datas.size(); ++i) {
        assert(datas[i].size() <= MAXSIZE);
    }
}

struct processparameters {
    bool needtodelta;
    bool fulldisplay;
    bool displayhistogram;
    bool computeentropy;
    bool cumulative;

    processparameters(bool ndelta, bool fdisplay, bool dhisto,
            bool compentropy, bool cumul) :
        needtodelta(ndelta), fulldisplay(fdisplay), displayhistogram(dhisto),
                computeentropy(compentropy), cumulative(cumul) {
    }
};
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
    static void encode(IntegerCODEC & c, bool SIMDmode, uint32_t *in,
            const size_t length, uint32_t * out, size_t &nvalue) {
        assert(!needPaddingTo128Bits(in));
        if (SIMDmode)
            deltaSIMD(in, length);
        else
            delta(in, length);
        assert(!needPaddingTo128Bits(out));
        c.encodeArray(in, length , out , nvalue);
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


    // by Leonid Boytsov, revised by D. Lemire
    template<class T>
    static void deltaSIMD(T * pData, const size_t TotalQty) {
        if (TotalQty < 5) {
             delta(pData, TotalQty); // no need for SIMD
             return;
        }
        const size_t Qty4 = TotalQty / 4;
        for (size_t i = 4 * Qty4; i < TotalQty; ++i) {
             pData[i] -= pData[i-4];
        }
        __m128i* pCurr = reinterpret_cast<__m128i*>(pData) + Qty4 - 1;
        const __m128i* pStart = reinterpret_cast<__m128i*>(pData);
        __m128i a = _mm_load_si128(pCurr);
        while (pCurr > pStart) {
            register __m128i b = _mm_load_si128(pCurr - 1);
            _mm_store_si128(pCurr-- , _mm_sub_epi32(a, b));
            a = b;
        }
     }



     // by Leonid Boytsov, modified by D. Lemire
     template<class T>
     static void inverseDeltaSIMD(T * pData,  const size_t TotalQty) {
         if (TotalQty < 5) {
             inverseDelta(pData, TotalQty);// no SIMD
             return;
         }
         const size_t Qty4 = TotalQty / 4;

         __m128i* pCurr = reinterpret_cast<__m128i*>(pData);
         const __m128i* pEnd = pCurr + Qty4;
         __m128i a = _mm_load_si128(pCurr++);
         while (pCurr < pEnd) {
             __m128i b = _mm_load_si128(pCurr);
             a = _mm_add_epi32(a, b);
             _mm_store_si128(pCurr++ , a);
         }

         for (size_t i = Qty4 * 4; i < TotalQty; ++i) {
             pData[i] += pData[i-4];
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
        const size_t sz0 = (size / UnrollQty) * UnrollQty; // equal to 0, if size < UnrollQty
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

    static const uint32_t * decode(IntegerCODEC & c, const bool SIMDmode, const uint32_t *in,
            const size_t length, uint32_t *out, size_t & nvalue) {
        assert(!needPaddingTo128Bits(in));
        assert(!needPaddingTo128Bits(out));
        const uint32_t * finalin = c.decodeArray(in , length , out,
                nvalue);
        if(SIMDmode)
            inverseDeltaSIMD(out, nvalue);
        else
            fastinverseDelta(out, nvalue);
        return finalin;
    }


    // a convenience function
    template <class container>
    static void process(vector<algostats> & myalgos,
            const vector<container > & datas, processparameters & pp /*const bool needtodelta,
            const bool fulldisplay, const bool displayhistogram, const bool computeentropy,
            const bool cumulative*/, const string prefix = "") {
        // pp.needtodelta = false;
        enum {verbose = false};
        if(datas.empty() || myalgos.empty()) return;
        if(pp.needtodelta) {
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
#if !defined(__clang__) && !defined(_MSC_VER) && !defined(__INTEL_COMPILER)
#pragma GCC diagnostic ignored "-Wunsafe-loop-optimizations" // otherwise I get bogus warning
#endif
            for(auto & x : datas)
                if(sorted && (x.size()>=1))
                        for (size_t k = 1; k < x.size(); ++k) {
                            if(x[k]<x[k-1]) {
                                sorted = false;
                                break;
                            }
                        }
#if !defined(__clang__) && !defined(_MSC_VER) && !defined(__INTEL_COMPILER)
#pragma GCC diagnostic pop
#endif
            if(sorted) {
                cout<<"#\n#\n# you are providing sorted arrays, but you are not requesting delta coding. Are you sure?\n#\n#\n"<<endl;
            } else {
                if(verbose) cout<<"# I verified that the arrays are not sorted so simple delta coding is unapplicable."<<endl;
            }

        }
        if (pp.displayhistogram) {
            BitWidthHistoGram hist;
            for (auto i = datas.begin(); i != datas.end(); ++i)
                hist.eatIntegers(*i);
            hist.display("#");
        }
        if (pp.fulldisplay) cout << "#";
        if (pp.fulldisplay && pp.computeentropy)
            cout << " entropy  databits(entropy) ";

        if (pp.fulldisplay) {
            for (auto i = myalgos.begin(); i != myalgos.end(); ++i) {
                cout << (*i).name() << "\t";
            }
            cout << endl;
        }
        if (pp.fulldisplay)
            cout
                    << "# for each scheme we give compression speed (million int./s)"
                        " decompression speed and bits per integer" << endl;
        EntropyRecorder er;
        if(pp.computeentropy) {
             for (size_t k = 0; k < datas.size(); ++k)
               if(!datas[k].empty()) er.eat(&datas[k][0], datas[k].size());
             if (pp.fulldisplay)    cout << "# generated " << er.totallength << " integers" << endl;
        }
        if (pp.fulldisplay)cout  << prefix << "\t";
        if(pp.computeentropy && pp.fulldisplay)
            cout << std::setprecision(4) << er.computeShannon() << "\t";
        if (pp.computeentropy && pp.fulldisplay)
            cout << std::setprecision(4) << er.computeDataBits() << "\t";
        WallClockTimer z;
        size_t totallength = 0;
        size_t maxlength = 0;
        vector<container > outs(datas.size());
        for (size_t k = 0; k < datas.size(); ++k) {
                auto & data = datas[k];
                outs[k].resize(4*data.size() + 2048 + 64);
                totallength += data.size();
                if(maxlength < data.size()) maxlength = data.size();
        }
        vector<size_t> nvalues(datas.size());
        container recovereds(maxlength + 2048 + 64);
        container backupdata;
        backupdata.reserve(maxlength + 2048 + 64);
        for (auto i = myalgos.begin(); i != myalgos.end(); ++i) {
            IntegerCODEC & c = *(i->algo);
            const bool SIMDDeltas = i->SIMDDeltas;
            size_t nvalue;
            size_t totalcompressed = 0;
            double timemsdecomp = 0;
            double timemscomp = 0;
            for (size_t k = 0; k < datas.size(); ++k) {
                if(datas[k].empty()) continue;
                uint32_t * outp = &outs[k][0];
                nvalue = outs[k].size();
                assert(!needPaddingTo128Bits(outp));
                uint64_t elapsedcomp = 0;
                const size_t orignvalue = nvalue;
                {
                    nvalue = orignvalue;
                    backupdata.assign(datas[k].begin(),datas[k].end()); // making a copy to be safe
                    z.reset();
                    if (pp.needtodelta) {
                        encode(c,SIMDDeltas,&backupdata[0],backupdata.size(),outp,nvalue);
                    } else {
                        c.encodeArray(&backupdata[0], backupdata.size(), outp, nvalue);
                    }
                    elapsedcomp += z.split();
                    nvalues[k] = nvalue;
                }
                timemscomp += static_cast<double>(elapsedcomp);
                totalcompressed += nvalue;
            }
            for (size_t k = 0; k < datas.size(); ++k) {
                const uint32_t * outp = &outs[k][0];
                nvalue = nvalues[k];
                size_t recoveredsize = datas[k].size();
                assert(recoveredsize > 0);
                uint32_t * recov = &recovereds[0];
                assert(!needPaddingTo128Bits(recov));
                z.reset();
                {
                  if  (pp.needtodelta) {
                        decode(c,SIMDDeltas,outp,nvalue,recov,recoveredsize);
                   } else {
                        c.decodeArray(outp, nvalue,
                                recov, recoveredsize);
                  }
                }
                const uint64_t elapseddecomp = z.split();
                timemsdecomp += static_cast<double>(elapseddecomp);
                if(recoveredsize!= datas[k].size()) {
                    cerr<<" expected size of "<<datas[k].size()<<" got "<<recoveredsize<<endl;
                    throw logic_error("arrays don't have same size: bug.");
                }
                if (!equal(datas[k].begin(),datas[k].end(), recov))  {
                    throw logic_error("we have a bug");
                }

            }
            if(pp.cumulative)
                i->comptime += timemscomp;
            else
                i->compspeed.push_back(static_cast<double>(totallength)  / timemscomp);
            if (pp.fulldisplay)
                cout << std::setprecision(4) << static_cast<double>(totallength) / timemscomp
                        << "\t";
            if(pp.cumulative)
                i->decomptime += timemsdecomp;
            else
                i->decompspeed.push_back(static_cast<double>(totallength) / timemsdecomp);
            if (pp.fulldisplay)
                cout << std::setprecision(4) << static_cast<double>(totallength) / timemsdecomp
                        << "\t";
            if (pp.fulldisplay)cout << std::setprecision(4) << static_cast<double>(totalcompressed) * 32.0 / static_cast<double>(totallength)
                    << "\t";
            if(pp.cumulative) {
                i->output += static_cast<double>(totalcompressed);
                i->input += static_cast<double>(totallength);
            } else
                i->bitsperint.push_back(static_cast<double>(totalcompressed) * 32.0 / static_cast<double>(totallength));
            if (pp.fulldisplay) cout << "\t";
        }
        if (pp.fulldisplay) cout << endl;
    }


};

#endif /* DELTAUTIL_H_ */
