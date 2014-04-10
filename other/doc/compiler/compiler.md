`<stdx/compiler.hh>`

Summary
=

Provides some utilities for detecting compilers and doing compiler-dependent tasks in a more uniform manner.

Namespace
=

Since everything is a macro, no namespace applies. Instead, all default-provided macros are prefixed with `STDX_`.   
    
Dependencies
=

No dependencies at this time.

Layout
=

`detection.hh`

- Provides compiler detection
  
`unused.hh` 

- Declare something as unused  


`pragma.hh` and `pragma/` 

- Compiler-specific pragmas

Macros
=

Compiler Detection
-

    STDX_CLANG

1 if `__clang__` is defined, or 0 otherwise

    STDX_GCC

1 if `__GNUC__` is defined, or 0 otherwise

    STDX_MSVC

1 if `_MSC_VER` is defined, or 0 otherwise

Compiler-Dependent Utilities
-

    STDX_UNUSED

Informs the compiler that a variable or function is not used, and that the compiler should not issue a warning. If `STDX_USE_SHORT_NAMES` is defined, `unused_` will act the same way.

For example, `STDX_UNUSED int i;` or `unused_ void foo();`

Compiler Pragmas
-

- See [Pragmas](pragma/pragma.md)
  