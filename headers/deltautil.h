/**
 * This is code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */

#ifndef DELTAUTIL_H_
#define DELTAUTIL_H_
#include "common.h"
#include "codecs.h"

/**
 * This class encodes and decode data using
 * an existing IntegerCODEC and delta coding.
 * It organizes the data by pages to avoid cache
 * misses.
 */
class PagedDelta {
public:
    size_t PageSize;

    PagedDelta(size_t ps = 65536 + 1) ://recommended to choose a power of 2 + 1
        PageSize(ps) {

    }

    /*
     *  Input data is modified in the encoding process.
     */
    void encodeWithPaging(IntegerCODEC & c, uint32_t *in, const size_t length,
            uint32_t * out, size_t &nvalue) {
        size_t initnvalue (nvalue);
        size_t nvaluesofar (0);
        const uint32_t * const initout = out;
        for(size_t i = 0; i < length; i += PageSize) {
            size_t thisnvalue = initnvalue - nvaluesofar;
            size_t thislength = length-i < PageSize? length - i : PageSize;
            uint32_t * header = out++;
            encode(c,in+i,thislength,out,thisnvalue);
            *header = thisnvalue;
            out += thisnvalue;
            thisnvalue += 1;
            nvaluesofar += thisnvalue;
        }
        nvalue = nvaluesofar;
        assert(nvalue + initout == out);
    }
    const uint32_t * decodeWithPaging(IntegerCODEC & c, const uint32_t *in, const size_t length,
            uint32_t *out, size_t & nvalue) {
        size_t initnvalue (nvalue);
        size_t nvaluesofar (0);
        const uint32_t * const initin (in);

        for(const uint32_t * const finalin = in + length; in < finalin; ) {
            size_t lengthtoread = *in++;
            size_t thisnvalue = initnvalue - nvaluesofar < PageSize ? initnvalue - nvaluesofar : PageSize ;
            const uint32_t * newin = decode(c, in, lengthtoread,out, thisnvalue);
            assert(newin == in + lengthtoread);
            in = newin;
            out += thisnvalue;
            nvaluesofar += thisnvalue;
        }
        assert(in  <= length + initin);
        return in;
    }

    static void encode(IntegerCODEC & c, uint32_t *in, const size_t length,
            uint32_t * out, size_t &nvalue) {
        if (length == 0)
            throw runtime_error("delta coding impossible with no value!");
        for (size_t i = length - 1; i > 0; --i) {
            in[i] -= in[i - 1];
        }
        out[0] = in[0];
        c.encodeArray(in + 1, length - 1, out + 1, nvalue);
        nvalue += 1;
    }
    static const uint32_t * decode(IntegerCODEC & c, const uint32_t *in, const size_t length,
            uint32_t *out, size_t & nvalue) {
        out[0] = in[0];
        const uint32_t * finalin = c.decodeArray(in + 1, length - 1, out + 1, nvalue);
        nvalue += 1;
        size_t i = 1;
        for (; i < nvalue - 1; i += 2) {
            out[i] += out[i - 1];
            out[i + 1] += out[i];
        }
        for (; i != nvalue; ++i) {
            out[i] += out[i - 1];
        }
        return finalin;
    }


};

#endif /* DELTAUTIL_H_ */
