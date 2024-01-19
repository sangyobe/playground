#include <iostream>

constexpr int Factorial(int n) {
  int total = 1;
  for (int i = 1; i <= n; i++) {
    total *= i;
  }
  return total;
}

class Vector {
 public:
  constexpr Vector(int x, int y) : x_(x), y_(y) {}

  constexpr int x() const { return x_; }
  constexpr int y() const { return y_; }

 private:
  int x_;
  int y_;
};

constexpr Vector AddVec(const Vector& v1, const Vector& v2) {
  return {v1.x() + v2.x(), v1.y() + v2.y()};
}

template <int N>
struct A {
  int operator()() { return N; }
};

int main() {

  A<Factorial(10)> a;
  std::cout << "10! = " << a() << std::endl;

  int num;
  std::cout << "input number: ";
  std::cin >> num;
  std::cout << num << "! = " << Factorial(num) << std::endl;


  constexpr Vector v1{1, 2};
  constexpr Vector v2{2, 3};

  // constexpr 객체의 constexpr 멤버 함수는 역시 constexpr!
  A<v1.x()> b;
  std::cout << b() << std::endl;

  // AddVec 역시 constexpr 을 리턴한다.
  A<AddVec(v1, v2).x()> c;
  std::cout << c() << std::endl;
}