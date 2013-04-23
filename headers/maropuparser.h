/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */

#ifndef MAROPUPARSER_H_
#define MAROPUPARSER_H_

#include "common.h"

using namespace std;

/**
 * This is just a bit of code to parse the binary files provided by the
 * Maropu-Open-Coders library at
 * http://integerencoding.isti.cnr.it/?page_id=8
 */
class MaropuGapReader {
public:
    MaropuGapReader(const string & filename) :
        mFilename(filename), fd(NULL) {
    }
    MaropuGapReader(const MaropuGapReader & mgr) :
        mFilename(mgr.mFilename), fd(NULL) {
    }
    MaropuGapReader& operator=(const MaropuGapReader & mgr) {
        close();
        mFilename = mgr.mFilename;
        return *this;
    }

    string mFilename;
    FILE * fd;


    ~MaropuGapReader() {
        close();
    }

    // return false if no more data can be loaded
    template <class container>
    bool loadIntegers(container & buffer) {
        if(fd == NULL) {
          cerr<<"You forgot to open the file."<<endl;
          return false;
        }
        uint32_t number;
        size_t result = fread(&number, sizeof(number), 1, fd);
        if (result != 1) {
            return false;
        }
        buffer.resize(number);
        result = fread(&(buffer[0]), sizeof(uint32_t), buffer.size(),
                fd);
        if (result != buffer.size()) {
            cerr << "IO status: " << strerror(errno) << endl;
            cerr << "Error reading from file " << endl;
            throw runtime_error("bad read");
        }
        return true;
    }


    void open() {
        close();
        fd = ::fopen(mFilename.c_str(), "rb");
        if (fd == NULL) {
            cerr << "IO status: " << strerror(errno) << endl;
            cerr << "Can't open " << mFilename << endl;
            throw runtime_error("could not open temp file");
        }
        setvbuf (fd , NULL , _IOFBF , 1024*4 ); // large buffer
    }

    void close() {
        if (fd != NULL) {
            ::fclose(fd);
            fd = NULL;
        }
    }
};

#endif /* MAROPUPARSER_H_ */
