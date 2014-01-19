//Compares floating-point numbers using 4 ULPs.
//std::invalid_argument: NaN was compared
//0: Equal
//1: First > Second
//-1 First < Second

#ifndef STDX_FLOATCMP_H
#define STDX_FLOATCMP_H

namespace stdx {
inline namespace FloatCmpNs {

int Fcmp(float a, float b);

}
}

#endif
