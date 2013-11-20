#
.SUFFIXES:
#
.SUFFIXES: .cpp .o .c .h
ifeq ($(INTEL), 1)
# if you wish to use the Intel compiler, please do "make INTEL=1".
    YOURCXX ?= /opt/intel/bin/icpc
ifeq ($(DEBUG),1)
    CXXFLAGS = -std=c++11 -O3 -Wall -xSSSE3 -D_GLIBCXX_DEBUG  -DDEBUG=1 -ggdb
else
    CXXFLAGS = -std=c++11 -O3 -Wall -xSSSE3 -DNDEBUG=1 -ggdb
endif
else 
# replace the YOURCXX variable with a path to a C++11 compatible compiler.
YOURCXX ?= g++-4.7
CXX := $(YOURCXX)

# todo: allow custom architectures , e.g., -march=nocona -march=corei7
CXXFLAGSEXTRA = -mssse3 # mssse3 necessary for varintg8iu and msse4.1 necessary for horizontal bit packing

ifeq ($(DEBUG),1)
CXXFLAGS = $(CXXFLAGSEXTRA) -Wconversion  -std=c++0x -Weffc++ -pedantic -O3 -ggdb -D_GLIBCXX_DEBUG -Wold-style-cast -Wall -Wextra -Wcast-align -Wunsafe-loop-optimizations -Wcast-qual
else
CXXFLAGS = $(CXXFLAGSEXTRA) -Wconversion  -std=c++0x -Weffc++ -pedantic -O3 -Wold-style-cast -Wall -Wextra -Wcast-align -Wunsafe-loop-optimizations -Wcast-qual
endif
#-ggdb
endif
CXX := $(YOURCXX)

HEADERS = ./headers/simdfastpfor.h ./headers/simdbinarypacking.h ./headers/bitpackinghelpers.h ./headers/common.h ./headers/memutil.h ./headers/pfor.h ./headers/pfor2008.h ./headers/bitpackingunaligned.h ./headers/bitpackingaligned.h ./headers/blockpacking.h  ./headers/codecfactory.h ./headers/packingvectors.h ./headers/compositecodec.h ./headers/cpubenchmark.h  ./headers/maropuparser.h ./headers/bitpacking.h  ./headers/util.h ./headers/simple9.h ./headers/simple8b.h ./headers/simple16.h ./headers/optpfor.h ./headers/newpfor.h ./headers/vsencoding.h ./headers/mersenne.h  ./headers/ztimer.h ./headers/codecs.h ./headers/synthetic.h ./headers/fastpfor.h ./headers/variablebyte.h ./headers/stringutil.h ./headers/entropy.h ./headers/VarIntG8IU.h ./headers/deltautil.h 

all: unit codecs inmemorybenchmark  

allallall: unit codecs inmemorybenchmark entropy gapstats benchbitpacking partitionbylength csv2maropu  

#snappy requires that the snappy lib be installed!!!
snap: codecssnappy inmemorybenchmarksnappy

test: unit
	./unit

#search to find which is the important parameter.  Turns out that there are 2.  Note that 400 insns was not enough
#GCCPARAMS=  --param max-completely-peel-times=32  --param max-completely-peeled-insns=800 # --param max-peeled-insns=1000  # --param max-unrolled-insns=1000 # --param max-average-unrolled-insns=500 --param max-unroll-times=32 --param max-peel-times=32

#GCCPARAMS=  --param max-completely-peel-times=64  --param max-completely-peeled-insns=5000 --param max-peeled-insns=6000  --param max-unrolled-insns=6000 --param max-average-unrolled-insns=4000  --param max-unroll-times=64 --param max-peel-times=64
GCCPARAMS=
./headers/common.h.gch: ./headers/common.h 
	$(CXX) $(CXXFLAGS) -x c++-header  -c ./headers/common.h -Iheaders

COMMONBINARIES= bitpacking.o bitpackingaligned.o bitpackingunaligned.o simdbitpacking.o

bitpacking.o: ./headers/bitpacking.h ./src/bitpacking.cpp
	$(CXX) $(CXXFLAGS) -c ./src/bitpacking.cpp -Iheaders

bitpackingunaligned.o: ./headers/bitpacking.h ./src/bitpackingunaligned.cpp
	$(CXX) $(CXXFLAGS) -c ./src/bitpackingunaligned.cpp -Iheaders

