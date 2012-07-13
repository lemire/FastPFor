/**
 * This is code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */

#include <vector>
#include "maropuparser.h"
#include "util.h"
#include "entropy.h"
#include "deltaio.h"

void message(const char * prog) {
    cerr << " usage : " << prog << " scheme  maropubinaryfile "
            << endl;
    cerr << "By default, is assumes that the original data is made of "
        "sorted distinct integers, to process the more general case,"
        "add the -notdgaps flag." << endl;
    cerr << "The -nodelta flag disables delta coding." << endl;
    cerr << "The -minlength ignores all arrays smaller than a threshold."
            << endl;
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
    cout <<"# computing entropy" <<endl;
    string filename = argv[argindex++];
    if (argindex < argc)
        MAXCOUNTER = atoi(argv[argindex++]);
    cout << "# parsing " << filename << endl;
    MaropuGapReader reader(filename);
    vector<uint32_t, cacheallocator> rawdata;
    reader.open();
    size_t counter = 0;
    size_t integers = 0;
    EntropyRecorder er;
    while (reader.loadIntegers(rawdata)) {
        if (rawdata.size() < MINLENGTH)
            continue;
        DeltaIO::inplacedeltas(rawdata,mode);
        er.eat(&rawdata[0],rawdata.size());
        ++counter;
        integers += rawdata.size();
        if (counter >= MAXCOUNTER) {
            cout << "#breaking early" << endl;
            break;
        }
    }
    reader.close();
    cout << "# integers = " << integers << endl;
    cout << "# arrays = " << counter << endl;
    cout << "# next line is shannon entropy and data bits" << endl;
    cout << er.computeShannon() << "\t" << er.computeDataBits() <<endl;
}


