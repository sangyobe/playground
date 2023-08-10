#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

class Printer
{
public:
    void operator()(int val) {
        std::cout << val << std::endl;
    }
};

int main()
{
    std::vector<int> myVec;
    for (int i=0; i<10; i++)
        myVec.push_back(i);
    std::cout << "size of myVec = " << myVec.size() << std::endl;
    int iv = 0;
    auto printVal = [&iv] (int val) -> void {
        std::cout << "myVec[" << iv << "] = " << val << std::endl;
        iv++;
    };
    // lambda
    for_each(myVec.begin(), myVec.end(), printVal);

    // unary function
    std::function<void(int)> printVal2 = [] (int val) -> void {
        std::cout << val << std::endl;
    };
    for_each(myVec.begin(), myVec.end(), printVal2);
    // functor
    for_each(myVec.begin(), myVec.end(), Printer());


    // unary predicate
    std::function<bool(int)> isEven = [] (int val) -> bool {
        return (val %2 == 0);
    };
    std::vector<int> myTarget(10);

    std::copy_if(myVec.begin(), myVec.end(), myTarget.begin(), isEven);
    for_each(myTarget.begin(), myTarget.end(), Printer());

    return 0;
}