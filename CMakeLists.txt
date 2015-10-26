cmake_minimum_required (VERSION 2.6)
project (page_fault_measure)
# The version number.
set (PAGE_FAULT_MEASURE_VERSION_MAJOR 0)
set (PAGE_FAULT_MEASURE_VERSION_MINOR 11)
set (PROJECT_SOURCE_DIR src)

configure_file (
  "${PROJECT_SOURCE_DIR}/page_fault_measure.h.in"
  "${PROJECT_BINARY_DIR}/page_fault_measure.h"
  )
include_directories("${PROJECT_BINARY_DIR}")

add_executable(pagefault_measure ${PROJECT_SOURCE_DIR}/pagefault_measure.c)
