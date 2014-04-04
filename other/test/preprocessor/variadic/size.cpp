#include <stdx/preprocessor/variadic/size.hh>

int main() {
	static_assert(STDX_PP_VARIADIC_SIZE() == 1, "Empty list -> one argument");
	static_assert(STDX_PP_VARIADIC_SIZE(1) == 1, "One argument");
	static_assert(STDX_PP_VARIADIC_SIZE(,) == 2, "Comma -> two arguments");
	static_assert(STDX_PP_VARIADIC_SIZE(1, 2) == 2, "Two arguments");
	static_assert(STDX_PP_VARIADIC_SIZE(,,) == 3, "Three arguments");
	static_assert(STDX_PP_VARIADIC_SIZE(,,,) == 4, "Four arguments");
	static_assert(STDX_PP_VARIADIC_SIZE(,,,,) == 5, "Five arguments");
	static_assert(STDX_PP_VARIADIC_SIZE(,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,) == 64, "64 arguments");
}