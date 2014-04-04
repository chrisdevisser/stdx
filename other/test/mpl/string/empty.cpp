#include <stdx/mpl/string/empty.hh>
#include <stdx/mpl/string/string.hh>

int main() {
	using namespace stdx::mpl;

	static_assert(Empty<String<>>, "Empty string");
	static_assert(!Empty<String<'A'>>, "One character");
	static_assert(!Empty<String<'A', 'B'>>, "Two characters");
	static_assert(!Empty<String<'1', '2', '3'>>, "Three characters");
}