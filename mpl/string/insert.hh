#pragma once

#include <cstddef> 

#include <stdx/mpl/string/size.hh>
#include <stdx/mpl/string/string.hh>

namespace stdx {
inline namespace mpl {

namespace detail {
	template<typename T, typename U, std::size_t Pos, char C>
	struct Insert_ {
		static_assert(Pos > 0, "Insert index out of range.");
	};

	template<char... Done, char C>
	struct Insert_<String<Done...>, String<>, 0, C> {
		using type = String<Done..., C>;
	};

	template<char... Done, char Head, char... Tail, char C>
	struct Insert_<String<Done...>, String<Head, Tail...>, 0, C> {
		using type = String<Done..., C, Head, Tail...>;
	};

	template<char... Done, char Head, char... Tail, std::size_t Pos, char C>
	struct Insert_<String<Done...>, String<Head, Tail...>, Pos, C> {
		static_assert(Size<String<Tail...>> >= Pos - 1, "Insert index out of range.");
		using type = typename Insert_<String<Done..., Head>, String<Tail...>, Pos - 1, C>::type;
	};
}

template<typename T, std::size_t Pos, char C>
using Insert = typename detail::Insert_<String<>, T, Pos, C>::type;

}
}