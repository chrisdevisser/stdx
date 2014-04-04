Summary
=

- Only constructible with a value via [Degrees](classes/degrees.md) and [Radians](classes/radians.md)
- Acts like a numeric type
- Conversion to degrees and radians

Constructors
=

    Angle();

Creates a new angle with a value of 0.

Members
=

    long double deg() const noexcept;

Retrieves the angle value in degrees. This retrieval causes a conversion calculation.

    long double rad() const noexcept;

Retrieves the angle value in radians. No conversion calculation will occur.

Free Functions
=

    Angle &Simplify(Angle &angle) noexcept;

Fits `angle` to the range `[0, 2 pi)` in place. 

    Angle Simplified(Angle angle) noexcept;

Returns `angle` fitted to the range `[0, 2 pi)`.

Operators
=

    Angle operator+(Angle lhs, const Angle &rhs) noexcept;
    Angle &operator+=(const Angle &rhs) noexcept;

Adds two angles together. For example, pi radians + 180 degrees = 360 degrees or 2 pi radians.

    Angle operator-(Angle lhs, const Angle &rhs) noexcept;
    Angle &operator-=(const Angle &rhs) noexcept;

Subtracts one angle from another. For example, 360 degrees - pi radians = 180 degrees or pi radians.

    Angle operator*(Angle lhs, const long double rhs) noexcept;
    Angle operator*(const long double lhs, Angle rhs) noexcept;
    Angle &operator*=(const long double rhs) noexcept;

Scales an angle. For example, 2 * 180 degrees = 2 pi radians or 360 degrees.

    long double operator/(Angle lhs, const Angle &rhs) noexcept; (1)
    Angle operator/(Angle lhs, const long double rhs) noexcept; (2)
    Angle &operator/=(const long double rhs) noexcept;

1) Returns one angle as a fraction of another. For example, 30 degrees / 180 degrees = 1/6.   
2,3) Scales the angle downwards. For example, 360 degrees / 2 = 180 degrees or pi radians.

    Angle operator%(Angle lhs, const Angle &rhs) noexcept;
    Angle &operator%=(const Angle &rhs) noexcept;

Calculates the remainder of one angle divided by another. If only one argument is negative, the sign of the result is undefined.

    Angle operator+(const Angle &angle) noexcept;

Takes the positive of an angle. For example, +(2 radians) is 2 radians.

    Angle operator-(const Angle &angle) noexcept;

Takes the negative of an angle. For example, -(200 degrees) is -200 degrees.

    bool operator<(const Angle &lhs, const Angle &rhs);
    bool operator<=(const Angle &lhs, const Angle &rhs);

Determines whether one angle is less than (or equal to) another. For example, 100 degrees < pi radians.

    bool operator>(const Angle &lhs, const Angle &rhs);
    bool operator>=(const Angle &lhs, const Angle &rhs);

Determines whether one angle is greater than (or equal to) another. For example, 360 degrees > pi radians.
    
    bool operator==(const Angle &lhs, const Angle &rhs);

Determines whether one angle is equal to another. For example, pi radians == 180 degrees.

    bool operator!=(const Angle &lhs, const Angle &rhs);

Determines whether one angle is not equal to another. For example, 3 radians != 10 degrees.