#ifndef __MY_VECTOR_H__
#define __MY_VECTOR_H__

#include <iostream>
#include <map>
#include <memory>
#include <string>

template <typename T> class MyVector {
public:
  MyVector(T a, T b, T c) {
    pa = std::make_unique<T>(a);
    pb = std::make_unique<T>(b);
    pc = std::make_unique<T>(c);
    // *pa = a;
    // *pb = b;
    // *pc = c;
  }
  T GetX() { return *pa; }
  T GetY() { return *pb; }
  T GetZ() { return *pc; }
  void Print() {
    std::cout << "[" << *pa << "," << *pb << "," << *pc << "]" << std::endl;
  }

private:
  std::unique_ptr<T> pa;
  std::unique_ptr<T> pb;
  std::unique_ptr<T> pc;
};

#endif // __MY_VECTOR_H__