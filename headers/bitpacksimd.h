/**
 * This is code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Leonid Boytsov
 */

#ifndef BITPACKSIMD_H
#define BITPACKSIMD_H

#include "common.h"

#include <immintrin.h>

typedef unsigned __v4su __attribute__ ((__vector_size__ (16)));

void SIMD_fastunpack_32(const __m128i *  __restrict__ in, uint32_t *  __restrict__  out, const uint32_t bit);
void SIMD_fastpackwithoutmask_32(const uint32_t *  __restrict__ in, __m128i *  __restrict__  out, const uint32_t bit);
void SIMD_fastpack_32(const uint32_t *  __restrict__ in, __m128i *  __restrict__  out, const uint32_t bit);

#endif
