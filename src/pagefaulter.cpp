/*! @file pagefaulter.cpp
 */

#include "pagefaulter.hpp"

#include <iostream>
#include <cstdlib>

#include <ccl.h>

namespace pagefault_measure {

    pagefaulter::pagefaulter (size_t memory_size_mib){
        std::intmax_t cycles = rdtsc() - rdtsc();
        std::cout << "Calibration: Cycles needed to measure cycles: " << std::abs(cycles) << std::endl;
    }

}