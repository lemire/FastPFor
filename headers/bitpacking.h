/**
 * This is code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */
#ifndef BITPACKING
#define BITPACKING
#include <cstdint>
void fastunpack(const uint32_t *  __restrict__ in, uint32_t *  __restrict__  out, const uint32_t bit);
void fastpack(const uint32_t *  __restrict__ in, uint32_t *  __restrict__  out, const uint32_t bit);
void fastpackwithoutmask(const uint32_t *  __restrict__ in, uint32_t *  __restrict__  out, const uint32_t bit);

#endif // BITPACKING
