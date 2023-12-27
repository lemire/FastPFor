include(CheckCXXCompilerFlag)

check_cxx_compiler_flag("-mfpu=neon" SUPPORT_NEON)