
#include <stdio.h> 

#include <darray/darray.h>

int main() {

    printf("Hello World\n");

    da_Array_uint *array1 = da_array_uint_init(2);

    for (size_t i = 0; i < 10; i++) {
        da_array_uint_push_back(array1, i);
    }

    uint32_t value = da_array_uint_pop(array1);
    da_array_uint_print(array1);


    da_Array_uint *array2 = da_array_uint_init(1);
    uint32_t carray[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
    da_array_uint_assign_carray(array2, carray, 8);
    da_array_uint_print(array2);
        
    da_array_uint_free(array1);
    da_array_uint_free(array2);

    return 0;
}
