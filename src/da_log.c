
#include <stdio.h>

#include "../include/darray/da_log.h"

da_ErrorInfo da_last_error = {0};
bool da_error_log_enable = true;
da_ErrorCallback da_error_callback = da_default_error_callback;

void da_default_error_callback(const da_ErrorInfo *error) {
    printf("Error in %s:%d (%s): %s - %s\n",
            error->file_name,
            error->line_number,
            error->function_name,
            da_error_string(error->error_code),
            error->message
            );
}

const char* da_error_string(DA_RESULT result) {
    switch (result) {
        case DA_UNDEFINED:          return "Undefinied";
        case DA_OK:                 return "Success";
        case DA_ERROR:              return "General Error";
        case DA_INVALID_SIZE:       return "Invalid Array Size";
        case DA_ALLOC_FAIL:         return "Allocating Fail";
        case DA_INVALID_INPUT:      return "Invalid Input";
        default:                    return "Unkown Error";
    }
}

void da_enable_error_log(bool enable) {
    da_error_log_enable = enable;
}

void da_set_error_callback(da_ErrorCallback callback) {
    da_error_callback = callback;
}

const da_ErrorInfo *da_get_last_error() {
    return &da_last_error;    
}

void da_clear_last_error() {
    da_last_error.error_code = DA_UNDEFINED;
    da_last_error.file_name = 0;
    da_last_error.function_name = 0;
    da_last_error.line_number = 0;
}

