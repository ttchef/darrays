
#ifndef DA_ARRAY_H
#define DA_ARRAY_H

#include <stdint.h>
#include <stdlib.h>

// watch out very unsafe
#define CARRAY_COUNT(array) (sizeof(array) / sizeof(array[0]))

typedef struct {
    uint32_t *data;
    size_t size;
    size_t capacity;
} da_Array_uint;

da_Array_uint *da_array_uint_init(size_t size);
void da_array_uint_free(da_Array_uint *array);

void da_array_uint_push_back(da_Array_uint *array, uint32_t value);
uint32_t da_array_uint_pop(da_Array_uint *array);
void da_array_uint_print(da_Array_uint *array);
void da_array_uint_fill(da_Array_uint *array, uint32_t value);

void da_array_uint_assign_carray(da_Array_uint *array, uint32_t *carray, size_t size);
void da_array_uint_push_back_carray(da_Array_uint *array, uint32_t *carray, size_t size);

#endif

