/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 */

#ifndef ZTIMER
#define ZTIMER

#include "common.h"

/**
 *  author: Preston Bannister
 */
 class WallClockTimer {
 public:
    typedef std::chrono::high_resolution_clock clock;
    std::chrono::time_point<clock> t1, t2;
     WallClockTimer() :
         t1(), t2() {
         t1 = std::chrono::high_resolution_clock::now();
         t2 = t1;
     }
     void reset() {
         t1 = std::chrono::high_resolution_clock::now();
         t2 = t1;
     }
     uint64_t elapsed() {
       std::chrono::nanoseconds delta = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);
       return delta.count();
     }
     uint64_t split() {
        t2 = std::chrono::high_resolution_clock::now();
         return elapsed();
     }
 };
#ifndef _MSC_VER

class CPUTimer {
public:
    //clock_t t1, t2;
    struct rusage t1,t2;

    CPUTimer() :
        t1(), t2() {
        getrusage(RUSAGE_SELF, &t1);
        //t1 = clock();
        t2 = t1;
    }
    void reset() {
        getrusage(RUSAGE_SELF, &t1);
        t2 = t1;
    }
    // proxy for userelapsed
    uint64_t elapsed() {
        return totalelapsed();
    }

    uint64_t totalelapsed() {
        return userelapsed() + systemelapsed();
    }
    // returns the *user* CPU time in micro seconds (mu s)
    uint64_t userelapsed() {
        return ((t2.ru_utime.tv_sec - t1.ru_utime.tv_sec) * 1000ULL * 1000ULL) + ((t2.ru_utime.tv_usec - t1.ru_utime.tv_usec)
                );
    }

    // returns the *system* CPU time in micro seconds (mu s)
    uint64_t systemelapsed() {
        return ((t2.ru_stime.tv_sec - t1.ru_stime.tv_sec) * 1000ULL * 1000ULL) + ((t2.ru_stime.tv_usec - t1.ru_stime.tv_usec)
                );
    }

    uint64_t split() {
        getrusage(RUSAGE_SELF, &t2);
        return elapsed();
    }
};
#endif
#endif

