#include <iostream>
#include <sys/time.h>
#include "osm.h"

int main()
{

    printf("%f\n",osm_operation_time(1000));
    printf("%f\n",osm_function_time(1000));
    printf("%f",osm_syscall_time(1000));

}