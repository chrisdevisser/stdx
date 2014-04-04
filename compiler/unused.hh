#pragma once

#include <stdx/compiler/detection.hh>

#if STDX_CLANG
    #define STDX_UNUSED __attribute__((unused))
#elif STDX_GCC
    #define STDX_UNUSED __attribute__((unused))
#elif STDX_MSVC
	#define STDX_UNUSED 
#endif

#ifdef STDX_USE_SHORT_NAMES
	#define unused_ STDX_UNUSED
#endif