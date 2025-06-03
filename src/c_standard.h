#ifndef C_STANDARD_H
#define C_STANDARD_H

#ifdef __cplusplus
extern "C" {
#endif


#define PREDEF_STANDARD_C89

#if __STDC_VERSION__ >= 199901L
    #define PREDEF_STANDARD_C99
#endif

#if __STDC_VERSION__ >= 201112L
    #define PREDEF_STANDARD_C11
#endif


#ifdef __cplusplus
}
#endif

#endif // ifndef C_STANDARD_H


