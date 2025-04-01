#include <iostream>
#include <type_traits>

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

template <typename T>
void show_value(T t)
{
    if constexpr (std::is_pointer<T>::value)
        std::cout << "T*:" << *t << std::endl;
    else
        std::cout << "T:" << t << std::endl;
}

int main() {

  A<Factorial(10)> a;
  std::cout << "10! = " << a() << std::endl; // compile time에 계산되어 상수(값)로 치환

  int num;
  std::cout << "input number: ";
  std::cin >> num;
  std::cout << num << "! = " << Factorial(num) << std::endl; // num이 constexpr이 아니므로 일반함수처럼 동작

  constexpr Vector v1{1, 2};
  constexpr Vector v2{2, 3};

  // constexpr 객체의 constexpr 멤버 함수는 역시 constexpr!
  A<v1.x()> b;
  std::cout << b() << std::endl;

  // AddVec 역시 constexpr 을 리턴한다.
  A<AddVec(v1, v2).x()> c;
  std::cout << c() << std::endl;

  // if constexpr
  int x = 3;
  show_value(x);
  int *p_x = &x;
  show_value(p_x);

  return 0;
}