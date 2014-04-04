#include <stdx/preprocessor/stringize.hh>

#define macro_ macro_message
#define functionmacro_() functionmacro_message

int main() {
	static_assert(false, "Basic message: " STDX_PP_STRINGIZE(should_see_this_message));
	static_assert(false, "Macro: " STDX_PP_STRINGIZE(macro_));
	static_assert(false, "Function macro: " STDX_PP_STRINGIZE(functionmacro_()));
}