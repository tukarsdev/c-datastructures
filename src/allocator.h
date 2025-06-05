#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stddef.h>
#include "c_standard.h"
#include "extern_c.h"

EXTERN_C_START

typedef struct Allocator Allocator;


/**
 * @brief Function pointer type for memory allocation.
 * @param size The number of bytes to allocate.
 * @param context A user-defined pointer passed to the allocator.
 * @return A pointer to the allocated memory, or NULL on failure.
 */
typedef void* (*Alloc_Func)(const size_t size, void* context);

/**
 * @brief Function pointer type for memory deallocation.
 * @param ptr A pointer to the memory to deallocate.
 * @param context A user-defined pointer passed to the allocator.
 */
typedef void (*Free_Func)(const void* ptr, void* context);

/**
 * @brief Structure representing a generic memory allocator.
 *
 * This struct encapsulates the allocation and deallocation functions,
 * along with an optional user-defined context pointer that can be
 * passed to the allocation/deallocation routines.
 */
struct Allocator {
    Alloc_Func alloc;
    Free_Func  free;
    void*      context;
};

#define P_ALLOCATOR_ALLOC_SIG \
void* allocator_alloc( \
    const Allocator* allocator, \
    const size_t size \
)

#define P_ALLOCATOR_ALLOC_BODY \
    { return allocator->alloc(size, allocator->context); }

C_STANDARD_INLINE_H(P_ALLOCATOR_ALLOC_SIG, P_ALLOCATOR_ALLOC_BODY)

#define P_ALLOCATOR_FREE_SIG \
void allocator_free( \
    const Allocator* allocator, \
    const void* ptr \
) 

#define P_ALLOCATOR_FREE_BODY \
    { allocator->free(ptr, allocator->context); }

C_STANDARD_INLINE_H(P_ALLOCATOR_FREE_SIG, P_ALLOCATOR_FREE_BODY)

/* --- Convenience functions for default C standard library allocator --- */

/* These functions simply wrap malloc and free, ignoring the context */

void* default_malloc_func(const size_t size, void* context);
void default_free_func(const void* ptr, void* context);

/* A globally available default allocator instance using malloc/free */
/* Defined in allocator.c */
extern Allocator g_default_allocator;

EXTERN_C_END
#endif