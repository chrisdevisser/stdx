#pragma once

#include <stdx/preprocessor/detail/cat.hh>
#include <stdx/preprocessor/variadic/size.hh>

#define STDX_PP_OVERLOAD(name, ...) STDX_PP_DETAIL_CAT(name, STDX_PP_VARIADIC_SIZE(__VA_ARGS__))
#define STDX_PP_CALL_OVERLOAD(name, ...) STDX_PP_OVERLOAD(name, __VA_ARGS__)(__VA_ARGS__)