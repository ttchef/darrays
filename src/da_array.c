
#include "../include/darray/da_array.h"
#include "../include/darray/da_log.h"

da_Array_uint *da_array_uint_init(size_t size) {
    if (size <= 0) {
        DA_SET_ERROR(DA_INVALID_SIZE, "Input Size is smaller equal to 0!");
    } 
}

void da_array_uint_free(da_Array_uint *array) {
    if (array) {
        free(array);
        array = NULL;
    }
}

