#include <iostream>
#include <cmath>

#include <boost/program_options.hpp>

#include "pagefault_measure.h"
#include "getMemorySize.hpp"
#include "pagefaulter.hpp"

int main(int argc, char** args)
{
    
    size_t memory_size = 0;
    
    namespace po = boost::program_options;
    po::options_description desc("Allowed options");
    desc.add_options()
    ("help,h", "produce help message")
    ("memory,m", po::value<size_t>(), "set assumed physical memory amount in mebibytes")
    ("dry_mode,n", "dry mode, will not actually allocate memory")
    ;
    
    po::positional_options_description p;
    p.add("memory", -1);
    
    po::variables_map vm;
    po::store(po::command_line_parser(argc, args).
              options(desc).positional(p).run(), vm);
    po::notify(vm);
    
    
    if (vm.count("help")) {
        std::cout << desc << "\n";
        return EXIT_FAILURE;
    }
    
    if (vm.count("memory")) {
        memory_size = vm["memory"].as<size_t>();
        std::cout << "Memory size was set to "
        << memory_size << " MiB\n";
    } else{
        std::cout << "Memory size was not set trying to auto detect memory size\n";
        memory_size = getMemorySize() / std::pow(2,20);
        if (memory_size == 0){
            std::cout << "Could not determine memory size\n";
            return EXIT_FAILURE;
        } else{
            std::cout << "Memory size was set to " << memory_size << " MiB\n";
        }
    }
    
    pagefault_measure::pagefaulter foo{memory_size};
    
    return 0;
}
