//Copyright Chris DeVisser 2013
//Code may be used freely in personal and commercial environments.
//Compiled with GCC 4.8.1 and MinGWBuilds - http://sourceforge.net/projects/mingwbuilds/

#include <cmath>
#include <stdexcept>
#include "../angle.hh"
#include "../floatcmp.hh"

namespace stdx {
inline namespace AngleNs {

long double Angle::deg() const noexcept {return rad_ / PI * 180;}
long double Angle::rad() const noexcept {return rad_;}

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
Angle operator/(const long double lhs, Angle rhs) noexcept {rhs /= lhs; return rhs;}
Angle operator%(Angle lhs, const Angle &rhs) noexcept {lhs %= rhs; return lhs;}

Angle operator+(const Angle &angle) noexcept {return angle;}
Angle operator-(const Angle &angle) noexcept {return Radians{-angle.rad()};}

bool operator<(const Angle &lhs, const Angle &rhs) {return Fcmp(lhs.rad(), rhs.rad()) < 0;}
bool operator>(const Angle &lhs, const Angle &rhs) {return rhs < lhs;}
bool operator==(const Angle &lhs, const Angle &rhs) {return Fcmp(lhs.rad(), rhs.rad()) == 0;}
bool operator<=(const Angle &lhs, const Angle &rhs) {return lhs < rhs || lhs == rhs;}
bool operator>=(const Angle &lhs, const Angle &rhs) {return lhs > rhs || lhs == rhs;}
bool operator!=(const Angle &lhs, const Angle &rhs) {return !(lhs == rhs);}

Angle &Simplify(Angle &angle) noexcept {
    angle %= 360_deg;
    if (angle < 0_rad) angle += 360_deg;
    return angle;
}

Angle Simplified(Angle angle) noexcept {
    Simplify(angle);
    return angle;
}

}
}
