#include <chrono>
#include <string>
#include "../udl.hh"

namespace stdx {
namespace lit {

std::string operator"" _s(const char *str, const std::size_t) {return str;}
std::wstring operator"" _s(const wchar_t *str, const std::size_t) {return str;}

}
}
