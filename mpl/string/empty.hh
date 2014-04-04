#pragma once

#include <stdx/mpl/string/size.hh>

namespace stdx {
inline namespace mpl {

template<typename T>
static constexpr bool Empty{Size<T> == 0};

}
}