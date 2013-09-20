/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */

#ifndef CODECFACTORY_H_
#define CODECFACTORY_H_

#include "common.h"
#include "codecs.h"
#include "vsencoding.h"
#include "util.h"
#include "simple16.h"
#include "simple9.h"
#include "simple8b.h"
#include "newpfor.h"
#include "optpfor.h"
#include "fastpfor.h"
#include "simdfastpfor.h"
#include "variablebyte.h"
#include "compositecodec.h"
#include "blockpacking.h"
#include "pfor.h"
#include "pfor2008.h"
#include "VarIntG8IU.h"
#include "simdbinarypacking.h"
#include "snappydelta.h"

using namespace std;
typedef map<string, shared_ptr<IntegerCODEC> > CodecMap;

class CODECFactory {
public:
	static CodecMap scodecmap;

    // hacked for convenience
    static vector<shared_ptr<IntegerCODEC> > allSchemes() {
        vector < shared_ptr<IntegerCODEC> > ans;
        for (auto i = scodecmap.begin(); i != scodecmap.end(); ++i) {
            ans.push_back(i->second);
        }
        return ans;
    }

    static vector<string> allNames() {
        vector < string > ans;
        for (auto i = scodecmap.begin(); i != scodecmap.end(); ++i) {
            ans.push_back(i->first);
        }
        return ans;
    }

    static shared_ptr<IntegerCODEC> & getFromName(string name) {
        if (scodecmap.find(name) == scodecmap.end()) {
            cerr << "name " << name << " does not refer to a CODEC." << endl;
            cerr << "possible choices:" << endl;
            for (auto i = scodecmap.begin(); i != scodecmap.end(); ++i) {
                cerr << static_cast<string> (i->first) << endl;// useless cast, but just to be clear
            }
            cerr << "for now, I'm going to just return 'copy'" << endl;
            return scodecmap["copy"];
        }
        return scodecmap[name];
    }

};


// C++11 allows better than this, but neither Microsoft nor Intel support C++11 fully.
static inline CodecMap initializefactory() {
	CodecMap map;
	map["fastbinarypacking8"] = shared_ptr<IntegerCODEC> (
			new CompositeCodec<FastBinaryPacking<8> , VariableByte> );
	map["fastbinarypacking16"] = shared_ptr<IntegerCODEC> (
			new CompositeCodec<FastBinaryPacking<16> , VariableByte> );
	map["fastbinarypacking32"] = shared_ptr<IntegerCODEC> (
			new CompositeCodec<FastBinaryPacking<32> , VariableByte> );
	map["BP32"] =  shared_ptr<IntegerCODEC> (new CompositeCodec<BP32 ,
			VariableByte>);
	map["vsencoding"] = shared_ptr<IntegerCODEC> (
			new vsencoding::VSEncodingBlocks(1U << 16));
	map["fastpfor"] = shared_ptr<IntegerCODEC> (
			new CompositeCodec<FastPFor, VariableByte> ());
	map["simdfastpfor"] = shared_ptr<IntegerCODEC> (
			new CompositeCodec<SIMDFastPFor, VariableByte> ());
	map["simplepfor"] = shared_ptr<IntegerCODEC> (
			new CompositeCodec<SimplePFor<> , VariableByte> ());
	map["pfor"] = shared_ptr<IntegerCODEC> (
			new CompositeCodec<PFor, VariableByte> ());
	map["pfor2008"] = shared_ptr<IntegerCODEC> (
			new CompositeCodec<PFor2008, VariableByte> ());
	map["newpfor"] = shared_ptr<IntegerCODEC> (
			new CompositeCodec<NewPFor<4, Simple16<false>> , VariableByte> ());
	map["optpfor"] = shared_ptr<IntegerCODEC> (
			new CompositeCodec<OPTPFor<4, Simple16<false> > , VariableByte> ());
	map["vbyte"] = shared_ptr<IntegerCODEC> (new VariableByte());
	map["simple8b"] = shared_ptr<IntegerCODEC> (new Simple8b<true> ());
#ifdef VARINTG8IU_H__
	map["varintg8iu"] = shared_ptr<IntegerCODEC> (new VarIntG8IU ());
#endif
#ifdef USESNAPPY
	map["snappy"] = shared_ptr<IntegerCODEC> (new JustSnappy ());
#endif
	map["simdbinarypacking"] = shared_ptr<IntegerCODEC> (
			new CompositeCodec<SIMDBinaryPacking, VariableByte> ());
	map["copy"] = shared_ptr<IntegerCODEC> (new JustCopy());
	return map;
}


CodecMap CODECFactory::scodecmap = initializefactory();

#endif /* CODECFACTORY_H_ */
