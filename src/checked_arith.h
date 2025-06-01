#ifndef CHECKED_ARITH_H
#define CHECKED_ARITH_H

// maybe these as a macro for each type (return type is always int)
// arg types are always of the same type
// int type_name_op_behaviour const type, const type, type*
// one macro for unsigned types
// another for signed types
// function bodies go in checked_arith.c
// generic generator function in header for non-precompiled types?

typedef enum Checked_Result {
    NO_ERROR = 0,
    OVERFLOW = 1,
    UNDERFLOW = 2,
    DIVISION_BY_ZERO = 3
} Checked_Result;

typedef Checked_Result (*checked) (
    const size_t x, 
    const size_t y, 
    size_t* res
);

#define UNSIGNED_CHECKED_ARITH_FUNCTIONS(TYPE) \
    typedef Checked_Result (*checked##_TYPE) (const TYPE x, const TYPE y, TYPE* res); \
    \
    checked##_TYPE TYPE##_add; \
    checked##_TYPE TYPE##_add_sat; \
    checked##_TYPE TYPE##_add_wrap; \
    \
    checked##_TYPE TYPE##_sub; \
    checked##_TYPE TYPE##_sub_sat; \
    checked##_TYPE TYPE##_sub_wrap; \
    \
    checked##_TYPE TYPE##_mul; \
    checked##_TYPE TYPE##_mul_sat; \
    checked##_TYPE TYPE##_mul_wrap; \
    \
    checked##_TYPE TYPE##_div; \
    checked##_TYPE TYPE##_div_sat; \
    checked##_TYPE TYPE##_div_wrap; \
    \
    checked##_TYPE TYPE##_mod;
    

UNSIGNED_CHECKED_ARITH_FUNCTIONS(size_t);



#endif