#ifndef STDX_COMPILERDIAGNOSTICS_H
#define STDX_COMPILERDIAGNOSTICS_H

//Provides diagnostic options that work for MSVC, GCC, and Clang.

#define STDX_PRAGMA(x) _Pragma(#x)

#if __clang__
    #define STDX_PRAGMA_PUSH STDX_PRAGMA(clang diagnostic push)
    #define STDX_PRAGMA_POP STDX_PRAGMA(clang diagnostic pop)
    #define STDX_PRAGMA_IGNORE_STR(x) STDX_PRAGMA(clang diagnostic ignored x)
    #define STDX_PRAGMA_IGNORE_NUM(x)
#elif __GNUC__
    #define STDX_PRAGMA_PUSH STDX_PRAGMA(GCC diagnostic push)
    #define STDX_PRAGMA_POP STDX_PRAGMA(GCC diagnostic pop)
    #define STDX_PRAGMA_IGNORE_STR(x) STDX_PRAGMA(GCC diagnostic ignored x)
    #define STDX_PRAGMA_IGNORE_NUM(x)
#elif _MSC_VER
    #define STDX_PRAGMA_PUSH STDX_PRAGMA(warning(push))
    #define STDX_PRAGMA_POP STDX_PRAGMA(warning(pop))
    #define STDX_PRAGMA_IGNORE_STR(x)
    #define STDX_PRAGMA_IGNORE_NUM(x) STDX_PRAGMA(warning(disable: x))
#endif

#endif
