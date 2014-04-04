Summary
=

Abstracts the different units of angles into a single `Angle` class. Now your functions can just have an `Angle` parameter and the caller can use the most convenient units. Internally, the value is stored as radians.

Namespace
=

>
- `stdx` - main namespace       
    - `AngleNs` (inline) - everything Angle
        - `lit` (inline) - user-defined literals 

Dependencies
=

- [Floatcmp](../Floatcmp/floatcmp.md)

Classes
=

- [`Angle`](classes/angle.md) - Store an angle with any units
- [`Degrees`](classes/degrees.md) - Helper class to create an `Angle` from degrees

- [`Radians`](classes/radians.md) - Helper class to create an `Angle` from radians

Free Functions
=

- [`Simplify`](classes/angle.md) - Simplifies an angle to `[0, 2 pi)` in place
- [`Simplified`](classes/angle.md) - Returns an angle simplified to `[0, 2 pi)`

User-Defined Literals
=

- [`_deg`](classes/degrees.md) - Creates a `Degrees` object
- [`_rad`](classes/radians.md) - Creates a `Radians` object


