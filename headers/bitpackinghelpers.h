/*
 * bitpackinghelpers.h
 *
 *  Created on: Jul 11, 2012
 *      Author: lemire
 */

#ifndef BITPACKINGHELPERS_H_
#define BITPACKINGHELPERS_H_

#include "bitpacking.h"

namespace FastPForLib {

inline void fastunpack(const uint32_t *__restrict__ in,
                       uint32_t *__restrict__ out, const uint32_t bit) {
  // Could have used function pointers instead of switch.
  // Switch calls do offer the compiler more opportunities for optimization in
  // theory. In this case, it makes no difference with a good compiler.
  switch (bit) {
  case 0:
    __fastunpack0(in, out);
    break;
  case 1:
    __fastunpack1(in, out);
    break;
  case 2:
    __fastunpack2(in, out);
    break;
  case 3:
    __fastunpack3(in, out);
    break;
  case 4:
    __fastunpack4(in, out);
    break;
  case 5:
    __fastunpack5(in, out);
    break;
  case 6:
    __fastunpack6(in, out);
    break;
  case 7:
    __fastunpack7(in, out);
    break;
  case 8:
    __fastunpack8(in, out);
    break;
  case 9:
    __fastunpack9(in, out);
    break;
  case 10:
    __fastunpack10(in, out);
    break;
  case 11:
    __fastunpack11(in, out);
    break;
  case 12:
    __fastunpack12(in, out);
    break;
  case 13:
    __fastunpack13(in, out);
    break;
  case 14:
    __fastunpack14(in, out);
    break;
  case 15:
    __fastunpack15(in, out);
    break;
  case 16:
    __fastunpack16(in, out);
    break;
  case 17:
    __fastunpack17(in, out);
    break;
  case 18:
    __fastunpack18(in, out);
    break;
  case 19:
    __fastunpack19(in, out);
    break;
  case 20:
    __fastunpack20(in, out);
    break;
  case 21:
    __fastunpack21(in, out);
    break;
  case 22:
    __fastunpack22(in, out);
    break;
  case 23:
    __fastunpack23(in, out);
    break;
  case 24:
    __fastunpack24(in, out);
    break;
  case 25:
    __fastunpack25(in, out);
    break;
  case 26:
    __fastunpack26(in, out);
    break;
  case 27:
    __fastunpack27(in, out);
    break;
  case 28:
    __fastunpack28(in, out);
    break;
  case 29:
    __fastunpack29(in, out);
    break;
  case 30:
    __fastunpack30(in, out);
    break;
  case 31:
    __fastunpack31(in, out);
    break;
  case 32:
    __fastunpack32(in, out);
    break;
  default:
    break;
  }
}

inline void fastpack(const uint32_t *__restrict__ in,
                     uint32_t *__restrict__ out, const uint32_t bit) {
  // Could have used function pointers instead of switch.
  // Switch calls do offer the compiler more opportunities for optimization in
  // theory. In this case, it makes no difference with a good compiler.
  switch (bit) {
  case 0:
    __fastpack0(in, out);
    break;
  case 1:
    __fastpack1(in, out);
    break;
  case 2:
    __fastpack2(in, out);
    break;
  case 3:
    __fastpack3(in, out);
    break;
  case 4:
    __fastpack4(in, out);
    break;
  case 5:
    __fastpack5(in, out);
    break;
  case 6:
    __fastpack6(in, out);
    break;
  case 7:
    __fastpack7(in, out);
    break;
  case 8:
    __fastpack8(in, out);
    break;
  case 9:
    __fastpack9(in, out);
    break;
  case 10:
    __fastpack10(in, out);
    break;
  case 11:
    __fastpack11(in, out);
    break;
  case 12:
    __fastpack12(in, out);
    break;
  case 13:
    __fastpack13(in, out);
    break;
  case 14:
    __fastpack14(in, out);
    break;
  case 15:
    __fastpack15(in, out);
    break;
  case 16:
    __fastpack16(in, out);
    break;
  case 17:
    __fastpack17(in, out);
    break;
  case 18:
    __fastpack18(in, out);
    break;
  case 19:
    __fastpack19(in, out);
    break;
  case 20:
    __fastpack20(in, out);
    break;
  case 21:
    __fastpack21(in, out);
    break;
  case 22:
    __fastpack22(in, out);
    break;
  case 23:
    __fastpack23(in, out);
    break;
  case 24:
    __fastpack24(in, out);
    break;
  case 25:
    __fastpack25(in, out);
    break;
  case 26:
    __fastpack26(in, out);
    break;
  case 27:
    __fastpack27(in, out);
    break;
  case 28:
    __fastpack28(in, out);
    break;
  case 29:
    __fastpack29(in, out);
    break;
  case 30:
    __fastpack30(in, out);
    break;
  case 31:
    __fastpack31(in, out);
    break;
  case 32:
    __fastpack32(in, out);
    break;
  default:
    break;
  }
}

/*assumes that integers fit in the prescribed number of bits*/
inline void fastpackwithoutmask(const uint32_t *__restrict__ in,
                                uint32_t *__restrict__ out,
                                const uint32_t bit) {
  // Could have used function pointers instead of switch.
  // Switch calls do offer the compiler more opportunities for optimization in
  // theory. In this case, it makes no difference with a good compiler.
  switch (bit) {
  case 0:
    __fastpackwithoutmask0(in, out);
    break;
  case 1:
    __fastpackwithoutmask1(in, out);
    break;
  case 2:
    __fastpackwithoutmask2(in, out);
    break;
  case 3:
    __fastpackwithoutmask3(in, out);
    break;
  case 4:
    __fastpackwithoutmask4(in, out);
    break;
  case 5:
    __fastpackwithoutmask5(in, out);
    break;
  case 6:
    __fastpackwithoutmask6(in, out);
    break;
  case 7:
    __fastpackwithoutmask7(in, out);
    break;
  case 8:
    __fastpackwithoutmask8(in, out);
    break;
  case 9:
    __fastpackwithoutmask9(in, out);
    break;
  case 10:
    __fastpackwithoutmask10(in, out);
    break;
  case 11:
    __fastpackwithoutmask11(in, out);
    break;
  case 12:
    __fastpackwithoutmask12(in, out);
    break;
  case 13:
    __fastpackwithoutmask13(in, out);
    break;
  case 14:
    __fastpackwithoutmask14(in, out);
    break;
  case 15:
    __fastpackwithoutmask15(in, out);
    break;
  case 16:
    __fastpackwithoutmask16(in, out);
    break;
  case 17:
    __fastpackwithoutmask17(in, out);
    break;
  case 18:
    __fastpackwithoutmask18(in, out);
    break;
  case 19:
    __fastpackwithoutmask19(in, out);
    break;
  case 20:
    __fastpackwithoutmask20(in, out);
    break;
  case 21:
    __fastpackwithoutmask21(in, out);
    break;
  case 22:
    __fastpackwithoutmask22(in, out);
    break;
  case 23:
    __fastpackwithoutmask23(in, out);
    break;
  case 24:
    __fastpackwithoutmask24(in, out);
    break;
  case 25:
    __fastpackwithoutmask25(in, out);
    break;
  case 26:
    __fastpackwithoutmask26(in, out);
    break;
  case 27:
    __fastpackwithoutmask27(in, out);
    break;
  case 28:
    __fastpackwithoutmask28(in, out);
    break;
  case 29:
    __fastpackwithoutmask29(in, out);
    break;
  case 30:
    __fastpackwithoutmask30(in, out);
    break;
  case 31:
    __fastpackwithoutmask31(in, out);
    break;
  case 32:
    __fastpackwithoutmask32(in, out);
    break;
  default:
    break;
  }
}

template <uint32_t BlockSize>
uint32_t *packblockup(const uint32_t *source, uint32_t *out,
                      const uint32_t bit) {
  for (uint32_t j = 0; j != BlockSize; j += 32) {
    fastpack(source + j, out, bit);
    out += bit;
  }
  return out;
}

template <uint32_t BlockSize>
const uint32_t *unpackblock(const uint32_t *source, uint32_t *out,
                            const uint32_t bit) {
  for (uint32_t j = 0; j != BlockSize; j += 32) {
    fastunpack(source, out + j, bit);
    source += bit;
  }
  return source;
}

} // namespace FastPFor

#endif /* BITPACKINGHELPERS_H_ */
