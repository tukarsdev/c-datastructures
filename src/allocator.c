#include "allocator.h"
#include <stdlib.h>

void* default_malloc_func(const size_t size, void* context) {
    (void)context;
    return malloc(size);
}

void default_free_func(const void* ptr, void* context) {
    (void)context;
    free((void*)ptr);
}

void* allocator_alloc(
    const Allocator* allocator,
    const size_t size
) {
    return allocator->alloc(size, allocator->context);
}

void allocator_free(
    const Allocator* allocator,
    const void* ptr
) {
    allocator->free(ptr, allocator->context);
}

Allocator g_default_allocator = {
    .alloc = default_malloc_func,
    .free = default_free_func,
    .context = NULL
};