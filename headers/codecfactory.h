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
 * This class is a convenience class to generate codecs quickly.
 * It cannot be used safely in a multithreaded context where
 * each thread should have a different IntegerCODEC.
 */
class CODECFactory {
public:
  static CodecMap scodecmap;

  // hacked for convenience
  static std::vector<std::shared_ptr<IntegerCODEC>> allSchemes() {
    std::vector<std::shared_ptr<IntegerCODEC>> ans;
    for (auto i = scodecmap.begin(); i != scodecmap.end(); ++i) {
      ans.push_back(i->second);
    }
    return ans;
  }

  static std::vector<std::string> allNames() {
    std::vector<std::string> ans;
    for (auto i = scodecmap.begin(); i != scodecmap.end(); ++i) {
      ans.push_back(i->first);
    }
    return ans;
  }

  static std::shared_ptr<IntegerCODEC> &getFromName(std::string name) {
    if (scodecmap.find(name) == scodecmap.end()) {
      std::cerr << "name " << name << " does not refer to a CODEC."
                << std::endl;
      std::cerr << "possible choices:" << std::endl;
      for (auto i = scodecmap.begin(); i != scodecmap.end(); ++i) {
        std::cerr << static_cast<std::string>(i->first)
                  << std::endl; // useless cast, but just to be clear
      }
      std::cerr << "for now, I'm going to just return 'copy'" << std::endl;
      return scodecmap["copy"];
    }
    return scodecmap[name];
  }
};


} // namespace FastPFor

#endif /* CODECFACTORY_H_ */
