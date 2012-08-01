/**
 * This is code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Leonid Boytsov, revised and optimized by Daniel Lemire
 */

/**
 * Note by D. Lemire: Obviously this code requires SSE2 so
 * when porting to non-x86 platforms, your best bet might be not
 * to port this part of the code.
 */

#include <iostream>
#include <iomanip>
#include <iomanip>
#include <stdexcept>


#include "common.h"
#include "bitpacksimd.h"

using namespace std;

__v4su  _NumMaskSIMD1{ 1U ,1U ,1U ,1U };
__v4sf  NumMaskSIMD1 =  reinterpret_cast<__v4sf>(_NumMaskSIMD1);
__v4su  _NumMaskSIMD2{ 3U ,3U ,3U ,3U };
__v4sf  NumMaskSIMD2 =  reinterpret_cast<__v4sf>(_NumMaskSIMD2);
__v4su  _NumMaskSIMD3{ 7U ,7U ,7U ,7U };
__v4sf  NumMaskSIMD3 =  reinterpret_cast<__v4sf>(_NumMaskSIMD3);
__v4su  _NumMaskSIMD4{ 15U ,15U ,15U ,15U };
__v4sf  NumMaskSIMD4 =  reinterpret_cast<__v4sf>(_NumMaskSIMD4);
__v4su  _NumMaskSIMD5{ 31U ,31U ,31U ,31U };
__v4sf  NumMaskSIMD5 =  reinterpret_cast<__v4sf>(_NumMaskSIMD5);
__v4su  _NumMaskSIMD6{ 63U ,63U ,63U ,63U };
__v4sf  NumMaskSIMD6 =  reinterpret_cast<__v4sf>(_NumMaskSIMD6);
__v4su  _NumMaskSIMD7{ 127U ,127U ,127U ,127U };
__v4sf  NumMaskSIMD7 =  reinterpret_cast<__v4sf>(_NumMaskSIMD7);
__v4su  _NumMaskSIMD8{ 255U ,255U ,255U ,255U };
__v4sf  NumMaskSIMD8 =  reinterpret_cast<__v4sf>(_NumMaskSIMD8);
__v4su  _NumMaskSIMD9{ 511U ,511U ,511U ,511U };
__v4sf  NumMaskSIMD9 =  reinterpret_cast<__v4sf>(_NumMaskSIMD9);
__v4su  _NumMaskSIMD10{ 1023U ,1023U ,1023U ,1023U };
__v4sf  NumMaskSIMD10 =  reinterpret_cast<__v4sf>(_NumMaskSIMD10);
__v4su  _NumMaskSIMD11{ 2047U ,2047U ,2047U ,2047U };
__v4sf  NumMaskSIMD11 =  reinterpret_cast<__v4sf>(_NumMaskSIMD11);
__v4su  _NumMaskSIMD12{ 4095U ,4095U ,4095U ,4095U };
__v4sf  NumMaskSIMD12 =  reinterpret_cast<__v4sf>(_NumMaskSIMD12);
__v4su  _NumMaskSIMD13{ 8191U ,8191U ,8191U ,8191U };
__v4sf  NumMaskSIMD13 =  reinterpret_cast<__v4sf>(_NumMaskSIMD13);
__v4su  _NumMaskSIMD14{ 16383U ,16383U ,16383U ,16383U };
__v4sf  NumMaskSIMD14 =  reinterpret_cast<__v4sf>(_NumMaskSIMD14);
__v4su  _NumMaskSIMD15{ 32767U ,32767U ,32767U ,32767U };
__v4sf  NumMaskSIMD15 =  reinterpret_cast<__v4sf>(_NumMaskSIMD15);
__v4su  _NumMaskSIMD16{ 65535U ,65535U ,65535U ,65535U };
__v4sf  NumMaskSIMD16 =  reinterpret_cast<__v4sf>(_NumMaskSIMD16);
__v4su  _NumMaskSIMD17{ 131071U ,131071U ,131071U ,131071U };
__v4sf  NumMaskSIMD17 =  reinterpret_cast<__v4sf>(_NumMaskSIMD17);
__v4su  _NumMaskSIMD18{ 262143U ,262143U ,262143U ,262143U };
__v4sf  NumMaskSIMD18 =  reinterpret_cast<__v4sf>(_NumMaskSIMD18);
__v4su  _NumMaskSIMD19{ 524287U ,524287U ,524287U ,524287U };
__v4sf  NumMaskSIMD19 =  reinterpret_cast<__v4sf>(_NumMaskSIMD19);
__v4su  _NumMaskSIMD20{ 1048575U ,1048575U ,1048575U ,1048575U };
__v4sf  NumMaskSIMD20 =  reinterpret_cast<__v4sf>(_NumMaskSIMD20);
__v4su  _NumMaskSIMD21{ 2097151U ,2097151U ,2097151U ,2097151U };
__v4sf  NumMaskSIMD21 =  reinterpret_cast<__v4sf>(_NumMaskSIMD21);
__v4su  _NumMaskSIMD22{ 4194303U ,4194303U ,4194303U ,4194303U };
__v4sf  NumMaskSIMD22 =  reinterpret_cast<__v4sf>(_NumMaskSIMD22);
__v4su  _NumMaskSIMD23{ 8388607U ,8388607U ,8388607U ,8388607U };
__v4sf  NumMaskSIMD23 =  reinterpret_cast<__v4sf>(_NumMaskSIMD23);
__v4su  _NumMaskSIMD24{ 16777215U ,16777215U ,16777215U ,16777215U };
__v4sf  NumMaskSIMD24 =  reinterpret_cast<__v4sf>(_NumMaskSIMD24);
__v4su  _NumMaskSIMD25{ 33554431U ,33554431U ,33554431U ,33554431U };
__v4sf  NumMaskSIMD25 =  reinterpret_cast<__v4sf>(_NumMaskSIMD25);
__v4su  _NumMaskSIMD26{ 67108863U ,67108863U ,67108863U ,67108863U };
__v4sf  NumMaskSIMD26 =  reinterpret_cast<__v4sf>(_NumMaskSIMD26);
__v4su  _NumMaskSIMD27{ 134217727U ,134217727U ,134217727U ,134217727U };
__v4sf  NumMaskSIMD27 =  reinterpret_cast<__v4sf>(_NumMaskSIMD27);
__v4su  _NumMaskSIMD28{ 268435455U ,268435455U ,268435455U ,268435455U };
__v4sf  NumMaskSIMD28 =  reinterpret_cast<__v4sf>(_NumMaskSIMD28);
__v4su  _NumMaskSIMD29{ 536870911U ,536870911U ,536870911U ,536870911U };
__v4sf  NumMaskSIMD29 =  reinterpret_cast<__v4sf>(_NumMaskSIMD29);
__v4su  _NumMaskSIMD30{ 1073741823U ,1073741823U ,1073741823U ,1073741823U };
__v4sf  NumMaskSIMD30 =  reinterpret_cast<__v4sf>(_NumMaskSIMD30);
__v4su  _NumMaskSIMD31{ 2147483647U ,2147483647U ,2147483647U ,2147483647U };
__v4sf  NumMaskSIMD31 =  reinterpret_cast<__v4sf>(_NumMaskSIMD31);
__v4su  _NumMaskSIMD32{ 4294967295U ,4294967295U ,4294967295U ,4294967295U };
__v4sf  NumMaskSIMD32 =  reinterpret_cast<__v4sf>(_NumMaskSIMD32);

