
#include "../include/darray/da_array.h"
#include "../include/darray/da_log.h"

da_Array_uint *da_array_uint_init(size_t size) {
    if (size <= 0) {
        DA_SET_ERROR(DA_INVALID_SIZE, "Input Size is smaller equal to 0!");
        return NULL;
    } 

    da_Array_uint* array = (da_Array_uint*)malloc(sizeof(da_Array_uint));
    if (!array) {
        DA_SET_ERROR(DA_ALLOC_FAIL, "Failed to allocate array struct");
        return NULL;
    }

    array->data = (uint32_t*)malloc(sizeof(uint32_t) * size);
    if (!array->data) {
        DA_SET_ERROR(DA_ALLOC_FAIL, "Failed to allocate array data array");
        return NULL;
    }

    array->capacity = size;
    array->size = size;

    da_array_uint_fill(array, 0);

    return array;
}

void da_array_uint_free(da_Array_uint *array) {
    if (array) {
        free(array);
        array = NULL;
    }
}

void da_array_uint_push_back(da_Array_uint *array, uint32_t value) {
    if (!array) {
        DA_SET_ERROR(DA_INVALID_INPUT, "Input Array is NULL");
        return;
    }

    if (array->size + 1 >= array->capacity) {
        size_t new_capacity = array->capacity * 2;
        uint32_t* new_data = (uint32_t*)realloc(array->data, sizeof(uint32_t) *sizeof(uint32_t) * new_capacity);
        if (!new_data) {
            DA_SET_ERROR(DA_ALLOC_FAIL, "Failed to realloc array data!");
            return;
        }
        array->data = new_data;
        array->capacity = new_capacity;

        array->data[array->size] = value;
        array->size++;
    }
    else {
        array->data[array->size] = value;
        array->size++;
    }
}

void da_array_uint_print(da_Array_uint *array) {
    if (!array) {
        DA_SET_ERROR(DA_INVALID_INPUT, "Input Array is NULL");
        return;
    }

    printf("==Print Array==\n");
    for (size_t i = 0; i < array->size; i++) {
        printf("%ld: %d\n", i, array->data[i]);
    }   
}

void da_array_uint_fill(da_Array_uint *array, uint32_t value) {
    if (!array) {
        DA_SET_ERROR(DA_INVALID_INPUT, "Input Array is NULL");
        return;
    }

    for (size_t i = 0; i < array->capacity; i++) {
        array->data[i] = value;
    }
}
