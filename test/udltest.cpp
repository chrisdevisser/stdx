//Copyright Chris DeVisser 2013
//Code may be used freely in personal and commercial environments.
//Compiled with GCC 4.8.1 and MinGWBuilds - http://sourceforge.net/projects/mingwbuilds/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <thread>
#include <stdx/udl.hh>

int main() {
    using namespace stdx::lit;

    auto str = "abc"_s;
    assert(str.length() == 3);
    assert(str == std::string("abc"));

    auto wstr = L"abc"_s;
    assert(wstr.length() == 3);
    assert(wstr == std::wstring(L"abc"));

    assert(std::equal(std::begin(str), std::end(str), std::begin(wstr)));

    std::cout << "Sleeping for 1 billion nanoseconds.\n";
    std::this_thread::sleep_for(1000000000_ns);

    std::cout << "Sleeping for 1 million microseconds.\n";
    std::this_thread::sleep_for(1000000_us);

    std::cout << "Sleeping for 1000 milliseconds.\n";
    std::this_thread::sleep_for(1000_ms);

    std::cout << "Sleeping for 1 second.\n";
    std::this_thread::sleep_for(1_s);

    std::cout << "Sleeping for 1/60 minutes.\n";
    std::this_thread::sleep_for(0.0167_min);

    std::cout << "Sleeping for 1/3600 hours.\n";
    std::this_thread::sleep_for(0.000277_h);
}
