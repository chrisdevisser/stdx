#pragma once

#include <cstddef> 

namespace stdx {
inline namespace mpl {

template<char... Chars>
struct String {};

namespace detail {
	template<std::size_t N, typename T, typename U>
	struct StringFromFirstN_;

	template<char... Done>
	struct StringFromFirstN_<0, String<Done...>, String<>> {
		using type = String<Done...>;
	};

	template<char... Done, char Head, char... Tail>
	struct StringFromFirstN_<0, String<Done...>, String<Head, Tail...>> {
		using type = String<Done...>;
	};

	template<std::size_t N, char... Done, char Head, char... Tail>
	struct StringFromFirstN_<N, String<Done...>, String<Head, Tail...>> {
		static_assert(N <= sizeof...(Tail) + 1, "StringFromFirstN N too high");
		using type = typename StringFromFirstN_<N - 1,  String<Done..., Head>, String<Tail...>>::type;
	};
}

template<std::size_t N, typename T>
using StringFromFirstN = typename detail::StringFromFirstN_<N, String<>, T>::type;

}
}