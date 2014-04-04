#include <iostream>

#include <stdx/mpl/string/c_str.hh>
#include <stdx/mpl/string/string.hh>

int main() {
	using namespace stdx::mpl;

	std::cout << "(Nothing): " << CStr<String<>> << '\n';
	std::cout << "A: " << CStr<String<'A'>> << '\n';
	std::cout << "AB: " << CStr<String<'A', 'B'>> << '\n';
	std::cout << "123: " << CStr<String<'1', '2', '3'>> << '\n';
	std::cout << "Hello, world!: " << CStr<String<'H', 'e', 'l', 'l', 'o', ',', ' ', 'w', 'o', 'r', 'l', 'd', '!'>> << '\n';
}