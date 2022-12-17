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
#include "simple9_rle.h"
#include "simple8b.h"
#include "simple8b_rle.h"
#include "newpfor.h"
#include "simdnewpfor.h"
#include "optpfor.h"
#include "simdoptpfor.h"
#include "fastpfor.h"
#include "simdfastpfor.h"
#include "variablebyte.h"
#include "compositecodec.h"
#include "blockpacking.h"
#include "pfor.h"
#include "simdpfor.h"
#include "pfor2008.h"
#include "VarIntG8IU.h"
#include "simdbinarypacking.h"
#include "snappydelta.h"
#include "varintgb.h"
#include "simdvariablebyte.h"
#include "streamvariablebyte.h"
#include "simdgroupsimple.h"

namespace FastPForLib {

typedef std::map<std::string, std::shared_ptr<IntegerCODEC>> CodecMap;

/**
 * You should have at least one factory per thread.
 */
class CODECFactory {
public:
  CODECFactory();

  std::vector<std::shared_ptr<IntegerCODEC>> allSchemes();

  std::vector<std::string> allNames();

  std::shared_ptr<IntegerCODEC> &getFromName(std::string name);
private:
  CodecMap scodecmap;
};


} // namespace FastPFor

#endif /* CODECFACTORY_H_ */
