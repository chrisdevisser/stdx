#include <cmath>
#include <stdexcept>
#include <stdx/util/angle.hh>
#include <stdx/util/floatcmp.hh>

namespace stdx {
inline namespace util {

//50 digits to be safe
constexpr long double PI = 3.14159265358979323846264338327950288419716939937510L;

Angle::Angle() noexcept : rad_{} {}

long double Angle::deg() const noexcept {return rad_ / PI * 180.0L;}
long double Angle::rad() const noexcept {return rad_;}

//private constructor
Angle::Angle(const long double _rad) noexcept : rad_{_rad} {}

Angle &Angle::operator+=(const Angle &rhs) noexcept {rad_ += rhs.rad(); return *this;}
Angle &Angle::operator-=(const Angle &rhs) noexcept {rad_ -= rhs.rad(); return *this;}
Angle &Angle::operator*=(const long double rhs) noexcept {rad_ *= rhs; return *this;}
Angle &Angle::operator/=(const long double rhs) noexcept {rad_ /= rhs; return *this;}
Angle &Angle::operator%=(const Angle &rhs) noexcept {rad_ = std::fmod(rad_, rhs.rad()); return *this;}

Angle operator+(Angle lhs, const Angle &rhs) noexcept {lhs += rhs; return lhs;}
Angle operator-(Angle lhs, const Angle &rhs) noexcept {lhs -= rhs; return lhs;}
Angle operator*(Angle lhs, const long double rhs) noexcept {lhs *= rhs; return lhs;}
Angle operator*(const long double lhs, Angle rhs) noexcept {rhs *= lhs; return rhs;}
Angle operator/(Angle lhs, const long double rhs) noexcept {lhs /= rhs; return lhs;}
long double operator/(const Angle &lhs, const Angle &rhs) noexcept {return lhs.rad() / rhs.rad();}
Angle operator%(Angle lhs, const Angle &rhs) noexcept {lhs %= rhs; return lhs;}

Angle operator+(const Angle &angle) noexcept {return angle;}
Angle operator-(const Angle &angle) noexcept {return Radians{-angle.rad()};}

bool operator<(const Angle &lhs, const Angle &rhs) {return fcmp(lhs.rad(), rhs.rad()) < 0;}
bool operator>(const Angle &lhs, const Angle &rhs) {return rhs < lhs;}
bool operator==(const Angle &lhs, const Angle &rhs) {return fcmp(lhs.rad(), rhs.rad()) == 0;}
bool operator<=(const Angle &lhs, const Angle &rhs) {return lhs < rhs || lhs == rhs;}
bool operator>=(const Angle &lhs, const Angle &rhs) {return lhs > rhs || lhs == rhs;}
bool operator!=(const Angle &lhs, const Angle &rhs) {return !(lhs == rhs);}

Angle &simplify(Angle &angle) noexcept {
    angle %= 360_deg;
    if (angle < 0_rad) angle += 360_deg;
    return angle;
}

Angle simplified(Angle angle) noexcept {
    simplify(angle);
    return angle;
}

Degrees::Degrees(const long double deg) noexcept : deg_{deg} {}
Degrees::operator Angle() const noexcept {return deg_ / 180 * PI;}

Radians::Radians(const long double rad) noexcept : rad_{rad} {}
Radians::operator Angle() const noexcept {return rad_;}

inline namespace lit {
    Degrees operator"" _deg(const long double deg) noexcept {return Degrees{deg};}
    Degrees operator"" _deg(const unsigned long long deg) noexcept {return Degrees(deg);}
    Radians operator"" _rad(const long double rad) noexcept {return Radians{rad};}
    Radians operator"" _rad(const unsigned long long rad) noexcept {return Radians(rad);}
}

}
}
