#include <iostream>
#include <sys/time.h>
#include "osm.h"
#include <chrono>
#include <thread>

int main()
{
    unsigned int iter = 1000000;
    printf("%f\n",osm_operation_time(iter));
    printf("%f\n",osm_function_time(iter));
    printf("%f",osm_syscall_time(iter));
}