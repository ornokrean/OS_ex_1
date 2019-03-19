#include "osm.h"
#include <sys/time.h>
#include <cmath>

#define UNROLL_TIMES 10
#define DEFAULT_ITER 1000
#define SEC_FACT 1000000000L
#define USEC_FACT 1000L
#define ERROR_CODE 1

double calc_total_time(unsigned int iterations, const timeval &start, const timeval &end);

unsigned int check_iterations(unsigned int iterations);

int osm_init()
{ return 0; }

int osm_finalizer()
{ return 0; }

double osm_operation_time(unsigned int iterations)
{
    iterations = check_iterations(iterations);
    struct timeval start, end;
    double x = 0;
    if (gettimeofday(&start, nullptr))
    {
        return ERROR_CODE;
    }
    for (unsigned int i = 0; i < iterations; i += UNROLL_TIMES)
    {
        x = 1 + 1;
        x = 1 + 1;
        x = 1 + 1;
        x = 1 + 1;
        x = 1 + 1;
        x = 1 + 1;
        x = 1 + 1;
        x = 1 + 1;
        x = 1 + 1;
        x = 1 + 1;
    }
    if (gettimeofday(&end, nullptr))
    {
        return ERROR_CODE;
    }
    // avoid compiler issues:
    x = 0;
    iterations += (unsigned int) x;

    return calc_total_time(iterations, start, end);
}


void func()
{}

double osm_function_time(unsigned int iterations)
{

    iterations = check_iterations(iterations);
    struct timeval start, end;

    if (gettimeofday(&start, nullptr))
    {
        return ERROR_CODE;
    }
    for (unsigned int i = 0; i < iterations; i += UNROLL_TIMES)
    {
        func();
        func();
        func();
        func();
        func();
        func();
        func();
        func();
        func();
        func();
    }

    if (gettimeofday(&end, nullptr))
    {
        return ERROR_CODE;
    }
    return calc_total_time(iterations, start, end);
}



double osm_syscall_time(unsigned int iterations)
{
    iterations = check_iterations(iterations);
    struct timeval start, end;
    if (gettimeofday(&start, nullptr))
    {
        return ERROR_CODE;
    }
    for (unsigned int i = 0; i < iterations; i += UNROLL_TIMES)
    {
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
    }
    if (gettimeofday(&end, nullptr))
    {
        return ERROR_CODE;
    }
    return calc_total_time(iterations, start, end);
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
    return double(((end.tv_sec - start.tv_sec) * SEC_FACT) +
                  ((end.tv_usec - start.tv_usec) * USEC_FACT)) / double(iterations);
}

/**
 * this function validates the iteration given
 * @param iterations the iterations to check
 * @return a non-zero, round-up iteration number.
 */
unsigned int check_iterations(unsigned int iterations)
{
    if (iterations == 0)
    {
        iterations = DEFAULT_ITER;
    }
    if (iterations % UNROLL_TIMES)
    {
        iterations += UNROLL_TIMES - (iterations % UNROLL_TIMES);
    }
    return iterations;
}