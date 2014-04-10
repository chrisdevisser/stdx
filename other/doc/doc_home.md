Summary
=

`stdx` is a bunch of extensions to the C++ standard library, mostly for my own use and enjoyment. All should compile with Clang 3.5 and the following options:

    -std=c++1y -Wall -Wextra -pedantic-errors

Namespace
=

Everything is in the `stdx` namespace.

Dependencies
=

None at this time. Possibly Boost in the future.

Components
=

Each utility has its own file and/or folder. Files with the same name as same-level folder include everything in that folder. For example, `<stdx/compiler.hh>` includes everything in `<stdx/compiler>`. 

The utilities are as follows:

[Angle](util/angle/angle.md) 
-
`<stdx/util/angle.hh>` 


- One [`Angle`](util/angle/classes/angle.md) class
- Can be created from [`Degrees`](util/angle/classes/degrees.md) and [`Radians`](util/angle/classes/radians.md) classes
- Provides `deg` and `rad` functions to retrieve the value as needed
- Provides user-defined literals `_deg` and `_rad` to create literal angles