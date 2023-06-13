
#include <iostream>

void RValRef(int *&&a, int len) {
  for (int i = 0; i < len; i++) {
    std::cout << a[i] << std::endl;
    a[i]++;
  }
}

void LValRef(int *&a, int len) {
  for (int i = 0; i < len; i++) {
    std::cout << a[i] << std::endl;
    a[i]++;
  }
}

template <typename T, uint16_t len> class Foo {
public:
  void Func(T &&a) {
    for (int i = 0; i < len; i++) {
      std::cout << "Foo::Func[" << i << "] = " << a[i] << std::endl;
      a[i]++;
    }
  }

  void Func(T &a) {
    for (int i = 0; i < len; i++) {
      std::cout << "Foo::Func[" << i << "] = " << a[i] << std::endl;
      a[i]++;
    }
  }
};

template <typename T, uint16_t len> class MyArray {
public:
  T &operator[](unsigned int idx) { return m_arr[idx]; }
  T m_arr[len];
};

struct A {};
void func(const A &t) { std::cout << "func(const A &t)" << std::endl; }
void func(A &&t) { std::cout << "func(A &&t)" << std::endl; }
void func2(A &&t) { std::cout << "func2(A &&t)" << std::endl; }
A source() {
  A tmp;
  return tmp;
}
const A const_source() {
  A tmp;
  return tmp;
}

struct W {
  W(int &, int &) {}
};

struct X {
  X(const int &, int &) {}
};

struct Y {
  Y(int &, const int &) {}
};

struct Z {
  Z(const int &, const int &) {}
};

template <typename T, typename A1, typename A2> T *factory(A1 &&a1, A2 &&a2) {
  return new T(std::forward<A1>(a1), std::forward<A2>(a2));
}

int main(int argc, char *argv[]) {

  int n = 3;
  int &r = n;
  const int &r2 = 5;

  int arr1[3] = {1, 2, 3};
  RValRef(arr1, 3);
  std::cout << "arr1 = " << arr1[0] << ", " << arr1[1] << ", " << arr1[2]
            << std::endl;

  int *arr2 = &arr1[0];
  LValRef(arr2, 3);
  std::cout << "arr2 = " << arr2[0] << ", " << arr2[1] << ", " << arr2[2]
            << std::endl;

  int *arr3 = new int[3]{5, 6, 7};
  LValRef(arr3, 3);
  std::cout << "arr3 = " << arr3[0] << ", " << arr3[1] << ", " << arr3[2]
            << std::endl;
  delete arr3;

  // template argument deduction with r-value ref
  Foo<int *, 3> foo;
  foo.Func(arr1);

  MyArray<int, 3> arr5{10, 20, 30};
  Foo<MyArray<int, 3>, 3> bar;
  bar.Func(arr5);

  // function overloading
  A a;
  const A ca;

  std::cout << "func(A) ==> ";
  func(a);
  std::cout << "func(cosnt A) ==> ";
  func(ca);
  std::cout << "func(source()) ==> ";
  func(source());
  std::cout << "func(const_source()) ==> ";
  func(const_source());
  // std::cout << "func2(A) ==> ";
  // func2(a);

  int c = 4, d = 5;
  W *pw = factory<W>(c, d);
  X *px = factory<X>(2, d);
  Y *py = factory<Y>(c, 2);
  Z *pz = factory<Z>(2, 2);

  delete pw;
  delete px;
  delete py;
  delete pz;

  return 0;
}