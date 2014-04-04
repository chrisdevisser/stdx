#include <stdx/compiler/detection.hh>

int main() {
	static_assert(STDX_CLANG, "Clang detection");
	static_assert(!STDX_GCC, "GCC detection");
	static_assert(!STDX_MSVC, "MSVC detection");
}