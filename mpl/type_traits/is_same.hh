#pragma once

#include <type_traits> 

namespace stdx {
inline namespace mpl {

template<typename T, typename U>
static constexpr bool IsSame{std::is_same<T, U>::value};

}
}