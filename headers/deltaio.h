/**
 * This is code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */

#ifndef DELTAIO_H_
#define DELTAIO_H_

#include "common.h"
#include "codecs.h"
#include "memutil.h"
using namespace std;

/**
 * Just a convenience class.
 */
class DeltaIO {
public:
    DeltaIO() :
        buffer() {
    }
    vector<uint32_t, cacheallocator> buffer;

    enum {
        fudgefactor = 1024
    };

    struct header {
        uint32_t number;
        uint32_t compressedsize;
        uint32_t data0;
    };
    struct simpleheader {
        uint32_t number;
        uint32_t compressedsize;
    };

    enum {
        DeltaMode, DeltaDGapMode, NoDeltaMode
    };
    /**
     * Return true if successful
     * In delta mode (DeltaMode or DeltaDGapMode), the
     * provided data can be modified.
     *
     * mode should be one of DeltaMode,DeltaDGapMode,NoDeltaMode
     */
    template<class container>
    bool compress(container & data, FILE * fd, IntegerCODEC &c, int mode) {
        switch (mode) {
        case DeltaMode:
            return compressDGapDeltas<false> (data, fd, c);
        case DeltaDGapMode:
            return compressDGapDeltas<true> (data, fd, c);
        case NoDeltaMode:
            return compress(data, fd, c);
        default:
            throw runtime_error("unsupported mode");
        }
    }

    /**
     * Return true if successful
     *
     * mode should be one of DeltaMode,DeltaDGapMode,NoDeltaMode
     */
    template<class container>
    bool uncompress(container & data, FILE * fd, IntegerCODEC &c, int mode) {
        switch (mode) {
        case DeltaMode:
            return uncompressDGapDeltas<false> (data, fd, c);
        case DeltaDGapMode:
            return uncompressDGapDeltas<true> (data, fd, c);
        case NoDeltaMode:
            return uncompress(data, fd, c);
        default:
            throw runtime_error("unsupported mode");
        }
    }

private:

    /**
     * Return true if successful
     *
     */
    template<bool valuesaredgap, class container>
    bool compressDGapDeltas(container & data, FILE * fd, IntegerCODEC &c) {
        header h;
        h.number = data.size();
        const uint8_t mbits = valuesaredgap ? 32 : maxbits(data.begin(),
                data.end());
        if (!valuesaredgap) {
            size_t resultmbits = fwrite(&mbits, sizeof(mbits), 1, fd);
            if (resultmbits != 1) {
                return false;
            }
        }
        const uint32_t mask = (mbits < 32) ? ((1UL << mbits) - 1) : 0xFFFFFFFF;
        if (data.empty()) {
            h.compressedsize = 0;
            h.data0 = 0;
            size_t result = fwrite(&h, sizeof(h), 1, fd);
            if (result != 1)
                return false;
            return true;
        }
        h.data0 = data[0];
        for (size_t i = data.size() - 1; i > 0; --i) {
            data[i] = valuesaredgap ? (data[i] - data[i - 1] - 1) : (data[i]
                    - data[i - 1]) & mask;
        }
        if (buffer.size() < data.size() * 2 + fudgefactor)
            buffer.resize(data.size() * 2 + fudgefactor);
        size_t finalsize = buffer.size();
        uint32_t *aligned_buffer = &buffer[0];
        assert(!needPaddingTo64bytes(aligned_buffer));
        c.encodeArray(&data[1], data.size() - 1, aligned_buffer, finalsize);
        h.compressedsize = finalsize;
        size_t result = fwrite(&h, sizeof(h), 1, fd);

        if (result != 1) {
            return false;
        }
        result = fwrite(aligned_buffer, sizeof(buffer[0]),
                finalsize, fd);
        if (result != finalsize) {
            return false;
        }
        return true;
    }
    /**
     * This compresses the integers (without delta coding).
     *
     * Return true if successful
     */
    template<class container>
    bool compress(const container & data, FILE * fd, IntegerCODEC &c) {
        simpleheader h;
        h.number = data.size();
        if (static_cast<size_t> (h.number) != data.size()) {
            cerr << "Array too big! we only support up to (1<<32)-1 elements."
                    << endl;
            return false;
        }
        if (data.empty()) {
            h.compressedsize = 0;
            size_t result = fwrite(&h, sizeof(h), 1, fd);
            if (result != 1)
                return false;
            return true;
        }
        if (buffer.size() < data.size() * 2 + fudgefactor)
            buffer.resize(data.size() * 2 + fudgefactor);
        size_t finalsize = buffer.size();
        uint32_t *aligned_buffer = &buffer[0];
        assert(!needPaddingTo64bytes(aligned_buffer));
        c.encodeArray(&data[0], data.size(), aligned_buffer, finalsize);
        h.compressedsize = finalsize;
        size_t result = fwrite(&h, sizeof(h), 1, fd);
        if (result != 1) {
            return false;
        }
        result = fwrite(aligned_buffer, sizeof(buffer[0]), finalsize, fd);
        if (result != finalsize) {
            return false;
        }
        return true;
    }

