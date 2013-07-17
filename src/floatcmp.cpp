//Copyright Chris DeVisser 2013
//Code may be used freely in personal and commercial environments.
//Compiled with GCC 4.8.1 and MinGWBuilds - http://sourceforge.net/projects/mingwbuilds/

#include <cmath>
#include <cstdlib>
#include <limits>
#include <stdexcept>

#include "../floatcmp.hh"
#include "../compiler_diagnostics.hh"

void makeNegativeOpposite(int &i) {
    if (i < 0) i = 0x80000000 - i;
}

STDX_PRAGMA_PUSH
STDX_PRAGMA_IGNORE_STR("-Wstrict-aliasing")
//STDX_PRAGMA_IGNORE_NUM()
//TODO: Fill in MSVC code

bool withinUlp(float a, float b, const int ulp) {
    auto aa = *reinterpret_cast<int *>(&a);
    auto bb = *reinterpret_cast<int *>(&b);

    makeNegativeOpposite(aa);
    makeNegativeOpposite(bb);

    return std::abs(aa - bb) <= ulp;
}

STDX_PRAGMA_POP

namespace stdx {
inline namespace FloatCmpNs {

int fcmp(const float a, const float b) {
    if (std::isunordered(a, b)) throw std::invalid_argument{"Compared NaN."};

    if (withinUlp(a, b, 4)) return 0;
    if (a > b) return 1;
    return -1;
}

}
}
