/**
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 * (c) Daniel Lemire, http://lemire.me/en/
 */
#ifndef COMPOSITECODEC_H_
#define COMPOSITECODEC_H_

#include "common.h"
#include "util.h"
#include "codecs.h"

namespace FastPForLib {

/**
 * This is a useful class for CODEC that only compress
 * data having length a multiple of some unit length.
 */
template <class Codec1, class Codec2>
class CompositeCodec : public IntegerCODEC {
public:
  CompositeCodec() : codec1(), codec2() {}
  Codec1 codec1;
  Codec2 codec2;
  void encodeArray(const uint32_t *in, const size_t length, uint32_t *out,
                   size_t &nvalue) {
    const size_t roundedlength = length / Codec1::BlockSize * Codec1::BlockSize;
    size_t nvalue1 = nvalue;
    codec1.encodeArray(in, roundedlength, out, nvalue1);

    if (roundedlength < length) {
      ASSERT(nvalue >= nvalue1, nvalue << " " << nvalue1);
      size_t nvalue2 = nvalue - nvalue1;
      codec2.encodeArray(in + roundedlength, length - roundedlength,
                         out + nvalue1, nvalue2);
      nvalue = nvalue1 + nvalue2;
    } else {
      nvalue = nvalue1;
    }
  }
  const uint32_t *decodeArray(const uint32_t *in, const size_t length,
                              uint32_t *out, size_t &nvalue) {
#ifndef NDEBUG
    const uint32_t *const initin(in);
#endif
    size_t mynvalue1 = nvalue;
    const uint32_t *in2 = codec1.decodeArray(in, length, out, mynvalue1);
    if (length + in > in2) {
      assert(nvalue > mynvalue1);
      size_t nvalue2 = nvalue - mynvalue1;
      const uint32_t *in3 = codec2.decodeArray(in2, length - (in2 - in),
                                               out + mynvalue1, nvalue2);
      nvalue = mynvalue1 + nvalue2;
      assert(initin + length >= in3);
      return in3;
    }
    nvalue = mynvalue1;
    assert(initin + length >= in2);
    return in2;
  }
  std::string name() const {
    std::ostringstream convert;
    convert << codec1.name() << "+" << codec2.name();
    return convert.str();
  }
};

} // namespace FastPFor

#endif /* COMPOSITECODEC_H_ */
