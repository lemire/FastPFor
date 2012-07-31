/**
 * This is code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 * and Owen Kaser
 */

#ifndef SIMDBINARYPACKING_H_
#define SIMDBINARYPACKING_H_

#include "codecs.h"
#include "bitpacksimd.h"
#include "util.h"


/**
 * Code data in miniblocks of 128 integers.
 * To preserve alignment, we use regroup
 * 8 such miniblocks into a block of 8 * 128 = 1024
 * integers.
 */
class SIMDBinaryPacking: public IntegerCODEC {
public:
public:
    enum {
        MiniBlockSize = 128,
        bits32 = 8,
        HowManyMiniBlocks = 16,
        BlockSize = HowManyMiniBlocks * MiniBlockSize,
        CookiePadder = 123456
    };

    /**
     * The way this code is written, it will automatically "pad" the
     * header according to the alignment of the out pointer. So if you
     * move the data around, you should preserve the alignmment.
     */
    void encodeArray(const uint32_t *in, const size_t length, uint32_t *out,
            size_t &nvalue) {
        checkifdivisibleby(length, BlockSize);
        const uint32_t * const initout(out);
        *out++ = length;
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
            Bs[0] = static_cast<uint8_t>(in[0] >> 24);
            Bs[1] = static_cast<uint8_t>(in[0] >> 16);
            Bs[2] = static_cast<uint8_t>(in[0] >> 8);
            Bs[3] = static_cast<uint8_t>(in[0]);
            ++in;
            Bs[4] = static_cast<uint8_t>(in[0] >> 24);
            Bs[5] = static_cast<uint8_t>(in[0] >> 16);
            Bs[6] = static_cast<uint8_t>(in[0] >> 8);
            Bs[7] = static_cast<uint8_t>(in[0]);
            ++in;
            Bs[8] = static_cast<uint8_t>(in[0] >> 24);
            Bs[9] = static_cast<uint8_t>(in[0] >> 16);
            Bs[10] = static_cast<uint8_t>(in[0] >> 8);
            Bs[11] = static_cast<uint8_t>(in[0]);
            ++in;
            Bs[12] = static_cast<uint8_t>(in[0] >> 24);
            Bs[13] = static_cast<uint8_t>(in[0] >> 16);
            Bs[14] = static_cast<uint8_t>(in[0] >> 8);
            Bs[15] = static_cast<uint8_t>(in[0]);
            ++in;
            for (int i = 0; i < HowManyMiniBlocks; ++i) {
                // D.L. : is the reinterpret_cast safe here?
                cout<<"Bs s["<<i<<"]="<<Bs[i]<<endl;
                if(needPaddingTo128Bits(in)) throw new runtime_error("bad input align");
                if(needPaddingTo128Bits(out+i*MiniBlockSize)) throw runtime_error("bad output align");
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




#endif /* SIMDBINARYPACKING_H_ */
