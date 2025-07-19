
#ifndef DA_LOG_H
#define DA_LOG_H 

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef enum {
    DA_UNDEFINED = 1,
    DA_OK = 0,
    DA_ERROR = -1,
    DA_INVALID_SIZE,
} DA_RESULT;

typedef struct {
    DA_RESULT error_code;
    const char* function_name;
    const char* file_name;
    int line_number;
    char message[256];
} da_ErrorInfo;

typedef void (*da_ErrorCallback)(const da_ErrorInfo *error);

extern da_ErrorInfo da_last_error;
extern bool da_error_log_enable;
extern da_ErrorCallback da_error_callback; 

#define DA_SET_ERROR(code, msg, ...) \
    do { \
        if (da_error_log_enable) { \
            da_last_error.error_code = code; \
            da_last_error.function_name = __func__; \
            da_last_error.file_name = __FILE__; \
            da_last_error.line_number = __LINE__; \
            snprintf(da_last_error.message, sizeof(da_last_error.message), msg, ##__VA_ARGS__); \
            if (da_error_callback) da_error_callback(&da_last_error); \
        } \
    } while(0)

void da_default_error_callback(const da_ErrorInfo *error);
void da_set_error_callback(da_ErrorCallback callback);
void da_enable_error_log(bool enable);
const da_ErrorInfo *da_get_last_error();
void da_clear_last_error();
const char* da_error_string(DA_RESULT result);

#endif
