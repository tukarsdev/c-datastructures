#ifndef C_STANDARD_H
#define C_STANDARD_H
    #if defined(__STDC__)
        #define PREDEF_STANDARD_C_1989
    #endif
    #if (__STDC_VERSION__ >= 199901L)
        #define PREDEF_STANDARD_C_1999
    #endif
    #if (__STDC_VERSION__ >= 201112L)
        #define PREDEF_STANDARD_C_2011
    #endif
#endif
