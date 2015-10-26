#include <stdio.h>
#include "page_fault_measure.h"

int main(int argc, char** args)
{
    printf("pagefaulter %d\n",PAGE_FAULT_MEASURE_VERSION_MINOR);
    return 0;
}