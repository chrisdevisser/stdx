Summary
=

- Intermediary step of creating [`Angle`](angle.md) from radians.

Constructors
=

    explicit Radians(long double rad) noexcept;

Creates a radians representation of `rad` radians.

Operators
=

    operator Angle() const noexcept;

Returns an `Angle` object with the value of the current radians.

User-Defined Literals
=

	Radians operator"" _rad(long double rad) noexcept;
    Radians operator"" _rad(unsigned long long rad) noexcept;

Constructs a `Radians` object from the given number of radians. 