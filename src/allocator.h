#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stddef.h>

typedef struct Allocator Allocator;


/**
 * @brief Function pointer type for memory allocation.
 * @param context A user-defined pointer passed to the allocator.
 * @param size The number of bytes to allocate.
 * @return A pointer to the allocated memory, or NULL on failure.
 */
typedef void* (*Alloc_Func)(void* context, size_t size);

/**
 * @brief Function pointer type for memory deallocation.
 * @param context A user-defined pointer passed to the allocator.
 * @param ptr A pointer to the memory to deallocate.
 */
typedef void (*Free_Func)(void* context, void* ptr);

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

inline void* allocator_alloc(
    Allocator* allocator, 
    size_t size
) {
    return allocator->alloc(allocator->context, size);
}

inline void allocator_free(
    Allocator* allocator, 
    void* ptr
) {
    allocator->free(allocator->context, ptr);
}

// --- Convenience functions for default C standard library allocator ---

// These functions simply wrap malloc and free, ignoring the context
void* default_malloc_func(void* context, size_t size);
void default_free_func(void* context, void* ptr);

// A globally available default allocator instance using malloc/free
// Defined in allocator.c
extern Allocator g_default_allocator;

#endif