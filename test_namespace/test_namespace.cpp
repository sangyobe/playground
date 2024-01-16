#include <iostream>

namespace dt
{
    namespace Math
    {
        class Point2D
        {
        public:
            Point2D(float x_, float y_) : x(x_), y(y_) {}
            float x;
            float y;
        };
    }
}

using namespace std;
using dtPoint2D = dt::Math::Point2D;

int main()
{
    dt::Math::Point2D xy(2, 1);
    //dtPoint2D xy2(2,2);

    cout << "x=" << xy.x << ", y=" << xy.y << endl;

    return 0;
}