#include <algorithm>
#include <cmath>
#include <dtMath/dtMath.h>
#include <iostream>

int main()
{
    ////////////////////////////////////////////////////
    // Quaternion
    std::cout << "Quaterion :" << std::endl;
    dt::Math::Quaternion q;
    q.SetElement(0x02, -M_PI / 2);
    q.Print();

    ////////////////////////////////////////////////////
    // dt::Math::Matrix<2, 2, double>
    std::cout << "dt::Math::Matrix<2, 2, double> :" << std::endl;
    dt::Math::Matrix<2, 2, double> dmat;
    dmat.SetIdentity();
    dmat.Print();

    ////////////////////////////////////////////////////
    // dt::Math::Matrix<2, 2, int32_t>
    std::cout << "dt::Math::Matrix<2, 2, int32_t> :" << std::endl;
    dt::Math::Matrix<2, 2, int> imat;
    imat.SetIdentity();
    imat.Print();

    ////////////////////////////////////////////////////
    // dt::Math::Matrix<2, 2, uint32_t>
    std::cout << "dt::Math::Matrix<2, 2, uint32_t> :" << std::endl;
    dt::Math::Matrix<2, 2, unsigned int> uimat;
    uimat.SetIdentity();
    uimat.Print();

    ////////////////////////////////////////////////////
    // dt::Math::Matrix<2, 2, bool>
    std::cout << "dt::Math::Matrix<2, 2, bool> :" << std::endl;
    dt::Math::Matrix<2, 2, bool> bmat;
    bmat.SetIdentity();
    bmat.Print();

    return 0;
}