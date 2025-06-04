#include "allocator.h"
#include <stdlib.h>


PREDEF_INLINE_C(P_ALLOCATOR_ALLOC_SIG, P_ALLOCATOR_ALLOC_BODY)
PREDEF_INLINE_C(P_ALLOCATOR_FREE_SIG, P_ALLOCATOR_FREE_BODY)


void* default_malloc_func(const size_t size, void* context) {
    (void)context;
    return malloc(size);
}

void default_free_func(const void* ptr, void* context) {
    (void)context;
    free((void*)ptr);
}

Allocator g_default_allocator = {
    .alloc = default_malloc_func,
    .free = default_free_func,
    .context = NULL
};