#include <cassert>
#include <string>
#include <vector>

#include <stdx/algorithm/string/string.hh>

int main() {
    using namespace stdx::algo::string;

    std::string s{"ababcadefa"};
    auto as = findAll(s, "a");
    if (as != std::vector<std::string::size_type>{0, 2, 5, 9}) assert(!"FindAll");

    assert(lowered("Aads4353sd4BDFJ") == "aads4353sd4bdfj");
    assert(replaced("abc123abcdef", 1, "abc", "z") == "abc123zdef");
    assert(replacedAll("aaabaacaaaad", "aa", "a") == "aabacaad");
    assert(replacedAllRecursive("aaabaacaaaad", "aa", "a") == "abacad");
    assert(replacedFirst("abc123abcdef", "abc", "z") == "z123abcdef");
    assert(replacedLast("abc123abcdef", "abc", "z") == "abc123zdef");
    assert(trimmedLeft("      as sd asd a   ") == "as sd asd a   ");
    assert(trimmedLeft("$$$$$$as sd asd a$$$", '$') == "as sd asd a$$$");
    assert(trimmedRight("      as sd asd a   ") == "      as sd asd a");
    assert(trimmedRight("$$$$$$as sd asd a$$$", '$') == "$$$$$$as sd asd a");
    assert(trimmed("      as sd asd a   ") == "as sd asd a");
    assert(trimmed("$$$$$$as sd asd a$$$", '$') == "as sd asd a");
    assert(uppered("Aads4353sd4BDFJ") == "AADS4353SD4BDFJ");
}
