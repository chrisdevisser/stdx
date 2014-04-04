#include <stdx/mpl/string/string.hh>
#include <stdx/mpl/type_traits/is_same.hh>

#include <iostream> 
#include <stdx/mpl/string/c_str.hh>

int main() {
	using namespace stdx::mpl;

	// static_assert(!IsSame<StringFromFirstN<1, String<>>, String<'A'>>, "(should FAIL) Empty string, first 1");
	// static_assert(!IsSame<StringFromFirstN<2, String<'A'>>, String<'A'>>, "(should FAIL) One character, first 2");

	static_assert(IsSame<StringFromFirstN<0, String<>>, String<>>, "Empty string, first 0");
	static_assert(IsSame<StringFromFirstN<0, String<'A'>>, String<>>, "One character, first 0");
	static_assert(IsSame<StringFromFirstN<1, String<'A'>>, String<'A'>>, "One character, first 1");
	static_assert(IsSame<StringFromFirstN<1, String<'A', 'B'>>, String<'A'>>, "Two characters, first 1");
	static_assert(IsSame<StringFromFirstN<2, String<'A', 'B'>>, String<'A', 'B'>>, "Two characters, first 2");
}