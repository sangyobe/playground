

///////////////////////////////////////////////////////////////////////////////
// override assert
#include <cstdlib>   // for abort
#include <iostream>  // for std::cerr
#define my_assert(var) do { std::cerr << "assertion failed: " << #var << " in function " << __PRETTY_FUNCTION__ << " at " << __FILE__ << ":" << __LINE__ << std::endl;  abort(); } while(0);
///////////////////////////////////////////////////////////////////////////////

#ifdef NDEBUG
#define my_plain_assert(x)
#else
#include <assert.h>
#define my_plain_assert(x) assert(x)
#endif

#ifndef my_assert
#define my_assert(x) my_plain_assert(x)
#endif


int main()
{
    my_assert(1 == 0);
    return 0;
}