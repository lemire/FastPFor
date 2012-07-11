/**
 * This is code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */
#include <iostream>
#include <iomanip>
#include "util.h"
#include "bitpacking.h"
#include "rolledbitpacking.h"
#include "synthetic.h"
#include "ztimer.h"


void maskfnc(vector<uint32_t,cacheallocator> & out, const uint32_t L) {
    if(L==32) return;
    for(auto i = out.begin(); i!= out.end() ; ++i) {
        *i = *i % (1U<<L);
    }
}

void fastpack(const vector<uint32_t,cacheallocator> & data, vector<uint32_t,cacheallocator> & out, const uint32_t bit) {
        const uint32_t N = data.size();
        for(uint32_t k = 0; k<N/32;++k) {
                fastpack(& data[0]+32*k,&out[0]+bit *k,bit);
        }
}

void fastpackwithoutmask(const vector<uint32_t,cacheallocator> & data, vector<uint32_t,cacheallocator> & out, const uint32_t bit) {
        const uint32_t N = data.size();
        for(uint32_t k = 0; k<N/32;++k) {
                fastpackwithoutmask(& data[0]+32*k,&out[0]+bit *k,bit);
        }
}

void fastunpack(const vector<uint32_t,cacheallocator> & data, vector<uint32_t,cacheallocator> & out, const uint32_t bit) {
        const uint32_t N = out.size();
        for(uint32_t k = 0; k<N/32;++k) {
                fastunpack(& data[0]+bit *k,&out[0]+32*k,bit);
        }
}



void pack(const vector<uint32_t> & data, vector<uint32_t> & out, const uint32_t bit) {
        const uint32_t N = data.size();
        for(uint32_t k = 0; k<N/32;++k) {
                pack<true>(& data[0]+32*k,&out[0]+bit *k,bit);
        }
}

void packwithoutmask(const vector<uint32_t> & data, vector<uint32_t> & out, const uint32_t bit) {
        const uint32_t N = data.size();
        for(uint32_t k = 0; k<N/32;++k) {
                pack<false>(& data[0]+32*k,&out[0]+bit *k,bit);
        }
}


void pack_tight(const vector<uint32_t> & data, vector<uint32_t> & out, const uint32_t bit) {
        const uint32_t N = data.size();
        for(uint32_t k = 0; k<N/32;++k) {
                pack_tight<true>(& data[0]+32*k,&out[0]+bit *k,bit);
        }
}

void pack_tightwithoutmask(const vector<uint32_t> & data, vector<uint32_t> & out, const uint32_t bit) {
        const uint32_t N = data.size();
        for(uint32_t k = 0; k<N/32;++k) {
                pack_tight<false>(& data[0]+32*k,&out[0]+bit *k,bit);
        }
}


void unpack(const vector<uint32_t> & data, vector<uint32_t> & out, const uint32_t bit) {
        const uint32_t N = out.size();
        for(uint32_t k = 0; k<N/32;++k) {
                unpack(& data[0]+bit *k,&out[0]+32*k,bit);
        }
}




template <class container32bit>
bool equalOnFirstBits(const container32bit & data, const container32bit & recovered, uint32_t bit) {
    if(bit == 32) {
        return data == recovered;
    }
    for(uint32_t k = 0; k<data.size(); ++k) {
        if(data[k] % (1U<<bit) != recovered[k]%(1U<<bit)) {
            cout<<" They differ at k = "<<k<< " data[k]= "<<data[k]<<" recovered[k]="<<recovered[k]<<endl;
            return false;
        }
    }
    return true;
}
void simplebenchmark(uint32_t N = 1U<<24) {
    vector<uint32_t,cacheallocator> data = generateArray32(N);
    vector<uint32_t,cacheallocator> compressed(N, 0);
    vector<uint32_t,cacheallocator> recovered(N, 0);
    WallClockTimer z;
    const uint32_t T = 5;
    double packtime,packtimewm,unpacktime;
    cout<<"#million of integers per second: higher is better"<<endl;
    cout<<"#bit, pack, pack without mask, unpack"<<endl;
    for (uint32_t bitindex = 0; bitindex < 32; ++bitindex) {
        uint32_t bit = 32-bitindex;
        maskfnc(data,bit);
        packtime=0;packtimewm=0;unpacktime=0;
        for (uint32_t t = 0; t < T; ++t) {
            compressed.clear();
            compressed.resize(N*bit/32, 0);
            recovered.clear();
            recovered.resize(N, 0);

            z.reset();
            fastpack(data, compressed, bit);
            if(t>0) packtime += z.split();

            z.reset();
            fastpackwithoutmask(data, compressed, bit);
            if(t>0) packtimewm += z.split();


            z.reset();
            fastunpack(compressed,recovered, bit);
            if(t>0) unpacktime += z.split();


            if (!equalOnFirstBits(data,recovered,bit)) {
                cout << " Bug1!" << endl;
                return;
            }

        }

        cout<<std::setprecision(4)<<bit<<"\t\t"<<N*(T-1)/(packtime)
                <<"\t\t"<<N*(T-1)/(packtimewm)<<"\t\t\t"
                <<N*(T-1)/(unpacktime);
        cout<<endl;

    }



}

using namespace std;
int main() {

        simplebenchmark( 1U<<25);

        return 0;
}
