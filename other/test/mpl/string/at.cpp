#include <stdx/mpl/string/at.hh>
#include <stdx/mpl/string/string.hh>

int main() {
	using namespace stdx::mpl;

	// static_assert(At<String<>, 0> != 'A', "(should FAIL) Empty string");
	//static_assert(At<String<'A'>, 1> != 'A', "(should FAIL) One character, index 1");

	static_assert(At<String<'A'>, 0> == 'A', "One character");
	static_assert(At<String<'A', 'B'>, 0> == 'A', "Two characters, index 0");
	static_assert(At<String<'A', 'B'>, 1> == 'B', "Two characters, index 1");
}