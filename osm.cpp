#include "osm.h"
#include <sys/time.h>

double calc_total_time(unsigned int iterations, const timeval &start, const timeval &end);

int osm_init()
{ return 0;}

int osm_finalizer()
{ return 0;}

double osm_operation_time(unsigned int iterations)
{
    struct timeval start, end;
    gettimeofday(&start, nullptr);
    if (iterations == 0)
    {
        iterations = 1000;
    }
    for (unsigned int i = 0; i < iterations; i+=5)
    {
        1 + 1;
        1 + 1;
        1 + 1;
        1 + 1;
        1 + 1;
    }
    gettimeofday(&end, nullptr);
    return calc_total_time(iterations, start, end);
}


void func()
{}

double osm_function_time(unsigned int iterations)
{
    if (iterations == 0)
    {
        iterations = 1000;
    }
    struct timeval start, end;
    gettimeofday(&start, nullptr);
    for (unsigned int i = 0; i < iterations; i+=5)
    {
        func();
        func();
        func();
        func();
        func();
    }
    gettimeofday(&end, nullptr);
    return calc_total_time(iterations, start, end);

}

double osm_syscall_time(unsigned int iterations)
{
    if (iterations == 0)
    {
        iterations = 1000;
    }
    struct timeval start, end;
    gettimeofday(&start, nullptr);
    for (unsigned int i = 0; i < iterations; i+=5)
    {
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
    }
    gettimeofday(&end, nullptr);
    return calc_total_time(iterations, start, end);
}

double calc_total_time(unsigned int iterations, const timeval &start, const timeval &end)
{
    return double((end.tv_sec * 1000000000 + end.tv_usec * 1000)
                  - (start.tv_sec * 1000000000 + start.tv_usec * 1000)) / iterations;
}
