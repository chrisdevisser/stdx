#include <cassert>
#include "../angle.hh"
#include "../compiler_diagnostics.hh"

int main() {
    using namespace stdx::AngleNs;

    constexpr Angle a;
    constexpr Angle b{23_deg};

    STDX_PRAGMA_PUSH
    STDX_PRAGMA_IGNORE_STR("-Wfloat-equal")
    static_assert(Angle{}.rad() == 0.0L, "Default constructed radians.");
    static_assert(Angle{}.deg() == 0.0L, "Default constructed degrees.");
    STDX_PRAGMA_POP

    assert(a != b);
    assert(5_deg + 6_rad != 6_deg + 5_rad);
    assert(5_deg < 10_deg);
    assert(360_deg > 3_rad);
    assert(2 * 180_deg == Radians(2*PI));
    assert(Simplified(360_deg) == Angle{});
    assert(Simplified(750_deg) == 30_deg);
    assert(Simplified(-120_deg) == 240_deg);

}

