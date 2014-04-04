#pragma once

#include <stdx/mpl/string/string.hh>

namespace stdx {
inline namespace mpl {

namespace detail {
	template<typename T, char C>
	struct PushFront_;

	template<char... Chars, char C>
	struct PushFront_<String<Chars...>, C> {
		using type = String<C, Chars...>;
	};
}

template<typename T, char C>
using PushFront = typename detail::PushFront_<T, C>::type;

}
}