void SIMD_nullunpacker32(const __m128i *  __restrict__ , uint32_t *  __restrict__  out) {
    memset(out,0,32 * 4 * 4);
}
  
  
void __SIMD_fastpackwithoutmask1_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);
      
    OutReg = reinterpret_cast<__v4sf>(InReg); 
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 1)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 3)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 5)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 7)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 9)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 11)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 13)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 15)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 17)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 19)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 21)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 23)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 25)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 27)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 29)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpack1_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
      
    register __v4sf mask =  NumMaskSIMD1;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 1)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 3)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 5)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 7)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 9)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 11)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 13)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 15)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 17)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 19)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 21)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 23)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 25)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 27)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 29)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpackwithoutmask2_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);
      
    OutReg = reinterpret_cast<__v4sf>(InReg); 
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpack2_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
      
    register __v4sf mask =  NumMaskSIMD2;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpackwithoutmask3_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);
      
    OutReg = reinterpret_cast<__v4sf>(InReg); 
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 3)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 9)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 15)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 21)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 27)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 3 - 1));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 1)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 7)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 13)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 19)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 25)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 3 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 5)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 11)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 17)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 23)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpack3_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
      
    register __v4sf mask =  NumMaskSIMD3;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 3)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 9)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 15)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 21)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 27)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 3 - 1));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 1)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 7)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 13)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 19)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 25)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 3 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 5)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 11)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 17)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 23)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpackwithoutmask4_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);
      
    OutReg = reinterpret_cast<__v4sf>(InReg); 
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpack4_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
      
    register __v4sf mask =  NumMaskSIMD4;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpackwithoutmask5_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);
      
    OutReg = reinterpret_cast<__v4sf>(InReg); 
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 5)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 15)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 25)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 5 - 3));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 3)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 13)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 23)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 5 - 1));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 1)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 11)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 21)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 5 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 9)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 19)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 5 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 7)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 17)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpack5_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
      
    register __v4sf mask =  NumMaskSIMD5;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 5)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 15)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 25)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 5 - 3));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 3)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 13)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 23)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 5 - 1));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 1)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 11)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 21)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 5 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 9)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 19)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 5 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 7)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 17)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpackwithoutmask6_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);
      
    OutReg = reinterpret_cast<__v4sf>(InReg); 
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 6 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 6 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 6 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 6 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpack6_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
      
    register __v4sf mask =  NumMaskSIMD6;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 6 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 6 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 6 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 6 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpackwithoutmask7_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);
      
    OutReg = reinterpret_cast<__v4sf>(InReg); 
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 7)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 21)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 7 - 3));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 3)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 17)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 7 - 6));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 13)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 7 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 9)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 23)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 7 - 5));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 5)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 19)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 7 - 1));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 1)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 15)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 7 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 11)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 25)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpack7_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
      
    register __v4sf mask =  NumMaskSIMD7;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 7)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 21)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 7 - 3));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 3)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 17)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 7 - 6));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 13)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 7 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 9)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 23)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 7 - 5));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 5)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 19)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 7 - 1));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 1)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 15)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 7 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 11)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 25)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpackwithoutmask8_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);
      
    OutReg = reinterpret_cast<__v4sf>(InReg); 
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpack8_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
      
    register __v4sf mask =  NumMaskSIMD8;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpackwithoutmask9_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);
      
    OutReg = reinterpret_cast<__v4sf>(InReg); 
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 9)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 9 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 13)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 9 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 17)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 9 - 3));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 3)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 21)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 9 - 7));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 7)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 25)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 9 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 11)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 9 - 6));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 15)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 9 - 1));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 1)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 19)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 9 - 5));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 5)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 23)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpack9_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
      
    register __v4sf mask =  NumMaskSIMD9;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 9)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 9 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 13)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 9 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 17)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 9 - 3));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 3)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 21)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 9 - 7));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 7)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 25)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 9 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 11)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 9 - 6));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 15)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 9 - 1));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 1)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 19)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 9 - 5));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 5)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 23)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpackwithoutmask10_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);
      
    OutReg = reinterpret_cast<__v4sf>(InReg); 
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 10 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 10 - 6));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 10 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 10 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 10 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 10 - 6));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 10 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 10 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpack10_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
      
    register __v4sf mask =  NumMaskSIMD10;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 10 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 10 - 6));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 10 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 10 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 10 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 10 - 6));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 10 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 10 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpackwithoutmask11_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 11)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 11 - 1));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 1)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 23)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 11 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 13)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 11 - 3));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 3)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 25)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 11 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 15)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 11 - 5));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 5)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 11 - 6));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 17)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 11 - 7));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 7)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 11 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 19)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 11 - 9));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 9)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 11 - 10));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 21)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpack11_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;

    register __v4sf mask =  NumMaskSIMD11;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 11)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 11 - 1));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 1)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 23)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 11 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 13)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 11 - 3));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 3)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 25)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 11 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 15)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 11 - 5));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 5)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 11 - 6));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 17)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 11 - 7));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 7)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 11 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 19)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 11 - 9));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 9)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 11 - 10));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 21)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpackwithoutmask12_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 12 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 12 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 12 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 12 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 12 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 12 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 12 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 12 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpack12_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;

    register __v4sf mask =  NumMaskSIMD12;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 12 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 12 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 12 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 12 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 12 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 12 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 12 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 12 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpackwithoutmask13_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 13)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 13 - 7));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 7)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 13 - 1));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 1)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 13 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 21)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 13 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 15)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 13 - 9));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 9)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 13 - 3));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 3)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 13 - 10));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 23)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 13 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 17)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 13 - 11));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 11)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 13 - 5));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 5)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 13 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 25)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 13 - 6));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 19)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpack13_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;

    register __v4sf mask =  NumMaskSIMD13;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 13)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 13 - 7));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 7)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 13 - 1));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 1)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 13 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 21)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 13 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 15)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 13 - 9));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 9)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 13 - 3));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 3)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 13 - 10));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 23)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 13 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 17)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 13 - 11));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 11)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 13 - 5));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 5)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 13 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 25)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 13 - 6));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 19)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpackwithoutmask14_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 14 - 10));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 14 - 6));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 14 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 14 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 14 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 14 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 14 - 10));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 14 - 6));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 14 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 14 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 14 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 14 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpack14_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;

    register __v4sf mask =  NumMaskSIMD14;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 14 - 10));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 14 - 6));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 14 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 14 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 14 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 14 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 14 - 10));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 14 - 6));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 14 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 14 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 14 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 14 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpackwithoutmask15_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 15)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 15 - 13));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 13)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 15 - 11));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 11)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 15 - 9));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 9)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 15 - 7));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 7)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 15 - 5));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 5)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 15 - 3));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 3)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 15 - 1));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 1)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 15 - 14));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 15 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 15 - 10));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 25)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 15 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 23)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 15 - 6));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 21)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 15 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 19)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 15 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 17)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpack15_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;

    register __v4sf mask =  NumMaskSIMD15;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 15)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 15 - 13));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 13)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 15 - 11));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 11)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 15 - 9));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 9)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 15 - 7));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 7)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 15 - 5));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 5)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 15 - 3));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 3)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 15 - 1));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 1)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 15 - 14));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 15 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 15 - 10));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 25)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 15 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 23)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 15 - 6));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 21)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 15 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 19)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 15 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 17)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpackwithoutmask16_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpack16_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;

    register __v4sf mask =  NumMaskSIMD16;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpackwithoutmask17_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 17)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 17 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 19)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 17 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 21)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 17 - 6));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 23)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 17 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 25)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 17 - 10));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 17 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 17 - 14));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 17 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 17 - 1));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 1)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 17 - 3));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 3)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 17 - 5));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 5)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 17 - 7));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 7)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 17 - 9));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 9)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 17 - 11));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 11)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 17 - 13));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 13)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 17 - 15));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 15)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpack17_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;

    register __v4sf mask =  NumMaskSIMD17;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 17)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 17 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 19)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 17 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 21)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 17 - 6));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 23)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 17 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 25)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 17 - 10));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 17 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 17 - 14));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 17 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 17 - 1));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 1)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 17 - 3));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 3)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 17 - 5));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 5)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 17 - 7));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 7)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 17 - 9));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 9)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 17 - 11));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 11)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 17 - 13));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 13)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 17 - 15));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 15)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpackwithoutmask18_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 18 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 18 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 18 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 18 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 18 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 18 - 6));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 18 - 10));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 18 - 14));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 18 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 18 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 18 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 18 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 18 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 18 - 6));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 18 - 10));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 18 - 14));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpack18_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;

    register __v4sf mask =  NumMaskSIMD18;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 18 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 18 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 18 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 18 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 18 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 18 - 6));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 18 - 10));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 18 - 14));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 18 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 18 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 18 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 18 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 18 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 18 - 6));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 18 - 10));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 18 - 14));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpackwithoutmask19_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 19)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 19 - 6));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 25)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 19 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 19 - 18));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 19 - 5));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 5)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 19 - 11));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 11)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 19 - 17));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 17)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 19 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 23)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 19 - 10));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 19 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 19 - 3));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 3)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 19 - 9));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 9)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 19 - 15));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 15)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 19 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 21)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 19 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 19 - 14));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 19 - 1));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 1)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 19 - 7));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 7)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 19 - 13));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 13)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpack19_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;

    register __v4sf mask =  NumMaskSIMD19;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 19)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 19 - 6));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 25)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 19 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 19 - 18));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 19 - 5));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 5)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 19 - 11));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 11)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 19 - 17));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 17)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 19 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 23)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 19 - 10));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 19 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 19 - 3));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 3)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 19 - 9));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 9)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 19 - 15));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 15)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 19 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 21)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 19 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 19 - 14));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 19 - 1));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 1)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 19 - 7));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 7)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 19 - 13));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 13)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpackwithoutmask20_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 20 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 20 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 20 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 20 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 20 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 20 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 20 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 20 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 20 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 20 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 20 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 20 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 20 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 20 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 20 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 20 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpack20_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;

    register __v4sf mask =  NumMaskSIMD20;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 20 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 20 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 20 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 20 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 20 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 20 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 20 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 20 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 20 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 20 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 20 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 20 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 20 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 20 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 20 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 20 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpackwithoutmask21_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 21)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 21 - 10));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 21 - 20));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 21 - 9));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 9)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 21 - 19));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 19)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 21 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 21 - 18));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 21 - 7));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 7)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 21 - 17));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 17)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 21 - 6));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 21 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 21 - 5));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 5)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 21 - 15));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 15)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 21 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 25)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 21 - 14));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 21 - 3));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 3)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 21 - 13));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 13)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 21 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 23)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 21 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 21 - 1));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 1)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 21 - 11));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 11)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpack21_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;

    register __v4sf mask =  NumMaskSIMD21;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 21)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 21 - 10));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 21 - 20));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 21 - 9));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 9)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 21 - 19));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 19)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 21 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 21 - 18));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 21 - 7));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 7)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 21 - 17));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 17)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 21 - 6));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 21 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 21 - 5));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 5)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 21 - 15));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 15)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 21 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 25)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 21 - 14));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 21 - 3));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 3)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 21 - 13));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 13)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 21 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 23)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 21 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 21 - 1));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 1)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 21 - 11));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 11)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpackwithoutmask22_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 22 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 22 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 22 - 14));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 22 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 22 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 22 - 6));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 22 - 18));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 22 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 22 - 20));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 22 - 10));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 22 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 22 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 22 - 14));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 22 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 22 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 22 - 6));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 22 - 18));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 22 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 22 - 20));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 22 - 10));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpack22_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;

    register __v4sf mask =  NumMaskSIMD22;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 22 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 22 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 22 - 14));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 22 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 22 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 22 - 6));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 22 - 18));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 22 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 22 - 20));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 22 - 10));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 22 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 22 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 22 - 14));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 22 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 22 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 22 - 6));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 22 - 18));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 22 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 22 - 20));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 22 - 10));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpackwithoutmask23_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 23)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 23 - 14));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 23 - 5));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 5)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 23 - 19));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 19)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 23 - 10));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 23 - 1));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 1)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 23 - 15));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 15)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 23 - 6));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 23 - 20));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 23 - 11));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 11)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 23 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 25)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 23 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 23 - 7));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 7)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 23 - 21));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 21)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 23 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 23 - 3));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 3)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 23 - 17));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 17)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 23 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 23 - 22));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 23 - 13));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 13)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 23 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 23 - 18));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 23 - 9));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 9)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpack23_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;

    register __v4sf mask =  NumMaskSIMD23;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 23)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 23 - 14));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 23 - 5));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 5)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 23 - 19));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 19)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 23 - 10));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 23 - 1));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 1)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 23 - 15));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 15)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 23 - 6));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 23 - 20));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 23 - 11));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 11)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 23 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 25)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 23 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 23 - 7));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 7)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 23 - 21));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 21)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 23 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 23 - 3));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 3)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 23 - 17));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 17)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 23 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 23 - 22));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 23 - 13));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 13)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 23 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 23 - 18));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 23 - 9));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 9)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpackwithoutmask24_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 24 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 24 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 24 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 24 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 24 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 24 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 24 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 24 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 24 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 24 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 24 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 24 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 24 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 24 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 24 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 24 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpack24_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;

    register __v4sf mask =  NumMaskSIMD24;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 24 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 24 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 24 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 24 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 24 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 24 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 24 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 24 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 24 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 24 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 24 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 24 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 24 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 24 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 24 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 24 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpackwithoutmask25_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 25)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 25 - 18));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 25 - 11));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 11)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 25 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 25 - 22));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 25 - 15));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 15)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 25 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 25 - 1));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 1)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 25 - 19));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 19)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 25 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 25 - 5));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 5)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 25 - 23));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 23)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 25 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 25 - 9));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 9)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 25 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 25 - 20));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 25 - 13));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 13)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 25 - 6));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 25 - 24));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 25 - 17));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 17)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 25 - 10));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 25 - 3));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 3)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 25 - 21));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 21)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 25 - 14));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 25 - 7));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 7)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpack25_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;

    register __v4sf mask =  NumMaskSIMD25;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 25)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 25 - 18));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 25 - 11));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 11)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 25 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 25 - 22));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 25 - 15));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 15)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 25 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 25 - 1));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 1)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 25 - 19));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 19)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 25 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 25 - 5));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 5)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 25 - 23));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 23)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 25 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 25 - 9));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 9)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 25 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 25 - 20));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 25 - 13));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 13)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 25 - 6));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 25 - 24));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 25 - 17));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 17)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 25 - 10));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 25 - 3));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 3)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 25 - 21));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 21)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 25 - 14));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 25 - 7));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 7)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpackwithoutmask26_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 26 - 20));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 26 - 14));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 26 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 26 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 26 - 22));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 26 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 26 - 10));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 26 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 26 - 24));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 26 - 18));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 26 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 26 - 6));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 26 - 20));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 26 - 14));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 26 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 26 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 26 - 22));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 26 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 26 - 10));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 26 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 26 - 24));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 26 - 18));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 26 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 26 - 6));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpack26_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;

    register __v4sf mask =  NumMaskSIMD26;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 26 - 20));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 26 - 14));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 26 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 26 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 26 - 22));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 26 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 26 - 10));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 26 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 26 - 24));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 26 - 18));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 26 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 26 - 6));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 26 - 20));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 26 - 14));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 26 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 26 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 26 - 22));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 26 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 26 - 10));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 26 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 26 - 24));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 26 - 18));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 26 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 26 - 6));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}



