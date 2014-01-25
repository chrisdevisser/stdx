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

- [Angle](classes/angle.md) - Store an angle with any units
- [Degrees](classes/degrees.md) - Helper class to create an Angle from degrees

- Helper class to create [Angle](classes/angle.md)
- Can be created with [_deg](udls/deg.md) suffix

- [Radians](classes/radians.md) - Helper class to create an Angle from radians

- Helper class to create [Angle](classes/angle.md)
- Can be created with [_rad](udls/rad.md) suffix

Free Functions
=

- [`Simplify`](../free/simplify.md) - Simplifies an angle to [0, 2 pi) in place
- [`Simplified`](../free/simplify.md) - Returns an angle simplified to [0, 2 pi)

User-Defined Literals
=

- [`deg`](udls/deg.md) - Creates a `Degrees` object
- [`rad`](udls/rad.md) - Creates a `Radians` object