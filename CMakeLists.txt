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

find_package(Boost COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(pagefault_measure ${PROJECT_SOURCE_DIR}/pagefault_measure.cpp)
set_property(TARGET pagefault_measure PROPERTY CXX_STANDARD 14)

TARGET_LINK_LIBRARIES( pagefault_measure ${Boost_LIBRARIES} )

enable_testing()

add_test( basic pagefault_measure -n --memory 42)
