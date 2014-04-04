#include <stdx/compiler/detection.hh>
#include <stdx/compiler/pragma/ignore.hh>
#include <stdx/compiler/pragma/pop.hh>
#include <stdx/compiler/pragma/push.hh>

int main() {
	STDX_PRAGMA_PUSH();
		STDX_PRAGMA_IGNORE_STR("-Wunused-variable");
		STDX_PRAGMA_IGNORE_NUM(4100);
		int unused1;
	STDX_PRAGMA_POP();

	#if STDX_CLANG || STDX_GCC
		STDX_PRAGMA_IGNORE("-Wunused-variable");
	#elif STDX_MSVC
		STDX_PRAGMA_IGNORE(4100);
	#endif

	int unused2;
}