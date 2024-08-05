#include <algorithm>
#include <cmath>
#include <dtMath/dtMath.h>
#include <iostream>

int main()
{
    dt::Math::Quaternion q;
    q.SetElement(0x02, -M_PI / 2);
    q.Print();

    return 0;
}