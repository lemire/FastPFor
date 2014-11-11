
set(SUPPORT_BMI2 0)
# Check if we are on a Linux system
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
	# Use /proc/cpuinfo to get the information
	file(STRINGS "/proc/cpuinfo" _cpuinfo)
	if(_cpuinfo MATCHES "(avx2)|(bmi2)")
		message(STATUS "Detected BMI2 Support")
		set(SUPPORT_BMI2 1)
	endif()
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
#  handle windows
#	get_filename_component(_vendor_id "[HKEY_LOCAL_MACHINE\\Hardware\\Description\\System\\CentralProcessor\\0;VendorIdentifier]" NAME CACHE)
#	get_filename_component(_cpu_id "[HKEY_LOCAL_MACHINE\\Hardware\\Description\\System\\CentralProcessor\\0;Identifier]" NAME CACHE)	
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
#  handle MacOs
execute_process(COMMAND sysctl -n machdep.cpu.features
                OUTPUT_VARIABLE _cpuinfo OUTPUT_STRIP_TRAILING_WHITESPACE)
	if(_cpuinfo MATCHES "BMI2")
		message(STATUS "Detected BMI2 Support")
		set(SUPPORT_BMI2 1)
	endif()
endif()	
	

set(SUPPORT_SSE42 0)
# Check if we are on a Linux system
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
	# Use /proc/cpuinfo to get the information
	file(STRINGS "/proc/cpuinfo" _cpuinfo)
	if(_cpuinfo MATCHES "(sse4_2)|(sse4a)")
	    message(STATUS "Detected SSE4.2 Support")
		set(SUPPORT_SSE42 1)
	endif()
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
#  handle windows
#	get_filename_component(_vendor_id "[HKEY_LOCAL_MACHINE\\Hardware\\Description\\System\\CentralProcessor\\0;VendorIdentifier]" NAME CACHE)
#	get_filename_component(_cpu_id "[HKEY_LOCAL_MACHINE\\Hardware\\Description\\System\\CentralProcessor\\0;Identifier]" NAME CACHE)	
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
#  handle MacOs
execute_process(COMMAND sysctl -n machdep.cpu.features
                OUTPUT_VARIABLE _cpuinfo OUTPUT_STRIP_TRAILING_WHITESPACE)
	if(_cpuinfo MATCHES "SSE4.2")
		message(STATUS "Detected SSE4.2 Support")
		set(SUPPORT_SSE42 1)
	endif()
endif()	
	

set(SUPPORT_SSE3 0)
# Check if we are on a Linux system
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
	# Use /proc/cpuinfo to get the information
	file(STRINGS "/proc/cpuinfo" _cpuinfo)
	if(_cpuinfo MATCHES "sse3")
		message(STATUS "Detected SSE3 Support")
		set(SUPPORT_SSE3 1)
	endif()
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
#  handle windows
#	get_filename_component(_vendor_id "[HKEY_LOCAL_MACHINE\\Hardware\\Description\\System\\CentralProcessor\\0;VendorIdentifier]" NAME CACHE)
#	get_filename_component(_cpu_id "[HKEY_LOCAL_MACHINE\\Hardware\\Description\\System\\CentralProcessor\\0;Identifier]" NAME CACHE)	
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
#  handle MacOs
execute_process(COMMAND sysctl -n machdep.cpu.features
                OUTPUT_VARIABLE _cpuinfo OUTPUT_STRIP_TRAILING_WHITESPACE)
	if(_cpuinfo MATCHES "SSE3")
		message(STATUS "Detected SSE3 Support")
		set(SUPPORT_SSE3 1)
	endif()
endif()	
	
