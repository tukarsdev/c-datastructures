#ifndef ARRAY_H
#define ARRAY_H

#include "checked_arith.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Array {
    size_t len;
    size_t capacity;
    unsigned char* data;
} Array;

Array* array_new() {
    return (Array*)0;
}


#ifdef __cplusplus
}
#endif

#endif