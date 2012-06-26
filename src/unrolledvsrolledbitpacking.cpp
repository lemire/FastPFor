/**
 * This is code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */
#include <iostream>
#include <iomanip>
#include "util.h"
#include "bitpacking.h"
typedef unsigned int uint;
#include "bitpackingunaligned.h"
#include "bitpackingaligned.h"  // temp temp

#include "rolledbitpacking.h"
#include "synthetic.h"
#include "ztimer.h"

// this exists only for looking at assembly language 
void foobar() {
    uint32_t fred[10];
    uint32_t bob[10];
    __pack<20> (fred, bob);
    cout << "now unpack";
    __unpack<20> (bob, fred);
    cout << "result is " << bob[5] << fred[5] << endl;
}

void barbaz() {
    uint32_t fred[10];
    uint32_t bob[10];
    __fastpackwithoutmask5_8 (fred, bob);
    cout << "now unpack";
    __fastunpack5_8 (bob, fred);
    cout << "result is " << bob[5] << fred[5] << endl;
}


void maskfnc(vector<uint32_t> & out, const uint32_t L) {
    if (L == 32)
        return;
    for (vector<uint32_t>::iterator i = out.begin(); i != out.end(); ++i) {
        *i = *i % (1U << L);
    }
}

void fastpack(const vector<uint32_t> & data, vector<uint32_t> & out,
        const uint32_t bit) {
    const uint32_t N = data.size();
    for (uint32_t k = 0; k < N / 32; ++k) {
        fastpack(&data[0] + 32 * k, &out[0] + bit * k, bit);
    }
}

void fastpackwithoutmask(const vector<uint32_t> & data, vector<uint32_t> & out,
        const uint32_t bit) {
    const uint32_t N = data.size();
    for (uint32_t k = 0; k < N / 32; ++k) {
        fastpackwithoutmask(&data[0] + 32 * k, &out[0] + bit * k, bit);
    }
}

void fastunpack(const vector<uint32_t> & data, vector<uint32_t> & out,
        const uint32_t bit) {
    const uint32_t N = out.size();
    for (uint32_t k = 0; k < N / 32; ++k) {
        fastunpack(&data[0] + bit * k, &out[0] + 32 * k, bit);
    }
}

template<uint32_t length>
void packwithoutmask_unaligned(const vector<uint32_t> & data,
        vector<uint32_t> & out, const uint32_t bit) {
    const uint32_t N = data.size();
    uint8_t * outbyte = reinterpret_cast<uint8_t *> (&out[0]);
    for (uint32_t k = 0; k < N / 32; ++k) {
        if (length == 8) {
            outbyte = fastunalignedpackwithoutmask_8(&data[0] + 32 * k,
                    outbyte, bit);
            outbyte = fastunalignedpackwithoutmask_8(&data[0] + 32 * k + 8,
                    outbyte, bit);
            outbyte = fastunalignedpackwithoutmask_8(&data[0] + 32 * k + 16,
                    outbyte, bit);
            outbyte = fastunalignedpackwithoutmask_8(&data[0] + 32 * k + 24,
                    outbyte, bit);

        } else if (length == 16) {
            outbyte = fastunalignedpackwithoutmask_16(&data[0] + 32 * k,
                    outbyte, bit);
            outbyte = fastunalignedpackwithoutmask_16(&data[0] + 32 * k + 16,
                    outbyte, bit);
        } else if (length == 32) {
            fastpackwithoutmask(&data[0] + 32 * k,reinterpret_cast<uint32_t*>(outbyte), bit);
            outbyte += sizeof(uint32_t) * bit;
        } else {
            throw logic_error("unsupported length");
        }
    }
}

