/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */

#ifndef STRINGUTIL_H_
#define STRINGUTIL_H_


#include "common.h"
#include "util.h"

using namespace std;

vector<string> split(const string& str, const string& del) {
    vector<string> tokens;
    size_t lastPos = str.find_first_not_of(del, 0);
    size_t pos     = str.find_first_of(del, lastPos);
    while (string::npos != pos || string::npos != lastPos) {
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        lastPos = str.find_first_not_of(del, pos);
        pos = str.find_first_of(del, lastPos);
    }
    return tokens;
}

#endif /* STRINGUTIL_H_ */
