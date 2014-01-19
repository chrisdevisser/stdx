int main() {
    using namespace stdx::StringNs;

    std::string s{"ababcadefa"};
    auto as = FindAll(s, "a");
    if (as != std::vector<std::string::size_type>{0, 2, 5, 9}) assert(!"FindAll");

    assert(Lowered("Aads4353sd4BDFJ") == "aads4353sd4bdfj");
    assert(Replaced("abc123abcdef", 1, "abc", "z") == "abc123zdef");
    assert(ReplacedAll("aaabaacaaaad", "aa", "a") == "aabacaad");
    assert(ReplacedAllRecursive("aaabaacaaaad", "aa", "a") == "abacad");
    assert(ReplacedFirst("abc123abcdef", "abc", "z") == "z123abcdef");
    assert(ReplacedLast("abc123abcdef", "abc", "z") == "abc123zdef");
    assert(TrimmedLeft("      as sd asd a   ") == "as sd asd a   ");
    assert(TrimmedLeft("$$$$$$as sd asd a$$$", '$') == "as sd asd a$$$");
    assert(TrimmedRight("      as sd asd a   ") == "      as sd asd a");
    assert(TrimmedRight("$$$$$$as sd asd a$$$", '$') == "$$$$$$as sd asd a");
    assert(Trimmed("      as sd asd a   ") == "as sd asd a");
    assert(Trimmed("$$$$$$as sd asd a$$$", '$') == "as sd asd a");
    assert(Uppered("Aads4353sd4BDFJ") == "AADS4353SD4BDFJ");
}