template<uint32_t length>
void unpack_unaligned(const vector<uint32_t> & data, vector<uint32_t> & out,
        const uint32_t bit) {
    const uint32_t N = out.size();
    const uint8_t * inbyte = reinterpret_cast<const uint8_t *> (&data[0]);
    for (uint32_t k = 0; k < N / 32; ++k) {
        if (length == 8) {
            inbyte = fastunalignedunpack_8(inbyte, &out[0] + 32 * k, bit);
            inbyte = fastunalignedunpack_8(inbyte, &out[0] + 32 * k + 8, bit);
            inbyte = fastunalignedunpack_8(inbyte, &out[0] + 32 * k + 16, bit);
            inbyte = fastunalignedunpack_8(inbyte, &out[0] + 32 * k + 24, bit);
        } else if (length == 16) {
            inbyte = fastunalignedunpack_16(inbyte, &out[0] + 32 * k, bit);
            inbyte = fastunalignedunpack_16(inbyte, &out[0] + 32 * k + 16, bit);
        } else if (length == 32) {
            fastunpack(reinterpret_cast<const uint32_t *>(inbyte), &out[0] + 32 * k, bit);
            inbyte += sizeof(uint32_t) * bit;
        } else {
            throw logic_error("unsupported length");
        }
    }
}

template<uint32_t length>
void packwithoutmask_vl(const vector<uint32_t> & data, vector<uint32_t> & out,
        const uint32_t bit) {
    const uint32_t N = data.size();
    uint8_t * outbyte = reinterpret_cast<uint8_t *> (&out[0]);
    for (uint32_t k = 0; k < N / 32; ++k) {
        for (uint32_t i = 0; i < 32 / length; ++i)
            outbyte = pack_vl<false, length> (&data[0] + 32 * k + i * length,
                    outbyte, bit);
    }
}

template<uint32_t length>
void unpack_vl(const vector<uint32_t> & data, vector<uint32_t> & out,
        const uint32_t bit) {
    const uint32_t N = out.size();
    const uint8_t * inbyte = reinterpret_cast<const uint8_t *> (&data[0]);
    //for (uint32_t k = 0; k < N / length; ++k) {
    //    inbyte =  unpack_vl<length>(inbyte, &out[0] + length * k, bit);
    //}
    for (uint32_t k = 0; k < N / 32; ++k) {
        for (uint32_t i = 0; i < 32 / length; ++i)
            inbyte = unpack_vl<length> (inbyte, &out[0] + 32 * k + i * length,
                    bit);
    }
}

void pack(const vector<uint32_t> & data, vector<uint32_t> & out,
        const uint32_t bit) {
    const uint32_t N = data.size();
    for (uint32_t k = 0; k < N / 32; ++k) {
        pack<true> (&data[0] + 32 * k, &out[0] + bit * k, bit);
    }
}

void packwithoutmask(const vector<uint32_t> & data, vector<uint32_t> & out,
        const uint32_t bit) {
    const uint32_t N = data.size();
    for (uint32_t k = 0; k < N / 32; ++k) {
        pack<false> (&data[0] + 32 * k, &out[0] + bit * k, bit);
    }
}

void pack_tight(const vector<uint32_t> & data, vector<uint32_t> & out,
        const uint32_t bit) {
    const uint32_t N = data.size();
    for (uint32_t k = 0; k < N / 32; ++k) {
        pack_tight<true> (&data[0] + 32 * k, &out[0] + bit * k, bit);
    }
}

void pack_tightwithoutmask(const vector<uint32_t> & data,
        vector<uint32_t> & out, const uint32_t bit) {
    const uint32_t N = data.size();
    for (uint32_t k = 0; k < N / 32; ++k) {
        pack_tight<false> (&data[0] + 32 * k, &out[0] + bit * k, bit);
    }
}

void unpack(const vector<uint32_t> & data, vector<uint32_t> & out,
        const uint32_t bit) {
    const uint32_t N = out.size();
    for (uint32_t k = 0; k < N / 32; ++k) {
        unpack(&data[0] + bit * k, &out[0] + 32 * k, bit);
    }
}

