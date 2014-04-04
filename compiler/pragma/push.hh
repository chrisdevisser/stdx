#pragma once

#include <stdx/compiler/detection.hh>
#include <stdx/compiler/pragma/pragma.hh>

#if STDX_CLANG
    #define STDX_PRAGMA_PUSH() STDX_PRAGMA(clang diagnostic push)
#elif STDX_GCC
    #define STDX_PRAGMA_PUSH() STDX_PRAGMA(GCC diagnostic push)
#elif STDX_MSVC
    #define STDX_PRAGMA_PUSH() STDX_PRAGMA(warning(push))
#endif