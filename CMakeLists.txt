cmake_minimum_required (VERSION 2.6)
project (page_fault_measure)
# The version number.
set (page_fault_measure_VERSION_MAJOR 0)
set (page_fault_measure_VERSION_MINOR 1)
add_executable(bin/pagefault_measure src/pagefault_measure.c)
