//Copyright Chris DeVisser 2013
//Code may be used freely in personal and commercial environments.
//Compiled with GCC 4.8.1 and MinGWBuilds - http://sourceforge.net/projects/mingwbuilds/

//Compares floating-point numbers using 4 ULPs.
//std::invalid_argument: NaN was compared
//0: Equal
//1: First > Second
//-1 First < Second

#ifndef STDX_FLOATCMP_H
#define STDX_FLOATCMP_H

namespace stdx {
inline namespace FloatCmpNs {

int fcmp(float a, float b);

}
}

#endif