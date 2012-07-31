/**
 * This is code is released under the
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
#include "variablebyte.h"
#include "compositecodec.h"
#include "blockpacking.h"
#include "pfor.h"
#include "pfor2008.h"
#include "VarIntG8IU.h"
#include "simdbinarypacking.h"

using namespace std;

class CODECFactory {
public:
    static map<string, shared_ptr<IntegerCODEC> > scodecmap;

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

map<string, shared_ptr<IntegerCODEC> > CODECFactory::scodecmap = {
    // unaligned
    {   "binarypacking8", shared_ptr<IntegerCODEC> (
                        new CompositeCodec<ByteAlignedPacking<8> , VariableByte> ) },
    {   "binarypacking16", shared_ptr<IntegerCODEC> (
                        new CompositeCodec<ByteAlignedPacking<16> , VariableByte> ) },
    // aligned
    {   "alignedbinarypacking8", shared_ptr<IntegerCODEC> (new CompositeCodec<BinaryPacking<8> ,
                VariableByte>)},
    {   "alignedbinarypacking16", shared_ptr<IntegerCODEC> (new CompositeCodec<BinaryPacking<16> ,
                VariableByte>)},
    {   "binarypacking32", shared_ptr<IntegerCODEC> (new CompositeCodec<BinaryPacking<32> ,
                VariableByte>)},
    {   "fastbinarypacking8", shared_ptr<IntegerCODEC> (new CompositeCodec<FastBinaryPacking<8> ,
                VariableByte>)},
    {   "fastbinarypacking16", shared_ptr<IntegerCODEC> (new CompositeCodec<FastBinaryPacking<16> ,
                VariableByte>)},
    {   "fastbinarypacking32", shared_ptr<IntegerCODEC> (new CompositeCodec<FastBinaryPacking<32> ,
                VariableByte>)},
    {   "BP32", shared_ptr<IntegerCODEC> (new CompositeCodec<BP32 ,
                        VariableByte>)},
    {   "globalbinarypacking32", shared_ptr<IntegerCODEC> (new CompositeCodec<PackedCODEC ,
                 VariableByte>)},
    {   "vsencoding", shared_ptr<IntegerCODEC> (new vsencoding::VSEncodingBlocks(1U << 16))},
    {  "fastpfor", shared_ptr<IntegerCODEC> (new CompositeCodec<FastPFor , VariableByte> ())},
    {  "simplepfor", shared_ptr<IntegerCODEC> (new CompositeCodec<SimplePFor<> , VariableByte> ())},
    {   "pfor", shared_ptr<IntegerCODEC> (new CompositeCodec<PFor , VariableByte> ())},
    {   "pfor2008", shared_ptr<IntegerCODEC> (new CompositeCodec<PFor2008 , VariableByte> ())},
    {   "newpfor", shared_ptr<IntegerCODEC> (new CompositeCodec<NewPFor<4, Simple16<false>> , VariableByte> ())},
    {   "optpfor", shared_ptr<IntegerCODEC> (new CompositeCodec<OPTPFor<4, Simple16<false> > , VariableByte> ())},
    {   "vbyte", shared_ptr<IntegerCODEC> (new VariableByte())},
    {   "simple16", shared_ptr<IntegerCODEC> (new Simple16<true> ())},
    {   "simple9", shared_ptr<IntegerCODEC> (new Simple9<true> ())},
    {   "simple8b", shared_ptr<IntegerCODEC> (new Simple8b<true> ())},
#ifdef VARINTG8IU_H__
    {   "varintg8iu", shared_ptr<IntegerCODEC> (new VarIntG8IU ())},
#endif
    {  "simdbinarypacking", shared_ptr<IntegerCODEC>(new CompositeCodec<SIMDBinaryPacking,VariableByte>())},
    {   "copy", shared_ptr<IntegerCODEC> (new JustCopy())}
};
#endif /* CODECFACTORY_H_ */
