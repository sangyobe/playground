#include <iostream>

enum class Number : uint8_t
{
    ZERO = 0,
    ONE = 1,
    TWO = 2,
    NUM_OF_NUMBER = 3
};

Number operator++(Number& n)
{
    n = (static_cast<uint8_t>(n) == static_cast<uint8_t>(Number::NUM_OF_NUMBER)-1) ? Number::ZERO : Number(static_cast<uint8_t>(n) + 1);
    return n;
}

int main()
{
    Number num = Number::ONE;
    ++num;
    ++num;

    static_assert(sizeof(Number::ZERO) == 1);

    std::cout << "num = " << static_cast<int>(num) << std::endl;
    return 0;
}