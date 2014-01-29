//Clarifies angle measurements. Angles can only be created through Degrees or Radians.
//
//Usage:
//
//void foo(Angle angle) {
//    std::cout << "Degrees: " << angle.deg() << "\n";
//    std::cout << "Radians: " << angle.rad() << "\n";
//}
//...
//foo(120); //error
//foo(120_deg); //ok
//foo(120_rad); //ok
//foo(Degrees(120)); //ok

#pragma once
#ifndef STDX_ANGLE_H
#define STDX_ANGLE_H

namespace stdx {
inline namespace AngleNs {

struct Degrees;
struct Radians;

struct Angle {
    friend struct Degrees;
    friend struct Radians;

    Angle() noexcept;

    long double deg() const noexcept;
    long double rad() const noexcept;

    Angle &operator+=(const Angle &rhs) noexcept;
    Angle &operator-=(const Angle &rhs) noexcept;
    Angle &operator*=(long double rhs) noexcept;
    Angle &operator/=(long double rhs) noexcept;
    Angle &operator%=(const Angle &rhs) noexcept;

private:
    long double rad_;

    //only Degrees and Radians can use
    Angle(long double _rad) noexcept;
};

Angle operator+(Angle lhs, const Angle &rhs) noexcept;
Angle operator-(Angle lhs, const Angle &rhs) noexcept;
Angle operator*(Angle lhs, long double rhs) noexcept;
Angle operator*(const long double lhs, Angle rhs) noexcept;
Angle operator/(Angle lhs, long double rhs) noexcept;
long double operator/(Angle lhs, const Angle &rhs) noexcept;
Angle operator%(Angle lhs, const Angle &rhs) noexcept;

Angle operator+(const Angle &angle) noexcept;
Angle operator-(const Angle &angle) noexcept;

bool operator<(const Angle &lhs, const Angle &rhs);
bool operator<=(const Angle &lhs, const Angle &rhs);
bool operator>(const Angle &lhs, const Angle &rhs);
bool operator>=(const Angle &lhs, const Angle &rhs);
bool operator==(const Angle &lhs, const Angle &rhs);
bool operator!=(const Angle &lhs, const Angle &rhs);

//makes angle [0, 2 pi)
Angle &Simplify(Angle &angle) noexcept;
Angle Simplified(Angle angle) noexcept;

struct Degrees {
    explicit Degrees(long double deg) noexcept;
    operator Angle() const noexcept;

private:
    const long double deg_;
};

struct Radians {
    explicit Radians(long double rad) noexcept;
    operator Angle() const noexcept;

private:
    const long double rad_;
};

inline namespace lit {
    Degrees operator"" _deg(long double deg) noexcept;
    Degrees operator"" _deg(unsigned long long deg) noexcept;
    Radians operator"" _rad(long double rad) noexcept;
    Radians operator"" _rad(unsigned long long rad) noexcept;
}

}
}

#endif
