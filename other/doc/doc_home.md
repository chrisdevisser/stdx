Summary
=

`stdx` is a bunch of extensions to the C++ standard library. All should compile with Clang 3.5 and the following options:

    -std=c++1y -Wall -Wextra -pedantic-errors

Namespace
=

Everything is in the `stdx` namespace.

Dependencies
=

None at this time. Possibly Boost in the future.

Components
=

The utilities are as follows:

[Angle](Angle/angle.md)
-

- One [`Angle`](Angle/classes/angle.md) class
- Can be created from [`Degrees`](Angle/classes/degrees.md) and [`Radians`](Angle/classes/radians.md) classes
- Provides `deg` and `rad` functions to retrieve the value as needed
- Provides user-defined literals `_deg` and `_rad` to create literal angles