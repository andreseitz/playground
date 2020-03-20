cmake_minimum_required(VERSION 3.10)

# set the project name
project(ExplicitAndImplicit CXX)

set(CMAKE_CXX_STANDARD 11) #98,11,14,17
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS NO)

add_subdirectory(test)
