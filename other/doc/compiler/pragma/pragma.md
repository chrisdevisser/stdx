Summary
=

Provides compiler-specific pragmas in a general form.

Contents
=

Macros
-

    STDX_PRAGMA(x)
Equivalent to `_Pragma(#x)`, which expands to `#pragma x`

    STDX_PRAGMA_PUSH()

Equivalent to the appropriate form of `#pragma push`

    STDX_PRAGMA_POP()

Equivalent to the appropriate form of `#pragma pop`

    STDX_PRAGMA_MESSAGE(message)

Equivalent to the appropriate form of `#pragma message`

    STDX_PRAGMA_IGNORE_STR(x)

- GCC and Clang: Ignores the warning given by the string `x` (e.g., `-Wwarning-name`)
- MSVC: Blank

<b></b> <!-- To stop list -->

     STDX_PRAGMA_IGNORE_NUM(x)

- MSVC: Ignores the warning given by the number `x` (e.g., `1111`)
- GCC and Clang: Blank

<b></b>

    STDX_PRAGMA_IGNORE(x)

- GCC and Clang: Delegates to `STDX_PRAGMA_IGNORE_STR(x)`
- MSVC: Delegates to `STDX_PRAGMA_IGNORE_NUM(x)`