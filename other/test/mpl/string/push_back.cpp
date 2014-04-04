#include <stdx/mpl/string/push_back.hh>
#include <stdx/mpl/string/string.hh>
#include <stdx/mpl/type_traits/is_same.hh>

int main() {
	using namespace stdx::mpl;

	static_assert(IsSame<PushBack<String<>, 'A'>, String<'A'>>, "Empty string");
	static_assert(IsSame<PushBack<String<'A'>, 'B'>, String<'A', 'B'>>, "One character");
	static_assert(IsSame<PushBack<String<'B'>, 'A'>, String<'B', 'A'>>, "One character");
	static_assert(IsSame<PushBack<String<'1', '2'>, '3'>, String<'1', '2', '3'>>, "Two characters");
}