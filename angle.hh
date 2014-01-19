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

#ifndef STDX_ANGLE_H
#define STDX_ANGLE_H

namespace stdx {
inline namespace AngleNs {

static constexpr long double PI = 3.1415926535897932384626433832795028841972;

class Degrees;
class Radians;

struct Angle {
    friend class Degrees;
    friend class Radians;

    constexpr Angle() noexcept : rad_{} {};

    long double deg() const noexcept;
    long double rad() const noexcept;

    Angle &operator+=(const Angle &rhs) noexcept;
    Angle &operator-=(const Angle &rhs) noexcept;
    Angle &operator*=(const long double rhs) noexcept;
    Angle &operator/=(const long double rhs) noexcept;
    Angle &operator%=(const Angle &rhs) noexcept;

private:
    long double rad_;

    constexpr Angle(const long double _rad) noexcept : rad_{_rad} {}
};

Angle operator+(Angle lhs, const Angle &rhs) noexcept;
Angle operator-(Angle lhs, const Angle &rhs) noexcept;
Angle operator*(Angle lhs, const long double rhs) noexcept;
Angle operator*(const long double lhs, Angle rhs) noexcept;
Angle operator/(Angle lhs, const long double rhs) noexcept;
Angle operator/(const long double lhs, Angle rhs) noexcept;
Angle operator%(Angle lhs, const Angle &rhs) noexcept;

Angle operator+(const Angle &angle) noexcept;
Angle operator-(const Angle &angle) noexcept;

bool operator<(const Angle &lhs, const Angle &rhs);
bool operator<=(const Angle &lhs, const Angle &rhs);
bool operator>(const Angle &lhs, const Angle &rhs);
bool operator>=(const Angle &lhs, const Angle &rhs);
bool operator==(const Angle &lhs, const Angle &rhs);
bool operator!=(const Angle &lhs, const Angle &rhs);

Angle &Simplify(Angle &angle) noexcept;
Angle Simplified(Angle angle) noexcept;

struct Degrees {
    constexpr explicit Degrees(const long double deg) noexcept : deg_{deg} {}
    constexpr operator Angle() const noexcept {return deg_ / 180 * PI;}

private:
    const long double deg_;
};

struct Radians {
    constexpr explicit Radians(const long double rad) noexcept : rad_{rad} {}
    constexpr operator Angle() const noexcept {return rad_;}

private:
    const long double rad_;
};

constexpr Degrees operator"" _deg(const long double deg) noexcept {return Degrees{deg};}
constexpr Degrees operator"" _deg(const unsigned long long deg) noexcept {return Degrees(deg);}
constexpr Radians operator"" _rad(const long double rad) noexcept {return Radians{rad};}
constexpr Radians operator"" _rad(const unsigned long long rad) noexcept {return Radians(rad);}

}
}

#endif
