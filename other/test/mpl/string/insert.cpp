#include <stdx/mpl/string/insert.hh>
#include <stdx/mpl/string/string.hh>
#include <stdx/mpl/type_traits/is_same.hh>

int main() {
	using namespace stdx::mpl;
	
	//static_assert(!IsSame<Insert<String<>, 1, 'A'>, String<'A'>>, "(should FAIL) Index out of range");
	//static_assert(!IsSame<Insert<String<'A'>, 2, 'B'>, String<'A', 'B'>>, "(should FAIL) Index out of range");
	//static_assert(!IsSame<Insert<String<>, -1, 'A'>, String<'A'>>, "(should FAIL) Index out of range");

	static_assert(IsSame<Insert<String<>, 0, 'A'>, String<'A'>>, "Empty string");
	static_assert(IsSame<Insert<String<'A'>, 0, 'B'>, String<'B', 'A'>>, "One character, index 0");
	static_assert(IsSame<Insert<String<'A'>, 1, 'B'>, String<'A', 'B'>>, "One character, index 1");
}