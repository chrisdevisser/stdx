Summary
=

- Intermediary step of creating [`Angle`](angle.md) from degrees.

Constructors
=

    explicit Degrees(long double deg) noexcept;

Creates a degrees representation of `deg` degrees.

Operators
=

    operator Angle() const noexcept;

Returns an `Angle` object with the value of the current degrees.

User-Defined Literals
=

	Degrees operator"" _deg(long double deg) noexcept;
    Degrees operator"" _deg(unsigned long long deg) noexcept;

Constructs a `Degrees` object from the given number of degrees. 