#include <functional>
#include <iostream>
#include <chrono>
#include <thread>
#include "dtTimeCheck.h"

#define DATA_LEN (10000)
using DATA_TYPE = long long;

template<typename T, int len>
void test1(T data[len])
{
    T sum = 0;
    for (int i=0; i<len; i++) {
        for (int j=0; j<len; j++) {
            sum += data[i];
        }
    }
    std::cout << "test1: sum=" << sum << std::endl;
}

template<typename T, int len>
void test2(T data[len])
{
    T sum = 0;
    for (int i=0; i<len; i++) {
        for (int j=0; j<len; j++) {
            sum += data[j];
        }
    }
    std::cout << "test2: sum=" << sum << std::endl;
}

int main() 
{
    DATA_TYPE data[DATA_LEN];
    for (int i=0; i<DATA_LEN; i++)
        data[i] = i;

    dtTimeCheck timer;

    timer.Start();
    test1<DATA_TYPE, DATA_LEN>(data);
    timer.Stop();
    std::cout << "elapsed time: " << timer.GetElapsedTime_msec() << " (msec)\n";


    timer.Start();
    test2<DATA_TYPE, DATA_LEN>(data);
    timer.Stop();
    std::cout << "elapsed time: " << timer.GetElapsedTime_msec() << " (msec) - simulate cache miss case\n";

    return 0;
}