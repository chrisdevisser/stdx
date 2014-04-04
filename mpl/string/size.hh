#pragma once

#include <cstddef> 

#include <stdx/compiler/unused.hh>
#include <stdx/mpl/string/string.hh>

namespace stdx {
inline namespace mpl {

template<typename>
STDX_UNUSED static constexpr std::size_t Size{};

template<char... Chars>
static constexpr std::size_t Size<String<Chars...>>{sizeof...(Chars)};

}
}