void __SIMD_fastpackwithoutmask27_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 27 - 22));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 27 - 17));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 17)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 27 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 27 - 7));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 7)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 27 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 27 - 24));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 27 - 19));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 19)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 27 - 14));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 27 - 9));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 9)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 27 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 27 - 26));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 27 - 21));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 21)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 27 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 27 - 11));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 11)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 27 - 6));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 27 - 1));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 1)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 27 - 23));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 23)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 27 - 18));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 27 - 13));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 13)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 27 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 27 - 3));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 3)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 27 - 25));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 25)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 27 - 20));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 27 - 15));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 15)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 27 - 10));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 27 - 5));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 5)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpack27_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
      
    register __v4sf mask =  NumMaskSIMD27;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 27 - 22));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 27 - 17));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 17)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 27 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 27 - 7));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 7)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 27 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 27 - 24));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 27 - 19));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 19)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 27 - 14));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 27 - 9));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 9)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 27 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 27 - 26));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 27 - 21));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 21)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 27 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 27 - 11));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 11)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 27 - 6));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 27 - 1));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 1)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 27 - 23));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 23)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 27 - 18));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 27 - 13));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 13)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 27 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 27 - 3));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 3)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 27 - 25));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 25)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 27 - 20));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 27 - 15));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 15)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 27 - 10));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 27 - 5));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 5)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpackwithoutmask28_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);
      
    OutReg = reinterpret_cast<__v4sf>(InReg); 
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 28 - 24));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 28 - 20));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 28 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 28 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 28 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 28 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 28 - 24));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 28 - 20));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 28 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 28 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 28 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 28 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 28 - 24));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 28 - 20));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 28 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 28 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 28 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 28 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 28 - 24));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 28 - 20));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 28 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 28 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 28 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 28 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpack28_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
      
    register __v4sf mask =  NumMaskSIMD28;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 28 - 24));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 28 - 20));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 28 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 28 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 28 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 28 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 28 - 24));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 28 - 20));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 28 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 28 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 28 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 28 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 28 - 24));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 28 - 20));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 28 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 28 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 28 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 28 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 28 - 24));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 28 - 20));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 28 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 28 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 28 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 28 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpackwithoutmask29_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);
      
    OutReg = reinterpret_cast<__v4sf>(InReg); 
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 26));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 23));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 23)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 20));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 17));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 17)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 14));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 11));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 11)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 5));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 5)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 28));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 25));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 25)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 22));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 19));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 19)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 13));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 13)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 10));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 7));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 7)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 1));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 1)));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 27));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 24));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 21));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 21)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 18));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 15));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 15)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 9));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 9)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 6));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 29 - 3));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 3)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpack29_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
      
    register __v4sf mask =  NumMaskSIMD29;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 26));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 23));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 23)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 20));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 17));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 17)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 14));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 11));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 11)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 5));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 5)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 28));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 25));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 25)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 22));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 19));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 19)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 13));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 13)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 10));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 7));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 7)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 1));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 1)));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 27));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 24));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 21));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 21)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 18));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 15));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 15)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 9));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 9)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 6));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 29 - 3));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 3)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpackwithoutmask30_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);
      
    OutReg = reinterpret_cast<__v4sf>(InReg); 
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 28));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 26));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 24));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 22));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 20));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 18));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 14));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 10));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 6));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 28));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 26));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 24));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 22));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 20));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 18));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 14));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 10));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 6));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 30 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpack30_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
      
    register __v4sf mask =  NumMaskSIMD30;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 28));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 26));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 24));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 22));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 20));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 18));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 14));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 10));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 6));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 28));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 26));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 24));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 22));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 20));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 18));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 14));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 10));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 6));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 30 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpackwithoutmask31_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);
      
    OutReg = reinterpret_cast<__v4sf>(InReg); 
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 30));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 29));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 28));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 27));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 26));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 25));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 25)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 24));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 23));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 23)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 22));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 21));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 21)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 20));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 19));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 19)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 18));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 17));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 17)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 16));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 15));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 15)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 14));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 13));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 13)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 12));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 11));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 11)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 10));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 10)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 9));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 9)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 8));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 7));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 7)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 6));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 6)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 5));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 5)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 4));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 4)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 3));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 3)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 2));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 2)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg, 31 - 1));
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(InReg, 1)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpack31_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
      
    register __v4sf mask =  NumMaskSIMD31;
    register __v4sf     InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);
    OutReg = InReg; // modif. by D. Lemire, was OutReg = _mm_and_ps(InReg, mask);
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 31)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 30));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 30)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 29));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 29)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 28));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 28)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 27));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 27)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 26));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 26)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 25));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 25)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 24));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 24)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 23));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 23)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 22));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 22)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 21));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 21)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 20));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 20)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 19));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 19)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 18));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 18)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 17));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 17)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 16));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 16)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 15));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 15)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 14));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 14)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 13));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 13)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 12));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 12)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 11));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 11)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 10));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 10)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 9));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 9)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 8));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 8)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 7));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 7)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 6));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 6)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 5));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 5)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 4));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 4)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 3));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 3)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 2));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 2)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    OutReg = reinterpret_cast<__v4sf>(_mm_srli_epi32(reinterpret_cast<__m128i>(InReg), 31 - 1));
    ++in;
    InReg = _mm_and_ps(reinterpret_cast<__v4sf>(_mm_load_si128(in)), mask);

    OutReg = _mm_or_ps(OutReg, reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(InReg), 1)));
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpackwithoutmask32_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    const __m128i       *in = reinterpret_cast<const __m128i*>(_in);
    register __v4sf     OutReg;
    register __m128i    InReg = _mm_load_si128(in);
      
    OutReg = reinterpret_cast<__v4sf>(InReg); 
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));
    ++out;
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__v4sf>(InReg);
    _mm_store_si128(out, reinterpret_cast<__m128i>(OutReg));


}


  
void __SIMD_fastpack32_32(const uint32_t *  __restrict__ _in, __m128i *  __restrict__  out) {
    __SIMD_fastpackwithoutmask32_32(_in,out);
}



