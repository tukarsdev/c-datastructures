#ifndef C_STANDARD_H
#define C_STANDARD_H

#define PREDEF_STANDARD_C89

#ifdef __STDC_VERSION__

#if __STDC_VERSION__ >= 199901L
    #define PREDEF_STANDARD_C99
#endif
#if __STDC_VERSION__ >= 201112L
    #define PREDEF_STANDARD_C11
#endif
#if __STDC_VERSION__ >= 201710L
    #define PREDEF_STANDARD_C17
#endif
#if __STDC_VERSION__ >= 202311L
    #define PREDEF_STANDARD_C23
#endif

#endif /* __STDC_VERSION__ */

#ifdef __cplusplus

#define PREDEF_STANDARD_CXX98
#if __cplusplus >= 201103L
    #define PREDEF_STANDARD_CXX11
#endif
#if __cplusplus >= 201402L
    #define PREDEF_STANDARD_CXX14
#endif
#if __cplusplus >= 201703L
    #define PREDEF_STANDARD_CXX17
#endif
#if __cplusplus >= 202002L
    #define PREDEF_STANDARD_CXX20
#endif
#if __cplusplus >= 202302L
    #define PREDEF_STANDARD_CXX23
#endif

#endif /* __cplusplus */

#if defined(PREDEF_STANDARD_C99) || defined(PREDEF_STANDARD_CXX98)
    #define PREDEF_STANDARD_C99_CXX98
#endif

#if defined(PREDEF_STANDARD_C99) || defined(PREDEF_STANDARD_CXX11)
    #define PREDEF_STANDARD_C99_CXX11
#endif



#if defined(PREDEF_STANDARD_C99_CXX98)
    #define PREDEF_INLINE extern inline
#else
    #define PREDEF_INLINE
#endif

#endif /* ifndef C_STANDARD_H */

