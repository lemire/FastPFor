/**
 * This is code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */


#ifndef ENTROPY_H_
#define ENTROPY_H_

#include "common.h"
#include "util.h"

using namespace std;

class EntropyRecorder {
public:
    EntropyRecorder() :
        counter(), totallength(0) {
    }
    void eat(const uint32_t * in, const size_t length) {
        if (length == 0)
            return;
        totallength += length;
        for (uint32_t k = 0; k < length; ++k, ++in) {
            map<uint32_t, double>::iterator i = counter.find(*in);
            if (i != counter.end())
                i->second += 1;
            else
                counter[*in] = 1;
        }
    }

    double computeShannon() {
        double total = 0;
        for (map<uint32_t, double>::iterator i = counter.begin(); i
                != counter.end(); ++i) {
            const double x = i->second;
            total += x / totallength * log(totallength / x) / log(2);
        }
        return total;
    }

    __attribute__ ((pure))
    double computeDataBits() {
        double total = 0;
        for (map<uint32_t, double>::const_iterator i = counter.begin(); i
                != counter.end(); ++i) {
            total += i->second * 1.0 / totallength * gccbits(i->first);
        }
        return total;
    }
    map<uint32_t, double> counter;
    size_t totallength;
};



/**
 * An entropic measure,
 * Index compression using 64-bit words by Vo Ngoc Anh and Alistair Moffat
 */
__attribute__ ((pure))
double databits(const uint32_t * in, const size_t length) {
    double sum = 0.0;
    for (size_t k = 0; k < length; ++k) {
        sum += gccbits(in[k]) * 1.0 / length;
    }
    return sum;
}

double entropy(const uint32_t * in, const size_t length) {
    if (length == 0)
        return 0;
    map<uint32_t, double> counter;
    for (uint32_t k = 0; k < length; ++k, ++in) {
        map<uint32_t, double>::iterator i = counter.find(*in);
        if (i != counter.end())
            i->second += 1;
        else
            counter[*in] = 1;
    }
    double total = 0;
    for (map<uint32_t, double>::iterator i = counter.begin(); i
            != counter.end(); ++i) {
        double x = i->second;
        total += x / length * log(length / x) / log(2);
    }
    return total;
}


#endif /* ENTROPY_H_ */
