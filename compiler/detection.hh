#pragma once

#if __clang__
    #define STDX_CLANG 1
    #define STDX_GCC 0
    #define STDX_MSVC 0
#elif __GNUC__
    #define STDX_CLANG 0
    #define STDX_GCC 1
    #define STDX_MSVC 0
#elif _MSC_VER
    #define STDX_CLANG 0
    #define STDX_GCC 0
    #define STDX_MSVC 1
#endif