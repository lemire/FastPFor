/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */

#ifndef SIMDBINARYPACKING_H_
#define SIMDBINARYPACKING_H_

#include "codecs.h"
#include "simdbitpacking.h"
#include "util.h"


/**
 *
 * Designed by D. Lemire with ideas from Leonid Boystov. This scheme is NOT patented.
 *
 * Code data in miniblocks of 128 integers.
 * To preserve alignment, we use regroup
 * 8 such miniblocks into a block of 8 * 128 = 1024
 * integers.
 *
 * Reference and documentation:
 *
 * Daniel Lemire and Leonid Boytsov, Decoding billions of integers per second through vectorization
 * http://arxiv.org/abs/1209.2137
 */
class SIMDBinaryPacking: public IntegerCODEC {
public:
    static const uint32_t CookiePadder = 123456;
    static const uint32_t MiniBlockSize = 128;
    static const uint32_t HowManyMiniBlocks = 16;
    static const uint32_t BlockSize = HowManyMiniBlocks * MiniBlockSize;

    /**
     * The way this code is written, it will automatically "pad" the
     * header according to the alignment of the out pointer. So if you
     * move the data around, you should preserve the alignment.
     */
    void encodeArray(const uint32_t *in, const size_t length, uint32_t *out,
            size_t &nvalue) {
        checkifdivisibleby(length, BlockSize);
        const uint32_t * const initout(out);
        *out++ = static_cast<uint32_t>(length);
        while(needPaddingTo128Bits(out)) *out++ = CookiePadder;
        uint32_t Bs[HowManyMiniBlocks];
        for (const uint32_t * const final = in + length; in + BlockSize
                <= final; in += BlockSize) {
            for (uint32_t i = 0; i < HowManyMiniBlocks; ++i)
                Bs[i] = maxbits(in + i * MiniBlockSize,
                        in + (i + 1) * MiniBlockSize);
            *out++ = (Bs[0] << 24) | (Bs[1] << 16) | (Bs[2] << 8)
                | Bs[3];
            *out++ = (Bs[4] << 24) | (Bs[5] << 16) | (Bs[6] << 8)
                            | Bs[7];
            *out++ = (Bs[8] << 24) | (Bs[9] << 16) | (Bs[10] << 8)
                            | Bs[11];
            *out++ = (Bs[12] << 24) | (Bs[13] << 16) | (Bs[14] << 8)
                            | Bs[15];
            for (uint32_t i = 0; i < HowManyMiniBlocks; ++i) {
                // D.L. : is the reinterpret_cast safe here?
                SIMD_fastpackwithoutmask_32(in + i * MiniBlockSize, reinterpret_cast<__m128i *>(out),
                                Bs[i]);
                out += MiniBlockSize/32 * Bs[i];
            }
        }
        nvalue = out - initout;
    }

    const uint32_t * decodeArray(const uint32_t *in, const size_t /*length*/,
            uint32_t *out, size_t & nvalue) {
        const uint32_t actuallength = *in++;
        if(needPaddingTo128Bits(out)) throw runtime_error("bad initial output align");
        while(needPaddingTo128Bits(in)) {
            if(in[0] != CookiePadder) throw logic_error("SIMDBinaryPacking alignment issue.");
            ++in;
        }
        const uint32_t * const initout(out);
        uint32_t Bs[HowManyMiniBlocks];
        for (; out < initout + actuallength; out += BlockSize) {
            for(uint32_t i = 0; i < 4 ; ++i,++in) {
                Bs[0 + 4 * i] = static_cast<uint8_t>(in[0] >> 24);
                Bs[1 + 4 * i] = static_cast<uint8_t>(in[0] >> 16);
                Bs[2 + 4 * i] = static_cast<uint8_t>(in[0] >> 8);
                Bs[3 + 4 * i] = static_cast<uint8_t>(in[0]);
            }
            for (uint32_t i = 0; i < HowManyMiniBlocks; ++i) {
                // D.L. : is the reinterpret_cast safe here?
                SIMD_fastunpack_32(reinterpret_cast<const __m128i *>(in), out + i * MiniBlockSize, Bs[i]);
                in += MiniBlockSize/32 * Bs[i];
            }
        }
        nvalue = out - initout;
        return in;
    }

    string name() const {
        return "SIMDBinaryPacking";
    }

};


class SIMDGlobalBinaryPacking: public IntegerCODEC {
public:
    static const uint32_t CookiePadder = 123456;
    static const uint32_t BlockSize = 128;

    /**
     * The way this code is written, it will automatically "pad" the
     * header according to the alignment of the out pointer. So if you
     * move the data around, you should preserve the alignment.
     */
    void encodeArray(const uint32_t *in, const size_t length, uint32_t *out,
            size_t &nvalue) {
        checkifdivisibleby(length, BlockSize);
        const uint32_t * const initout(out);
        *out++ = static_cast<uint32_t>(length);
        uint32_t Bs = maxbits(in,in + length);
        *out++ = Bs;
        while(needPaddingTo128Bits(out)) *out++ = CookiePadder;
        for (const uint32_t * const final = in + length; in + BlockSize
                <= final; in += BlockSize, out +=  4 * Bs) {
                SIMD_fastpackwithoutmask_32(in, reinterpret_cast<__m128i *>(out),
                                Bs);
        }
        nvalue = out - initout;
    }

    const uint32_t * decodeArray(const uint32_t *in, const size_t /*length*/,
            uint32_t *out, size_t & nvalue) {
        const uint32_t actuallength = *in++;
        const uint32_t Bs = *in++;
        if(needPaddingTo128Bits(out)) throw runtime_error("bad initial output align");
        while(needPaddingTo128Bits(in)) {
            if(in[0] != CookiePadder) throw logic_error("SIMDBinaryPacking alignment issue.");
            ++in;
        }
        for (uint32_t k = 0; k < actuallength / 128; ++k) {
               SIMD_fastunpack_32(reinterpret_cast<const __m128i *>(in + 4 * Bs * k), out + 128 * k, Bs);
        }
        nvalue = actuallength;
        return in + 4* Bs * actuallength / 128;
        /*const uint32_t * const initout(out);
        for (; out < initout + actuallength; out += BlockSize, in += 4 * Bs) {
                SIMD_fastunpack_32(reinterpret_cast<const __m128i *>(in), out , Bs);
        }
        nvalue = out - initout;
        return in;*/
    }

    string name() const {
        return "SIMDGlobalBinaryPacking";
    }

};

#endif /* SIMDBINARYPACKING_H_ */
