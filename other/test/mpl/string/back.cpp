#include <stdx/mpl/string/back.hh>
#include <stdx/mpl/string/string.hh>

int main() {
	using namespace stdx::mpl;

	//static_assert(Back<String<>>, "(should FAIL) Empty string");
	static_assert(Back<String<'A'>> == 'A', "One character");
	static_assert(Back<String<'A', 'B'>> == 'B', "Two characters");
	static_assert(Back<String<'1', '3', '2'>> == '2', "Three characters");
}