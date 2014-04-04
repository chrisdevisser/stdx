#include <stdx/compiler/pragma/pragma.hh>

#define some_message "Another success"
#define some_other_message() "And again"

int main() {
	STDX_PRAGMA(message "Message - success!");	
	STDX_PRAGMA(message some_message);	
	STDX_PRAGMA(message some_other_message());	
}