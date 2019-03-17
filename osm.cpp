//
// Created by Erez on 17-Mar-19.
//

#include "osm.h"
#include <sys/time.h>

int osm_init(){

}
int osm_finalizer(){


}

double osm_operation_time(unsigned int iterations){
    struct timeval start;
    gettimeofday(&start, NULL);
    if (iterations==0){
        iterations=1000;
    }
    for (int i=0; i < iterations; i++){
        1+1;
    }
    struct timeval  end;

    gettimeofday(&end, NULL);
    return (end.tv_sec * 1000000 + end.tv_usec)
                            - (start.tv_sec * 1000000 + start.tv_usec);
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

