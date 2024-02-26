#include <iostream>

template <typename... Ints>
int sum_all(Ints... nums) {
  return (... + nums);
}


template <typename Int, typename... Ints>
Int diff_from(Int start, Ints... nums) {
  return (start - ... - nums);
}


class A {
 public:
  void do_something(int x) const {
    std::cout << "Do something with " << x << std::endl;
  }
};

template <typename T, typename... Ints>
void do_many_things(const T& t, Ints... nums) {
  // 각각의 인자들에 대해 do_something 함수들을 호출한다.
  (t.do_something(nums), ...);
}


int main() {
  // 1 + 4 + 2 + 3 + 10
  std::cout << sum_all(1, 4, 2, 3, 10) << std::endl;


  // 100 - 1 - 4 - 2 - 3 - 10
  std::cout << diff_from(100, 1, 4, 2, 3, 10) << std::endl;

  A a;
  do_many_things(a, 1, 3, 2, 4);
}