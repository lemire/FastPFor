#include "codecfactory.h"

/**
 * We moved part of the factor to its own cpp file because some users
 * create multiple instances. Note that the factory is not meant to be
 * a safe class, it is a convenience class and you should just have one
 * instance of it per project.
 */
namespace FastPForLib {

// C++11 allows better than this, but neither Microsoft nor Intel support C++11
// fully.
inline CodecMap initializefactory() {
  CodecMap map;
  map["fastbinarypacking8"] = std::shared_ptr<IntegerCODEC>(
      new CompositeCodec<FastBinaryPacking<8>, VariableByte>);
  map["fastbinarypacking16"] = std::shared_ptr<IntegerCODEC>(
      new CompositeCodec<FastBinaryPacking<16>, VariableByte>);
  map["fastbinarypacking32"] = std::shared_ptr<IntegerCODEC>(
      new CompositeCodec<FastBinaryPacking<32>, VariableByte>);
  map["BP32"] =
      std::shared_ptr<IntegerCODEC>(new CompositeCodec<BP32, VariableByte>);
  map["vsencoding"] =
      std::shared_ptr<IntegerCODEC>(new vsencoding::VSEncodingBlocks(1U << 16));
  map["fastpfor128"] = std::shared_ptr<IntegerCODEC>(
      new CompositeCodec<FastPFor<4>, VariableByte>());
  map["fastpfor256"] = std::shared_ptr<IntegerCODEC>(
      new CompositeCodec<FastPFor<8>, VariableByte>());
  map["simdfastpfor128"] = std::shared_ptr<IntegerCODEC>(
      new CompositeCodec<SIMDFastPFor<4>, VariableByte>());
  map["simdfastpfor256"] = std::shared_ptr<IntegerCODEC>(
      new CompositeCodec<SIMDFastPFor<8>, VariableByte>());
  map["simplepfor"] = std::shared_ptr<IntegerCODEC>(
      new CompositeCodec<SimplePFor<>, VariableByte>());
  map["simdsimplepfor"] = std::shared_ptr<IntegerCODEC>(
      new CompositeCodec<SIMDSimplePFor<>, VariableByte>());
  map["pfor"] =
      std::shared_ptr<IntegerCODEC>(new CompositeCodec<PFor, VariableByte>());
  map["simdpfor"] = std::shared_ptr<IntegerCODEC>(
      new CompositeCodec<SIMDPFor, VariableByte>());
  map["pfor2008"] = std::shared_ptr<IntegerCODEC>(
      new CompositeCodec<PFor2008, VariableByte>());
  map["simdnewpfor"] = std::shared_ptr<IntegerCODEC>(
      new CompositeCodec<SIMDNewPFor<4, Simple16<false> >, VariableByte>());
  map["newpfor"] = std::shared_ptr<IntegerCODEC>(
      new CompositeCodec<NewPFor<4, Simple16<false> >, VariableByte>());
  map["optpfor"] = std::shared_ptr<IntegerCODEC>(
      new CompositeCodec<OPTPFor<4, Simple16<false> >, VariableByte>());
  map["simdoptpfor"] = std::shared_ptr<IntegerCODEC>(
      new CompositeCodec<SIMDOPTPFor<4, Simple16<false> >, VariableByte>());
  map["varint"] = std::shared_ptr<IntegerCODEC>(new VariableByte());
  map["vbyte"] = std::shared_ptr<IntegerCODEC>(new VByte());
  map["maskedvbyte"] = std::shared_ptr<IntegerCODEC>(new MaskedVByte());
  map["streamvbyte"] = std::shared_ptr<IntegerCODEC>(new StreamVByte());
  map["varintgb"] = std::shared_ptr<IntegerCODEC>(new VarIntGB<>());
  map["simple16"] = std::shared_ptr<IntegerCODEC>(new Simple16<true>());
  map["simple9"] = std::shared_ptr<IntegerCODEC>(new Simple9<true>());
  map["simple9_rle"] = std::shared_ptr<IntegerCODEC>(new Simple9_RLE<true>());
  map["simple8b"] = std::shared_ptr<IntegerCODEC>(new Simple8b<true>());
  map["simple8b_rle"] = std::shared_ptr<IntegerCODEC>(new Simple8b_RLE<true>());
#ifdef VARINTG8IU_H__
  map["varintg8iu"] = std::shared_ptr<IntegerCODEC>(new VarIntG8IU());
#endif
#ifdef USESNAPPY
  map["snappy"] = std::shared_ptr<IntegerCODEC>(new JustSnappy());
#endif
  map["simdbinarypacking"] = std::shared_ptr<IntegerCODEC>(
      new CompositeCodec<SIMDBinaryPacking, VariableByte>());
  map["simdgroupsimple"] = std::shared_ptr<IntegerCODEC>(
      new CompositeCodec<SIMDGroupSimple<false, false>, VariableByte>());
  map["simdgroupsimple_ringbuf"] = std::shared_ptr<IntegerCODEC>(
      new CompositeCodec<SIMDGroupSimple<true, true>, VariableByte>());
  map["copy"] = std::shared_ptr<IntegerCODEC>(new JustCopy());
  return map;
}
CodecMap CODECFactory::scodecmap = initializefactory();
}
