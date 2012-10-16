/**
 * This is code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire
 */
#include "simdbitpacking.h"

using namespace std;



static void SIMD_nullunpacker32(const __m128i *  __restrict__ , uint32_t *  __restrict__  out) {
    memset(out,0,32 * 4 * 4);
}
  
    const static __m128i mask1 =  _mm_set1_epi32(1U); 
    const static __m128i mask2 =  _mm_set1_epi32(3U); 
    const static __m128i mask3 =  _mm_set1_epi32(7U); 
    const static __m128i mask4 =  _mm_set1_epi32(15U); 
    const static __m128i mask5 =  _mm_set1_epi32(31U); 
    const static __m128i mask6 =  _mm_set1_epi32(63U); 
    const static __m128i mask7 =  _mm_set1_epi32(127U); 
    const static __m128i mask8 =  _mm_set1_epi32(255U); 
    const static __m128i mask9 =  _mm_set1_epi32(511U); 
    const static __m128i mask10 =  _mm_set1_epi32(1023U); 
    const static __m128i mask11 =  _mm_set1_epi32(2047U); 
    const static __m128i mask12 =  _mm_set1_epi32(4095U); 
    const static __m128i mask13 =  _mm_set1_epi32(8191U); 
    const static __m128i mask14 =  _mm_set1_epi32(16383U); 
    const static __m128i mask15 =  _mm_set1_epi32(32767U); 
    const static __m128i mask16 =  _mm_set1_epi32(65535U); 
    const static __m128i mask17 =  _mm_set1_epi32(131071U); 
    const static __m128i mask18 =  _mm_set1_epi32(262143U); 
    const static __m128i mask19 =  _mm_set1_epi32(524287U); 
    const static __m128i mask20 =  _mm_set1_epi32(1048575U); 
    const static __m128i mask21 =  _mm_set1_epi32(2097151U); 
    const static __m128i mask22 =  _mm_set1_epi32(4194303U); 
    const static __m128i mask23 =  _mm_set1_epi32(8388607U); 
    const static __m128i mask24 =  _mm_set1_epi32(16777215U); 
    const static __m128i mask25 =  _mm_set1_epi32(33554431U); 
    const static __m128i mask26 =  _mm_set1_epi32(67108863U); 
    const static __m128i mask27 =  _mm_set1_epi32(134217727U); 
    const static __m128i mask28 =  _mm_set1_epi32(268435455U); 
    const static __m128i mask29 =  _mm_set1_epi32(536870911U); 
    const static __m128i mask30 =  _mm_set1_epi32(1073741823U); 
    const static __m128i mask31 =  _mm_set1_epi32(2147483647U); 
  
