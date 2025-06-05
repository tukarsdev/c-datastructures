#ifndef ARRAY_H
#define ARRAY_H

#include "checked_arith.h"
#include "extern_c.h"

EXTERN_C_START

typedef struct Array {
    size_t len;
    size_t capacity;
    unsigned char* data;
} Array;

Array* array_new() {
    return (Array*)0;
}


EXTERN_C_END
#endif
