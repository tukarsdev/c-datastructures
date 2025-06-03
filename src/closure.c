#include "closure.h"
#include "checked_arith.h"

typedef void (*Closure_Func_NC) (void*, void*);

Closure* closure_create(
    const Closure_Func fn, 
    const void* env, 
    const Allocator* alloc
) {
    Closure* closure;
    
    closure = (Closure*)allocator_alloc(alloc, sizeof(Closure));
    if (!closure) { return NULL; }
    (Closure_Func_NC)closure->fn = fn;
    (void*)closure->env = env;
    
    return closure;
}

Closure* closure_create_env(
    const Closure_Func fn, 
    const size_t env, 
    const Allocator* alloc
) {
    Closure* closure;
    void* envp;
    
    envp = allocator_alloc(alloc, env);
    if (!envp) { return NULL; }
    closure = closure_create(fn, envp, alloc);
    if (!closure) {
        alloc_free(alloc, envp);
        return NULL;
    }
    
    return closure;
}