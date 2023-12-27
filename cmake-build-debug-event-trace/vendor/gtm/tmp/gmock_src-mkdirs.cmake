# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/kosakseb/Developer/FastPFor/cmake-build-debug-event-trace/vendor/gtm/src/googletest/googlemock"
  "/home/kosakseb/Developer/FastPFor/cmake-build-debug-event-trace/vendor/gtm/src/gmock_src-build"
  "/home/kosakseb/Developer/FastPFor/cmake-build-debug-event-trace/vendor/gtm/gmock"
  "/home/kosakseb/Developer/FastPFor/cmake-build-debug-event-trace/vendor/gtm/tmp"
  "/home/kosakseb/Developer/FastPFor/cmake-build-debug-event-trace/vendor/gtm/src/gmock_src-stamp"
  "/home/kosakseb/Developer/FastPFor/cmake-build-debug-event-trace/vendor/gtm/src"
  "/home/kosakseb/Developer/FastPFor/cmake-build-debug-event-trace/vendor/gtm/src/gmock_src-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/kosakseb/Developer/FastPFor/cmake-build-debug-event-trace/vendor/gtm/src/gmock_src-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/kosakseb/Developer/FastPFor/cmake-build-debug-event-trace/vendor/gtm/src/gmock_src-stamp${cfgdir}") # cfgdir has leading slash
endif()
