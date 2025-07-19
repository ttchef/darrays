
#include "include/darray/da_array.h"
#include <stdio.h> 

#include <darray/darray.h>

int main() {

    printf("Hello World\n");

    da_Array_uint *array1 = da_array_uint_init(2);

    for (size_t i = 0; i < 10; i++) {
        da_array_uint_push_back(array1, i);
    }

    da_array_uint_print(array1);

    da_array_uint_free(array1);

    return 0;
}
