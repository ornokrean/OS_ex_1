#include "osm.h"
#include <sys/time.h>

double clac_total_time(unsigned int iterations, const timeval &start, const timeval &end);

int osm_init(){}

int osm_finalizer(){}

double osm_operation_time(unsigned int iterations){
    struct timeval start, end;
    gettimeofday(&start, NULL);
    if (iterations==0){
        iterations=1000;
    }
    for (int i=0; i < iterations; i++){
        1+1;
    }
    gettimeofday(&end, NULL);
    return clac_total_time(iterations, start, end);
}


void func(){}
double osm_function_time(unsigned int iterations){
    if (iterations==0){
        iterations=1000;
    }
    struct timeval start, end;
    gettimeofday(&start, NULL);
    for (int i = 0; i < iterations; ++i)
    {
        func();
    }
    gettimeofday(&end, NULL);
    return clac_total_time(iterations, start, end);

}

double osm_syscall_time(unsigned int iterations){
    if (iterations==0){
        iterations=1000;
    }
    struct timeval start, end;
    gettimeofday(&start, NULL);
    for (int i = 0; i < iterations; ++i)
    {
        OSM_NULLSYSCALL;
    }
    gettimeofday(&end, NULL);
    return clac_total_time(iterations, start, end);
}

double clac_total_time(unsigned int iterations, const timeval &start, const timeval &end)
{
    return double((end.tv_sec * 1000000000 + end.tv_usec * 1000)
                  - (start.tv_sec * 1000000000 + start.tv_usec * 1000)) / iterations;
}
