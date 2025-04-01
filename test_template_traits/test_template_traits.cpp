/** 
 * SFINAE
 * : Substitubion Failure Is Not An Error.
 */

#include <iostream>
#include <type_traits> // C++11 introduce type_traits
#include <vector>
using namespace std;
#include "spdlog/fmt/fmt.h"

#if 0
// Template specialization
template <typename T, bool>
struct printHelper
{
    static void print(T const &t) { fmt::print("{}\n", t); }
};

template <typename T>
struct printHelper<T, true>
{
    static void print(T const &t) { fmt::print("{}\n", *t); }
};

template <typename T>
void print(T const &t)
{
    printHelper<T, std::is_pointer<T>::value>::print(t);
}
#else
// C++17: use if constexpr
template <typename T>
void print(T const &t)
{
    if constexpr (std::is_pointer<T>::value)
    {
        fmt::print("{}\n", *t);
    }
    else
    {
        fmt::print("{}\n", t);
    }
}
#endif

template <typename T>
struct is_container
{
    template <typename S>
    static std::byte f(...);

    template <typename S>
    static std::size_t f(typename S::iterator *);

    static const bool value = (sizeof(f<T>(0)) == sizeof(std::size_t));
};

int main(int argc, char *argv[])
{
    double d = 1.5;
    print(d);

    double p = 2.5;
    print(&p);

    fmt::print("int is {}\n", (is_container<int>::value ? "a container." : "not a container."));
    fmt::print("std::vector is {}\n", (is_container<std::vector<int>>::value ? "a container." : "not a container."));

    return 0;
}