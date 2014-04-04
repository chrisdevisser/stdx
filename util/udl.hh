//Will be removed when standard library support comes

#pragma once

#include <chrono>
#include <cstddef>
#include <ratio>
#include <string>

namespace stdx {
inline namespace util {
inline namespace lit {

std::string operator"" _s(const char *str, std::size_t);
std::wstring operator"" _s(const wchar_t *str, std::size_t);

constexpr auto operator"" _ns(const unsigned long long ns) noexcept {return std::chrono::nanoseconds{ns};}
constexpr auto operator"" _ns(const long double ns) noexcept {return std::chrono::duration<long double, std::nano>{ns};}
constexpr auto operator"" _us(const unsigned long long us) noexcept {return std::chrono::microseconds{us};}
constexpr auto operator"" _us(const long double us) noexcept {return std::chrono::duration<long double, std::micro>{us};}
constexpr auto operator"" _ms(const unsigned long long ms) noexcept {return std::chrono::milliseconds{ms};}
constexpr auto operator"" _ms(const long double ms) noexcept {return std::chrono::duration<long double, std::milli>{ms};}
constexpr auto operator"" _s(const unsigned long long s) noexcept {return std::chrono::seconds{s};}
constexpr auto operator"" _s(const long double s) noexcept {return std::chrono::duration<long double>{s};}
constexpr auto operator"" _min(const unsigned long long mins) noexcept {return std::chrono::minutes{mins};}
constexpr auto operator"" _min(const long double mins) noexcept {return std::chrono::duration<long double, std::ratio<60>>{mins};}
constexpr auto operator"" _h(const unsigned long long h) noexcept {return std::chrono::hours{h};}
constexpr auto operator"" _h(const long double h) noexcept {return std::chrono::duration<long double, std::ratio<3600>>{h};}

}
}
}