#include <iostream>
using namespace std;

template <typename T>
void print(T) { cout << "Generic" << endl; }
template <typename T>
void print(T *) { cout << "Overload" << endl; }
template <>
void print(double *) { cout << "Specialization" << endl; }

int main(int argc, char *argv[])
{
    double d = 1.5;
    print(&d);
    return 0;
}