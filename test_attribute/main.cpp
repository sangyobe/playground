#include <algorithm>
#include <iostream>

using namespace std;

[[noreturn]] void trw()
{
    throw "error";
}

[[noreturn]] void func(int a)
{
    //
}

[[noreturn]] int foo()
{
    return 1; // warning
}

int bar [[noreturn]] (int n)
{
    return 2; // warning
}

[[nodiscard]] int twice(int x)
{
    return x * 2;
}

int main()
{
    func(10);

    cout << foo();
    cout << bar(10);

    twice(1);
    (void)twice(2);

    return 0;
}