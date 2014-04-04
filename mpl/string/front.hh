#pragma once

#include <stdx/mpl/string/empty.hh>
#include <stdx/mpl/string/string.hh>

namespace stdx {
inline namespace mpl {

namespace detail {
	template<typename T>
	struct Front_ {
		static_assert(!Empty<T>, "Front on empty String.");
	};

	template<char Head, char... Tail>
	struct Front_<String<Head, Tail...>> {
		static constexpr char value{Head};
	};

	template<char Head, char... Tail>
	constexpr char Front_<String<Head, Tail...>>::value;
}

template<typename T>
constexpr char Front{detail::Front_<T>::value};

}
}