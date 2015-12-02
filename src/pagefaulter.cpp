/*! @file pagefaulter.cpp
 */

#include "pagefaulter.hpp"

#include <iostream>
#include <cinttypes>

#include <ccl.h>

namespace pagefault_measure {
    pagefaulter::pagefaulter ():
    memory_size_mib(1),
    cycles(0)
    {
        constexpr unsigned sample_count = 10;
        std::intmax_t cycles = 0;
        for (int i = 0; i < sample_count; i++) {
            cycles += std::imaxabs(rdtsc() - rdtsc());
        }
        this->cycle_calibration_count = cycles / sample_count;
        
        std::cout << "Calibration: Cycles needed to measure cycles: " << cycle_calibration_count << std::endl;
    }

    pagefaulter::pagefaulter (size_t memory_size_mib):
    pagefaulter()
    {
        this->memory_size_mib = memory_size_mib;
    }
    
    void pagefaulter::measure(){
        
    }
    
    pagefaulter::cycle_count_t pagefaulter::cycle_count() const noexcept{
        return cycles;
    }

}