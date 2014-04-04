#pragma once

#include <stdx/mpl/string/size.hh>
#include <stdx/mpl/string/string.hh>

namespace stdx {
inline namespace mpl {

namespace detail {
	template<typename T, std::size_t Pos>
	struct At_;

	template<char Head, char... Tail>
	struct At_<String<Head, Tail...>, 0> {
		static constexpr char value{Head};
	};

	template<char Head, char... Tail>
	constexpr char At_<String<Head, Tail...>, 0>::value;

	template<char Head, char... Tail, std::size_t Pos>
	struct At_<String<Head, Tail...>, Pos> {
		static_assert(Size<String<Head, Tail...>> > Pos, "At index out of range");
		static constexpr char value{At_<String<Tail...>, Pos - 1>::value};
	};

	template<char Head, char... Tail, std::size_t Pos>
	constexpr char At_<String<Head, Tail...>, Pos>::value;
}

template<typename T, std::size_t Pos>
static constexpr char At{detail::At_<T, Pos>::value};
}
}