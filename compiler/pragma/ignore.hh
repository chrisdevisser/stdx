#pragma once

#include <stdx/compiler/detection.hh>
#include <stdx/compiler/pragma/pragma.hh>

#if STDX_CLANG
    #define STDX_PRAGMA_IGNORE_STR(x) STDX_PRAGMA(clang diagnostic ignored x)
    #define STDX_PRAGMA_IGNORE_NUM(x)
    #define STDX_PRAGMA_IGNORE(x) STDX_PRAGMA_IGNORE_STR(x)
#elif STDX_GCC
    #define STDX_PRAGMA_IGNORE_STR(x) STDX_PRAGMA(GCC diagnostic ignored x)
    #define STDX_PRAGMA_IGNORE_NUM(x)
    #define STDX_PRAGMA_IGNORE(x) STDX_PRAGMA_IGNORE_STR(x)
#elif STDX_MSVC
    #define STDX_PRAGMA_IGNORE_STR(x)
    #define STDX_PRAGMA_IGNORE_NUM(x) STDX_PRAGMA(warning(disable: x))
    #define STDX_PRAGMA_IGNORE(x) STDX_PRAGMA_IGNORE_NUM(x)
#endif