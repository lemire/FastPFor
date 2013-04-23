/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */


#ifndef CVSTOMAROPUCVS_H_
#define CVSTOMAROPUCVS_H_
#include "common.h"

using namespace std;

enum {
    INCREASINGCARDINALITY, DECREASINGCARDINALITY
};
/**
 * Comma-Separate Values
 */
class CSVReader {
public:

    CSVReader(istream * in, const string delimiter = ",",
            const char commentmarker = '#') :
        line(), mDelimiter(delimiter), mDelimiterPlusSpace(delimiter),
                mCommentMarker(commentmarker), mIn(in), currentData() {
    }
    CSVReader(const CSVReader & o) :
        line(o.line), mDelimiter(o.mDelimiter),
                mDelimiterPlusSpace(o.mDelimiterPlusSpace),
                mCommentMarker(o.mCommentMarker), mIn(o.mIn),
                currentData(o.currentData) {
    }
    CSVReader & operator=(const CSVReader & o) {
        line = o.line;
        mDelimiter = o.mDelimiter;
        mDelimiterPlusSpace = o.mDelimiterPlusSpace;
        mCommentMarker = o.mCommentMarker;
        mIn = o.mIn;
        currentData = o.currentData;
        return *this;
    }

    virtual ~CSVReader() {
    }

    void linkStream(istream * in) {
        mIn = in;
    }

    inline bool hasNext() {
        while (getline(*mIn, line)) {
            if (line.size() == 0)
                continue;
            if (line[0] == mCommentMarker)
                continue;
            tokenize(line);
            return true;
        }
        return false;
    }

    inline const vector<string> & nextRow() const {
        return currentData;
    }

    string line;

private:

    inline void tokenize(const string& str) {
        string::size_type lastPos = str.find_first_not_of(mDelimiterPlusSpace,
                0);
        string::size_type pos = str.find_first_of(mDelimiter, lastPos);
        string::size_type pos_w = str.find_last_not_of(' ', pos);
        while (string::npos != pos || string::npos != lastPos) {
            const string::size_type fieldlength = pos == string::npos ? pos_w
                    + 1 - lastPos : pos_w - lastPos;
            currentData.push_back(str.substr(lastPos, fieldlength));
            lastPos = str.find_first_not_of(mDelimiterPlusSpace, pos);
            pos = str.find_first_of(mDelimiter, lastPos);
            pos_w = str.find_last_not_of(' ', pos);
        }
    }

    string mDelimiter;
    string mDelimiterPlusSpace;
    char mCommentMarker;
    istream * mIn;
    vector<string> currentData;

};

class CSVFlatFile {
public:

    typedef map<string, size_t> maptype;
    typedef map<string, size_t> umaptype;

    enum {
        FREQNORMALISATION, DOMAINNORMALISATION
    };
    CSVFlatFile(const char * filename, const int normtype) :
        in(), mainreader(NULL), mapping(), NumberOfLines(0) {
        cout << "# computing normalization of file " << filename << endl;
        if (normtype == FREQNORMALISATION)
            computeFreqNormalization(filename);
        else if (normtype == DOMAINNORMALISATION)
            computeDomainNormalization(filename);
        in.open(filename);
        mainreader.linkStream(&in);
    }

    size_t getNumberOfRows() const {
        return NumberOfLines;
    }
    size_t getNumberOfColumns() const {
        return mapping.size();
    }

    size_t numberOfAttributeValues() {
        size_t sum = 0;
        for (size_t k = 0; k < mapping.size(); ++k) {
            sum += mapping[k].size();
        }
        return sum;
    }

    vector<size_t> cardinalities() {
        vector < size_t > cardinalities;
        for (size_t k = 0; k < mapping.size(); ++k) {
                    cardinalities.push_back(mapping[k].size());
        }
        return cardinalities;
    }

    vector<size_t> computeColumnOrderAndReturnColumnIndexes(
            int order = INCREASINGCARDINALITY) {
        vector < size_t > cardinalities;
        for (size_t k = 0; k < mapping.size(); ++k) {
            cardinalities.push_back(mapping[k].size());
        }
        vector < pair<size_t, size_t> > cardinalitiesindex;
        for (size_t k = 0; k < cardinalities.size(); ++k)
            cardinalitiesindex.push_back(
                    pair<size_t, size_t> (cardinalities[k], k));
        if (order == INCREASINGCARDINALITY)
            sort(cardinalitiesindex.begin(), cardinalitiesindex.end());
        else
            sort(cardinalitiesindex.rbegin(), cardinalitiesindex.rend());
        vector < size_t > answer(getNumberOfColumns());
        for (size_t k = 0; k < answer.size(); ++k)
            answer[k] = cardinalitiesindex[k].second;
        return answer;
    }

