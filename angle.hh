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

    constexpr Angle() noexcept
        : Angle{0.} {}

    double deg() const noexcept {
        return rad_ * 180 / PI;
    }

    double rad() const noexcept {
        return rad_;
    }

    Angle &operator+=(const Angle &rhs) noexcept {
        rad_ += rhs.rad_;
        return *this;
    }

    Angle &operator-=(const Angle &rhs) noexcept {
        rad_ -= rhs.rad_;
        return *this;
    }

    Angle &operator*=(const double rhs) noexcept {
        rad_ *= rhs;
        return *this;
    }

    Angle &operator/=(const double rhs) noexcept {
        rad_ /= rhs;
        return *this;
    }

private:
    double rad_;

    constexpr Angle(const double r) noexcept
        : rad_{r} {}
};

inline Angle operator+(Angle lhs, const Angle &rhs) noexcept {
    return lhs += rhs;
}

inline Angle operator-(Angle lhs, const Angle &rhs) noexcept {
    return lhs -= rhs;
}

inline Angle operator*(Angle lhs, const double rhs) noexcept {
    return lhs *= rhs;
}

inline Angle operator*(const double lhs, Angle rhs) noexcept {
    return rhs *= lhs;
}

inline Angle operator/(Angle lhs, const double rhs) noexcept {
    return lhs /= rhs;
}

inline Angle operator/(const double lhs, Angle rhs) noexcept {
    return rhs /= lhs;
}

struct Degrees {
    constexpr explicit Degrees(const double deg) noexcept
        : deg_{deg} {}

    operator Angle() const noexcept {
        return deg_ * PI / 180;
    }

private:
    double deg_;
};

struct Radians {
    constexpr explicit Radians(const double rad) noexcept
        : rad_{rad} {}

    operator Angle() const noexcept {
        return rad_;
    }

private:
    double rad_;
};

inline constexpr Degrees operator"" _deg(const long double d) noexcept {
    return Degrees{d};
}

inline constexpr Degrees operator"" _deg(const unsigned long long d) noexcept {
    return Degrees{d};
}

inline constexpr Radians operator"" _rad(const long double r) noexcept {
    return Radians{r};
}

inline constexpr Radians operator"" _rad(const unsigned long long r) noexcept {
    return Radians{r};
}

}

#endif