void __SIMD_fastunpack1_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD1;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,1));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,3));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,5));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,7));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,9));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,11));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,13));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,15));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,17));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,19));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,21));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,23));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,25));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,27));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,29));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,31));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack2_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD2;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack3_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD3;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,3));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,9));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,15));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,21));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,27));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD1)), 3-1))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,1));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,7));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,13));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,19));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,25));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,31));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 3-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,5));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,11));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,17));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,23));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,29));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack4_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD4;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack5_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD5;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,5));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,15));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,25));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD3)), 5-3))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,3));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,13));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,23));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD1)), 5-1))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,1));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,11));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,21));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,31));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 5-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,9));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,19));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,29));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 5-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,7));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,17));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,27));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack6_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD6;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 6-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 6-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 6-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 6-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack7_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD7;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,7));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,21));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD3)), 7-3))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,3));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,17));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,31));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD6)), 7-6))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,13));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,27));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 7-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,9));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,23));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD5)), 7-5))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,5));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,19));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD1)), 7-1))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,1));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,15));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,29));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 7-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,11));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,25));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack8_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD8;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack9_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD9;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,9));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,27));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 9-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,13));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,31));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 9-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,17));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD3)), 9-3))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,3));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,21));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD7)), 9-7))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,7));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,25));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 9-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,11));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,29));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD6)), 9-6))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,15));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD1)), 9-1))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,1));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,19));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD5)), 9-5))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,5));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,23));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack10_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD10;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 10-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD6)), 10-6))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 10-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 10-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 10-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD6)), 10-6))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 10-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 10-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack11_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD11;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,11));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD1)), 11-1))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,1));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,23));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 11-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,13));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD3)), 11-3))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,3));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,25));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 11-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,15));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD5)), 11-5))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,5));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,27));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD6)), 11-6))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,17));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD7)), 11-7))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,7));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,29));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 11-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,19));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD9)), 11-9))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,9));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,31));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD10)), 11-10))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,21));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack12_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD12;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 12-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 12-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 12-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 12-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 12-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 12-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 12-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 12-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack13_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD13;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,13));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD7)), 13-7))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,7));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD1)), 13-1))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,1));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,27));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 13-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,21));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 13-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,15));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD9)), 13-9))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,9));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD3)), 13-3))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,3));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,29));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD10)), 13-10))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,23));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 13-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,17));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD11)), 13-11))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,11));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD5)), 13-5))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,5));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,31));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 13-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,25));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD6)), 13-6))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,19));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack14_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD14;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD10)), 14-10))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD6)), 14-6))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 14-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 14-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 14-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 14-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD10)), 14-10))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD6)), 14-6))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 14-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 14-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 14-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 14-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack15_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD15;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,15));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD13)), 15-13))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,13));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD11)), 15-11))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,11));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD9)), 15-9))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,9));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD7)), 15-7))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,7));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD5)), 15-5))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,5));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD3)), 15-3))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,3));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD1)), 15-1))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,1));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,31));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD14)), 15-14))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,29));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 15-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,27));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD10)), 15-10))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,25));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 15-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,23));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD6)), 15-6))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,21));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 15-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,19));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 15-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,17));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack16_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD16;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack17_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD17;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,17));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 17-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,19));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 17-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,21));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD6)), 17-6))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,23));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 17-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,25));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD10)), 17-10))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,27));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 17-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,29));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD14)), 17-14))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,31));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 17-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD1)), 17-1))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,1));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD3)), 17-3))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,3));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD5)), 17-5))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,5));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD7)), 17-7))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,7));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD9)), 17-9))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,9));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD11)), 17-11))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,11));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD13)), 17-13))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,13));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD15)), 17-15))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,15));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack18_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD18;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 18-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 18-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 18-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 18-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 18-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD6)), 18-6))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD10)), 18-10))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD14)), 18-14))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 18-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 18-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 18-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 18-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 18-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD6)), 18-6))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD10)), 18-10))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD14)), 18-14))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack19_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD19;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,19));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD6)), 19-6))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,25));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 19-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,31));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD18)), 19-18))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD5)), 19-5))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,5));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD11)), 19-11))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,11));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD17)), 19-17))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,17));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 19-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,23));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD10)), 19-10))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,29));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 19-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD3)), 19-3))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,3));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD9)), 19-9))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,9));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD15)), 19-15))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,15));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 19-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,21));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 19-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,27));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD14)), 19-14))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD1)), 19-1))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,1));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD7)), 19-7))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,7));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD13)), 19-13))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,13));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack20_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD20;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 20-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 20-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 20-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 20-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 20-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 20-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 20-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 20-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 20-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 20-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 20-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 20-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 20-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 20-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 20-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 20-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack21_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD21;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,21));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD10)), 21-10))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,31));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD20)), 21-20))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD9)), 21-9))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,9));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD19)), 21-19))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,19));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 21-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,29));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD18)), 21-18))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD7)), 21-7))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,7));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD17)), 21-17))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,17));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD6)), 21-6))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,27));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 21-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD5)), 21-5))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,5));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD15)), 21-15))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,15));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 21-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,25));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD14)), 21-14))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD3)), 21-3))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,3));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD13)), 21-13))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,13));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 21-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,23));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 21-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD1)), 21-1))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,1));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD11)), 21-11))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,11));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack22_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD22;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 22-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 22-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD14)), 22-14))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 22-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 22-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD6)), 22-6))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD18)), 22-18))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 22-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD20)), 22-20))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD10)), 22-10))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 22-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 22-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD14)), 22-14))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 22-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 22-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD6)), 22-6))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD18)), 22-18))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 22-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD20)), 22-20))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD10)), 22-10))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack23_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD23;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,23));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD14)), 23-14))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD5)), 23-5))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,5));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD19)), 23-19))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,19));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD10)), 23-10))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD1)), 23-1))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,1));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD15)), 23-15))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,15));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD6)), 23-6))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,29));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD20)), 23-20))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD11)), 23-11))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,11));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 23-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,25));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 23-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD7)), 23-7))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,7));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD21)), 23-21))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,21));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 23-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD3)), 23-3))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,3));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD17)), 23-17))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,17));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 23-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,31));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD22)), 23-22))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD13)), 23-13))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,13));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 23-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,27));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD18)), 23-18))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD9)), 23-9))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,9));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack24_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD24;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 24-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 24-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 24-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 24-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 24-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 24-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 24-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 24-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 24-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 24-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 24-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 24-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 24-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 24-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 24-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 24-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack25_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD25;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,25));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD18)), 25-18))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD11)), 25-11))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,11));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 25-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,29));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD22)), 25-22))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD15)), 25-15))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,15));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 25-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD1)), 25-1))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,1));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD19)), 25-19))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,19));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 25-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD5)), 25-5))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,5));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD23)), 25-23))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,23));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 25-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD9)), 25-9))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,9));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 25-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,27));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD20)), 25-20))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD13)), 25-13))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,13));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD6)), 25-6))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,31));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD24)), 25-24))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD17)), 25-17))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,17));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD10)), 25-10))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD3)), 25-3))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,3));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD21)), 25-21))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,21));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD14)), 25-14))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD7)), 25-7))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,7));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack26_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD26;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD20)), 26-20))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD14)), 26-14))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 26-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 26-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD22)), 26-22))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 26-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD10)), 26-10))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 26-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD24)), 26-24))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD18)), 26-18))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 26-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD6)), 26-6))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD20)), 26-20))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD14)), 26-14))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 26-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 26-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD22)), 26-22))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 26-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD10)), 26-10))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 26-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD24)), 26-24))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD18)), 26-18))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 26-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD6)), 26-6))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack27_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD27;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,27));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD22)), 27-22))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD17)), 27-17))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,17));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 27-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD7)), 27-7))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,7));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 27-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,29));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD24)), 27-24))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD19)), 27-19))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,19));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD14)), 27-14))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD9)), 27-9))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,9));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 27-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,31));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD26)), 27-26))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD21)), 27-21))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,21));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 27-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD11)), 27-11))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,11));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD6)), 27-6))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD1)), 27-1))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,1));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD23)), 27-23))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,23));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD18)), 27-18))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD13)), 27-13))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,13));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 27-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD3)), 27-3))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,3));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD25)), 27-25))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,25));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD20)), 27-20))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD15)), 27-15))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,15));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD10)), 27-10))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD5)), 27-5))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,5));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack28_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD28;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD24)), 28-24))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD20)), 28-20))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 28-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 28-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 28-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 28-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD24)), 28-24))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD20)), 28-20))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 28-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 28-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 28-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 28-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD24)), 28-24))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD20)), 28-20))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 28-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 28-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 28-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 28-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD24)), 28-24))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD20)), 28-20))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 28-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 28-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 28-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 28-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack29_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD29;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,29));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD26)), 29-26))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD23)), 29-23))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,23));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD20)), 29-20))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD17)), 29-17))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,17));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD14)), 29-14))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD11)), 29-11))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,11));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 29-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD5)), 29-5))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,5));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 29-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,31));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD28)), 29-28))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD25)), 29-25))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,25));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD22)), 29-22))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD19)), 29-19))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,19));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 29-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD13)), 29-13))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,13));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD10)), 29-10))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD7)), 29-7))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,7));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 29-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD1)), 29-1))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,1));
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD27)), 29-27))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,27));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD24)), 29-24))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD21)), 29-21))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,21));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD18)), 29-18))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD15)), 29-15))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,15));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 29-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD9)), 29-9))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,9));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD6)), 29-6))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD3)), 29-3))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,3));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack30_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD30;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD28)), 30-28))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD26)), 30-26))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD24)), 30-24))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD22)), 30-22))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD20)), 30-20))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD18)), 30-18))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 30-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD14)), 30-14))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 30-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD10)), 30-10))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 30-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD6)), 30-6))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 30-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 30-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD28)), 30-28))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD26)), 30-26))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD24)), 30-24))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD22)), 30-22))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD20)), 30-20))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD18)), 30-18))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 30-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD14)), 30-14))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 30-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD10)), 30-10))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 30-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD6)), 30-6))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 30-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 30-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack31_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    register __v4sf mask =  NumMaskSIMD31;
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(_mm_and_ps(tmp, mask));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,31));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD30)), 31-30))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,30));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD29)), 31-29))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,29));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD28)), 31-28))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,28));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD27)), 31-27))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,27));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD26)), 31-26))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,26));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD25)), 31-25))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,25));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD24)), 31-24))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,24));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD23)), 31-23))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,23));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD22)), 31-22))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,22));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD21)), 31-21))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,21));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD20)), 31-20))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,20));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD19)), 31-19))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,19));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD18)), 31-18))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,18));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD17)), 31-17))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,17));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD16)), 31-16))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,16));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD15)), 31-15))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,15));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD14)), 31-14))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,14));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD13)), 31-13))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,13));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD12)), 31-12))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,12));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD11)), 31-11))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,11));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD10)), 31-10))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,10));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD9)), 31-9))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,9));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD8)), 31-8))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,8));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD7)), 31-7))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,7));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD6)), 31-6))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,6));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD5)), 31-5))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,5));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD4)), 31-4))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,4));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD3)), 31-3))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,3));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD2)), 31-2))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,2));
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    OutReg = reinterpret_cast<__m128i>(_mm_or_ps(reinterpret_cast<__v4sf>(OutReg), reinterpret_cast<__v4sf>(_mm_slli_epi32(reinterpret_cast<__m128i>(_mm_and_ps(reinterpret_cast<__v4sf>(InReg), NumMaskSIMD1)), 31-1))));
    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(_mm_srli_epi32(InReg,1));
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}




void __SIMD_fastunpack32_32(const  __m128i*  __restrict__ in, uint32_t *  __restrict__  _out) {
      
    __m128i*   out = reinterpret_cast<__m128i*>(_out);
    register __m128i    InReg = _mm_load_si128(in);
    register __m128i    OutReg;    
    register __v4sf     tmp;
    
    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    ++in;
    InReg = _mm_load_si128(in);

    _mm_store_si128(out++, OutReg);

    tmp = reinterpret_cast<__v4sf>(InReg);
    OutReg = reinterpret_cast<__m128i>(tmp);
    _mm_store_si128(out++, OutReg);


}



void SIMD_fastunpack_32(const __m128i *  __restrict__ in, uint32_t *  __restrict__  out, const uint32_t bit) {
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
void SIMD_fastpackwithoutmask_32(const uint32_t *  __restrict__ in, __m128i *  __restrict__  out, const uint32_t bit) {
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
void SIMD_fastpack_32(const uint32_t *  __restrict__ in, __m128i *  __restrict__  out, const uint32_t bit) {
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