static void __SIMD_fastpackwithoutmask1_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask2_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask3_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 3 - 1);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 3 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask5_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 5 - 3);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 5 - 1);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 5 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 5 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask6_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 6 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 6 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 6 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 6 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask7_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 7 - 3);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 7 - 6);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 7 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 7 - 5);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 7 - 1);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 7 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask9_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 9 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 9 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 9 - 3);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 9 - 7);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 9 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 9 - 6);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 9 - 1);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 9 - 5);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask10_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 10 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 10 - 6);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 10 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 10 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 10 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 10 - 6);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 10 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 10 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask11_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 11 - 1);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 11 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 11 - 3);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 11 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 11 - 5);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 11 - 6);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 11 - 7);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 11 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 11 - 9);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 11 - 10);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask12_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 12 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 12 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 12 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 12 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 12 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 12 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 12 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 12 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask13_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 13 - 7);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 13 - 1);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 13 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 13 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 13 - 9);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 13 - 3);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 13 - 10);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 13 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 13 - 11);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 13 - 5);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 13 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 13 - 6);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask14_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 14 - 10);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 14 - 6);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 14 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 14 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 14 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 14 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 14 - 10);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 14 - 6);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 14 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 14 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 14 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 14 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask15_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 13);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 11);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 9);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 7);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 5);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 3);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 1);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 14);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 10);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 6);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask17_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 6);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 10);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 14);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 1);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 3);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 5);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 7);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 9);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 11);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 13);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 15);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask18_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 6);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 10);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 14);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 6);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 10);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 14);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask19_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 6);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 18);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 5);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 11);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 17);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 10);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 3);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 9);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 15);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 14);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 1);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 7);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 13);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask20_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask21_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 10);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 20);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 9);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 19);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 18);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 7);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 17);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 6);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 5);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 15);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 14);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 3);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 13);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 1);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 11);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask22_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 14);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 6);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 18);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 20);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 10);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 14);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 6);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 18);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 20);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 10);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask23_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 14);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 5);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 19);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 10);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 1);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 15);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 6);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 20);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 11);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 7);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 21);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 3);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 17);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 22);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 13);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 18);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 9);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask24_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask25_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 18);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 11);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 22);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 15);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 1);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 19);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 5);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 23);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 9);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 20);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 13);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 6);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 24);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 17);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 10);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 3);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 21);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 14);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 7);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask26_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 20);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 14);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 22);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 10);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 24);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 18);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 6);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 20);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 14);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 22);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 10);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 24);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 18);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 6);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask27_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 22);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 17);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 7);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 24);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 19);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 14);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 9);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 26);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 21);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 11);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 6);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 1);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 23);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 18);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 13);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 3);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 25);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 20);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 15);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 10);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 5);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask28_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 24);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 20);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 24);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 20);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 24);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 20);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 24);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 20);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask29_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 26);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 23);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 20);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 17);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 14);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 11);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 5);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 28);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 25);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 22);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 19);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 13);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 10);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 7);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 1);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 27);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 24);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 21);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 18);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 15);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 9);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 6);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 3);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask30_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 28);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 26);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 24);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 22);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 20);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 18);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 14);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 10);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 6);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 28);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 26);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 24);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 22);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 20);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 18);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 14);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 10);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 6);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask31_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 30);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 29);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 28);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 27);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 26);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 25);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 25));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 24);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 23);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 23));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 22);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 21);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 21));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 20);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 19);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 19));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 18);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 17);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 17));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 16);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 15);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 15));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 14);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 13);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 13));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 12);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 11);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 11));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 10);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 10));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 9);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 9));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 8);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 7);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 7));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 6);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 6));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 5);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 5));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 4);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 3);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 3));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 2);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 2));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 1);
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 1));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask32_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpackwithoutmask4_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
  for(uint32_t outer=0; outer< 4 ;++outer) {
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 4));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 12));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 20));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

  }

}


  
static void __SIMD_fastpackwithoutmask8_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
  for(uint32_t outer=0; outer< 8 ;++outer) {
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 8));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

  }

}


  
static void __SIMD_fastpackwithoutmask16_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i    OutReg;
    __m128i    InReg = _mm_load_si128(in);
      
  for(uint32_t outer=0; outer< 16 ;++outer) {
    OutReg = InReg; 
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

  }

}


  
static void __SIMD_fastpack1_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask1);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 1));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 3));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 5));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 7));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 9));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 11));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 13));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 15));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 17));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 19));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 21));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 23));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 25));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 27));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 29));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask1);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack2_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask2);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask2);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack3_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask3);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 3));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 9));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 15));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 21));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 27));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 3 - 1);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 1));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 7));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 13));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 19));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 25));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 3 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 5));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 11));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 17));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 23));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask3);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack5_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask5);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 5));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 15));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 25));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 5 - 3);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 3));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 13));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 23));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 5 - 1);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 1));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 11));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 21));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 5 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 9));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 19));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 5 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 7));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 17));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask5);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack6_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask6);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 6 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 6 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 6 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 6 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask6);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack7_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask7);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 7));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 21));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 7 - 3);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 3));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 17));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 7 - 6);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 13));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 7 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 9));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 23));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 7 - 5);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 5));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 19));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 7 - 1);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 1));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 15));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 7 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 11));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask7);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 25));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack9_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask9);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 9));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 9 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 13));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 9 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 17));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 9 - 3);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 3));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 21));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 9 - 7);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 7));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 25));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 9 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 11));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 9 - 6);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 15));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 9 - 1);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 1));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 19));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 9 - 5);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 5));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask9);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 23));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack10_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask10);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 10 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 10 - 6);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 10 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 10 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 10 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 10 - 6);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 10 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 10 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask10);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack11_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask11);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 11));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 11 - 1);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 1));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 23));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 11 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 13));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 11 - 3);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 3));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 25));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 11 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 15));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 11 - 5);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 5));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 11 - 6);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 17));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 11 - 7);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 7));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 11 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 19));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 11 - 9);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 9));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 11 - 10);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask11);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 21));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack12_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask12);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 12 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 12 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 12 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 12 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 12 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 12 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 12 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 12 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask12);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack13_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask13);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 13));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 13 - 7);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 7));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 13 - 1);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 1));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 13 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 21));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 13 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 15));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 13 - 9);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 9));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 13 - 3);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 3));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 13 - 10);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 23));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 13 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 17));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 13 - 11);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 11));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 13 - 5);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 5));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 13 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 25));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 13 - 6);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask13);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 19));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack14_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask14);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 14 - 10);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 14 - 6);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 14 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 14 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 14 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 14 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 14 - 10);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 14 - 6);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 14 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 14 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 14 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 14 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask14);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack15_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask15);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 15));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 13);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 13));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 11);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 11));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 9);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 9));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 7);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 7));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 5);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 5));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 3);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 3));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 1);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 1));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 14);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 10);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 25));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 23));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 6);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 21));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 19));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 15 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask15);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 17));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack17_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask17);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 17));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 19));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 21));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 6);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 23));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 25));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 10);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 14);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 1);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 1));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 3);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 3));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 5);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 5));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 7);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 7));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 9);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 9));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 11);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 11));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 13);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 13));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 17 - 15);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask17);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 15));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack18_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask18);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 6);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 10);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 14);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 6);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 10);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 18 - 14);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask18);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack19_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask19);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 19));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 6);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 25));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 18);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 5);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 5));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 11);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 11));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 17);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 17));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 23));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 10);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 3);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 3));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 9);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 9));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 15);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 15));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 21));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 14);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 1);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 1));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 7);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 7));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 19 - 13);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask19);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 13));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack20_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask20);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 20 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask20);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack21_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask21);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 21));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 10);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 20);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 9);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 9));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 19);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 19));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 18);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 7);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 7));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 17);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 17));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 6);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 5);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 5));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 15);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 15));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 25));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 14);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 3);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 3));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 13);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 13));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 23));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 1);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 1));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 21 - 11);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask21);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 11));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack22_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask22);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 14);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 6);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 18);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 20);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 10);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 14);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 6);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 18);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 20);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 22 - 10);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask22);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack23_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask23);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 23));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 14);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 5);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 5));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 19);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 19));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 10);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 1);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 1));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 15);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 15));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 6);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 20);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 11);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 11));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 25));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 7);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 7));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 21);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 21));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 3);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 3));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 17);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 17));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 22);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 13);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 13));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 18);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 23 - 9);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask23);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 9));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack24_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask24);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 24 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask24);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack25_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask25);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 25));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 18);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 11);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 11));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 22);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 15);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 15));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 1);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 1));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 19);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 19));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 5);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 5));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 23);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 23));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 9);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 9));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 20);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 13);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 13));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 6);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 24);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 17);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 17));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 10);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 3);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 3));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 21);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 21));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 14);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 25 - 7);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask25);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 7));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack26_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask26);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 20);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 14);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 22);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 10);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 24);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 18);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 6);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 20);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 14);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 22);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 10);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 24);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 18);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 26 - 6);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask26);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack27_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask27);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 22);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 17);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 17));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 7);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 7));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 24);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 19);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 19));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 14);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 9);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 9));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 26);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 21);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 21));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 11);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 11));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 6);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 1);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 1));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 23);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 23));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 18);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 13);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 13));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 3);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 3));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 25);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 25));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 20);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 15);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 15));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 10);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 27 - 5);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask27);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 5));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack28_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask28);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 24);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 20);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 24);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 20);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 24);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 20);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 24);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 20);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 28 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask28);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack29_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask29);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 26);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 23);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 23));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 20);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 17);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 17));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 14);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 11);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 11));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 5);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 5));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 28);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 25);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 25));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 22);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 19);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 19));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 13);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 13));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 10);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 7);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 7));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 1);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 1));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 27);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 24);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 21);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 21));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 18);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 15);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 15));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 9);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 9));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 6);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 29 - 3);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask29);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 3));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack30_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask30);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 28);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 26);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 24);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 22);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 20);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 18);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 14);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 10);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 6);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 28);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 26);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 24);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 22);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 20);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 18);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 14);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 10);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 6);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 30 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask30);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack31_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask31);
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 31));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 30);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 30));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 29);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 29));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 28);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 27);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 27));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 26);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 26));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 25);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 25));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 24);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 23);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 23));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 22);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 22));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 21);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 21));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 20);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 19);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 19));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 18);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 18));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 17);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 17));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 16);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 15);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 15));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 14);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 14));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 13);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 13));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 12);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 11);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 11));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 10);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 10));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 9);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 9));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 8);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 7);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 7));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 6);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 6));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 5);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 5));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 4);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 3);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 3));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 2);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 2));
    _mm_store_si128(out, OutReg);
    ++out;
    OutReg = _mm_srli_epi32(InReg, 31 - 1);
    InReg = _mm_and_si128(_mm_load_si128(++in), mask31);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 1));
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack32_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_load_si128(in);
    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_load_si128(++in);

    OutReg = InReg; 
    _mm_store_si128(out, OutReg);


}


  
static void __SIMD_fastpack4_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask4);
  for(uint32_t outer=0; outer< 4 ;++outer) {
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask4);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 4));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask4);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask4);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 12));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask4);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask4);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 20));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask4);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask4);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 28));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_and_si128(_mm_load_si128(++in), mask4);

  }

}


  
static void __SIMD_fastpack8_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask8);
  for(uint32_t outer=0; outer< 8 ;++outer) {
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask8);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 8));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask8);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    InReg = _mm_and_si128(_mm_load_si128(++in), mask8);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 24));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_and_si128(_mm_load_si128(++in), mask8);

  }

}


  
static void __SIMD_fastpack16_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    __m128i     OutReg;
      
    __m128i InReg = _mm_and_si128(_mm_load_si128(in), mask16);
  for(uint32_t outer=0; outer< 16 ;++outer) {
    OutReg = InReg; 
    InReg = _mm_and_si128(_mm_load_si128(++in), mask16);

    OutReg =  _mm_or_si128(OutReg,_mm_slli_epi32(InReg, 16));
    _mm_store_si128(out, OutReg);
    ++out;
    InReg = _mm_and_si128(_mm_load_si128(++in), mask16);

  }

}




