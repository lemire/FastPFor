/**
 * This is code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */
#include <iostream>
#include <iomanip>
#include "util.h"
#include "bitpackinghelpers.h"
#include "rolledbitpacking.h"
#include "synthetic.h"
#include "ztimer.h"

// useless, for experiments
struct Block5 {
    uint32_t v1 :5;
    uint32_t v2 :5;
    uint32_t v3 :5;
    uint32_t v4 :5;
    uint32_t v5 :5;
    uint32_t v6 :5;
    uint32_t v7 :5;
    uint32_t v8 :5;
    uint32_t v9 :5;
    uint32_t v10 :5;
    uint32_t v11 :5;
    uint32_t v12 :5;
    uint32_t v13 :5;
    uint32_t v14 :5;
    uint32_t v15 :5;
    uint32_t v16 :5;
    uint32_t v17 :5;
    uint32_t v18 :5;
    uint32_t v19 :5;
    uint32_t v20 :5;
    uint32_t v21 :5;
    uint32_t v22 :5;
    uint32_t v23 :5;
    uint32_t v24 :5;
    uint32_t v25 :5;
    uint32_t v26 :5;
    uint32_t v27 :5;
    uint32_t v28 :5;
    uint32_t v29 :5;
    uint32_t v30 :5;
    uint32_t v31 :5;
    uint32_t v32 :5;
}__attribute__ ((packed));

// useless, for experiments
struct Block3 {
    uint32_t v1 :3;
    uint32_t v2 :3;
    uint32_t v3 :3;
    uint32_t v4 :3;
    uint32_t v5 :3;
    uint32_t v6 :3;
    uint32_t v7 :3;
    uint32_t v8 :3;
    uint32_t v9 :3;
    uint32_t v10 :3;
    uint32_t v11 :3;
    uint32_t v12 :3;
    uint32_t v13 :3;
    uint32_t v14 :3;
    uint32_t v15 :3;
    uint32_t v16 :3;
    uint32_t v17 :3;
    uint32_t v18 :3;
    uint32_t v19 :3;
    uint32_t v20 :3;
    uint32_t v21 :3;
    uint32_t v22 :3;
    uint32_t v23 :3;
    uint32_t v24 :3;
    uint32_t v25 :3;
    uint32_t v26 :3;
    uint32_t v27 :3;
    uint32_t v28 :3;
    uint32_t v29 :3;
    uint32_t v30 :3;
    uint32_t v31 :3;
    uint32_t v32 :3;
}__attribute__ ((__packed__));

void maskfnc(vector<uint32_t, cacheallocator> & out, const uint32_t L) {
    if (L == 32)
        return;
    for (auto i = out.begin(); i != out.end(); ++i) {
        *i = *i % (1U << L);
    }
}

void fastpack(const vector<uint32_t, cacheallocator> & data,
        vector<uint32_t, cacheallocator> & out, const uint32_t bit) {
    const uint32_t N = data.size();
    for (uint32_t k = 0; k < N / 32; ++k) {
        fastpack(&data[0] + 32 * k, &out[0] + bit * k, bit);
    }
}

// useless, for experiments
void fastbitfieldpack(const vector<uint32_t, cacheallocator> & data,
        vector<uint32_t, cacheallocator> & out) {
    const uint32_t N = data.size();
    Block5 * bout = reinterpret_cast<Block5 *> (&out[0]);
    for (uint32_t k = 0; k < N / 32; ++k) {
        Block5 & x = *(bout + k);
        x.v1 = data[32 * k];
        x.v2 = data[32 * k + 1];
        x.v3 = data[32 * k + 2];
        x.v4 = data[32 * k + 3];
        x.v5 = data[32 * k + 4];
        x.v6 = data[32 * k + 5];
        x.v7 = data[32 * k + 6];
        x.v8 = data[32 * k + 7];
        x.v9 = data[32 * k + 8];
        x.v10 = data[32 * k + 9];
        x.v11 = data[32 * k + 10];
        x.v12 = data[32 * k + 11];
        x.v13 = data[32 * k + 12];
        x.v14 = data[32 * k + 13];
        x.v15 = data[32 * k + 14];
        x.v16 = data[32 * k + 15];
        x.v17 = data[32 * k + 16];
        x.v18 = data[32 * k + 17];
        x.v19 = data[32 * k + 18];
        x.v20 = data[32 * k + 19];
        x.v21 = data[32 * k + 20];
        x.v22 = data[32 * k + 21];
        x.v23 = data[32 * k + 22];
        x.v24 = data[32 * k + 23];
        x.v25 = data[32 * k + 24];
        x.v26 = data[32 * k + 25];
        x.v27 = data[32 * k + 26];
        x.v28 = data[32 * k + 27];
        x.v29 = data[32 * k + 28];
        x.v30 = data[32 * k + 29];
        x.v31 = data[32 * k + 30];
        x.v32 = data[32 * k + 31];

    }
}

