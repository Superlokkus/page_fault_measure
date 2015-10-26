cmake_minimum_required (VERSION 2.6)
project (pagefault_measure)
# The version number.
set (PAGEFAULT_MEASURE_VERSION_MAJOR 0)
set (PAGEFAULT_MEASURE_VERSION_MINOR 11)
set (PROJECT_SOURCE_DIR src)

configure_file (
  "${PROJECT_SOURCE_DIR}/pagefault_measure.h.in"
  "${PROJECT_BINARY_DIR}/pagefault_measure.h"
  )
include_directories("${PROJECT_BINARY_DIR}")

add_executable(pagefault_measure ${PROJECT_SOURCE_DIR}/pagefault_measure.c)

enable_testing()

add_test( basic pagefault_measure )
