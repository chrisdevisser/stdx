//Copyright Chris DeVisser 2013
//Code may be used freely in personal and commercial environments.
//Compiled with GCC 4.8.1 and MinGWBuilds - http://sourceforge.net/projects/mingwbuilds/

//Clarifies angle measurements. Angles can only be created through Degrees or Radians.

#ifndef STDX_ANGLE_H
#define STDX_ANGLE_H

namespace stdx {

static constexpr double PI = 3.14159265358979;

struct Degrees;
struct Radians;

struct Angle {
    friend class Degrees;
    friend class Radians;

    double deg() const noexcept {
        return rad_ * 180 / PI;
    }

    double rad() const noexcept {
        return rad_;
    }

private:
    double rad_;

    constexpr Angle(double r) noexcept
        : rad_{r} {}
};

struct Degrees {
    constexpr explicit Degrees(double deg) noexcept
        : deg_{deg} {}

    operator Angle() const noexcept {
        return deg_ * PI / 180;
    }

private:
    double deg_;
};

struct Radians {
    constexpr explicit Radians(double rad) noexcept
        : rad_{rad} {}

    operator Angle() const noexcept {
        return rad_;
    }

private:
    double rad_;
};

inline constexpr Degrees operator"" _deg(long double d) noexcept {
    return Degrees(d);
}

inline constexpr Degrees operator"" _deg(unsigned long long d) noexcept {
    return Degrees(d);
}

inline constexpr Radians operator"" _rad(long double r) noexcept {
    return Radians(r);
}

inline constexpr Radians operator"" _rad(unsigned long long r) noexcept {
    return Radians(r);
}

}

#endif
