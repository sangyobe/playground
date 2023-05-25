#include <functional>
#include <iostream>

int func(int a, int b, int c) { return a * 100 + b * 10 + c; }

int main() {
  auto func1 = std::bind(func, std::placeholders::_1, 0, 0);
  std::cout << func1(3) << std::endl;

  std::function<int(int)> func2 = std::bind(func, 1, std::placeholders::_1, 0);
  std::cout << func2(5) << std::endl;
  return 0;
}