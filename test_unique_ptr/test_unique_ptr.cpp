#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <vector>

class A
{
public:
    A(int a_) : a(a_) { std::cout << "A:ctor(" << a << ")" << std::endl; }
    ~A() { std::cout << "A:dtor(" << a << ")" << std::endl; }
    int a;
    void Print() { std::cout << a << std::endl; }
};

void func(std::unique_ptr<A> pp)
{
    pp->Print();
}

int main()
{

    std::unique_ptr<A> pA = std::make_unique<A>(1);
    std::unique_ptr<A> pB = std::make_unique<A>(2);
    std::unique_ptr<A> pC = std::make_unique<A>(3);

    std::vector<std::unique_ptr<A>> my_vec;

    // my_vec.push_back(std::move(pA));
    // my_vec.push_back(std::move(pB));
    // my_vec.push_back(std::move(pC));

    // for_each(my_vec.begin(), my_vec.end(), [](std::unique_ptr<A> &pa) {
    //     pa->Print();
    // });

    pA->Print();
    func(std::move(pA));
    pB->Print();

    // std::vector<A *> my_vec;

    // my_vec.push_back(pA.get());
    // my_vec.push_back(pB.get());
    // my_vec.push_back(pC.get());

    // for_each(my_vec.begin(), my_vec.end(), [](A *&pa) {
    //     pa->Print();
    // });

    return 0;
}