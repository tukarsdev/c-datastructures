#include "allocator.h"
#include <stdlib.h>

void* default_malloc_func(void* context, size_t size) {
    (void)context;
    return malloc(size);
}

void default_free_func(void* context, void* ptr) {
    (void)context;
    free(ptr);
}

g_default_allocator = {
    .alloc = default_malloc_func,
    .free = default_free_func,
    .context = NULL
};