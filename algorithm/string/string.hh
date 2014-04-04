//Due for multiple files

//Provides string algorithms.

#pragma once

#include <cctype>
#include <cstddef>
#include <string>
#include <vector>

namespace stdx {
inline namespace algo {
inline namespace string {

//returns a vector containing all positions of the substring
template<typename String, typename String2>
auto findAll(const String &str, const String2 &find) {
    std::vector<typename String::size_type> temp;
    typename String::size_type pos = 0;
    while (pos = str.find(find, pos), pos != String::npos && pos < str.size()) temp.emplace_back(pos++);
    return temp;
}

//returns the length of a C string
template<typename Char>
std::size_t length(const Char *const str) noexcept {
    auto ptr(str);
    for (; *ptr; ++ptr);
    return ptr - str;
}

//returns the length of a C++ string
template<typename String>
auto length(const String &str) noexcept {return str.size();}

//replaces a substring from the specified position with another
template<typename String, typename String2, typename String3>
String &replace(String &str, const typename String::size_type start, const String2 &from, const String3 &to) {
    if (from == to || start < 0 || start >= str.size()) return str;

    auto pos = str.find(from, start);
    if (pos != String::npos) str.replace(pos, length(from), to);
    return str;
}

//immutable Replace
template<typename String, typename String2, typename String3>
String replaced(String str, const typename String::size_type start, const String2 &from, const String3 &to) {
    replace(str, start, from, to);
    return str;
}

//immutable Replace for C strings
template<typename Char, typename String2, typename String3>
auto replaced(const Char * const str, const std::size_t start, const String2 &from, const String3 &to) {
    std::basic_string<Char> temp{str};
    replace(temp, start, from, to);
    return temp;
}

//replaces all substrings with another
template<typename String, typename String2, typename String3>
String &replaceAll(String &str, const String2 &from, const String3 &to) {
    if (from == to) return str;

    typename String::size_type pos = 0;
    while ((pos = str.find(from, pos)) != String::npos) {
        str.replace(pos, length(from), to);
        if ((pos += length(to)) >= str.size()) break;
    }

    return str;
}

//immutable ReplaceAll
template<typename String, typename String2, typename String3>
String replacedAll(String str, const String2 &from, const String3 &to) {
    replaceAll(str, from, to);
    return str;
}

//immutable ReplaceAll for C strings
template<typename Char, typename String2, typename String3>
auto replacedAll(const Char * const str, const String2 &from, const String3 &to) {
    std::basic_string<Char> temp{str};
    replaceAll(temp, from, to);
    return temp;
}

//replaces all substrings with another such that no occurrences of it are left
template<typename String, typename String2, typename String3>
String &replaceAllRecursive(String &str, const String2 &from, const String3 &to) {
    if (from == to) return str;

    typename String::size_type pos = 0;
    for (; (pos = str.find(from, pos)) != String::npos; str.replace(pos, length(from), to));
    return str;
}

//immutable ReplaceAllRecursive
template<typename String, typename String2, typename String3>
String replacedAllRecursive(String str, const String2 &from, const String3 &to) {
    replaceAllRecursive(str, from, to);
    return str;
}

//immutable ReplaceAllRecursive for C strings
template<typename Char, typename String2, typename String3>
auto replacedAllRecursive(const Char * const str, const String2 &from, const String3 &to) {
    std::basic_string<Char> temp{str};
    replaceAllRecursive(temp, from, to);
    return temp;
}

//replaces the first substring with another
template<typename String, typename String2, typename String3>
String &replaceFirst(String &str, const String2 &from, const String3 &to) {
    if (from == to) return str;

    auto pos = str.find(from);
    if (pos != String::npos) str.replace(pos, length(from), to);
    return str;
}

//immutable ReplaceFirst
template<typename String, typename String2, typename String3>
String replacedFirst(String str, const String2 &from, const String3 &to) {
    replaceFirst(str, from, to);
    return str;
}

//immutable ReplaceFirst for C strings
template<typename Char, typename String2, typename String3>
auto replacedFirst(const Char * const str, const String2 &from, const String3 &to) {
    std::basic_string<Char> temp{str};
    replaceFirst(temp, from, to);
    return temp;
}

//replaces the last substring with another
template<typename String, typename String2, typename String3>
String &replaceLast(String &str, const String2 &from, const String3 &to) {
    if (from == to) return str;

    auto pos = str.rfind(from);
    if (pos != String::npos) str.replace(pos, length(from), to);
    return str;
}

//immutable ReplaceLast
template<typename String, typename String2, typename String3>
String replacedLast(String str, const String2 &from, const String3 &to) {
    replaceLast(str, from, to);
    return str;
}

//immutable ReplaceLast for C strings
template<typename Char, typename String2, typename String3>
auto replacedLast(const Char * const str, const String2 &from, const String3 &to) {
    std::basic_string<Char> temp{str};
    replaceLast(temp, from, to);
    return temp;
}

//converts a string to lowercase
template<typename String>
String &toLower(String &str) noexcept {
    for (auto &chr : str) chr = std::tolower(static_cast<unsigned char>(chr));
    return str;
}

//immutable ToLower
template<typename String>
String lowered(String str) noexcept {
    toLower(str);
    return str;
}

//immutable ToLower for C strings
template<typename Char>
auto lowered(const Char * const str) {
    std::basic_string<Char> temp{str};
    toLower(temp);
    return temp;
}

//converts a string to uppercase
template<typename String>
String &toUpper(String &str) noexcept {
    for (auto &chr : str) chr = std::toupper(static_cast<unsigned char>(chr));
    return str;
}

//immutable ToUpper
template<typename String>
String uppered(String str) noexcept {
    toUpper(str);
    return str;
}

//immutable ToUpper for C strings
template<typename Char>
auto uppered(const Char * const str) {
    std::basic_string<Char> temp{str};
    toUpper(temp);
    return temp;
}

//trims the beginning of a string
template<typename String>
String &trimLeft(String &str, const typename String::value_type toTrim = ' ') noexcept {
    str.erase(0, str.find_first_not_of(toTrim));
    return str;
}

//immutable TrimLeft
template<typename String>
String trimmedLeft(String str, const typename String::value_type toTrim = ' ') noexcept {
    trimLeft(str, toTrim);
    return str;
}

//immutable TrimLeft for C strings
template<typename Char>
auto trimmedLeft(const Char * const str, const Char toTrim = ' ') {
    std::basic_string<Char> temp{str};
    trimLeft(temp, toTrim);
    return temp;
}

//trims the end of a string
template<typename String>
String &trimRight(String &str, const typename String::value_type toTrim = ' ') noexcept {
    str.erase(str.find_last_not_of(toTrim) + 1);
    return str;
}

//immutable TrimRight
template<typename String>
String trimmedRight(String str, const typename String::value_type toTrim = ' ') noexcept {
    trimRight(str, toTrim);
    return str;
}

//immutable TrimRight for C strings
template<typename Char>
auto trimmedRight(const Char * const str, const Char toTrim = ' ') {
    std::basic_string<Char> temp{str};
    trimRight(temp, toTrim);
    return temp;
}

//trims a string
template<typename String>
String &trim(String &str, const typename String::value_type toTrim = ' ') noexcept {
    return trimLeft(trimRight(str, toTrim), toTrim);
}

//immutable Trim
template<typename String>
String trimmed(String str, const typename String::value_type toTrim = ' ') noexcept {
    trim(str, toTrim);
    return str;
}

//immutable Trim for C strings
template<typename Char>
auto trimmed(const Char * const str, const Char toTrim = ' ') {
    std::basic_string<Char> temp{str};
    trim(temp, toTrim);
    return temp;
}

}
}
}