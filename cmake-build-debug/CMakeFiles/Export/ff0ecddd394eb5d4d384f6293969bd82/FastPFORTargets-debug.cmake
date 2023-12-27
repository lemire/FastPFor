#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "FastPFOR::FastPFOR" for configuration "Debug"
set_property(TARGET FastPFOR::FastPFOR APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(FastPFOR::FastPFOR PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C;CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libFastPFOR.a"
  )

list(APPEND _cmake_import_check_targets FastPFOR::FastPFOR )
list(APPEND _cmake_import_check_files_for_FastPFOR::FastPFOR "${_IMPORT_PREFIX}/lib/libFastPFOR.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
