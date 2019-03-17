//
// Created by Erez on 17-Mar-19.
//

#include <sys/time.h>
#include "osm.h"
int osm_init(){}
int osm_finalizer(){}

double osm_operation_time(unsigned int iterations){
    for (int i=0; i < iterations; i++){
        1+1;
    }
}
void func(){
    return;
}
double osm_function_time(unsigned int iterations){
    for (int i = 0; i < iterations; ++i)
    {
        func();
    }
}

double osm_syscall_time(unsigned int iterations){

    for (int i = 0; i < iterations; ++i)
    {
        OSM_NULLSYSCALL;
    }
}

