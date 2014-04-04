#pragma once

#include <stdx/mpl/string/string.hh>

namespace stdx {
inline namespace mpl {

namespace detail {
	template<typename T, char C>
	struct PushBack_;

	template<char... Chars, char C>
	struct PushBack_<String<Chars...>, C> {
		using type = String<Chars..., C>;
	};
}

template<typename T, char C>
using PushBack = typename detail::PushBack_<T, C>::type;

}
}