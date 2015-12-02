/*! @file pagefaulter.hpp
 */

#ifndef PAGEFAULT_MEASURE_SRC_PAGEFAULTER_HPP
#define PAGEFAULT_MEASURE_SRC_PAGEFAULTER_HPP

#include <cstddef>
#include <cstdint>

namespace pagefault_measure {
    
    /*! @brief Class to provoke and measure the time duration of a pagefault
     */
    class pagefaulter
    {
    public:
        typedef uintmax_t cycle_count_t;
        
        pagefaulter();
        
        pagefaulter (size_t memory_size_mib);
        
        void measure();
        
        cycle_count_t cycle_count() const noexcept;
    private:
        size_t memory_size_mib;
        cycle_count_t cycle_calibration_count;
        cycle_count_t cycles;
    };
    
}


#endif /* pagefaulter_hpp */
