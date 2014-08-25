/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */

#ifndef SIMPLE8B_RLE_H_
#define SIMPLE8B_RLE_H_

#include "common.h"
#include "codecs.h"

namespace FastPForLib {

/**
*  Simple8b
*
*  Follows Vo Ngoc Anh, Alistair Moffat: Index compression using 64-bit words.
*  Softw., Pract. Exper. 40(2): 131-147 (2010)
*
*  Implemented by D. Lemire
*
*  RLE variant:
*
*  Instead of using selector values 0 and 1 for encoding 240 and 120 integers,
*  a single selector value 15 is used to run-length encode up to 2^28 repeated
*  32-bit integers. The rest of the selector values are shifted down by one to
*  their natural position (selector values 1-14 will encode bit lengths 1-60).
*  This also frees up selector value 0 to be used as end of stream marker.
*
*  Selector value: 0 |  1  2  3  4  5  6  7  8  9 10 11 12 13 14 | 15 (RLE)
*  Integers coded: 0 | 60 30 20 15 12 10  8  7  6  5  4  3  2  1 | up to 2^28
*  Bits/integer:   0 |  1  2  3  4  5  6  7  8 10 12 15 20 30 60 | 32 bits
*
*  If larger than 32-bit integers need to be RL-encoded, the 60 bits allocated
*  for selector value 15 can be shifted more towards storage and less towards
*  quantity, i.e 2^12 48bit integers, or the other way, say 2^44 16bit integers.
*
*  Performance:
*
*  Decoding is somewhat faster (20-30%) than Simple8b due to less branching.
*  On highly repeatable datasets it may be *the* fastest decoder of all :)
*  Encoding is slower than Simple8b due to no optimization. The extra pass
*  for run-length encoding is not that expensive and not a big factor.
*
*  Since the encoding is entirely unoptimized to keep the code simple, there are
*  some other bit packing schemes that have faster (2x) encoding, while costing
*  only a minor increase in the packed size (packed bits per integer) metric.
*  If your dataset does not have a lot of 1 bit integers, these may work better:
*
*  Selector value: 0 |  1  2  3  4  5  6  7  8  9 10 11 12 13 14 | 15 (RLE)
*  Integers coded: 0 | 30 20 15 12 10  9  8  7  6  6  5  4  3  2 | up to 2^28
*  Bits/integer:   0 |  2  3  4  5  6  6  7  8  9 10 12 15 20 30 | 32 bits
*
*  Selector value: 0 |  1  2  3  4  5  6  7  8  9 10 11 12 13 14 | 15 (RLE)
*  Integers coded: 0 | 20 15 12 11 10  9  8  7  6  6  5  5  4  3 | up to 2^28
*  Bits/integer:   0 |  3  4  5  5  6  6  7  8  9 10 11 12 15 20 | 32 bits
*
**/

/**
* If MarkLength is true, than the number of symbols is written
* in the stream. Otherwise you need to specify it using the nvalue
* parameter decodeArray.
*
* Note that when MarkLength is false, some unaligned (64-bit vs. 32-bit)
* access are possible. This may fail on non-x86 platforms.
*/
	template<bool MarkLength>
	class Simple8b_RLE : public IntegerCODEC {

	public:
		void encodeArray(const uint32_t *in, const size_t length,
			uint32_t *out, size_t &nvalue);

		const uint32_t * decodeArray(const uint32_t *in, const size_t length,
			uint32_t *out, size_t &nvalue);

		std::string name() const {
			return "Simple8b_RLE";
		}

		Simple8b_RLE() { }

	private:
		static const uint32_t SIMPLE8B_LOGDESC = 4;
		static const uint32_t SIMPLE8B_BITS = (64 - SIMPLE8B_LOGDESC);
		static const uint64_t RLE_MAX_VALUE = (1ULL << 32) - 1;
		static const uint64_t RLE_MAX_COUNT = (1ULL << 28) - 1;

