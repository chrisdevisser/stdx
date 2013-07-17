//Copyright Chris DeVisser 2013
//Code may be used freely in personal and commercial environments.
//Compiled with GCC 4.8.1 and MinGWBuilds - http://sourceforge.net/projects/mingwbuilds/

#include <cassert>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include "../floatcmp.hh"

int main() {
    using namespace stdx::FloatCmpNs;

    assert(fcmp(0., -0.) == 0);
    assert(fcmp(static_cast<double>(.7f), .7) == 0);
    assert(fcmp(1234560., 1234561.) != 0);

    assert(fcmp(0.1f, 0.09f) > 0);
    assert(fcmp(0.1f, 0.101f) < 0);

    assert(fcmp(0.1, 0.09) > 0);
    assert(fcmp(0.1, 0.101) < 0);

    assert(fcmp(0.1L, 0.09L) > 0);
    assert(fcmp(0.1L, 0.101L) < 0);

    try {
        fcmp(std::nan(""), std::nan(""));
    } catch (const std::invalid_argument &ex) {
        std::cout << "Double NaN exception thrown.\n";
    }

    try {
        fcmp(std::nan(""), 0);
    } catch (const std::invalid_argument &ex) {
        std::cout << "Single NaN exception thrown.\n";
    }
}