    // a bit awkward... but convenient:
    set<size_t> AllButTopCardinalityColumnsExceptThoseWithCardinalityLowerThan(
            size_t topcolumns, size_t threshold) {
        if (mapping.empty()) {
            set < size_t > answer;
            return answer;
        }
        vector < size_t > allcards;
        for (size_t k = 0; k < mapping.size(); ++k) {
            allcards.push_back(mapping[k].size());
        }
        sort(allcards.rbegin(), allcards.rend());
        size_t mythreshold = allcards[min(topcolumns - 1, allcards.size() - 1)];
        cout << "# top " << topcolumns << " columns selected with cardinality "
                << mythreshold << endl;
        if (mythreshold < threshold)
            mythreshold = threshold;
        cout << "# cardinality threshold " << mythreshold << endl;
        set < size_t > answer;
        for (size_t k = 0; k < mapping.size(); ++k) {
            if (mapping[k].size() < mythreshold) {
                answer.insert(k);
            }
        }
        return answer;
    }
    void clear() {
        mapping.clear();
    }
    void close() {
        in.close();
    }

    //size_t getCardinalityOfColumn(size_t k) {return mapping[k].size();}
    template<class C>
    bool nextRow(C & container) {
        if (mainreader.hasNext()) {
            const vector<string> & row = mainreader.nextRow();
            for (size_t k = 0; k < row.size(); ++k) {
                container[k] = mapping[k][row[k]];
            }
            return true;
        } else
            return false;
    }

    void computeHisto(ifstream & fsin, vector<umaptype> & histograms) {
        NumberOfLines = 0;
        CSVReader csvfile(&fsin);
        if (csvfile.hasNext()) {
            ++NumberOfLines;
            const vector<string> & row = csvfile.nextRow();
            histograms.resize(row.size());
            for (size_t k = 0; k < row.size(); ++k) {
                histograms[k][row[k]] = 1;
            }
        } else {
            cerr
                    << "could open the file, but couldn't even read the first line"
                    << endl;
            return;
        }
        while (csvfile.hasNext()) {
            ++NumberOfLines;
            const vector<string> & row = csvfile.nextRow();
            for (size_t k = 0; k < row.size(); ++k) {
                histograms[k][row[k]] += 1;
            }
        }
    }
    // map the string values to integer per frequency
    void computeFreqNormalization(const char * filename) {
        ifstream fsin(filename);
        if (!fsin) {
            cerr << "can't open " << filename << endl;
            return;
        }

        vector<umaptype> histograms;
        computeHisto(fsin, histograms);

        fsin.close();
        mapping.resize(histograms.size());
        // next we sort the values per frequency
        for (size_t k = 0; k < histograms.size(); ++k) {
            vector < pair<size_t, string> > tobesorted;
            tobesorted.reserve(histograms[k].size());
            for (umaptype::iterator i = histograms[k].begin(); i
                    != histograms[k].end(); ++i) {
                tobesorted.push_back(pair<size_t, string> (i->second, i->first));
            }
            histograms[k].clear();// free the memory
            sort(tobesorted.rbegin(), tobesorted.rend());
            maptype & thismap = mapping[k];
            for (size_t k = 0; k < tobesorted.size(); ++k)
                thismap[tobesorted[k].second] = k;
        }
    }

    // map the string values to integers in lexicographical order
    void computeDomainNormalization(const char * filename) {
        ifstream fsin(filename);
        if (!fsin) {
            cerr << "can't open " << filename << endl;
            return;
        }
        NumberOfLines = 0;
        CSVReader csvfile(&fsin);
        vector < set<string> > histograms;
        if (csvfile.hasNext()) {
            ++NumberOfLines;
            const vector<string> & row = csvfile.nextRow();
            histograms.resize(row.size());
            for (size_t k = 0; k < row.size(); ++k) {
                histograms[k].insert(row[k]);
            }
        } else {
            cerr
                    << "could open the file, but couldn't even read the first line of "
                    << filename << endl;
            return;
        }
        while (csvfile.hasNext()) {
            ++NumberOfLines;
            const vector<string> & row = csvfile.nextRow();
            for (size_t k = 0; k < row.size(); ++k) {
                histograms[k].insert(row[k]);
            }
        }
        fsin.close();
        mapping.resize(histograms.size());
        // the values are already sorted lexicographically
        for (size_t k = 0; k < histograms.size(); ++k) {
            set < string > &myvalues = histograms[k];
            maptype & thismap = mapping[k];
            size_t counter = 0;
            for (set<string>::iterator i = myvalues.begin(); i
                    != myvalues.end(); ++i) {
                thismap[*i] = counter++;
            }
            myvalues.clear();
        }
    }

    ifstream in;
    CSVReader mainreader;
    vector<maptype> mapping;
    size_t NumberOfLines;
};

#endif /* CVSTOMAROPU_H_ */
