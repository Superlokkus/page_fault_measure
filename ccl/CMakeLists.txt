#Cmake project file for the library to measure the cylces used for the part of a program
#Author of this cmake file: Markus Klemm markusklemm.net
#Author of the library: Prof. Dr.-Ing. Robert Baumgartl http://www2.htw-dresden.de/~robge/ezs/prak/src/ccl.tar.gz

cmake_minimum_required (VERSION 2.6)
project (cycle_count_library
)

add_library(ccl ccl.h ccl.c)

target_include_directories(ccl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
