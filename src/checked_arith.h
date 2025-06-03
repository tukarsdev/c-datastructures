#ifndef CHECKED_ARITH_H
#define CHECKED_ARITH_H

// TODO: REMOVE
#define CHECKED_ARITH_INCLUDE_STDINT_H

#include "c_standard.h"
#include <stddef.h>
#ifdef CHECKED_ARITH_INCLUDE_STDINT_H
    #include <stdint.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef enum Checked_Result {
    NO_ERROR = 0,
    OVERFLOW = 1,
    UNDERFLOW = 2,
    DIVISION_BY_ZERO = 3
} Checked_Result;


#define P_CHECKED_ARITH_UNSIGNED_DEF(TYPE, FUNC_NAME) \
    typedef Checked_Result (*checked_arith_f_##FUNC_NAME) ( \
        const TYPE x, \
        const TYPE y, \
        TYPE* res \
    ); \
    \
    checked_arith_f_##FUNC_NAME FUNC_NAME##_add; \
    checked_arith_f_##FUNC_NAME FUNC_NAME##_add_sat; \
    checked_arith_f_##FUNC_NAME FUNC_NAME##_add_wrap; \
    \
    checked_arith_f_##FUNC_NAME FUNC_NAME##_sub; \
    checked_arith_f_##FUNC_NAME FUNC_NAME##_sub_sat; \
    checked_arith_f_##FUNC_NAME FUNC_NAME##_sub_wrap; \
    \
    checked_arith_f_##FUNC_NAME FUNC_NAME##_mul; \
    checked_arith_f_##FUNC_NAME FUNC_NAME##_mul_sat; \
    checked_arith_f_##FUNC_NAME FUNC_NAME##_mul_wrap; \
    \
    checked_arith_f_##FUNC_NAME FUNC_NAME##_div; \
    \
    checked_arith_f_##FUNC_NAME FUNC_NAME##_mod; \
\

#define P_CHECKED_ARITH_SIGNED_DEF(TYPE, FUNC_NAME) \
    P_CHECKED_ARITH_UNSIGNED_DEF(TYPE, FUNC_NAME) \
    \
    checked_arith_f_##FUNC_NAME FUNC_NAME##_div_sat; \
    checked_arith_f_##FUNC_NAME FUNC_NAME##_div_wrap; \
    \
    checked_arith_f_##FUNC_NAME FUNC_NAME##_mod_pos; \
\


P_CHECKED_ARITH_UNSIGNED_DEF(unsigned char, unsigned_char);
P_CHECKED_ARITH_UNSIGNED_DEF(unsigned short, unsigned_short);
P_CHECKED_ARITH_UNSIGNED_DEF(unsigned int, unsigned_int);
P_CHECKED_ARITH_UNSIGNED_DEF(unsigned long, unsigned_long);
P_CHECKED_ARITH_UNSIGNED_DEF(size_t, size_t);
#if defined(PREDEF_STANDARD_C99)
    P_CHECKED_ARITH_UNSIGNED_DEF(unsigned long long, unsigned_long_long);
#endif
#ifdef CHECKED_ARITH_INCLUDE_STDINT_H
    P_CHECKED_ARITH_UNSIGNED_DEF(uint8_t, uint8_t);
    P_CHECKED_ARITH_UNSIGNED_DEF(uint16_t, uint16_t);
    P_CHECKED_ARITH_UNSIGNED_DEF(uint32_t, uint32_t);
    P_CHECKED_ARITH_UNSIGNED_DEF(uint64_t, uint64_t);
    P_CHECKED_ARITH_UNSIGNED_DEF(uint_least8_t, uint_least8_t);
    P_CHECKED_ARITH_UNSIGNED_DEF(uint_least16_t, uint_least16_t);
    P_CHECKED_ARITH_UNSIGNED_DEF(uint_least32_t, uint_least32_t);
    P_CHECKED_ARITH_UNSIGNED_DEF(uint_least64_t, uint_least64_t);
    P_CHECKED_ARITH_UNSIGNED_DEF(uint_fast8_t, uint_fast8_t);
    P_CHECKED_ARITH_UNSIGNED_DEF(uint_fast16_t, uint_fast16_t);
    P_CHECKED_ARITH_UNSIGNED_DEF(uint_fast32_t, uint_fast32_t);
    P_CHECKED_ARITH_UNSIGNED_DEF(uint_fast64_t, uint_fast64_t);
    P_CHECKED_ARITH_UNSIGNED_DEF(uintptr_t, uintptr_t);
    P_CHECKED_ARITH_UNSIGNED_DEF(uintmax_t, uintmax_t);
#endif

P_CHECKED_ARITH_UNSIGNED_DEF(signed char, signed_char);
P_CHECKED_ARITH_UNSIGNED_DEF(short int, short_int);
P_CHECKED_ARITH_UNSIGNED_DEF(int, int);
P_CHECKED_ARITH_UNSIGNED_DEF(long int, long_int);

#if defined(PREDEF_STANDARD_C99)
    P_CHECKED_ARITH_UNSIGNED_DEF(long long int, long_long_int);
#endif
#ifdef CHECKED_ARITH_INCLUDE_STDINT_H
    P_CHECKED_ARITH_UNSIGNED_DEF(int8_t, int8_t);
    P_CHECKED_ARITH_UNSIGNED_DEF(int16_t, int16_t);
    P_CHECKED_ARITH_UNSIGNED_DEF(int32_t, int32_t);
    P_CHECKED_ARITH_UNSIGNED_DEF(int64_t, int64_t);
    P_CHECKED_ARITH_UNSIGNED_DEF(int_least8_t, int_least8_t);
    P_CHECKED_ARITH_UNSIGNED_DEF(int_least16_t, int_least16_t);
    P_CHECKED_ARITH_UNSIGNED_DEF(int_least32_t, int_least32_t);
    P_CHECKED_ARITH_UNSIGNED_DEF(int_least64_t, int_least64_t);
    P_CHECKED_ARITH_UNSIGNED_DEF(int_fast8_t, int_fast8_t);
    P_CHECKED_ARITH_UNSIGNED_DEF(int_fast16_t, int_fast16_t);
    P_CHECKED_ARITH_UNSIGNED_DEF(int_fast32_t, int_fast32_t);
    P_CHECKED_ARITH_UNSIGNED_DEF(int_fast64_t, int_fast64_t);
    P_CHECKED_ARITH_UNSIGNED_DEF(intptr_t, intptr_t);
    P_CHECKED_ARITH_UNSIGNED_DEF(intmax_t, intmax_t);
#endif

#ifdef __cplusplus
}
#endif

#endif