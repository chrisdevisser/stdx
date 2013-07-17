//Copyright Chris DeVisser 2013
//Code may be used freely in personal and commercial environments.
//Compiled with GCC 4.8.1 and MinGWBuilds - http://sourceforge.net/projects/mingwbuilds/

#include <cassert>
#include "../angle.hh"

int main() {
    using namespace stdx::AngleNs;

    constexpr Angle a;
    constexpr Angle b{23_deg};

    assert(a != b);
    assert(5_deg + 6_rad != 6_deg + 5_rad);
    assert(5_deg < 10_deg);
    assert(360_deg > 3_rad);
    assert(2 * 180_deg == Radians(2*PI));
    assert(simplified(360_deg) == Angle{});
    assert(simplified(750_deg) == 30_deg);
    assert(simplified(-120_deg) == 240_deg);

}

