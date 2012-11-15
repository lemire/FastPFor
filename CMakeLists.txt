cmake_minimum_required(VERSION 2.8)

project(FastPFor)

set(warnings -Wall -Wextra -pedantic -Weffc++ -Wcast-align -Wunsafe-loop-optimizations -Wcast-qual)
add_definitions(-std=c++0x -O3 -mssse3 ${warnings})
if(${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    add_definitions(-stdlib=libc++)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++")
endif()

include_directories(headers)


add_library(FastPFor_lib STATIC src/bitpacking.cpp
                                src/bitpackingaligned.cpp
                                src/bitpackingunaligned.cpp
                                src/simdbitpacking.cpp)


add_executable(gapstats src/gapstats.cpp)
add_executable(partitionbylength src/partitionbylength.cpp)
add_executable(csv2maropu src/csv2maropu.cpp)

add_executable(entropy src/entropy.cpp)
target_link_libraries(entropy FastPFor_lib)

# Enable sse4.1 instructions for horizontal bit packing
set_source_files_properties(src/horizontalbitpacking.cpp PROPERTIES COMPILE_FLAGS -msse4.1)
add_executable(benchbitpacking src/benchbitpacking.cpp src/horizontalbitpacking.cpp)
target_link_libraries(benchbitpacking FastPFor_lib)

add_executable(codecssnappy src/codecs.cpp)
set_target_properties(codecssnappy PROPERTIES DEFINE_SYMBOL USESNAPPY LINK_FLAGS snappy)
target_link_libraries(codecssnappy FastPFor_lib)

add_executable(codecs src/codecs.cpp)
target_link_libraries(codecs FastPFor_lib)

add_executable(inmemorybenchmark src/inmemorybenchmark.cpp)
target_link_libraries(inmemorybenchmark FastPFor_lib)

add_executable(inmemorybenchmarksnappy src/inmemorybenchmark.cpp)
set_target_properties(inmemorybenchmarksnappy PROPERTIES DEFINE_SYMBOL USESNAPPY LINK_FLAGS snappy)
target_link_libraries(inmemorybenchmarksnappy FastPFor_lib)

add_executable(unit src/unit.cpp)
target_link_libraries(unit FastPFor_lib)
add_custom_target(check unit DEPENDS unit)
