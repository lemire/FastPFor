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
    cerr << " usage : "<<prog<<" scheme compressedfile maropubinaryfile "
    << endl;
    cerr << "By default, is assumes that the original data is made of "
        "sorted distinct integers, to process the more general case,"
        "add the -notdgaps flag." << endl;

    cerr << "The -nodelta flag disables delta coding." << endl;
    cerr << " schemes include:" << endl;
    vector < string > all = CODECFactory::allNames();
    for (auto i = all.begin(); i != all.end(); ++i) {
        cerr << *i << endl;
    }

}
int main(int argc, char **argv) {
    CODECFactory fact;
    if (argc < 3) {
        message(argv[0]);
        return -1;
    }
    int mode = DeltaIO::DeltaDGapMode;
    int argindex = 1;
    if (strcmp(argv[argindex], "-nodelta") == 0) {
        mode = DeltaIO::NoDeltaMode;
        ++argindex;
    } else if (strcmp(argv[argindex], "-notdgaps") == 0) {
        mode = DeltaIO::DeltaMode;
        ++argindex;
    }
    IntegerCODEC & codec = *fact.getFromName(argv[argindex++]);
    cout << "# using " << codec.name() << endl;
    string filename = argv[argindex++];
    string ofilename;
    const bool writeit = argindex < argc;
    if (argindex < argc) {
        ofilename = argv[argindex++];
    }
    cout << "# parsing " << filename << endl;
    FILE * fdin = ::fopen(filename.c_str(), "r");
    if (fdin == NULL) {
        cerr << "IO status: " << "IO status: " << strerror(errno) << endl;
        cerr << "can't open " << filename << endl;
        return -1;
    }
    setvbuf(fdin, NULL, _IOFBF, 1024 * 1024 * 32); // large buffer

    vector < uint32_t > rawdata;
    FILE * fd = writeit ? ::fopen(ofilename.c_str(), "w+b") : NULL;
    if ((writeit) and (fd == NULL)) {
        cerr << "IO status: " << "IO status: " << strerror(errno) << endl;
        ::fclose(fdin);
        cerr << "can't open " << ofilename << endl;
        return -1;
    }
    DeltaIO delta;
    size_t counter = 0;
    size_t integers = 0;

    WallClockTimer z;
    CPUTimer cpuz;
    CPUBenchmark cpu;
    z.reset();
    cpuz.reset();
    uint64_t clockcycles = 0;

    if (fseek(fdin, 0, SEEK_END)) {
        cerr << "couldn't seek the end of file" << endl;
        cerr << "IO status: " << "IO status: " << strerror(errno) << endl;
        if (fd != NULL)
            ::fclose(fd);
        ::fclose(fdin);
        return -1;
    }
    long lSize = ftell(fdin);
    if (lSize == -1) {
        cerr << "couldn't get end of file position" << endl;
        cerr << "IO status: " << strerror(errno) << endl;
        if (fd != NULL)
            ::fclose(fd);
        ::fclose(fdin);
        return -1;
    }
    rewind(fdin);
    cpu.start();
    while (true) {
        const bool ok = delta.uncompress(rawdata, fdin, codec, mode);
        if (!ok) {
            break;
        }
        uint32_t number = rawdata.size();
        if (writeit) {
            size_t result;
            result = fwrite(&number, sizeof(number), 1, fd);
            result
                    = fwrite(&rawdata[0], sizeof(rawdata[0]), rawdata.size(),
                            fd);
            if (result != rawdata.size()) {
                cerr << strerror(errno) << endl;
                break;
            }
        }
        ++counter;
        integers += rawdata.size();
    }
    clockcycles += cpu.stop();
    if (fd != NULL)
        ::fclose(fd);
    ::fclose(fdin);
    cout << "# integers = " << integers << endl;
    cout << "# arrays = " << counter << endl;
    const uint64_t timespent = z.split();
    const uint64_t cputimespent = cpuz.split();
    cout << "# wall clock time = " << timespent << " mu s" << endl;
    cout << "# cpu time = " << cputimespent << " mu s" << endl;

    if (timespent > 0) {
        cout << "# million integers per second = " << integers * 1000 / ( 1000.0 * timespent) << " mis" << endl;
        cout << "# million integers per CPU second = " << integers * 1000
                / (1000.0 * cputimespent) << " mis" << endl;
    }
    if (integers > 0) {
        cout << "# nanoseconds per integer = " << timespent * 1000.0
                / integers << " ms" << endl;
        cout << "# cpu nanoseconds per integer = " << cputimespent * 1000.0
                / integers << " ms" << endl;

        cout << "# CPU = " << ((clockcycles
                / static_cast<__uint128_t > (integers)) + (clockcycles
                % static_cast<__uint128_t > (integers)) * 1.0 / integers)
                << " clock cycles per integer" << endl;
    }
    cout << "# wrote " << counter << " arrays to " << ofilename << endl;
    struct stat s;
    lstat(filename.c_str(), &s);
    cout << "# file size = " << s.st_size << endl;
    cout << "# file size = " << s.st_size / (1024.0 * 1024.0) << " MiB" << endl;
    cout << "# file size = " << s.st_size / (1000.0 * 1000.0) << " MB" << endl;
    if (integers > 0)
        cout << "# bits per integer = " << s.st_size * 8.0 / integers
                << "  bits/integer" << endl;
}

