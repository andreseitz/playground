cmake_minimum_required(VERSION 3.10)
project(ExampleExportedGlobals)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(library)
add_subdirectory(binary)
