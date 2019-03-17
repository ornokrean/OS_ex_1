#include "osm.h"
#include <sys/time.h>

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
    return double((end.tv_sec * 1000000000 + end.tv_usec * 1000)
                            - (start.tv_sec * 1000000000 + start.tv_usec * 1000))/iterations;
}

void func(){}
double osm_function_time(unsigned int iterations){
    if (iterations==0){
        iterations=1000;
    }
    for (int i = 0; i < iterations; ++i)
    {
        func();
    }

}

double osm_syscall_time(unsigned int iterations){
    if (iterations==0){
        iterations=1000;
    }
    for (int i = 0; i < iterations; ++i)
    {
        OSM_NULLSYSCALL;
    }
}