		static const uint32_t bitLengths[];

		static uint32_t ones(uint32_t x)
		{
			x -= ((x >> 1) & 0x55555555);
			x = (((x >> 2) & 0x33333333) + (x & 0x33333333));
			x = (((x >> 4) + x) & 0x0F0F0F0F);
			x += (x >> 8);
			x += (x >> 16);
			return (x & 0x0000003F);
		}

		static uint32_t bits(uint32_t x)
		{
			x |= (x >> 1);
			x |= (x >> 2);
			x |= (x >> 4);
			x |= (x >> 8);
			x |= (x >> 16);
			return ones(x);
		}

		// check if next integer repeats, return count if packs better, otherwize 0
		static uint32_t tryRunLength(const uint32_t* input, uint32_t pos, uint32_t count)
		{
			uint32_t start = pos;
			uint32_t end = (pos + count);
			uint32_t test = input[pos++];
			while (pos < end && test == input[pos]) { pos++; }
			uint32_t bitLen = bits(test);
			bitLen = (bitLen == 0) ? 1 : bitLen;
			uint32_t repeatCount = (pos - start);
			return (bitLen * repeatCount > SIMPLE8B_BITS) ? repeatCount : 0;
		}

		static bool tryBitPack(uint32_t bitLen, const uint32_t* input, uint32_t pos, uint32_t count)
		{
			if (bitLen >= 32)
				return true;
			uint32_t end = pos + count;
			uint32_t maxval = 1U << (bitLen % 32);
			uint32_t test = 0;
			for (uint32_t i = pos; i < end; ++i) {
				test |= input[i];
			}
			return test < maxval;
		}
	};

	template<bool MarkLength>
	const uint32_t Simple8b_RLE<MarkLength>::bitLengths[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 12, 15, 20, 30, 60, 0 };
	//const uint32_t Simple8b_RLE<MarkLength>::bitLengths[] = { 0, 2, 3, 4, 5, 6, 6, 7, 8, 9, 10, 12, 15, 20, 30, 0 };
	//const uint32_t Simple8b_RLE<MarkLength>::bitLengths[] = { 0, 3, 4, 5, 5, 6, 6, 7, 8, 9, 10, 11, 12, 15, 20, 0 };
	//const uint32_t Simple8b_RLE<MarkLength>::bitLengths[] = { 0, 4, 4, 5, 5, 6, 6, 7, 8, 9, 10, 11, 12, 14, 15, 0 };

	template<bool MarkLength>
	void Simple8b_RLE<MarkLength>::encodeArray(const uint32_t *input,
		const size_t length, uint32_t *out, size_t &nvalue) {

		const uint32_t * const initout(out);
		if (MarkLength) {
			*out++ = static_cast<uint32_t>(length);
		}
		// this may lead to unaligned access. Performance may be affected.
		// not much of an effect in practice on recent Intel processors.
		uint64_t * out64 = reinterpret_cast<uint64_t*> (out);

		uint32_t pos = 0;
		uint32_t count = static_cast<uint32_t>(length);

		uint32_t remainingValuesCount = count;
		while (remainingValuesCount > 0) {
			uint64_t val = 0;

			// try if run-length encoding packs better than bit packing
			uint64_t numberOfRepeats = tryRunLength(input, pos, remainingValuesCount);
			if (numberOfRepeats > 0) {
				numberOfRepeats &= RLE_MAX_COUNT;
				val = (15ULL << SIMPLE8B_BITS) | (numberOfRepeats << 32) | input[pos];
				pos += static_cast<uint32_t>(numberOfRepeats);
				remainingValuesCount -= static_cast<uint32_t>(numberOfRepeats);
			}
			// otherwise try all the bit packing possibilities
			else {
				uint32_t i;
				for (i = 1; i < 15; ++i) {
					uint32_t bitLen = bitLengths[i];
					uint32_t codeNum = bitLengths[15 - i];
					uint32_t numberOfValuesToPack = (remainingValuesCount < codeNum) ? remainingValuesCount : codeNum;

					if (tryBitPack(bitLen, input, pos, numberOfValuesToPack)) {
						val = i;
						for (uint32_t j = 0; j < numberOfValuesToPack; j++) {
							val = (val << bitLen) | input[pos + j];
						}
						val <<= SIMPLE8B_BITS - bitLen * numberOfValuesToPack;
						pos += numberOfValuesToPack;
						remainingValuesCount -= numberOfValuesToPack;
						break;
					}
				}
				// if no bit packing possible, encode just one value
				if (i >= 15) {
					val = (15ULL << SIMPLE8B_BITS) | (1ULL << 32) | input[pos];
					pos += 1;
					remainingValuesCount -= 1;
				}
			}
			*out64++ = val;
		}

		assert(pos == length);
		nvalue = reinterpret_cast<uint32_t*> (out64)-initout;
	}

