//
// Created by Erez on 17-Mar-19.
//

#include "osm.h"
#include <sys/time.h>

int osm_init(){

}
int osm_finalizer(){}

double osm_operation_time(unsigned int iterations){
    if (iterations==0){
        iterations=1000;
    }
    for (int i=0; i < iterations; i++){
        1+1;
    }
}

void func(){
    return;
}
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

