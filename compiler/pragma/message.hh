#pragma once

#include <stdx/compiler/detection.hh>
#include <stdx/compiler/pragma/pragma.hh>

#if STDX_CLANG
	#define STDX_PRAGMA_MESSAGE(x) STDX_PRAGMA(message x)
#elif STDX_GCC
	#define STDX_PRAGMA_MESSAGE(x) STDX_PRAGMA(message x)
#elif STDX_MSVC
	#define STDX_PRAGMA_MESSAGE(x) STDX_PRAGMA(message(x))
#endif