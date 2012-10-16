/**
 * This is code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire
 */

#ifndef HORIZONTALBITPACKING_H_
#define HORIZONTALBITPACKING_H_


#ifndef __SSE4_1__
#pragma message "No SSSE4.1 support? try adding -msse4.1"
#endif
#include "common.h"

#include <immintrin.h>


void simdhunpack(const uint8_t * __restrict__ in,uint32_t * __restrict__ out, uint32_t bit);

#endif /* HORIZONTALBITPACKING_H_ */

