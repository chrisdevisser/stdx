#include <cmath>
#include <cstdlib>
#include <limits>
#include <stdexcept>

#include <stdx/util/floatcmp.hh>
#include <stdx/compiler/pragma/ignore.hh>
#include <stdx/compiler/pragma/pop.hh>
#include <stdx/compiler/pragma/push.hh>

static void makeNegativeOpposite(int &i) {
    if (i < 0) i = 0x80000000 - i;
}

STDX_PRAGMA_PUSH()
STDX_PRAGMA_IGNORE("-Wstrict-aliasing")
//STDX_PRAGMA_IGNORE_NUM()
//TODO: Fill in MSVC code

static bool withinUlp(float a, float b, const int ulp) {
    auto aa = *reinterpret_cast<int *>(&a);
    auto bb = *reinterpret_cast<int *>(&b);

    makeNegativeOpposite(aa);
    makeNegativeOpposite(bb);

    return std::abs(aa - bb) <= ulp;
}

STDX_PRAGMA_POP()

namespace stdx {
inline namespace util {

int fcmp(const float a, const float b) {
    if (std::isunordered(a, b)) throw std::invalid_argument{"Compared NaN."};

    if (withinUlp(a, b, 4)) return 0;
    if (a > b) return 1;
    return -1;
}

}
}
