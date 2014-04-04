#include <stdx/preprocessor/detail/cat.hh>

int main() {
	STDX_PP_DETAIL_CAT(static_, assert)(true, "static_, assert");
	STDX_PP_DETAIL_CAT(s, tatic_assert)(true, "s, tatic_assert");
	STDX_PP_DETAIL_CAT(, static_assert)(true, ", static_assert");
	STDX_PP_DETAIL_CAT(static_assert,)(true, "static_assert,");
	static_assert(STDX_PP_DETAIL_CAT(,)true, ", -> blank");
}