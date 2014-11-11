# This code is released under the
# Apache License Version 2.0 http://www.apache.org/licenses/.
#
# Copyright (c) 2012 Louis Dionne
#
cmake_minimum_required(VERSION 2.8.7)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules")
include(AppendCompilerFlags)

project(FastPFor CXX C)
set(PROJECT_URL "https://github.com/lemire/FastPFOR")
set(PROJECT_DESCRIPTION "The FastPFOR C++ library: Fast integer compression")
set(CMAKE_BUILD_TYPE "Release") # CHANGE TO Debug HERE

# C++11 compiler Check
if(NOT CMAKE_CXX_COMPILER_VERSION) # work around for cmake versions smaller than 2.8.10
    execute_process(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion OUTPUT_VARIABLE CMAKE_CXX_COMPILER_VERSION)
endif()
if(CMAKE_CXX_COMPILER MATCHES ".*clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
      set(CMAKE_COMPILER_IS_CLANGXX 1)
endif()
if( (CMAKE_COMPILER_IS_GNUCXX AND ${CMAKE_CXX_COMPILER_VERSION} VERSION_LESS 4.7) OR
    (CMAKE_COMPILER_IS_CLANGXX AND ${CMAKE_CXX_COMPILER_VERSION} VERSION_LESS 3.2))
  message(FATAL_ERROR "Your C++ compiler does not support C++11. Please install g++ 4.7 (or greater) or clang 3.2 (or greater)")
else()
  message(STATUS "Compiler is recent enough to support C++11.")
endif()

# warnings and standard flags
if( CMAKE_COMPILER_IS_GNUCXX )  
    append_cxx_compiler_flags("-std=c++11 -Weffc++ -pedantic -O3 -ggdb -D_GLIBCXX_DEBUG" "GCC" CMAKE_CXX_FLAGS_DEBUG)
    append_cxx_compiler_flags("-Wold-style-cast -Wall -Wextra -Wcast-align  -Wcast-qual" "GCC" CMAKE_CXX_FLAGS_DEBUG)
    append_cxx_compiler_flags("-std=c++11 -Weffc++ -Wold-style-cast -Wall -Wextra -Wcast-align -Wcast-qual" "GCC" CMAKE_CXX_FLAGS_RELEASE)
    append_cxx_compiler_flags("-pedantic -O3 -ffast-math -funroll-loops" "GCC" CMAKE_CXX_FLAGS_RELEASE)
else()
    append_cxx_compiler_flags("-std=c++11 -Weverything -pedantic -O3 -g" "GCC" CMAKE_CXX_FLAGS_DEBUG)
    append_cxx_compiler_flags("-Wall -Wextra -Wcast-align  -Wcast-qual" "GCC" CMAKE_CXX_FLAGS_DEBUG)
    append_cxx_compiler_flags("-std=c++11 -Weffc++ -Wold-style-cast -Wall -Wextra -Wcast-align -Wcast-qual" "GCC" CMAKE_C_FLAGS_RELEASE)
    append_cxx_compiler_flags("-pedantic -O3 -ffast-math -funroll-loops" "GCC" CMAKE_C_FLAGS_RELEASE)
endif()

# cpu features
include(DetectCPUFeatures)
if( SUPPORT_BMI2 )
    if( CMAKE_COMPILER_IS_GNUCXX )
        append_cxx_compiler_flags("-mbmi2" "GCC" CMAKE_CXX_FLAGS)
    else()
        append_cxx_compiler_flags("-mbmi2" "CLANG" CMAKE_CXX_FLAGS)
    endif()
endif()
if( SUPPORT_SSE42 )
    if( CMAKE_COMPILER_IS_GNUCXX )
        append_cxx_compiler_flags("-msse4.2" "GCC" CMAKE_CXX_FLAGS)
    else()
        append_cxx_compiler_flags("-msse4.2" "CLANG" CMAKE_CXX_FLAGS)
    endif()
endif()
if( SUPPORT_SSE3 )
    if( CMAKE_COMPILER_IS_GNUCXX )
        append_cxx_compiler_flags("-msse3" "GCC" CMAKE_CXX_FLAGS)
    else()
        append_cxx_compiler_flags("-msse3" "CLANG" CMAKE_CXX_FLAGS)
    endif()
endif()


# library target
include_directories(headers)
add_library(FastPFor STATIC src/bitpacking.cpp
                                src/bitpacking.cpp
                                src/bitpackingaligned.cpp
                                src/bitpackingunaligned.cpp
                                src/horizontalbitpacking.cpp 
                                src/simdunalignedbitpacking.cpp
                                src/simdbitpacking.cpp)


# other executables
add_executable(gapstats src/gapstats.cpp)
add_executable(partitionbylength src/partitionbylength.cpp)
add_executable(csv2maropu src/csv2maropu.cpp)

add_executable(entropy src/entropy.cpp)
target_link_libraries(entropy FastPFor)

if( SUPPORT_SSE42 )
    add_executable(benchbitpacking src/benchbitpacking.cpp)
    target_link_libraries(benchbitpacking FastPFor)
endif()

find_package(snappy)
if(NOT ${snappy_FOUND})
    message(STATUS "Snappy was not found. codecssnappy and "
                   "inmemorybenchmarksnappy targets are not available.")
else()
    message(STATUS "Snappy was found. Building additional targets "
                   "codecssnappy and inmemorybenchmarksnappy.")
    include_directories(${snappy_INCLUDE_DIRS})
    add_executable(codecssnappy src/codecs.cpp)
    set_target_properties(codecssnappy PROPERTIES DEFINE_SYMBOL USESNAPPY)
    target_link_libraries(codecssnappy FastPFor ${snappy_LIBRARIES})

    add_executable(inmemorybenchmarksnappy src/inmemorybenchmark.cpp)
    set_target_properties(inmemorybenchmarksnappy PROPERTIES DEFINE_SYMBOL USESNAPPY)
    target_link_libraries(inmemorybenchmarksnappy FastPFor ${snappy_LIBRARIES})
endif()

add_executable(codecs src/codecs.cpp)
target_link_libraries(codecs FastPFor)

add_executable(inmemorybenchmark src/inmemorybenchmark.cpp)
target_link_libraries(inmemorybenchmark FastPFor)

add_executable(unit src/unit.cpp)
target_link_libraries(unit FastPFor)
add_custom_target(check unit DEPENDS unit)
