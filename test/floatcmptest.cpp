#include <cassert>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include "../floatcmp.hh"

int main() {
    using namespace stdx::FloatCmpNs;

    assert(Fcmp(0., -0.) == 0);
    assert(Fcmp(static_cast<double>(.7f), .7) == 0);
    assert(Fcmp(1234560., 1234561.) != 0);

    assert(Fcmp(0.1f, 0.09f) > 0);
    assert(Fcmp(0.1f, 0.101f) < 0);

    assert(Fcmp(0.1, 0.09) > 0);
    assert(Fcmp(0.1, 0.101) < 0);

    assert(Fcmp(0.1L, 0.09L) > 0);
    assert(Fcmp(0.1L, 0.101L) < 0);

    try {
        Fcmp(std::nan(""), std::nan(""));
    } catch (const std::invalid_argument &ex) {
        std::cout << "Double NaN exception thrown.\n";
    }

    try {
        Fcmp(std::nan(""), 0);
    } catch (const std::invalid_argument &ex) {
        std::cout << "Single NaN exception thrown.\n";
    }
}