    /**
     * Return true if successful
     */
    template<bool valuesaredgap, class container>
    bool uncompressDGapDeltas(container & data, FILE * fd, IntegerCODEC &c) {
        uint8_t mbits = 32;
        if (!valuesaredgap) {
            size_t resultmbits = fread(&mbits, sizeof(mbits), 1, fd);
            if (resultmbits != 1) {
                return false;
            }
        }
        const uint32_t mask = (mbits < 32) ? ((1U << mbits) - 1) : 0xFFFFFFFF;
        header h;
        size_t result = fread(&h, sizeof(h), 1, fd);
        if (result != 1) {
            return false;
        }
        data.reserve(h.number + fudgefactor);
        data.resize(h.number);
        if (data.empty())
            return true;
        data[0] = h.data0;
        if (buffer.size() < h.compressedsize + fudgefactor)
            buffer.resize(h.compressedsize + fudgefactor);
        uint32_t *aligned_buffer = &buffer[0];
        assert(!needPaddingTo64bytes(aligned_buffer));
        result = fread(aligned_buffer, sizeof(buffer[0]),
                h.compressedsize, fd);
        if (result != h.compressedsize) {
            cerr << "IO status: " << strerror(errno) << endl;
            cerr << "Error reading from file " << endl;
            throw runtime_error("bad read");
        }
        size_t nvalue = data.size() - 1;
        c.decodeArray(aligned_buffer, h.compressedsize, &data[1], nvalue);
        for (size_t i = 1; i < data.size(); ++i) {
            data[i] = valuesaredgap ? data[i] + data[i - 1] + 1 : (data[i]
                    + data[i - 1]) & mask;
        }
        return true;
    }

    /**
     * This uncompresses integers (without delta coding)
     * Return true if successful
     */
    template<class container>
    bool uncompress(container & data, FILE * fd, IntegerCODEC &c) {
        simpleheader h;
        size_t result = fread(&h, sizeof(h), 1, fd);
        if (result != 1) {
            return false;
        }
        data.reserve(h.number + fudgefactor);
        data.resize(h.number);
        if (data.empty())
            return true;
        data.reserve(h.number + fudgefactor);
        data.resize(h.number);
        if (buffer.size() < h.compressedsize + fudgefactor)
            buffer.resize(h.compressedsize + fudgefactor);
        uint32_t *aligned_buffer = &buffer[0];
        assert(!needPaddingTo64bytes(aligned_buffer));
        result = fread(aligned_buffer, sizeof(buffer[0]), h.compressedsize, fd);
        if (result != h.compressedsize) {
            return false;
        }
        size_t nvalue = data.size();
        c.decodeArray(aligned_buffer, h.compressedsize, &data[0], nvalue);
        return true;
    }

};
#endif /* DELTAIO_H_ */
