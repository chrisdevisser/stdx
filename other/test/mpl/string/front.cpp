#include <stdx/mpl/string/front.hh>
#include <stdx/mpl/string/string.hh>

int main() {
	using namespace stdx::mpl;

	//static_assert(Front<String<>>, "(should FAIL) Empty string");
	static_assert(Front<String<'A'>> == 'A', "One character");
	static_assert(Front<String<'A', 'B'>> == 'A', "Two characters");
	static_assert(Front<String<'1', '3', '2'>> == '1', "Three characters");
}