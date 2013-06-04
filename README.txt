This is a newly-started C++11-reliant library that is implemented using only the standard headers. Boost is a slight possibility if something would really benefit from it.

Current features:
-take Angle as a parameter and use Degrees or Radians object as argument for explicitness
-both degrees and radians have user-defined litetals
-Angle can only be instantiated through Degrees or Radians

-make an enum class usable as flags through the MAKE_ENUM_FLAGS macro, which takes the name, the new name, and the number of bits required to hold the flags

This is mainly compiled with GCC. At the time of writing, I use the MinGWBuilds GCC 4.8.1, which has standard threading that works on Windows. I'm fairly pedantic with warnings, and I aim for a clean build with at least -Wall, -Wextra, and -pedantic.