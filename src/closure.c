#include "closure.h"
#include "checked_arith.h"

Closure* closure_create(
    Closure_Func fn, 
    size_t env_size, 
    Allocator* alloc
) {
    //size_t closure_size = sizeof(Closure) + env_size;
    size_t closure_size;
    int overflowed = size_t_add_checked(
        sizeof(Closure), env_size, &closure_size
    );
    if (overflowed) {
        return NULL;
    }
    
}