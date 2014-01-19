//Provides string algorithms.

#ifndef STDX_STRING_H
#define STDX_STRING_H

#include <cctype>
#include <cstddef>
#include <string>
#include <vector>

namespace stdx {
inline namespace StringNs {

//returns a vector containing all positions of the substring
template<typename String, typename String2>
auto FindAll(const String &str, const String2 &find) {
    std::vector<typename String::size_type> temp;
    typename String::size_type pos = 0;
    while (pos = str.find(find, pos), pos != String::npos && pos < str.size()) temp.emplace_back(pos++);
    return temp;
}

//returns the length of a C string
template<typename Char>
std::size_t Length(const Char *const str) noexcept {
    auto ptr(str);
    for (; *ptr; ++ptr);
    return ptr - str;
}

//returns the length of a C++ string
template<typename String>
auto Length(const String &str) noexcept {return str.size();}

//replaces a substring from the specified position with another
template<typename String, typename String2, typename String3>
String &Replace(String &str, const typename String::size_type start, const String2 &from, const String3 &to) {
    if (from == to || start < 0 || start >= str.size()) return str;

    auto pos = str.find(from, start);
    if (pos != String::npos) str.replace(pos, Length(from), to);
    return str;
}

//immutable Replace
template<typename String, typename String2, typename String3>
String Replaced(String str, const typename String::size_type start, const String2 &from, const String3 &to) {
    Replace(str, start, from, to);
    return str;
}

//immutable Replace for C strings
template<typename Char, typename String2, typename String3>
auto Replaced(const Char * const str, const std::size_t start, const String2 &from, const String3 &to) {
    std::basic_string<Char> temp{str};
    Replace(temp, start, from, to);
    return temp;
}

//replaces all substrings with another
template<typename String, typename String2, typename String3>
String &ReplaceAll(String &str, const String2 &from, const String3 &to) {
    if (from == to) return str;

    typename String::size_type pos = 0;
    while ((pos = str.find(from, pos)) != String::npos) {
        str.replace(pos, Length(from), to);
        if ((pos += Length(to)) >= str.size()) break;
    }

    return str;
}

//immutable ReplaceAll
template<typename String, typename String2, typename String3>
String ReplacedAll(String str, const String2 &from, const String3 &to) {
    ReplaceAll(str, from, to);
    return str;
}

//immutable ReplaceAll for C strings
template<typename Char, typename String2, typename String3>
auto ReplacedAll(const Char * const str, const String2 &from, const String3 &to) {
    std::basic_string<Char> temp{str};
    ReplaceAll(temp, from, to);
    return temp;
}

//replaces all substrings with another such that no occurrences of it are left
template<typename String, typename String2, typename String3>
String &ReplaceAllRecursive(String &str, const String2 &from, const String3 &to) {
    if (from == to) return str;

    typename String::size_type pos = 0;
    for (; (pos = str.find(from, pos)) != String::npos; str.replace(pos, Length(from), to));
    return str;
}

//immutable ReplaceAllRecursive
template<typename String, typename String2, typename String3>
String ReplacedAllRecursive(String str, const String2 &from, const String3 &to) {
    ReplaceAllRecursive(str, from, to);
    return str;
}

//immutable ReplaceAllRecursive for C strings
template<typename Char, typename String2, typename String3>
auto ReplacedAllRecursive(const Char * const str, const String2 &from, const String3 &to) {
    std::basic_string<Char> temp{str};
    ReplaceAllRecursive(temp, from, to);
    return temp;
}

//replaces the first substring with another
template<typename String, typename String2, typename String3>
String &ReplaceFirst(String &str, const String2 &from, const String3 &to) {
    if (from == to) return str;

    auto pos = str.find(from);
    if (pos != String::npos) str.replace(pos, Length(from), to);
    return str;
}

//immutable ReplaceFirst
template<typename String, typename String2, typename String3>
String ReplacedFirst(String str, const String2 &from, const String3 &to) {
    ReplaceFirst(str, from, to);
    return str;
}

//immutable ReplaceFirst for C strings
template<typename Char, typename String2, typename String3>
auto ReplacedFirst(const Char * const str, const String2 &from, const String3 &to) {
    std::basic_string<Char> temp{str};
    ReplaceFirst(temp, from, to);
    return temp;
}

//replaces the last substring with another
template<typename String, typename String2, typename String3>
String &ReplaceLast(String &str, const String2 &from, const String3 &to) {
    if (from == to) return str;

    auto pos = str.rfind(from);
    if (pos != String::npos) str.replace(pos, Length(from), to);
    return str;
}

//immutable ReplaceLast
template<typename String, typename String2, typename String3>
String ReplacedLast(String str, const String2 &from, const String3 &to) {
    ReplaceLast(str, from, to);
    return str;
}

//immutable ReplaceLast for C strings
template<typename Char, typename String2, typename String3>
auto ReplacedLast(const Char * const str, const String2 &from, const String3 &to) {
    std::basic_string<Char> temp{str};
    ReplaceLast(temp, from, to);
    return temp;
}

//converts a string to lowercase
template<typename String>
String &ToLower(String &str) noexcept {
    for (auto &chr : str) chr = std::tolower(chr);
    return str;
}

//immutable ToLower
template<typename String>
String Lowered(String str) noexcept {
    ToLower(str);
    return str;
}

//immutable ToLower for C strings
template<typename Char>
auto Lowered(const Char * const str) {
    std::basic_string<Char> temp{str};
    ToLower(temp);
    return temp;
}

//converts a string to uppercase
template<typename String>
String &ToUpper(String &str) noexcept {
    for (auto &chr : str) chr = std::toupper(chr);
    return str;
}

//immutable ToUpper
template<typename String>
String Uppered(String str) noexcept {
    ToUpper(str);
    return str;
}

//immutable ToUpper for C strings
template<typename Char>
auto Uppered(const Char * const str) {
    std::basic_string<Char> temp{str};
    ToUpper(temp);
    return temp;
}

//trims the beginning of a string
template<typename String>
String &TrimLeft(String &str, const typename String::value_type toTrim = ' ') noexcept {
    str.erase(0, str.find_first_not_of(toTrim));
    return str;
}

//immutable TrimLeft
template<typename String>
String TrimmedLeft(String str, const typename String::value_type toTrim = ' ') noexcept {
    TrimLeft(str, toTrim);
    return str;
}

//immutable TrimLeft for C strings
template<typename Char>
auto TrimmedLeft(const Char * const str, const Char toTrim = ' ') {
    std::basic_string<Char> temp{str};
    TrimLeft(temp, toTrim);
    return temp;
}

//trims the end of a string
template<typename String>
String &TrimRight(String &str, const typename String::value_type toTrim = ' ') noexcept {
    str.erase(str.find_last_not_of(toTrim) + 1);
    return str;
}

//immutable TrimRight
template<typename String>
String TrimmedRight(String str, const typename String::value_type toTrim = ' ') noexcept {
    TrimRight(str, toTrim);
    return str;
}

//immutable TrimRight for C strings
template<typename Char>
auto TrimmedRight(const Char * const str, const Char toTrim = ' ') {
    std::basic_string<Char> temp{str};
    TrimRight(temp, toTrim);
    return temp;
}

//trims a string
template<typename String>
String &Trim(String &str, const typename String::value_type toTrim = ' ') noexcept {
    return TrimLeft(TrimRight(str, toTrim), toTrim);
}

//immutable Trim
template<typename String>
String Trimmed(String str, const typename String::value_type toTrim = ' ') noexcept {
    Trim(str, toTrim);
    return str;
}

//immutable Trim for C strings
template<typename Char>
auto Trimmed(const Char * const str, const Char toTrim = ' ') {
    std::basic_string<Char> temp{str};
    Trim(temp, toTrim);
    return temp;
}

}
}

#endif
