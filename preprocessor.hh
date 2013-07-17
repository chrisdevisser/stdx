#ifndef STDX_PREPROCESSOR_H
#define STDX_PREPROCESSOR_H

//Defines preprocessor operations.

#define STDX_PP_STRINGIFY2(x) #x
#define STDX_PP_CONCAT2(x, y) x##y

#define STDX_PP_STRINGIFY(x) STDX_PP_STRINGIFY2(x)
#define STDX_PP_CONCAT(x, y) STDX_PP_CONCAT2(x, y)

#endif
