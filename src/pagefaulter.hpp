/*! @file pagefaulter.hpp
 */

#ifndef PAGEFAULT_MEASURE_SRC_PAGEFAULTER_HPP
#define PAGEFAULT_MEASURE_SRC_PAGEFAULTER_HPP

#include <cstddef>

namespace pagefault_measure {
    
    /*! @brief Class to provoke and measure the time duration of a pagefault
     */
    class pagefaulter
    {
    public:
        
        pagefaulter() = delete;
        
        pagefaulter (size_t memory_size_mib);
    };
    
}


#endif /* pagefaulter_hpp */