static void __SIMD_fastunpack1_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,1) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,3) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,5) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,6) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,7) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,9) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,10) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,11) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,13) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,14) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,15) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,17) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,18) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,19) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,20) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,21) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,22) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,23) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,24) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,25) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,26) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,27) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,28) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,29) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,30) , mask1);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,31) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack2_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,6) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,10) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,14) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,18) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,20) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,22) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,24) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,26) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,28) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,6) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,10) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,14) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,18) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,20) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,22) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,24) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,26) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,28) , mask2);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack3_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {

    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,3) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,6) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,9) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,15) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,18) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,21) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,24) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,27) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask1), 3-1));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,1) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,7) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,10) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,13) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,19) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,22) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,25) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,28) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,31) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 3-2));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,5) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,11) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,14) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,17) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,20) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,23) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,26) , mask3);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,29) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack4_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {

    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;

    OutReg = _mm_and_si128( InReg , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,20) , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,24) , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,20) , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,24) , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,20) , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,24) , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,20) , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,24) , mask4);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack5_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask5);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,5) , mask5);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,10) , mask5);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,15) , mask5);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,20) , mask5);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,25) , mask5);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask3), 5-3));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,3) , mask5);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask5);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,13) , mask5);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,18) , mask5);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,23) , mask5);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask1), 5-1));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,1) , mask5);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,6) , mask5);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,11) , mask5);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask5);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,21) , mask5);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,26) , mask5);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,31) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 5-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask5);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,9) , mask5);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,14) , mask5);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,19) , mask5);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,24) , mask5);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,29) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 5-2));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask5);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,7) , mask5);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask5);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,17) , mask5);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,22) , mask5);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,27) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack6_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask6);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,6) , mask6);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask6);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,18) , mask6);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,24) , mask6);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 6-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask6);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,10) , mask6);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask6);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,22) , mask6);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 6-2));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask6);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask6);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,14) , mask6);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,20) , mask6);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,26) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask6);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,6) , mask6);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask6);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,18) , mask6);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,24) , mask6);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 6-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask6);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,10) , mask6);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask6);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,22) , mask6);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 6-2));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask6);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask6);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,14) , mask6);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,20) , mask6);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,26) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack7_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask7);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,7) , mask7);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,14) , mask7);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,21) , mask7);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask3), 7-3));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,3) , mask7);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,10) , mask7);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,17) , mask7);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,24) , mask7);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,31) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask6), 7-6));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,6) , mask7);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,13) , mask7);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,20) , mask7);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,27) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 7-2));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask7);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,9) , mask7);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask7);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,23) , mask7);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask5), 7-5));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,5) , mask7);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask7);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,19) , mask7);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,26) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask1), 7-1));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,1) , mask7);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask7);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,15) , mask7);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,22) , mask7);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,29) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 7-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask7);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,11) , mask7);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,18) , mask7);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,25) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack8_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask8);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask8);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask8);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask8);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask8);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask8);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask8);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask8);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask8);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask8);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask8);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask8);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask8);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask8);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask8);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask8);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask8);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask8);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask8);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask8);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask8);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask8);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask8);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask8);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack9_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask9);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,9) , mask9);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,18) , mask9);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,27) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 9-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask9);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,13) , mask9);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,22) , mask9);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,31) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 9-8));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask9);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,17) , mask9);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,26) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask3), 9-3));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,3) , mask9);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask9);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,21) , mask9);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask7), 9-7));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,7) , mask9);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask9);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,25) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 9-2));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask9);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,11) , mask9);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,20) , mask9);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,29) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask6), 9-6));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,6) , mask9);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,15) , mask9);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask1), 9-1));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,1) , mask9);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,10) , mask9);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,19) , mask9);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask5), 9-5));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,5) , mask9);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,14) , mask9);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,23) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack10_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask10);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,10) , mask10);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,20) , mask10);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 10-8));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask10);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,18) , mask10);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask6), 10-6));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,6) , mask10);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask10);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,26) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 10-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask10);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,14) , mask10);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 10-2));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask10);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask10);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,22) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask10);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,10) , mask10);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,20) , mask10);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 10-8));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask10);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,18) , mask10);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask6), 10-6));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,6) , mask10);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask10);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,26) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 10-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask10);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,14) , mask10);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 10-2));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask10);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask10);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,22) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack11_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask11);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,11) , mask11);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,22) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask1), 11-1));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,1) , mask11);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask11);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,23) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 11-2));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask11);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,13) , mask11);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask3), 11-3));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,3) , mask11);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,14) , mask11);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,25) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 11-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask11);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,15) , mask11);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,26) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask5), 11-5));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,5) , mask11);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask11);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,27) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask6), 11-6));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,6) , mask11);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,17) , mask11);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask7), 11-7));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,7) , mask11);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,18) , mask11);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,29) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 11-8));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask11);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,19) , mask11);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask9), 11-9));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,9) , mask11);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,20) , mask11);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,31) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask10), 11-10));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,10) , mask11);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,21) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack12_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask12);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask12);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 12-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask12);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask12);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 12-8));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask12);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask12);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask12);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 12-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask12);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask12);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 12-8));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask12);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask12);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask12);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 12-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask12);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask12);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 12-8));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask12);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask12);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask12);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 12-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask12);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask12);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 12-8));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask12);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack13_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask13);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,13) , mask13);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,26) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask7), 13-7));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,7) , mask13);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask1), 13-1));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,1) , mask13);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,14) , mask13);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,27) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 13-8));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask13);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,21) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 13-2));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask13);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,15) , mask13);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask9), 13-9));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,9) , mask13);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,22) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask3), 13-3));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,3) , mask13);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask13);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,29) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask10), 13-10));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,10) , mask13);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,23) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 13-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask13);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,17) , mask13);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask11), 13-11));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,11) , mask13);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask5), 13-5));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,5) , mask13);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,18) , mask13);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,31) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 13-12));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask13);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,25) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask6), 13-6));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,6) , mask13);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,19) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack14_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask14);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,14) , mask14);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask10), 14-10));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,10) , mask14);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask6), 14-6));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,6) , mask14);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 14-2));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask14);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask14);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 14-12));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask14);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,26) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 14-8));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask14);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,22) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 14-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask14);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,18) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask14);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,14) , mask14);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask10), 14-10));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,10) , mask14);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask6), 14-6));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,6) , mask14);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 14-2));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask14);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask14);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 14-12));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask14);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,26) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 14-8));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask14);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,22) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 14-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask14);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,18) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack15_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask15);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,15) , mask15);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask13), 15-13));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,13) , mask15);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask11), 15-11));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,11) , mask15);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,26) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask9), 15-9));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,9) , mask15);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask7), 15-7));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,7) , mask15);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,22) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask5), 15-5));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,5) , mask15);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask3), 15-3));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,3) , mask15);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,18) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask1), 15-1));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,1) , mask15);
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,16) , mask15);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,31) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask14), 15-14));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,14) , mask15);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,29) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 15-12));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask15);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,27) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask10), 15-10));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,10) , mask15);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,25) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 15-8));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask15);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,23) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask6), 15-6));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,6) , mask15);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,21) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 15-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask15);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,19) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 15-2));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask15);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,17) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack16_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask16);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask16);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask16);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask16);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask16);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask16);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask16);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask16);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask16);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask16);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask16);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask16);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask16);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask16);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask16);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask16);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack17_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask17);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,17) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 17-2));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask17);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,19) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 17-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask17);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,21) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask6), 17-6));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,6) , mask17);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,23) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 17-8));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask17);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,25) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask10), 17-10));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,10) , mask17);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,27) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 17-12));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask17);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,29) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask14), 17-14));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,14) , mask17);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,31) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 17-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask1), 17-1));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,1) , mask17);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,18) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask3), 17-3));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,3) , mask17);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask5), 17-5));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,5) , mask17);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,22) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask7), 17-7));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,7) , mask17);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask9), 17-9));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,9) , mask17);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,26) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask11), 17-11));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,11) , mask17);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask13), 17-13));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,13) , mask17);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask15), 17-15));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,15) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack18_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask18);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,18) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 18-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask18);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,22) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 18-8));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask18);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,26) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 18-12));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask18);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 18-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 18-2));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask18);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask6), 18-6));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,6) , mask18);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask10), 18-10));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,10) , mask18);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask14), 18-14));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,14) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask18);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,18) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 18-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask18);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,22) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 18-8));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask18);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,26) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 18-12));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask18);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 18-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 18-2));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask18);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask6), 18-6));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,6) , mask18);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask10), 18-10));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,10) , mask18);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask14), 18-14));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,14) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack19_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask19);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,19) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask6), 19-6));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,6) , mask19);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,25) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 19-12));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,12) , mask19);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,31) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask18), 19-18));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,18) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask5), 19-5));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,5) , mask19);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask11), 19-11));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,11) , mask19);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask17), 19-17));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,17) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 19-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask19);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,23) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask10), 19-10));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,10) , mask19);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,29) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 19-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask3), 19-3));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,3) , mask19);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,22) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask9), 19-9));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,9) , mask19);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask15), 19-15));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,15) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 19-2));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask19);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,21) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 19-8));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask19);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,27) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask14), 19-14));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,14) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask1), 19-1));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,1) , mask19);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask7), 19-7));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,7) , mask19);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,26) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask13), 19-13));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,13) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack20_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask20);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 20-8));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask20);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 20-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 20-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask20);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 20-12));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,12) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask20);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 20-8));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask20);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 20-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 20-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask20);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 20-12));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,12) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask20);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 20-8));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask20);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 20-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 20-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask20);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 20-12));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,12) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask20);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 20-8));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask20);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 20-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 20-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask20);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 20-12));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,12) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack21_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask21);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,21) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask10), 21-10));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,10) , mask21);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,31) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask20), 21-20));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask9), 21-9));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,9) , mask21);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask19), 21-19));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,19) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 21-8));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask21);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,29) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask18), 21-18));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,18) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask7), 21-7));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,7) , mask21);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask17), 21-17));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,17) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask6), 21-6));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,6) , mask21);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,27) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 21-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask5), 21-5));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,5) , mask21);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,26) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask15), 21-15));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,15) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 21-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask21);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,25) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask14), 21-14));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,14) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask3), 21-3));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,3) , mask21);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask13), 21-13));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,13) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 21-2));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask21);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,23) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 21-12));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,12) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask1), 21-1));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,1) , mask21);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,22) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask11), 21-11));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,11) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack22_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask22);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,22) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 22-12));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,12) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 22-2));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask22);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask14), 22-14));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,14) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 22-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask22);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,26) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 22-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask6), 22-6));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,6) , mask22);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask18), 22-18));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,18) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 22-8));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask22);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask20), 22-20));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask10), 22-10));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,10) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask22);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,22) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 22-12));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,12) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 22-2));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask22);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask14), 22-14));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,14) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 22-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask22);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,26) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 22-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask6), 22-6));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,6) , mask22);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask18), 22-18));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,18) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 22-8));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask22);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask20), 22-20));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask10), 22-10));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,10) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack23_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask23);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,23) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask14), 23-14));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,14) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask5), 23-5));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,5) , mask23);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask19), 23-19));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,19) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask10), 23-10));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,10) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask1), 23-1));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,1) , mask23);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask15), 23-15));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,15) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask6), 23-6));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,6) , mask23);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,29) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask20), 23-20));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask11), 23-11));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,11) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 23-2));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask23);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,25) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 23-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask7), 23-7));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,7) , mask23);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask21), 23-21));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,21) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 23-12));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,12) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask3), 23-3));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,3) , mask23);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,26) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask17), 23-17));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,17) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 23-8));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,8) , mask23);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,31) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask22), 23-22));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,22) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask13), 23-13));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,13) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 23-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask23);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,27) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask18), 23-18));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,18) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask9), 23-9));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,9) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack24_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask24);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 24-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 24-8));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,8) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask24);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 24-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 24-8));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,8) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask24);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 24-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 24-8));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,8) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask24);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 24-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 24-8));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,8) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask24);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 24-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 24-8));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,8) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask24);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 24-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 24-8));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,8) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask24);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 24-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 24-8));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,8) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask24);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 24-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 24-8));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,8) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack25_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask25);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,25) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask18), 25-18));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,18) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask11), 25-11));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,11) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 25-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask25);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,29) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask22), 25-22));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,22) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask15), 25-15));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,15) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 25-8));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,8) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask1), 25-1));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,1) , mask25);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,26) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask19), 25-19));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,19) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 25-12));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,12) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask5), 25-5));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,5) , mask25);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask23), 25-23));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,23) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 25-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask9), 25-9));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,9) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 25-2));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask25);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,27) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask20), 25-20));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask13), 25-13));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,13) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask6), 25-6));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,6) , mask25);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,31) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask24), 25-24));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask17), 25-17));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,17) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask10), 25-10));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,10) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask3), 25-3));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,3) , mask25);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask21), 25-21));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,21) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask14), 25-14));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,14) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask7), 25-7));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,7) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack26_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask26);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,26) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask20), 26-20));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask14), 26-14));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,14) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 26-8));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,8) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 26-2));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask26);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask22), 26-22));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,22) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 26-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask10), 26-10));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,10) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 26-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask26);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask24), 26-24));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask18), 26-18));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,18) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 26-12));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,12) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask6), 26-6));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,6) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask26);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,26) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask20), 26-20));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask14), 26-14));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,14) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 26-8));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,8) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 26-2));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask26);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask22), 26-22));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,22) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 26-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask10), 26-10));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,10) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 26-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask26);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask24), 26-24));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask18), 26-18));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,18) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 26-12));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,12) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask6), 26-6));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,6) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack27_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask27);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,27) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask22), 27-22));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,22) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask17), 27-17));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,17) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 27-12));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,12) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask7), 27-7));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,7) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 27-2));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask27);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,29) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask24), 27-24));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask19), 27-19));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,19) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask14), 27-14));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,14) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask9), 27-9));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,9) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 27-4));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,4) , mask27);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,31) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask26), 27-26));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,26) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask21), 27-21));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,21) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 27-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask11), 27-11));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,11) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask6), 27-6));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,6) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask1), 27-1));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,1) , mask27);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask23), 27-23));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,23) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask18), 27-18));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,18) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask13), 27-13));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,13) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 27-8));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,8) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask3), 27-3));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,3) , mask27);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask25), 27-25));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,25) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask20), 27-20));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask15), 27-15));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,15) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask10), 27-10));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,10) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask5), 27-5));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,5) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack28_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask28);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask24), 28-24));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask20), 28-20));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 28-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 28-12));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,12) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 28-8));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,8) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 28-4));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,4) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask28);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask24), 28-24));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask20), 28-20));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 28-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 28-12));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,12) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 28-8));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,8) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 28-4));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,4) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask28);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask24), 28-24));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask20), 28-20));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 28-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 28-12));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,12) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 28-8));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,8) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 28-4));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,4) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask28);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask24), 28-24));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask20), 28-20));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 28-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 28-12));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,12) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 28-8));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,8) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 28-4));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,4) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack29_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask29);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,29) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask26), 29-26));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,26) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask23), 29-23));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,23) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask20), 29-20));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask17), 29-17));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,17) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask14), 29-14));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,14) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask11), 29-11));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,11) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 29-8));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,8) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask5), 29-5));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,5) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 29-2));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,2) , mask29);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,31) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask28), 29-28));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask25), 29-25));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,25) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask22), 29-22));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,22) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask19), 29-19));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,19) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 29-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask13), 29-13));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,13) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask10), 29-10));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,10) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask7), 29-7));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,7) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 29-4));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,4) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask1), 29-1));
    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128(  _mm_srli_epi32(InReg,1) , mask29);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask27), 29-27));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,27) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask24), 29-24));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask21), 29-21));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,21) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask18), 29-18));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,18) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask15), 29-15));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,15) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 29-12));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,12) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask9), 29-9));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,9) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask6), 29-6));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,6) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask3), 29-3));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,3) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack30_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask30);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask28), 30-28));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask26), 30-26));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,26) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask24), 30-24));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask22), 30-22));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,22) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask20), 30-20));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask18), 30-18));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,18) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 30-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask14), 30-14));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,14) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 30-12));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,12) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask10), 30-10));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,10) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 30-8));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,8) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask6), 30-6));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,6) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 30-4));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,4) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 30-2));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,2) ;
    InReg = _mm_load_si128(++in);

    _mm_store_si128(out++, OutReg);

    OutReg = _mm_and_si128( InReg , mask30);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask28), 30-28));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask26), 30-26));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,26) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask24), 30-24));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask22), 30-22));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,22) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask20), 30-20));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask18), 30-18));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,18) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 30-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask14), 30-14));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,14) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 30-12));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,12) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask10), 30-10));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,10) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 30-8));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,8) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask6), 30-6));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,6) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 30-4));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,4) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 30-2));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,2) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack31_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    __m128i    InReg = _mm_load_si128(in);
    __m128i    OutReg;    
    
    OutReg = _mm_and_si128( InReg , mask31);
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,31) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask30), 31-30));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,30) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask29), 31-29));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,29) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask28), 31-28));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,28) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask27), 31-27));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,27) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask26), 31-26));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,26) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask25), 31-25));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,25) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask24), 31-24));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,24) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask23), 31-23));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,23) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask22), 31-22));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,22) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask21), 31-21));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,21) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask20), 31-20));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,20) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask19), 31-19));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,19) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask18), 31-18));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,18) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask17), 31-17));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,17) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask16), 31-16));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,16) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask15), 31-15));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,15) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask14), 31-14));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,14) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask13), 31-13));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,13) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask12), 31-12));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,12) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask11), 31-11));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,11) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask10), 31-10));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,10) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask9), 31-9));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,9) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask8), 31-8));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,8) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask7), 31-7));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,7) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask6), 31-6));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,6) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask5), 31-5));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,5) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask4), 31-4));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,4) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask3), 31-3));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,3) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask2), 31-2));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,2) ;
    InReg = _mm_load_si128(++in);

    OutReg = _mm_or_si128(OutReg, _mm_slli_epi32(_mm_and_si128(InReg, mask1), 31-1));
    _mm_store_si128(out++, OutReg);

    OutReg =   _mm_srli_epi32(InReg,1) ;
    _mm_store_si128(out++, OutReg);


}




