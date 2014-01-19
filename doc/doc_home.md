Summary
=

`stdx` is a bunch of extensions to the C++ standard library. All should compile with GCC 4.8.1 and the following options:

    -std=c++1y -Wall -Wextra -pedantic-errors

Namespace
=

Everything is in the `stdx` namespace.

Requirements
=

None at this time. Possibly Boost in the future.

Components
=

The utilities are as follows:

[Angle](angle/angle.md)
-

- One `Angle` class
- Can be created from `Degree` and `Radian` classes
- Provides `deg` and `rad` functions
- Provides user-defined literals