#include <stdx/compiler/pragma/message.hh>

#define message1 "Some message"
#define message2() "Another message"

int main() {
	STDX_PRAGMA_MESSAGE("should see this message");
	STDX_PRAGMA_MESSAGE(message1);
	STDX_PRAGMA_MESSAGE(message2());
}