static void __SIMD_fastunpack32_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
  for(uint32_t outer=0; outer< 32 ;++outer) {
    _mm_store_si128(out++, _mm_load_si128(in++));
  }
}
  
  

void simdunpack(const __m128i *  __restrict__ in, uint32_t *  __restrict__  out, const uint32_t bit) {
    switch(bit) {
        case 0: SIMD_nullunpacker32(in,out); return;

        case 1: __SIMD_fastunpack1_32(in,out); return;

        case 2: __SIMD_fastunpack2_32(in,out); return;

        case 3: __SIMD_fastunpack3_32(in,out); return;

        case 4: __SIMD_fastunpack4_32(in,out); return;

        case 5: __SIMD_fastunpack5_32(in,out); return;

        case 6: __SIMD_fastunpack6_32(in,out); return;

        case 7: __SIMD_fastunpack7_32(in,out); return;

        case 8: __SIMD_fastunpack8_32(in,out); return;

        case 9: __SIMD_fastunpack9_32(in,out); return;

        case 10: __SIMD_fastunpack10_32(in,out); return;

        case 11: __SIMD_fastunpack11_32(in,out); return;

        case 12: __SIMD_fastunpack12_32(in,out); return;

        case 13: __SIMD_fastunpack13_32(in,out); return;

        case 14: __SIMD_fastunpack14_32(in,out); return;

        case 15: __SIMD_fastunpack15_32(in,out); return;

        case 16: __SIMD_fastunpack16_32(in,out); return;

        case 17: __SIMD_fastunpack17_32(in,out); return;

        case 18: __SIMD_fastunpack18_32(in,out); return;

        case 19: __SIMD_fastunpack19_32(in,out); return;

        case 20: __SIMD_fastunpack20_32(in,out); return;

        case 21: __SIMD_fastunpack21_32(in,out); return;

        case 22: __SIMD_fastunpack22_32(in,out); return;

        case 23: __SIMD_fastunpack23_32(in,out); return;

        case 24: __SIMD_fastunpack24_32(in,out); return;

        case 25: __SIMD_fastunpack25_32(in,out); return;

        case 26: __SIMD_fastunpack26_32(in,out); return;

        case 27: __SIMD_fastunpack27_32(in,out); return;

        case 28: __SIMD_fastunpack28_32(in,out); return;

        case 29: __SIMD_fastunpack29_32(in,out); return;

        case 30: __SIMD_fastunpack30_32(in,out); return;

        case 31: __SIMD_fastunpack31_32(in,out); return;

        case 32: __SIMD_fastunpack32_32(in,out); return;

        default: break;    
    }
    throw logic_error("number of bits is unsupported");
}


  
  /*assumes that integers fit in the prescribed number of bits*/
