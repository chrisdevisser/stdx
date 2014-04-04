#pragma once

#include <stdx/mpl/string/size.hh>
#include <stdx/mpl/string/string.hh>

namespace stdx {
inline namespace mpl {

namespace detail {
	template<typename>
	struct CStr_;

	template<char... Chars>
	struct CStr_<String<Chars...>> {
		static constexpr char value[Size<String<Chars...>> + 1]{Chars..., '\0'};
	};

	template<char... Chars>
	constexpr char CStr_<String<Chars...>>::value[Size<String<Chars...>> + 1];
}

template<typename T>
static constexpr const char(&CStr)[Size<T> + 1]{detail::CStr_<T>::value};

}
}