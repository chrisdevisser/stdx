Summary
=

- Only constructible with a value via [Degrees](classes/degrees.md) and [Radians](classes/radians.md)
- Acts like a numeric type
- Conversion to degrees and radians

Members
=

- [(constructor)](members/ctor) - Creates a new instance
- [`deg`](members/deg) - Gets value in degrees
- [`rad`](members/rad) - Gets value in radians

Free Functions
=

- [`Simplify`](../free/simplify.md) - Simplifies an angle to [0, 2 pi) in place
- [`Simplified`](../free/simplify.md) - Returns an angle simplified to [0, 2 pi)

Operators
=

- [`operator=`](operators/assign.md) - Assigns the value of another Angle
- [`operator+`](operators/plus.md) - Adds two Angles
- [`operator+=`](operators/plus.md) - Adds another Angle
- [`operator-`](operators/minus.md) - Subtracts one Angle from another
- [`operator-=`](operators/plus.md) - Subtracts another Angle
- [`operator*`](operators/times.md) - Scales an Angle
- [`operator*=`](operators/plus.md) - Scales Angle
- [`operator/`](operators/divide.md) - Shrinks an angle or divides two Angles
- [`operator/=`](operators/divide.md) - Shrinks Angle 
- [`operator%`](operators/remainder.md) - Calculates remainder of one Angle divided by another. The resulting sign is the sign of the first argument
- [`operator%=`](operators/remainder.md) - Takes on the remainder of being divided by another Angle. The sign is left unchanged. 
- [`operator+`](operators/unaryplus.md) - Takes the positive value of an Angle
- [`operator-`](operators/negate.md) - Calculates the negative of an Angle
- [`operator<`](operators/less.md) - Calculates whether one Angle is smaller than another
- [`operator<=`](operators/less.md) - Calculates whether one Angle is smaller than or equal to another
- [`operator>`](operators/greater.md) - Calculates whether one Angle is greater than another
- [`operator>=`](operators/greater.md) - Calculates whether one Angle is greater than or equal to another
- [`operator==`](operators/equal.md) - Calculates whether one Angle is equal to another
- [`operator!=`](operators/equal.md) - Calculates whether one Angle is not equal to another