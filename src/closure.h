#ifndef CLOSURE_H
#define CLOSURE_H

#include "allocator.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*Closure_Func) (void* env, void* args);
typedef struct Closure Closure;

/**
 * @brief 
 * @param fn
 * @param env_size The size of the environment in bytes to allocate. A size of zero will not allocate.
 * @param allocator 
 * @return
 */
Closure* closure_create(
    const Closure_Func fn, 
    const size_t env_size, 
    const Allocator* allocator
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



#ifdef __cplusplus
}
#endif

#endif