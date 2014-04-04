//Compares floating-point numbers using 4 ULPs.
//std::invalid_argument: NaN was compared
//0: Equal
//1: First > Second
//-1 First < Second

#pragma once

namespace stdx {
inline namespace util {

int fcmp(float a, float b);

}
}