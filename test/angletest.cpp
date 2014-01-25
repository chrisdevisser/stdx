#include <cassert>
#include "../angle.hh"
#include "../compiler_diagnostics.hh"

int main() {
    using namespace stdx::AngleNs;

    Angle a;
    Angle b(23_deg);

    assert(Angle{}.rad() == 0.0L);
    assert(Angle{}.deg() == 0.0L);

    assert(a != b);
    assert(5_deg + 6_rad != 6_deg + 5_rad);
    assert(5_deg < 10_deg);
    assert(360_deg > 3_rad);
    assert(2 * 180_deg == Radians(2*3.14159265358979323846264338327950288419716939937510L));
    assert(Simplified(360_deg) == Angle{});
    assert(Simplified(750_deg) == 30_deg);
    assert(Simplified(-120_deg) == 240_deg);

}

