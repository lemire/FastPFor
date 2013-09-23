/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 */
/**
 *
 * Implementation of varint-G8IU taken from
 * Stepanov et al., SIMD-Based Decoding of Posting Lists, CIKM 2011
 *
 * Update: D. Lemire believes that this scheme was patented by Rose, Stepanov et al. (patent 20120221539).
 * We wrote this code before the patent was published (August 2012).
 *
 * By Maxime Caron
 * From
 * https://github.com/maximecaron/SIMD-Based-Posting-lists
 * with minor modifications by D. Lemire.
 */
#ifndef __SSSE3__
#pragma message "Disabling varintg8iu due to lack of SSSE3 support, try adding -mssse3 or the equivalent on your compiler"
#else
#ifndef VARINTG8IU_H__
#define VARINTG8IU_H__
#include <emmintrin.h>
#include "codecs.h"
#ifdef __GNUC__
#define PREDICT_FALSE(x) (__builtin_expect(x, 0))
#define PREDICT_TRUE(x) (__builtin_expect(!!(x), 1))
#else
#define PREDICT_FALSE(x) x
#define PREDICT_TRUE(x) x
#endif
//typedef char v16qi __attribute__ ((vector_size (16)));

class VarIntG8IU: public IntegerCODEC {

public:

    // For all possible values of the
    // descriptor we build a table of any shuffle sequence
    // that might be needed at decode time.
    VarIntG8IU() {
        for (int desc = 0; desc <= 255; desc++) {
            int bitmask = 0x00000001;
            int bitindex = 0;
            // count number of 0 in the char
            int complete = 0;
            int ithSize[8];
            int lastpos = -1;
            while (bitindex < 8) {
                if ((desc & bitmask) == 0) {
                    ithSize[complete] = bitindex - lastpos;
                    lastpos = bitindex;
                    complete++;
                }
                bitindex++;
                bitmask = bitmask << 1;
            }
            maskOutputSize[desc] = complete;

            int j = 0;
            int k = 0;
            for (int i = 0; i < complete; i++) {
                for (int n = 0; n < 4; n++) {
                    if (n < ithSize[i]) {
                        mask[desc][k] = static_cast<unsigned char>(j);
                        j = j + 1;
                    } else {
                        mask[desc][k] = -1;
                    }
                    k = k + 1;
                }
            }

        }

    }

    void encodeArray(const uint32_t *in, const size_t length,
            uint32_t *out, size_t &nvalue) {
        const uint32_t * src = in;
        size_t srclength = length * 4;

        unsigned char* dst = reinterpret_cast<unsigned char*> (out);
        nvalue = nvalue * 4;

        size_t compressed_size = 0;
        while (srclength > 0 && nvalue >= 9) {
            compressed_size += encodeBlock(src, srclength, dst, nvalue);
        }
        //Ouput might not be a multiple of 4 so we make it so
        nvalue = ((compressed_size + 3 )/ 4);
    }

    const uint32_t * decodeArray(const uint32_t *in,
            const size_t length, uint32_t *out, size_t &nvalue) {
        size_t srclength = length * 4;
        const unsigned char* src = reinterpret_cast<const unsigned char*> (in);

        uint32_t * dst = out;
        nvalue = nvalue * 4;

        uint32_t uncompressSize = 0;
        while (srclength >= 9) {
            uncompressSize += decodeBlock(src, srclength, dst, nvalue);
        }
        nvalue = uncompressSize;
        return reinterpret_cast<uint32_t *> ((reinterpret_cast<uintptr_t> (src)
                + 3) & ~3);
    }

    virtual std::string name() const {
        return string("VarIntG8IU");
    }






    int encodeBlock(const uint32_t*& src, size_t& srclength,
            unsigned char*& dest, size_t& dstlength) {
        unsigned char desc = 0xFF;
        unsigned char bitmask = 0x01;
        uint32_t buffer[8];
        int ithSize[8];
        int length = 0;
        int numInt = 0;

        while (srclength > 0) {
            //size_t n;
            const uint32_t* temp = src;
            int byteNeeded = getNumByteNeeded(*temp);

            if (PREDICT_FALSE(length + byteNeeded > 8)) {
                break;
            }

            //flip the correct bit in desc
            bitmask = static_cast<unsigned char>(bitmask << (byteNeeded - 1));
            desc = desc ^ bitmask;
            bitmask = static_cast<unsigned char>(bitmask << 1);

            ithSize[numInt] = byteNeeded;
            length += byteNeeded;
            buffer[numInt] = *temp;
            src = src + 1;
            srclength -= 4;
            numInt++;
        }


        dest[0] = desc;
        int written = 1;
        for (int i = 0; i < numInt; i++) {
            int size = ithSize[i];
            uint32_t value = buffer[i];
            for (int j = 0; j < size; j++) {
                dest[written] = static_cast<unsigned char>(value >> (j * 8));
                written++;
            }
        }
        dest += 9;
        dstlength -= 9;
        return 9;
    }

    /**
     * src : a compressed buffer
     * dst : a buffer for uncompressed data of size uncompressed_length(src)
     */
    int decodeBlock(const unsigned char*& src, size_t& srclength,
            uint32_t*& dest, size_t& dstlength) const {

        const unsigned char* pdesc = src;
        unsigned char desc = *pdesc;
        src += 1;
        srclength -= 1;

        const unsigned char* peek = src;
        __m128i data;//v16qi data;
        if (PREDICT_TRUE(srclength >= 16)) {
            // read 16 byte of data only if we need
            // to avoid cache miss
            data = _mm_lddqu_si128 (reinterpret_cast<__m128i const* > (peek)) ;//__builtin_ia32_lddqu(reinterpret_cast<const char*> (peek));
        } else {
            static char buff[16];
            memcpy(buff, peek, 8);
            data = _mm_lddqu_si128 (reinterpret_cast<__m128i const*> (buff)) ;//__builtin_ia32_lddqu(buff);
        }

        // load de required mask
        __m128i shf = _mm_lddqu_si128 (reinterpret_cast<__m128i const*> (mask[desc])) ;//__builtin_ia32_lddqu(mask[desc]);
        __m128i result =  _mm_shuffle_epi8 (data, shf);//__builtin_ia32_pshufb128(data, shf);
        char* dst = reinterpret_cast<char*> (dest);
        _mm_storeu_si128(reinterpret_cast<__m128i*> (dst), result);//__builtin_ia32_storedqu(dst, result);
        int readSize = maskOutputSize[desc];

        if (PREDICT_TRUE( readSize >= 4)) {
        	__m128i shf2 = _mm_lddqu_si128 (reinterpret_cast<__m128i const*> (mask[desc] + 16));//__builtin_ia32_lddqu(mask[desc] + 16);
        	__m128i result2 = _mm_shuffle_epi8 (data, shf2);//__builtin_ia32_pshufb128(data, shf2);
            _mm_storeu_si128(reinterpret_cast<__m128i *> (dst + (16)), result2);//__builtin_ia32_storedqu(dst + (16), result2);
        }
        // pop 8 input char
        src += 8;
        srclength -= 8;
        dest += readSize;
        dstlength -= readSize * 4;
        return readSize;
    }




private:

    int maskOutputSize[256];
    char mask[256][32];

    int getNumByteNeeded(const uint32_t value) {
        if (value > 0x000000FF) {
            if (value > 0x0000FFFF) {
                if (value > 0x00FFFFFF) {
                    return 4;
                } else {
                    return 3;
                }
            } else {
                return 2;
            }
        } else {
            return 1;
        }
    }

};
#endif  // VARINTG8IU_H__
#endif //__SSE3__
