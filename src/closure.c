#include "closure.h"
#include "checked_arith.h"

struct Closure {
    Closure_Func fn;
    void* env;
};


Closure* closure_create(
    const Closure_Func fn, 
    const size_t env_size, 
    const Allocator*  allocator
) {
    Closure* closure;
    void* envp = NULL;
    
    if (env_size > 0) {
        envp = allocator_alloc(allocator, env_size);
        if (!envp) { return NULL; }
    }
    
    closure = (Closure*)allocator_alloc(allocator, sizeof(Closure));
    
    if (!closure) {
        if (env_size > 0) {
            allocator_free(allocator, envp);
        }
        return NULL;
    }
    
    closure->fn = fn;
    closure->env = envp;
    
    return closure;
}

void closure_call(
    Closure* closure,
    void* args
) {
    closure->fn(closure->env, args);
}

void closure_free(
    Closure* closure,
    Allocator* allocator
) {
    if (closure->env) {
        allocator_free(allocator, closure->env);
    }
    allocator_free(allocator, closure);
}