void fastpackwithoutmask(const vector<uint32_t, cacheallocator> & data,
        vector<uint32_t, cacheallocator> & out, const uint32_t bit) {
    const uint32_t N = data.size();
    for (uint32_t k = 0; k < N / 32; ++k) {
        fastpackwithoutmask(&data[0] + 32 * k, &out[0] + bit * k, bit);
    }
}

void fastunpack(const vector<uint32_t, cacheallocator> & data,
        vector<uint32_t, cacheallocator> & out, const uint32_t bit) {
    const uint32_t N = out.size();
    for (uint32_t k = 0; k < N / 32; ++k) {
        fastunpack(&data[0] + bit * k, &out[0] + 32 * k, bit);
    }
}

void pack(const vector<uint32_t, cacheallocator> & data,
        vector<uint32_t, cacheallocator> & out, const uint32_t bit) {
    const uint32_t N = data.size();
    for (uint32_t k = 0; k < N / 32; ++k) {
        pack<true> (&data[0] + 32 * k, &out[0] + bit * k, bit);
    }
}

void packwithoutmask(const vector<uint32_t, cacheallocator> & data,
        vector<uint32_t, cacheallocator> & out, const uint32_t bit) {
    const uint32_t N = data.size();
    for (uint32_t k = 0; k < N / 32; ++k) {
        pack<false> (&data[0] + 32 * k, &out[0] + bit * k, bit);
    }
}

void pack_tight(const vector<uint32_t, cacheallocator> & data,
        vector<uint32_t, cacheallocator> & out, const uint32_t bit) {
    const uint32_t N = data.size();
    for (uint32_t k = 0; k < N / 32; ++k) {
        pack_tight<true> (&data[0] + 32 * k, &out[0] + bit * k, bit);
    }
}

void pack_tightwithoutmask(const vector<uint32_t, cacheallocator> & data,
        vector<uint32_t, cacheallocator> & out, const uint32_t bit) {
    const uint32_t N = data.size();
    for (uint32_t k = 0; k < N / 32; ++k) {
        pack_tight<false> (&data[0] + 32 * k, &out[0] + bit * k, bit);
    }
}

void unpack_tight(const vector<uint32_t, cacheallocator> & data,
        vector<uint32_t, cacheallocator> & out, const uint32_t bit) {
    const uint32_t N = out.size();
    for (uint32_t k = 0; k < N / 32; ++k) {
        unpack_tight(&data[0] + bit * k, &out[0] + 32 * k, bit);
    }
}

void unpack(const vector<uint32_t, cacheallocator> & data,
        vector<uint32_t, cacheallocator> & out, const uint32_t bit) {
    const uint32_t N = out.size();
    for (uint32_t k = 0; k < N / 32; ++k) {
        unpack(&data[0] + bit * k, &out[0] + 32 * k, bit);
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
    vector<uint32_t, cacheallocator> data = generateArray32(N);
    vector<uint32_t, cacheallocator> compressed(N, 0);
    vector<uint32_t, cacheallocator> recovered(N, 0);
    WallClockTimer z;
    const uint32_t T = 5;
    double packtime, packtimewm, unpacktime;
    double tightpacktime, tightpacktimewm, tightunpacktime;

    cout << "#million of integers per second: higher is better" << endl;
    cout << "#bit, pack, pack without mask, unpack" << endl;
    for (uint32_t bitindex = 0; bitindex < 32; ++bitindex) {
        uint32_t bit = 32 - bitindex;
        maskfnc(data, bit);
        for (uint32_t repeat = 0; repeat < 3; ++repeat) {
            packtime = 0;
            packtimewm = 0;
            unpacktime = 0;
            tightpacktime = 0;
            tightpacktimewm = 0;
            tightunpacktime = 0;

            for (uint32_t t = 0; t < T; ++t) {
                compressed.clear();
                compressed.resize(N * bit / 32, 0);
                recovered.clear();
                recovered.resize(N, 0);
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
                    cout << " Bug0!" << endl;
                    return;
                }

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

            }

            cout << std::setprecision(4) << bit << "\t\t" << N * (T - 1)
                    / (packtime) << "\t\t" << N * (T - 1) / (packtimewm)
                    << "\t\t\t" << N * (T - 1) / (unpacktime) << "\t\t";

            cout << std::setprecision(4) << bit << "\t\t" << N * (T - 1)
                    / (tightpacktime) << "\t\t" << N * (T - 1)
                    / (tightpacktimewm) << "\t\t\t" << N * (T - 1)
                    / (tightunpacktime) << "\t\t";

            cout << endl;
        }

    }

}

using namespace std;
int main() {
    //cout<<sizeof(Block3)<<endl;
    //cout<<sizeof(Block5)<<endl;

    simplebenchmark(1U << 25);

    return 0;
}
