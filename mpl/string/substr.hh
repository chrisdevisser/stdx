//unfinished

#pragma once

#include <stdx/mpl/string/size.hh>
#include <stdx/mpl/string/string.hh>

namespace stdx {
inline namespace mpl {

namespace detail {
	template<typename T, std::size_t Pos>
	struct Substr_;

	template<char Head, char... Tail>
	struct Substr_<String<Head, Tail...>, 0> {
		static constexpr char value{Head};
	};

	template<char Head, char... Tail>
	constexpr char Substr_<String<Head, Tail...>, 0>::value;

	template<char Head, char... Tail, std::size_t Pos>
	struct Substr_<String<Head, Tail...>, Pos> {
		static_assert(Size<String<Head, Tail...>> > Pos, "Substr index out of range");
		static constexpr char value{Substr_<String<Tail...>, Pos - 1>::value};
	};

	template<char Head, char... Tail, std::size_t Pos>
	constexpr char Substr_<String<Head, Tail...>, Pos>::value;
}

template<typename T, std::size_t Pos>
static constexpr char Substr{detail::Substr_<T, Pos>::value};

}
}