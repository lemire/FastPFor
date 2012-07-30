/**
 * This is code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Leonid Boytsov
 */

//#include <malloc.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "bitpacksimd.h"
#include "ztimer.h"
#include "bitpacking.h"
#include "util.h"


using namespace std;

void __SIMD_fastunpack1(const uint32_t *  __restrict__ src, uint32_t *  __restrict__  dst);

void fastunpack(const uint32_t*  __restrict__ in, uint32_t *  __restrict__  out, const uint32_t bit) {
    
    switch(bit) {
        case 0: __fastunpack0(in,out); return;

        case 1: __fastunpack1(in,out); return;

        case 2: __fastunpack2(in,out); return;

        case 3: __fastunpack3(in,out); return;

        case 4: __fastunpack4(in,out); return;

        case 5: __fastunpack5(in,out); return;

        case 6: __fastunpack6(in,out); return;

        case 7: __fastunpack7(in,out); return;

        case 8: __fastunpack8(in,out); return;

        case 9: __fastunpack9(in,out); return;

        case 10: __fastunpack10(in,out); return;

        case 11: __fastunpack11(in,out); return;

        case 12: __fastunpack12(in,out); return;

        case 13: __fastunpack13(in,out); return;

        case 14: __fastunpack14(in,out); return;

        case 15: __fastunpack15(in,out); return;

        case 16: __fastunpack16(in,out); return;

        case 17: __fastunpack17(in,out); return;

        case 18: __fastunpack18(in,out); return;

        case 19: __fastunpack19(in,out); return;

        case 20: __fastunpack20(in,out); return;

        case 21: __fastunpack21(in,out); return;

        case 22: __fastunpack22(in,out); return;

        case 23: __fastunpack23(in,out); return;

        case 24: __fastunpack24(in,out); return;

        case 25: __fastunpack25(in,out); return;

        case 26: __fastunpack26(in,out); return;

        case 27: __fastunpack27(in,out); return;

        case 28: __fastunpack28(in,out); return;

        case 29: __fastunpack29(in,out); return;

        case 30: __fastunpack30(in,out); return;

        case 31: __fastunpack31(in,out); return;

        case 32: __fastunpack32(in,out); return;

        default: break;    
    }
    throw logic_error("number of bits is unsupported");
}

bool TestSIMD(unsigned bit, unsigned RandIterQty1, unsigned RandIterQty2) {

    uint32_t    aSrcData[128];
    uint32_t    aPacked[128];
    uint32_t  __attribute__ ((aligned (16)))  aDstData[128];

    uint32_t    mask = (1U << bit) - 1;
    size_t      Qty = 0;

    cout << "Bit: " << bit << endl;
    for (unsigned iter1 = 0; iter1 < RandIterQty1 + 2; ++ iter1) {
        cout << "  Iter: " << iter1 << endl;

        for (unsigned i = 0; i < 128U; ++i) {
            if (iter1 == 0) { 
                aSrcData[i ] = 0;
            } else if (iter1 == 1) { 
                aSrcData[i ] = mask;
            } else {
                aSrcData[i] = rand() & mask;
            }
        }

        for (unsigned NumIndex = 0; NumIndex < 128U; ++NumIndex) {
            for (unsigned num = 1; num <= mask; num *= 2) {
                unsigned old = aSrcData[NumIndex];
            
                aSrcData[NumIndex] = num;

                SIMD_fastpackwithoutmask_32(aSrcData, reinterpret_cast<__m128i*>(aPacked), bit); 

                SIMD_fastunpack_32(reinterpret_cast<__m128i*>(aPacked), aDstData, bit);


                for (unsigned i = 0; i < 128U; ++i) {
                    Qty += aSrcData[i] != aDstData[i];
                }

                aSrcData[NumIndex] = old;
            }
            for (unsigned iter2 = 0; iter2 < RandIterQty2 + 2; ++iter2) {
                unsigned old = aSrcData[NumIndex];
            
                if (iter2 == 0) {
                    aSrcData[NumIndex] = 0;
                } else if (iter2 == 1) {
                    aSrcData[NumIndex] = mask;
                } else {
                    aSrcData[NumIndex] = rand() & mask;
                }

                SIMD_fastpackwithoutmask_32(aSrcData, reinterpret_cast<__m128i*>(aPacked), bit); 

                SIMD_fastunpack_32(reinterpret_cast<__m128i*>(aPacked), aDstData, bit);


                for (unsigned i = 0; i < 128U; ++i) {
                    Qty += aSrcData[i] != aDstData[i];
                }

                aSrcData[NumIndex] = old;
            }
        }
    }

    cout << "@@@@@@@ "  << bit << "  ->  # of failures " << Qty << endl;

    return Qty == 0;
}

int main() {
    srand(0);

    const size_t N = 1U * 1024U * 1024U;

    cout << "Align: " << __alignof__(__m128) << endl;

    unsigned FailedBitQty = 0;

    for (unsigned bit = 1; bit <= 32; ++bit) {
        FailedBitQty += !TestSIMD(bit, 100U, 10000U);
    }

    cout << "<###########> Failed function calls: " << FailedBitQty << endl;

    for (unsigned bit = 1; bit <= 32; ++bit) {
        size_t SrcQty = N * bit;
        size_t DstQty = N * 32;

        uint32_t*   pSrc = new uint32_t[SrcQty];
        //uint32_t*   pDst = new uint32_t[DstQty];
        uint32_t * unalignedpDst = new   uint32_t[DstQty + sizeof(__m128)/sizeof(uint32_t) - 1];
        uint32_t*  pDst = padTo128bytes(unalignedpDst);
//                reinterpret_cast<uint32_t*>(memalign(__alignof__(__m128), DstQty * sizeof(uint32_t)));

        for (unsigned i = 0; i < SrcQty; ++i) {
            pSrc[i] = rand();
        }

        for (int k = 1; k < 4; ++k) {
            WallClockTimer t1;

            uint32_t*   pIn = pSrc;
            uint32_t*   pOut = pDst;

            t1.reset();
        
            for (unsigned i = 0; i < DstQty/32; ++i) {
                fastunpack(pIn, pOut, bit);
                pIn += bit; pOut += 32;
            }

            unsigned long long delta1 = t1.split();

            cout << "SCALAR bit: " << bit << " Elapsed: " << delta1/1e6 << " secs. Million Ints: " << DstQty/ 1e6 << " MIS: " << DstQty /delta1 << endl;  
        }

        for (int k = 1; k < 4; ++k) {
            WallClockTimer t1;

            uint32_t*   pIn = pSrc;
            uint32_t*   pOut = pDst;

            t1.reset();
        
            for (unsigned i = 0; i < DstQty/128; ++i) {
                SIMD_fastunpack_32(reinterpret_cast<__m128i*>(pIn), pOut, bit); 
                pIn += bit * 4; pOut += 32 * 4;
            }

            unsigned long long delta1 = t1.split();

            cout << "SIMD   bit: " << bit << " Elapsed: " << delta1/1e6 << " secs. Million Ints: " << DstQty/ 1e6 << " MIS: " << DstQty /delta1 << endl;  
        }

        cout << "===========================================================================================" << endl;

        delete [] pSrc;
        delete [] unalignedpDst;
        //free(pDst);

    }
}
