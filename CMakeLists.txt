cmake_minimum_required(VERSION 3.20.0)
project(test_quic VERSION 0.1.0)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
if(CMAKE_CXX_COMPILER_ID MATCHES MSVC)
  add_compile_options("/permissive-")
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	add_definitions(-DWIN32_LEAN_AND_MEAN -DWIN32)
	add_compile_options(/EHsc)
	set(OTH_LIBRARY ws2_32.lib)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Android")
	add_definitions(-DPF_ANDROID)
	set(OTH_LIBRARY "android" "log")
endif()
message("CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}")
set(CMAKE_CXX_STANDARD 20)

set(COMM_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
find_package(Corrade REQUIRED Main)
find_package(Magnum CONFIG REQUIRED GL Sdl2Application Shaders )
add_subdirectory(triangle)