#include "osm.h"
#include <sys/time.h>
#include <cmath>
#include <iostream>


#define UNROLL_TIMES 5
#define DEFAULT_ITER 1000
#define SEC_FACT 1000000000L
#define USEC_FACT 1000L
//FIXME

double calc_total_time(unsigned int iterations, const timeval &start, const timeval &end);

int osm_init()
{ return 0; }

int osm_finalizer()
{ return 0; }

double osm_operation_time(unsigned int iterations)
{
    if (iterations == 0)
    {
        iterations = DEFAULT_ITER;
    }
    struct timeval start, end;
    double total = 0;
    int x = 0;
    for (unsigned int i = 0; i < iterations; i += UNROLL_TIMES)
    {
        gettimeofday(&start, nullptr);
        x++;
        x++;
        x++;
        x++;
        x++;
        gettimeofday(&end, nullptr);
        total += calc_total_time(iterations, start, end);
    }

    return total / double(iterations);
}


void func_to_call()
{}

double osm_function_time(unsigned int iterations)
{
    if (iterations == 0)
    {
        iterations = DEFAULT_ITER;
    }
    struct timeval start, end;
    double total = 0;

    for (unsigned int i = 0; i < iterations; i += UNROLL_TIMES)
    {
        gettimeofday(&start, nullptr);
        func_to_call();
        func_to_call();
        func_to_call();
        func_to_call();
        func_to_call();
        gettimeofday(&end, nullptr);
        total += calc_total_time(iterations, start, end);
    }

    return total / double(iterations);
}

double osm_syscall_time(unsigned int iterations)
{
    if (iterations == 0)
    {
        iterations = DEFAULT_ITER;
    }
    struct timeval start, end;
    double total = 0;
    for (unsigned int i = 0; i < iterations; i += UNROLL_TIMES)
    {
        gettimeofday(&start, nullptr);
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        gettimeofday(&end, nullptr);
        total += calc_total_time(iterations, start, end);
    }

    return total / double(iterations);
}

/**
 * This function calculates the time difference between end and start.
 * @param iterations the number of iterations made in the time par, we will divide by it
 * @param start the start timestamp, a timeval
 * @param end the end timestamp, a timeval
 * @return double- the time difference
 */
double calc_total_time(unsigned int iterations, const timeval &start, const timeval &end)
{
    return double(((end.tv_sec - start.tv_sec) * USEC_FACT) +
                  ((end.tv_usec - start.tv_usec)));
}
