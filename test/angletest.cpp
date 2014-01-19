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
    assert(Simplified(360_deg) == Angle{});
    assert(Simplified(750_deg) == 30_deg);
    assert(Simplified(-120_deg) == 240_deg);

}

