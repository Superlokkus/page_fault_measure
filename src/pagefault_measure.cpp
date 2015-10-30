#include <iostream>

#include <boost/program_options.hpp>

#include "pagefault_measure.h"

int main(int argc, char** args)
{
    //printf("pagefaulter %d\n",PAGEFAULT_MEASURE_VERSION_MINOR);
    
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
        std::cout << "Memory size was set to "
        << vm["memory"].as<size_t>() << " MiB\n";
    }
    
    return 0;
}
