#pragma once

#include <stdx/compiler/detection.hh>
#include <stdx/compiler/pragma/pragma.hh>

#if STDX_CLANG
    #define STDX_PRAGMA_POP() STDX_PRAGMA(clang diagnostic pop)
#elif STDX_GCC
    #define STDX_PRAGMA_POP() STDX_PRAGMA(GCC diagnostic pop)
#elif STDX_MSVC
    #define STDX_PRAGMA_POP() STDX_PRAGMA(warning(pop))
#endif