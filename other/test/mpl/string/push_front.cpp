#include <stdx/mpl/string/push_front.hh>
#include <stdx/mpl/string/string.hh>
#include <stdx/mpl/type_traits/is_same.hh>

int main() {
	using namespace stdx::mpl;

	static_assert(IsSame<PushFront<String<>, 'A'>, String<'A'>>, "Empty string");
	static_assert(IsSame<PushFront<String<'A'>, 'B'>, String<'B', 'A'>>, "One character");
	static_assert(IsSame<PushFront<String<'B'>, 'A'>, String<'A', 'B'>>, "One character");
	static_assert(IsSame<PushFront<String<'1', '2'>, '3'>, String<'3', '1', '2'>>, "Two characters");
}