	template<bool MarkLength>
	const uint32_t * Simple8b_RLE<MarkLength>::decodeArray(const uint32_t *in,
		const size_t length, uint32_t *out, size_t &nvalue) {

		uint32_t markednvalue;
		if (MarkLength) {
			markednvalue = *in++;
			if (markednvalue > nvalue)
				throw NotEnoughStorage(markednvalue);
		}
		const size_t actualvalue = MarkLength ? markednvalue : nvalue;
		// this may lead to unaligned access. Performance may be affected.
		// not much of an effect in practice on recent Intel processors.
		const uint64_t * in64 = reinterpret_cast<const uint64_t *> (in);
#ifndef NDEBUG
		const uint32_t * const endin(in + length);
		const uint64_t * finalin64 = reinterpret_cast<const uint64_t *> (endin);
#endif
		if (nvalue < actualvalue)
			std::cerr << " possible overrun" << std::endl;
		nvalue = actualvalue;
		const uint32_t * const end = out + nvalue;
		const uint32_t * const initout(out);

		uint32_t pos = 0;
		uint32_t count = static_cast<uint32_t>(length) / 2;

		while (pos < count && end > out) {
			uint64_t val = in64[pos++];
			uint32_t code = static_cast<uint32_t>(val >> SIMPLE8B_BITS);

			if (code == 0) {
				break; // end of stream
			}
			else if (code == 15) {
				uint32_t repeatValue = static_cast<uint32_t>(val & RLE_MAX_VALUE);
				uint32_t repeatCount = static_cast<uint32_t>((val >> 32) & RLE_MAX_COUNT);
				for (uint32_t k = 0; k < repeatCount; ++k) {
					*out++ = repeatValue;
				}
			}
			else {
				uint32_t bitLen = bitLengths[code];
				uint32_t intNum = bitLengths[15 - code];
				uint64_t mask = (1ULL << bitLen) - 1;

				uint32_t k = SIMPLE8B_BITS;
				uint32_t last = SIMPLE8B_BITS - bitLen * (intNum - 3);
				while (k > last) {
					*out++ = static_cast<uint32_t>((val >> (k -= bitLen)) & mask);
					*out++ = static_cast<uint32_t>((val >> (k -= bitLen)) & mask);
					*out++ = static_cast<uint32_t>((val >> (k -= bitLen)) & mask);
					*out++ = static_cast<uint32_t>((val >> (k -= bitLen)) & mask);
				}
				last = SIMPLE8B_BITS - bitLen * intNum;
				while (k > last) {
					*out++ = static_cast<uint32_t>((val >> (k -= bitLen)) & mask);
				}
			}
		}

		assert(in64 + pos <= finalin64);
		in = reinterpret_cast<const uint32_t *> (in64 + pos);
		assert(in <= endin);
		nvalue = MarkLength ? actualvalue : out - initout;
		return in;
	}

} // namespace FastPFor

#endif /* SIMPLE8B_RLE_H_ */
