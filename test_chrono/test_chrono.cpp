#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

void BigLoop()
{
    for (int i = 1; i <= 50000; i++)
    {
        for (int j = 1; j <= 50000; j++)
        {
            int x = (i + j) * 2 + (i / j);
        }
    }
}

int main() {
    // now() 함수를 통해 현재 시간값을 구한다.
    system_clock::time_point start = system_clock::now();
 
    BigLoop();
 
    system_clock::time_point end = system_clock::now();
 
    // 초 단위 (소수점으로 표현)
    duration<double> sec = end - start;

    cout << sec.count() << endl;

    return 0;
}