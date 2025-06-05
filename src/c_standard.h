#ifndef C_STANDARD_H
#define C_STANDARD_H

#define C_STANDARD_ATLEAST_C89

#ifdef __STDC_VERSION__

#if __STDC_VERSION__ >= 199901L
    #define C_STANDARD_ATLEAST_C99
#endif
#if __STDC_VERSION__ >= 201112L
    #define C_STANDARD_ATLEAST_C11
#endif
#if __STDC_VERSION__ >= 201710L
    #define C_STANDARD_ATLEAST_C17
#endif
#if __STDC_VERSION__ >= 202311L
    #define C_STANDARD_ATLEAST_C23
#endif

#ifndef C_STANDARD_ATLEAST_C99
    #define C_STANDARD_EXACT_C89
#endif

#endif /* __STDC_VERSION__ */


#ifdef __cplusplus

#define C_STANDARD_ATLEAST_CXX98
#if __cplusplus >= 201103L
    #define C_STANDARD_ATLEAST_CXX11
#endif
#if __cplusplus >= 201402L
    #define C_STANDARD_ATLEAST_CXX14
#endif
#if __cplusplus >= 201703L
    #define C_STANDARD_ATLEAST_CXX17
#endif
#if __cplusplus >= 202002L
    #define C_STANDARD_ATLEAST_CXX20
#endif
#if __cplusplus >= 202302L
    #define C_STANDARD_ATLEAST_CXX23
#endif

#endif /* __cplusplus */

#if defined(C_STANDARD_ATLEAST_C99) || defined(C_STANDARD_ATLEAST_CXX98)
    #define C_STANDARD_ATLEAST_C99_CXX98
#endif

#if defined(C_STANDARD_ATLEAST_C99) || defined(C_STANDARD_ATLEAST_CXX11)
    #define C_STANDARD_ATLEAST_C99_CXX11
#endif


#ifdef C_STANDARD_ATLEAST_C99_CXX98
    #define C_STANDARD_INLINE_H(SIGNATURE, BODY) inline SIGNATURE BODY
    #define C_STANDARD_INLINE_C(SIGNATURE, BODY) extern inline SIGNATURE;
#else
    #define C_STANDARD_INLINE_H(SIGNATURE, BODY) SIGNATURE;
    #define C_STANDARD_INLINE_C(SIGNATURE, BODY) SIGNATURE BODY
#endif


#endif /* ifndef C_STANDARD_H */