void unpack_tight(const vector<uint32_t> & data, vector<uint32_t> & out,
        const uint32_t bit) {
    const uint32_t N = out.size();
    for (uint32_t k = 0; k < N / 32; ++k) {
        unpack_tight(&data[0] + bit * k, &out[0] + 32 * k, bit);
    }
}

template<class container32bit>
bool equalOnFirstBits(const container32bit & data,
        const container32bit & recovered, uint32_t bit) {
    if (bit == 32) {
        return data == recovered;
    }
    for (uint32_t k = 0; k < data.size(); ++k) {
        if (data[k] % (1U << bit) != recovered[k] % (1U << bit)) {
            cout << " They differ at k = " << k << " data[k]= " << data[k]
                    << " recovered[k]=" << recovered[k] << endl;
            return false;
        }
    }
    return true;
}

void simplebenchmark(uint32_t N = 1U << 24) {
    vector < uint32_t > data = generateArray32(N);
    vector < uint32_t > compressed(N, 0);
    vector < uint32_t > recovered(N, 0);
    WallClockTimer z;
    const uint32_t T = 3;
    double packtime, packtimewm, unpacktime;
    double slowpacktime, slowpacktimewm, slowunpacktime;
    double tightpacktime, tightpacktimewm, tightunpacktime;
    double unalignedpacktimewm, unalignedunpacktime;
    double unaligned16packtimewm, unaligned16unpacktime;
    double unaligned8packtimewm, unaligned8unpacktime;
    double vlpacktimewm, vlunpacktime;

    cout << "#integers per second: higher is better" << endl;
    cout
            << "#first three: manually unrolled, next three: compiler, next three: compiler (alternative)"
            << endl;
    cout
            << "#bit\tunrolledpacktime\tunrolledpacktimewm\tunrolledunpacktime\tpacktimes\tpacktimeswithmask\tunpacktimes"
            << endl;
    //uint32_t bitvalues[] = {32,31,30,29,2,24,22,20,17,16,10,8,7,6,5,4,3,2,1};
    //for (uint32_t bitindex = 0; bitindex < 17; ++bitindex) {
    //    uint32_t bit = bitvalues[bitindex];
    for (uint32_t bitindex = 0; bitindex < 32; ++bitindex) {
        uint32_t bit = 32 - bitindex;
        maskfnc(data, bit);
        packtime = 0;
        packtimewm = 0;
        unpacktime = 0;
        slowpacktime = 0;
        slowpacktimewm = 0;
        slowunpacktime = 0;
        tightpacktime = 0;
        tightpacktimewm = 0;
        tightunpacktime = 0;
        unalignedpacktimewm = 0;
        unalignedunpacktime = 0;
        unaligned16packtimewm = 0;
        unaligned16unpacktime = 0;
        unaligned8packtimewm = 0;
        unaligned8unpacktime = 0;
        vlpacktimewm = 0;
        vlunpacktime = 0;
        for (uint32_t t = 0; t < T; ++t) {
            compressed.clear();
            compressed.resize(N * bit / 32, 0);
            recovered.clear();
            recovered.resize(N, 0);

            z.reset();
            fastpack(data, compressed, bit);
            if (t > 0)
                packtime += z.split();

            z.reset();
            fastpackwithoutmask(data, compressed, bit);
            if (t > 0)
                packtimewm += z.split();

            z.reset();
            fastunpack(compressed, recovered, bit);
            if (t > 0)
                unpacktime += z.split();

            if (!equalOnFirstBits(data, recovered, bit)) {
                cout << " Bug1!" << endl;
                return;
            }
            compressed.clear();
            compressed.resize(N * bit / 32, 0);
            recovered.clear();
            recovered.resize(N, 0);

            z.reset();
            pack(data, compressed, bit);
            if (t > 0)
                slowpacktime += z.split();

            z.reset();
            packwithoutmask(data, compressed, bit);
            if (t > 0)
                slowpacktimewm += z.split();

            z.reset();
            unpack(compressed, recovered, bit);
            if (t > 0)
                slowunpacktime += z.split();

            if (!equalOnFirstBits(data, recovered, bit)) {
                cout << " Bug2!" << endl;
                return;
            }
            z.reset();
            pack_tight(data, compressed, bit);
            if (t > 0)
                tightpacktime += z.split();

            z.reset();
            pack_tightwithoutmask(data, compressed, bit);
            if (t > 0)
                tightpacktimewm += z.split();

            z.reset();
            unpack_tight(compressed, recovered, bit);
            if (t > 0)
                tightunpacktime += z.split();

            if (!equalOnFirstBits(data, recovered, bit)) {
                cout << " Bug3!" << endl;
                return;
            }

            z.reset();
            packwithoutmask_unaligned<32> (data, compressed, bit);
            if (t > 0)
                unalignedpacktimewm += z.split();

            z.reset();
            unpack_unaligned<32> (compressed, recovered, bit);
            if (t > 0)
                unalignedunpacktime += z.split();

            if (!equalOnFirstBits(data, recovered, bit)) {
                cout << " Bug4!" << endl;
                return;
            }

            z.reset();
            packwithoutmask_unaligned<16> (data, compressed, bit);
            if (t > 0)
                unaligned16packtimewm += z.split();

            z.reset();
            unpack_unaligned<16> (compressed, recovered, bit);
            if (t > 0)
                unaligned16unpacktime += z.split();

            if (!equalOnFirstBits(data, recovered, bit)) {
                cout << " Bug5!" << endl;
                return;
            }

            z.reset();
            packwithoutmask_unaligned<8> (data, compressed, bit);
            if (t > 0)
                unaligned8packtimewm += z.split();

            z.reset();
            unpack_unaligned<8> (compressed, recovered, bit);
            if (t > 0)
                unaligned8unpacktime += z.split();

            if (!equalOnFirstBits(data, recovered, bit)) {
                cout << " Bug6!" << endl;
                return;
            }

            z.reset();
            packwithoutmask_vl<8> (data, compressed, bit);
            if (t > 0)
                vlpacktimewm += z.split();

            z.reset();
            unpack_vl<8> (compressed, recovered, bit);
            if (t > 0)
                vlunpacktime += z.split();

            if (!equalOnFirstBits(data, recovered, bit)) {
                cout << " Bug7!" << endl;
                return;
            }

        }

        cout << std::setprecision(4) << bit << "\t\t" << N * (T - 1)
                / (packtime * 1000) << "\t\t" << N * (T - 1) / (packtimewm
                * 1000) << "\t\t\t" << N * (T - 1) / (unpacktime * 1000);
        cout << "\t\t\t" << N * (T - 1) / (slowpacktime * 1000) << "\t\t\t"
                << N * (T - 1) / (slowpacktimewm * 1000) << "\t\t\t" << N * (T
                - 1) / (slowunpacktime * 1000);
        cout << "\t\t\t" << N * (T - 1) / (tightpacktime * 1000) << "\t\t\t"
                << N * (T - 1) / (tightpacktimewm * 1000) << "\t\t\t" << N * (T
                - 1) / (tightunpacktime * 1000);
        cout << "\t\t\t" << N * (T - 1) / (unalignedpacktimewm * 1000)
                << "\t\t\t" << N * (T - 1) / (unalignedunpacktime * 1000);
        cout << "\t\t\t" << N * (T - 1) / (unaligned16packtimewm * 1000)
                << "\t\t\t" << N * (T - 1) / (unaligned16unpacktime * 1000);
        cout << "\t\t\t" << N * (T - 1) / (unaligned8packtimewm * 1000)
                << "\t\t\t" << N * (T - 1) / (unaligned8unpacktime * 1000);
        cout << "\t\t\t" << N * (T - 1) / (vlpacktimewm * 1000) << "\t\t\t"
                << N * (T - 1) / (vlunpacktime * 1000);

        cout << endl;

    }

}

using namespace std;
int main() {

    simplebenchmark(1U << 25);

    return 0;
}
