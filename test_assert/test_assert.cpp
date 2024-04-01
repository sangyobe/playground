/**
 * dt_assert - macro with one argument that is used inside this for assertions. By default, it is basically defined to be assert, which aborts the program if the assertion is violated. Redefine this macro if you want to do something else, like throwing an exception.
 */
#include <cstdlib>   // for abort
#include <iostream>  // for std::cerr
#define dt_assert(var) \
    do { \
        if (!(bool)(var)) { \
            std::cerr << "assertion failed: " << #var << " in function " << __PRETTY_FUNCTION__ << " at " << __FILE__ << ":" << __LINE__ << std::endl; \
            abort(); \
        } \
    } while(false)

/**
 * MY_NDEBUG - disables assertions if defined. Not defined by default, unless the NDEBUG macro is defined (this is a standard C++ macro which disables all asserts).
 */
#ifdef NDEBUG
#define MY_NDEBUG
#endif

#ifdef MY_NDEBUG
#define my_plain_assert(x)
#else
#include <assert.h>
#define my_plain_assert(x) assert(x)
#endif

#ifndef dt_assert
#define dt_assert(x) my_plain_assert(x)
#endif

int main()
{
    dt_assert(0 == 1);
    return 0;
}