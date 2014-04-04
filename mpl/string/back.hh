#pragma once

#include <stdx/mpl/string/empty.hh>
#include <stdx/mpl/string/string.hh>

namespace stdx {
inline namespace mpl {

namespace detail {
	template<typename T>
	struct Back_ {
		static_assert(!Empty<T>, "Back on empty String.");
	};

	template<char C>
	struct Back_<String<C>> {
		static constexpr char value{C};
	};

	template<char C>
	constexpr char Back_<String<C>>::value;

	template<char Head, char... Tail>
	struct Back_<String<Head, Tail...>> : Back_<String<Tail...>> {};
}

template<typename T>
constexpr char Back{detail::Back_<T>::value};

}
}