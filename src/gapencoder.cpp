/**
 * This is code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */

#include <tr1/memory>
#include <iomanip>
#include <time.h>
#include "codecfactory.h"
#include "maropuparser.h"
#include "util.h"
#include "ztimer.h"
#include "cpubenchmark.h"
#include "deltaio.h"

using namespace std;

void message(const char * prog) {
    cerr << " usage : " << prog << " scheme  maropubinaryfile compressedfile "
            << endl;
    cerr << "By default, is assumes that the original data is made of "
        "sorted distinct integers, to process the more general case,"
        "add the -notdgaps flag." << endl;
    cerr << "The -nodelta flag disables delta coding." << endl;
    cerr << "The -minlength ignores all arrays smaller than a threshold."
            << endl;
    cerr << " schemes include:" << endl;
    vector < string > all = CODECFactory::allNames();
    for (auto i = all.begin(); i != all.end(); ++i) {
        cerr << *i << endl;
    }

}

int main(int argc, char **argv) {
    uint32_t MAXCOUNTER = 1U << 31;
    if (argc < 4) {
        message(argv[0]);
        return -1;
    }
    int mode = DeltaIO::DeltaDGapMode;

    uint32_t MINLENGTH = 2;
    int argindex = 1;
    while (true) {
        if (strcmp(argv[argindex], "-minlength") == 0) {
            ++argindex;
            MINLENGTH = atoi(argv[argindex++]);
        } else if (strcmp(argv[argindex], "-nodelta") == 0) {
            mode = DeltaIO::NoDeltaMode;
            ++argindex;
        } else if (strcmp(argv[argindex], "-notdgaps") == 0) {
            mode = DeltaIO::DeltaMode;
            ++argindex;
        } else
            break;
    }
    IntegerCODEC & codec = *CODECFactory::getFromName(argv[argindex++]);
    cout << "# using " << codec.name() << endl;
    string filename = argv[argindex++];
    string ofilename = argv[argindex++];
    if (argindex < argc)
        MAXCOUNTER = atoi(argv[argindex++]);
    cout << "# parsing " << filename << endl;
    MaropuGapReader reader(filename);

    vector<uint32_t, cacheallocator> rawdata;
#ifdef USE_O_DIRECT
    cout<<"# you are using Linux: I am disabling IO caching with O_DIRECT"<<endl;
    cout<<"# Performance may be negatively affected."<<endl;
    int fd = ::open(ofilename.c_str(), O_DIRECT | O_WRONLY);
    fd = ::fdopen(fd, "w+b");
#else
    FILE * fd = ::fopen(ofilename.c_str(), "w+b");
#endif
    setvbuf(fd, NULL, _IOFBF, 1024 * 1024 * 32); // large buffer
    if (fd == NULL) {
        cerr << strerror(errno) << endl;
        cerr << "can't open " << ofilename << endl;
        return -1;
    }
    reader.open();
    DeltaIO delta;
    size_t counter = 0;
    size_t integers = 0;

    WallClockTimer z;
    CPUTimer cpuz;
    CPUBenchmark cpu;
    z.reset();
    cpuz.reset();
    uint64_t x = 0;
    cpu.start();
    while (reader.loadIntegers(rawdata)) {
        if (rawdata.size() < MINLENGTH)
            continue;
        if (!delta.compress(rawdata, fd, codec, mode)) {
            cerr << strerror(errno) << endl;
            break;
        }
        ++counter;
        integers += rawdata.size();
        if (counter >= MAXCOUNTER) {
            cout << "#breaking early" << endl;
            break;
        }
    }
    x += cpu.stop();
    ::fclose(fd);
    reader.close();
    cout << "# integers = " << integers << endl;
    cout << "# arrays = " << counter << endl;
    const uint64_t timespent = z.split();
    const uint64_t cputimespent = cpuz.split();
    cout << "# wall clock time = " << timespent << " mu s" << endl;
    cout << "# cpu time = " << cputimespent << " mu s" << endl;

    if (timespent > 0) {
        cout << "# million integers per second = " << integers * 1000 / (1000.0 * timespent) << " mis" << endl;
        cout << "# million integers per CPU second = " << integers * 1000
                / (1000.0 * cputimespent) << " mis" << endl;
    }
    if (integers > 0) {
        cout << "# nanoseconds per integer = " << timespent * 1000.0
                / integers << " ms" << endl;
        cout << "# cpu nanoseconds per integer = " << cputimespent * 1000.0
                / integers << " ms" << endl;

        cout << "# CPU = " << ((x / static_cast<uint64_t > (integers)) + (x
                % static_cast<uint64_t > (integers)) * 1.0 / integers)
                << " clock cycles per integer" << endl;
    }
    cout << "# wrote " << counter << " arrays to " << ofilename << endl;
    struct stat s;
    lstat(ofilename.c_str(), &s);
    cout << "# file size = " << s.st_size << endl;
    cout << "# file size = " << s.st_size / (1024.0 * 1024.0) << " MiB" << endl;
    cout << "# file size = " << s.st_size / (1000.0 * 1000.0) << " MB" << endl;
    if (integers > 0)
        cout << "# bits per integer = " << s.st_size * 8.0 / integers
                << " bits/integer" << endl;
}