void simdpackwithoutmask(const uint32_t *  __restrict__ in, __m128i *  __restrict__  out, const uint32_t bit) {
    switch(bit) {
        case 0: return;

        case 1: __SIMD_fastpackwithoutmask1_32(in,out); return;

        case 2: __SIMD_fastpackwithoutmask2_32(in,out); return;

        case 3: __SIMD_fastpackwithoutmask3_32(in,out); return;

        case 4: __SIMD_fastpackwithoutmask4_32(in,out); return;

        case 5: __SIMD_fastpackwithoutmask5_32(in,out); return;

        case 6: __SIMD_fastpackwithoutmask6_32(in,out); return;

        case 7: __SIMD_fastpackwithoutmask7_32(in,out); return;

        case 8: __SIMD_fastpackwithoutmask8_32(in,out); return;

        case 9: __SIMD_fastpackwithoutmask9_32(in,out); return;

        case 10: __SIMD_fastpackwithoutmask10_32(in,out); return;

        case 11: __SIMD_fastpackwithoutmask11_32(in,out); return;

        case 12: __SIMD_fastpackwithoutmask12_32(in,out); return;

        case 13: __SIMD_fastpackwithoutmask13_32(in,out); return;

        case 14: __SIMD_fastpackwithoutmask14_32(in,out); return;

        case 15: __SIMD_fastpackwithoutmask15_32(in,out); return;

        case 16: __SIMD_fastpackwithoutmask16_32(in,out); return;

        case 17: __SIMD_fastpackwithoutmask17_32(in,out); return;

        case 18: __SIMD_fastpackwithoutmask18_32(in,out); return;

        case 19: __SIMD_fastpackwithoutmask19_32(in,out); return;

        case 20: __SIMD_fastpackwithoutmask20_32(in,out); return;

        case 21: __SIMD_fastpackwithoutmask21_32(in,out); return;

        case 22: __SIMD_fastpackwithoutmask22_32(in,out); return;

        case 23: __SIMD_fastpackwithoutmask23_32(in,out); return;

        case 24: __SIMD_fastpackwithoutmask24_32(in,out); return;

        case 25: __SIMD_fastpackwithoutmask25_32(in,out); return;

        case 26: __SIMD_fastpackwithoutmask26_32(in,out); return;

        case 27: __SIMD_fastpackwithoutmask27_32(in,out); return;

        case 28: __SIMD_fastpackwithoutmask28_32(in,out); return;

        case 29: __SIMD_fastpackwithoutmask29_32(in,out); return;

        case 30: __SIMD_fastpackwithoutmask30_32(in,out); return;

        case 31: __SIMD_fastpackwithoutmask31_32(in,out); return;

        case 32: __SIMD_fastpackwithoutmask32_32(in,out); return;

        default: break;    
    }
    throw logic_error("number of bits is unsupported");
}
  

  
  /*assumes that integers fit in the prescribed number of bits*/