bitpackingaligned.o: ./headers/bitpacking.h ./src/bitpackingaligned.cpp
	$(CXX) $(CXXFLAGS) -c ./src/bitpackingaligned.cpp -Iheaders

simdbitpacking.o: ./headers/common.h ./headers/simdbitpacking.h ./src/simdbitpacking.cpp
	$(CXX) $(CXXFLAGS) -c ./src/simdbitpacking.cpp -Iheaders

horizontalbitpacking.o: ./headers/common.h ./headers/horizontalbitpacking.h ./src/horizontalbitpacking.cpp
	$(CXX) $(CXXFLAGS) -msse4.1 -c ./src/horizontalbitpacking.cpp -Iheaders


entropy: $(HEADERS) src/entropy.cpp
	$(CXX) $(CXXFLAGS) -o entropy src/entropy.cpp $(COMMONBINARIES) -Iheaders

gapstats: $(HEADERS) src/gapstats.cpp
	$(CXX) $(CXXFLAGS) -o gapstats src/gapstats.cpp -Iheaders

benchbitpacking: $(HEADERS) src/benchbitpacking.cpp ./headers/rolledbitpacking.h ./headers/common.h.gch makefile $(COMMONBINARIES) horizontalbitpacking.o
	$(CXX) $(CXXFLAGS) $(GCCPARAMS) -msse4.1  -Winvalid-pch  -o benchbitpacking src/benchbitpacking.cpp $(COMMONBINARIES) horizontalbitpacking.o -Iheaders

partitionbylength: $(HEADERS) src/partitionbylength.cpp
	$(CXX) $(CXXFLAGS) -o partitionbylength src/partitionbylength.cpp -Iheaders

codecssnappy:  $(HEADERS) src/codecs.cpp ./headers/common.h.gch  ./headers/snappydelta.h makefile $(COMMONBINARIES)
	$(CXX) $(CXXFLAGS) $(GCCPARAMS) -Winvalid-pch  -o codecssnappy src/codecs.cpp $(COMMONBINARIES) -Iheaders  -lsnappy -DUSESNAPPY


example:  $(HEADERS) example.cpp ./headers/common.h.gch makefile $(COMMONBINARIES)
	$(CXX) $(CXXFLAGS) $(GCCPARAMS) -Winvalid-pch  -o example example.cpp $(COMMONBINARIES) -Iheaders


codecs:  $(HEADERS) src/codecs.cpp ./headers/common.h.gch makefile $(COMMONBINARIES)
	$(CXX) $(CXXFLAGS) $(GCCPARAMS) -Winvalid-pch  -o codecs src/codecs.cpp $(COMMONBINARIES) -Iheaders

cppcheck: 
	cppcheck --std=c++11 --enable=all $(HEADERS) src/codecs.cpp src/inmemorybenchmark.cpp src/unit.cpp src/bitpacking.cpp src/bitpackingaligned.cpp src/bitpackingunaligned.cpp

csv2maropu:  $(HEADERS) src/csv2maropu.cpp ./headers/externalvector.h ./headers/csv.h
	$(CXX)  $(CXXFLAGS) -o csv2maropu src/csv2maropu.cpp  -Iheaders


inmemorybenchmark: $(HEADERS)  src/inmemorybenchmark.cpp ./headers/common.h.gch makefile $(COMMONBINARIES)
	$(CXX) $(CXXFLAGS) -Winvalid-pch  -o inmemorybenchmark  src/inmemorybenchmark.cpp $(COMMONBINARIES) -Iheaders 


inmemorybenchmarksnappy: $(HEADERS)  src/inmemorybenchmark.cpp ./headers/common.h.gch ./headers/snappydelta.h makefile $(COMMONBINARIES)
	$(CXX) $(CXXFLAGS) -Winvalid-pch  -o inmemorybenchmarksnappy  src/inmemorybenchmark.cpp $(COMMONBINARIES) -Iheaders  -lsnappy -DUSESNAPPY



unit: $(HEADERS) src/unit.cpp makefile ./headers/common.h.gch $(COMMONBINARIES)
	$(CXX) $(CXXFLAGS) $(GCCPARAMS) -Winvalid-pch  -o unit src/unit.cpp $(COMMONBINARIES) -Iheaders

clean:
	rm -f *.o ./headers/*.gch codecs inmemorybenchmark inmemorybenchmarksnappy codecssnappy unit  csv2maropu entropy gapstats benchbitpacking partitionbylength
