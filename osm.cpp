#include "osm.h"
#include <sys/time.h>

#define UNROLL_TIMES 5
#define DEFAULT_ITER 1000
#define TIME_FACT 100

double calc_total_time(unsigned int iterations, const timeval &start, const timeval &end);

int osm_init()
{ return 0; }

int osm_finalizer()
{ return 0; }

double osm_operation_time(unsigned int iterations)
{
    struct timeval start, end;
    double test;
    if (iterations == 0)
    {
        iterations = DEFAULT_ITER;
    }
    int x = 0;

    gettimeofday(&start, nullptr);
    for (unsigned int i = 0; i < iterations; i += UNROLL_TIMES)
    {
        x = 1;
        x = 1;
        x = 1;
        x = 1;
        x = 1;
    }
    gettimeofday(&end, nullptr);

    test = calc_total_time(iterations, start, end);

    gettimeofday(&start, nullptr);
    for (unsigned int i = 0; i < iterations; i += UNROLL_TIMES)
    {
        x = 1 + 1;
        x = 1 + 1;
        x = 1 + 1;
        x = 1 + 1;
        x = 1 + 1;
    }
    gettimeofday(&end, nullptr);


    return calc_total_time(iterations, start, end) - test;
}


void func()
{}

double osm_function_time(unsigned int iterations)
{
    struct timeval start, end;
    double test;
    if (iterations == 0)
    {
        iterations = DEFAULT_ITER;
    }
    gettimeofday(&start, nullptr);
    for (unsigned int i = 0; i < iterations; i++)
    {}
    gettimeofday(&end, nullptr);

    test = calc_total_time(iterations, start, end);


    gettimeofday(&start, nullptr);
    for (unsigned int i = 0; i < iterations; i += UNROLL_TIMES)
    {
        func();
        func();
        func();
        func();
        func();
    }
    gettimeofday(&end, nullptr);


    return calc_total_time(iterations, start, end) - test;

}

double osm_syscall_time(unsigned int iterations)
{
    struct timeval start, end;
    double test;
    if (iterations == 0)
    {
        iterations = DEFAULT_ITER;
    }
    gettimeofday(&start, nullptr);
    for (unsigned int i = 0; i < iterations; i++)
    {}
    gettimeofday(&end, nullptr);

    test = calc_total_time(iterations, start, end);


    gettimeofday(&start, nullptr);
    for (unsigned int i = 0; i < iterations; i += UNROLL_TIMES)
    {
        OSM_NULLSYSCALL;;
        OSM_NULLSYSCALL;;
        OSM_NULLSYSCALL;;
        OSM_NULLSYSCALL;;
        OSM_NULLSYSCALL;;
    }
    gettimeofday(&end, nullptr);

    return calc_total_time(iterations, start, end) - test;
}

double calc_total_time(unsigned int iterations, const timeval &start, const timeval &end)
{
    return ((end.tv_sec - start.tv_sec) * 1000000.0
            + (end.tv_usec - start.tv_usec)) * 1000.0 / iterations;
}
