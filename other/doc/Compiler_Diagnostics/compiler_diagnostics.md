Summary
=

Provides some utilities for detecting compilers and doing compiler-dependent tasks in a more uniform manner.

Namespace
=

>
- `stdx` - main namespace       
    
Dependencies
=

No dependencies at this time.

Macros
=

Compiler Detection
-

- `STDX_CLANG`: 1 if `__clang__` is defined, or 0 otherwise
- `STDX_GCC`: 1 if `__GNUC__` is defined, or 0 otherwise
- `STDX_MSVC`: 1 if `_MSC_VER` is defined, or 0 otherwise

Compiler Diagnostics
-

- `STDX_PRAGMA(x)`: Equivalent to `_Pragma(#x)`, which expands to `#pragma x`
- `STDX_PRAGMA_PUSH`: Equivalent to the appropriate form of `#pragma push`
- `STDX_PRAGMA_POP`: Equivalent to the appropriate form of `#pragma pop`
- `STDX_PRAGMA_IGNORE_STR(x)`:
	- GCC and Clang: Ignores the warning given by the string `x` (e.g., `-Wwarning-name`)
	- MSVC: Blank
- `STDX_PRAGMA_IGNORE_NUM(x)`:
	- MSVC: Ignores the warning given by the number `x` (e.g., `1111`)
	- GCC and Clang: Blank
- `STDX_PRAGMA_IGNORE(x)`:
	- GCC and Clang: Delegates to `STDX_PRAGMA_IGNORE_STR(x)`
	- MSVC: Delegates to `STDX_PRAGMA_IGNORE_NUM(x)`
  