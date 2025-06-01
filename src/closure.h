#ifndef CLOSURE_H
#define CLOSURE_H

#include "allocator.h"

typedef void (*const Closure_Func) (void*, void*);

typedef struct Closure {
    Closure_Func fn;
    void* const env;
} Closure;

/**
 * @brief 
 * @param fn 
 * @param env_size
 * @param alloc
 * @return 
 */
Closure* closure_create(
    Closure_Func fn, 
    void* env, 
    Allocator* alloc
);

Closure* closure_create_env(
    const Closure_Func fn, 
    const size_t env, 
    const Allocator* alloc
);

/**
 * @brief 
 * @param closure
 * @param args
 * @return
 */
void closure_call(
    Closure* closure, 
    void* args
);

/**
 * @brief Frees the closure and the associated environment.
 * @param closure
 * @param allocator
 * @return
 */

void closure_free(
    Closure* closure,
    Allocator* allocator
);

#endif