void simdpack(const uint32_t *  __restrict__ in, __m128i *  __restrict__  out, const uint32_t bit) {
    switch(bit) {
        case 0: return;

        case 1: __SIMD_fastpack1_32(in,out); return;

        case 2: __SIMD_fastpack2_32(in,out); return;

        case 3: __SIMD_fastpack3_32(in,out); return;

        case 4: __SIMD_fastpack4_32(in,out); return;

        case 5: __SIMD_fastpack5_32(in,out); return;

        case 6: __SIMD_fastpack6_32(in,out); return;

        case 7: __SIMD_fastpack7_32(in,out); return;

        case 8: __SIMD_fastpack8_32(in,out); return;

        case 9: __SIMD_fastpack9_32(in,out); return;

        case 10: __SIMD_fastpack10_32(in,out); return;

        case 11: __SIMD_fastpack11_32(in,out); return;

        case 12: __SIMD_fastpack12_32(in,out); return;

        case 13: __SIMD_fastpack13_32(in,out); return;

        case 14: __SIMD_fastpack14_32(in,out); return;

        case 15: __SIMD_fastpack15_32(in,out); return;

        case 16: __SIMD_fastpack16_32(in,out); return;

        case 17: __SIMD_fastpack17_32(in,out); return;

        case 18: __SIMD_fastpack18_32(in,out); return;

        case 19: __SIMD_fastpack19_32(in,out); return;

        case 20: __SIMD_fastpack20_32(in,out); return;

        case 21: __SIMD_fastpack21_32(in,out); return;

        case 22: __SIMD_fastpack22_32(in,out); return;

        case 23: __SIMD_fastpack23_32(in,out); return;

        case 24: __SIMD_fastpack24_32(in,out); return;

        case 25: __SIMD_fastpack25_32(in,out); return;

        case 26: __SIMD_fastpack26_32(in,out); return;

        case 27: __SIMD_fastpack27_32(in,out); return;

        case 28: __SIMD_fastpack28_32(in,out); return;

        case 29: __SIMD_fastpack29_32(in,out); return;

        case 30: __SIMD_fastpack30_32(in,out); return;

        case 31: __SIMD_fastpack31_32(in,out); return;

        case 32: __SIMD_fastpack32_32(in,out); return;

        default: break;    
    }
    throw logic_error("number of bits is unsupported");
}
  


void SIMD_fastunpack_32(const __m128i *  __restrict__ in, uint32_t *  __restrict__  out, const uint32_t bit) {
    simdunpack(in,out, bit);
}
void SIMD_fastpackwithoutmask_32(const uint32_t *  __restrict__ in, __m128i *  __restrict__  out, const uint32_t bit) {
    simdpackwithoutmask(in,out, bit);
}
void SIMD_fastpack_32(const uint32_t *  __restrict__ in, __m128i *  __restrict__  out, const uint32_t bit) {
    simdpack(in,out, bit);
}
