#include <stdx/mpl/string/size.hh>
#include <stdx/mpl/string/string.hh>

int main() {
	using namespace stdx::mpl;

	static_assert(Size<String<>> == 0, "Empty string");
	static_assert(Size<String<'1'>> == 1, "One character");
	static_assert(Size<String<'1', '2'>> == 2, "Two characters");
	static_assert(Size<String<'H', 'e', 'l', 'l', 'o', ',', ' ', 'w', 'o', 'r', 'l', 'd', '!', '\0'>> == sizeof("Hello, world!"), "Hello, world!");
}