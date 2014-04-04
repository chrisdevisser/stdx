#include <stdx/mpl/type_traits/is_same.hh>

int main() {
	using namespace stdx::mpl;

	using int_ = int;

	static_assert(IsSame<int, int>, "int, int");
	static_assert(IsSame<int, int_>, "int, int_ (using alias for int)");
	static_assert(IsSame<int, signed int>, "int, signed int");
	
	static_assert(!IsSame<int, double>, "int, double");
	static_assert(!IsSame<int, const int>, "int, const int");
	static_assert(!IsSame<int, volatile int>, "int, volatile int");
	static_assert(!IsSame<int, long int>, "int, long int");
	static_assert(!IsSame<char, signed char>, "char, signed char");
	static_assert(!IsSame<char, unsigned char>, "char, unsigned char");
}