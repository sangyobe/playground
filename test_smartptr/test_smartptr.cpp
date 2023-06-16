/**
 * Copyright Sean. All rights reserved.
 * test smart pointer
 * - unique_ptr : 클래스맴버변수, 지역변수, STL 컨테이너 아이템
 * - shared_ptr : 참조카운팅(reference counting) 방식
 * - week_ptr : share_ptr 참조카운터 증가하지 않고 메모리 참조만
 */
#include "my_vector.h"
#include "simple_cache.h"
#include <cassert>
#include <iostream>
#include <memory>

void PrintTestHeader(char const *name);

/**
 * unique_ptr은 하나의 스마트 포인터만이 특정 객체를 소유할 수 있도록, 객체에
 * 소유권 개념을 도입한 스마트 포인터입니다.
 * 이 스마트 포인터는 해당 객체의 소유권을 가지고 있을 때만, 소멸자가 해당
 * 객체를 삭제할 수 있다. unique_ptr 인스턴스는 move() 멤버 함수를 통해 소유권을
 * 이전할 수는 있지만, 복사할 수는 없다(복사 생성자와 할당 연산자가 구현되어있지
 * 않기 때문). 소유권이 이전되면, 이전 unique_ptr 인스턴스는 더는 해당 객체를
 * 소유하지 않게 재설정된다.
 * ※ 보통의 C++ 객체에 대해 스마트 포인터가 필요한
 * 상황(scoped instance)에서는 주로 unique_ptr을 사용하면 된다.
 * ※ 클래스의 멤버 변수로 활용할 때 유용합니다. 소멸자가 호출될 때 알아서
 * 해제되기 때문에 편리합니다.
 */
void Test_UniquePointer() {
  PrintTestHeader("Test_UniquePointer");

  // 1. instance 생성
  std::unique_ptr<MyVector<int>> vec1 =
      std::make_unique<MyVector<int>>(1, 2, 3);

  // 2. do something
  vec1->Print();

  // 3. 함수 리턴과 동시에 instance 자동 삭제(delete)
}

void Test_UniquePointer_move() {
  PrintTestHeader("Test_UniquePointer_move");

  // 1. make_unique: instance 생성
  // unique_ptr
  // C++ 11
  // std::unique_ptr<MyVector<int>> vec1(new MyVector<int>(1, 2, 3));
  // C++14
  std::unique_ptr<MyVector<int>> vec1 =
      std::make_unique<MyVector<int>>(1, 2, 3);
  vec1->Print();

  // 2. move: 소유권 이전
  auto vec2 = std::move(vec1);

  // after moved, vec1 is not valid anymore.
  // vec1->Print(); // segmentation fault !!!
  vec2->Print();

  // 3. reset:
  vec2.reset();
  vec1.reset();
}

/**
 * shared_ptr은 하나의 특정 객체를 참조하는 스마트 포인터가 총 몇 개인지를
 * 참조하는 스마트 포인터이다.
 */
void Test_SharedPointer() {
  PrintTestHeader("Test_SharedPointer");

  // shared_ptr
  // 1. make_shared: shared instance 생성
  std::shared_ptr<MyVector<double>> vec_shared_1 =
      std::make_shared<MyVector<double>>(3.14, 2.5, 7.8);
  // 2-1. assignment: share instance (ref_count++)
  std::shared_ptr<MyVector<double>> vec_shared_2 = vec_shared_1;
  std::cout << "reference count (before): " << vec_shared_1.use_count()
            << std::endl;
  // 2-2. copy constructor: share instance (ref_count++)
  std::shared_ptr<MyVector<double>> vec_shared_3(vec_shared_1);
  std::cout << "reference count (before): " << vec_shared_1.use_count()
            << std::endl;
  // 3. reset:
  vec_shared_2.reset();
  std::cout << "reference count (after): " << vec_shared_1.use_count()
            << std::endl;
}

/**
 * weak_ptr은 하나 이상의 shared_ptr 인스턴스가 소유하는 객체에 대한 접근을
 * 제공하지만, 소유자의 수에는 포함되지 않는 스마트 포인터이다.
 */
void Test_WeakPointer() {
  PrintTestHeader("Test_WeakPointer");

  std::shared_ptr<MyVector<double>> vec_shared_1 =
      std::make_shared<MyVector<double>>(3.14, 2.5, 7.8);

  // weak_ptr
  // 1. create weak_ptr from shared_ptr
  std::weak_ptr<MyVector<double>> vec_weak = vec_shared_1;
  std::cout << "reference count (after weak): " << vec_shared_1.use_count()
            << std::endl;
  if (!vec_weak.expired())
    std::cout << "original pointer is valid." << std::endl;

  // 2. get shared_ptr to access instance
  std::shared_ptr<MyVector<double>> vec_shared_2 = vec_weak.lock();
  std::cout << "reference count (after weak_ptr.lock()): "
            << vec_shared_1.use_count() << std::endl;
  vec_shared_2->Print();
  vec_shared_2.reset();
  std::cout << "reference count (after shared_2::reset()): "
            << vec_shared_1.use_count() << std::endl;

  // 3.
  vec_shared_1.reset();
  std::cout << "reference count (after shared_1::reset()): "
            << vec_shared_1.use_count() << std::endl;
  if (vec_weak.expired())
    std::cout << "original pointer is released(null_ptr)." << std::endl;
}

void CacheExample() {
  PrintTestHeader("CacheExample");

  std::shared_ptr<MyVector<int>> vector1 =
      std::make_shared<MyVector<int>>(0, 1, 2);
  std::shared_ptr<MyVector<int>> vector2 =
      std::make_shared<MyVector<int>>(3, 4, 5);
  std::shared_ptr<MyVector<int>> vector3 =
      std::make_shared<MyVector<int>>(6, 7, 8);

  std::cout << "Usage of vector1: " << vector1.use_count() << std::endl;
  std::cout << "Usage of vector2: " << vector2.use_count() << std::endl;
  std::cout << "Usage of vector3: " << vector3.use_count() << std::endl;

  SimpleCache<MyVector<int>> cache;

  cache.Add("Candy", vector1);
  cache.Add("IceCream", vector2);
  cache.Add("Chocolate", vector3);

  std::cout << "Usage of vector1(after caching): " << vector1.use_count()
            << std::endl;
  std::cout << "Usage of vector2(after caching): " << vector2.use_count()
            << std::endl;
  std::cout << "Usage of vector3(after caching): " << vector3.use_count()
            << std::endl;

  std::shared_ptr<MyVector<int>> cachedVector2 = cache.Get("IceCream");

  std::cout << "Usage of vector1(after get): " << vector1.use_count()
            << std::endl;
  std::cout << "Usage of vector2(after get): " << vector2.use_count()
            << std::endl;
  std::cout << "Usage of vector3(after get): " << vector3.use_count()
            << std::endl;

  std::cout << "Usage of cachedVector2: " << cachedVector2.use_count()
            << std::endl;
  std::cout << "IceCream values: X: " << cachedVector2->GetX()
            << ", Y: " << cachedVector2->GetY()
            << ", Z: " << cachedVector2->GetZ() << std::endl;

  cache.Add("IceCream", vector3);

  std::cout << "Usage of vector1(after replace): " << vector1.use_count()
            << std::endl;
  std::cout << "Usage of vector2(after replace): " << vector2.use_count()
            << std::endl;
  std::cout << "Usage of vector3(after replace): " << vector3.use_count()
            << std::endl;

  cachedVector2 = cache.Get("IceCream");

  std::cout << "Usage of vector1(after get): " << vector1.use_count()
            << std::endl;
  std::cout << "Usage of vector2(after get): " << vector2.use_count()
            << std::endl;
  std::cout << "Usage of vector3(after get): " << vector3.use_count()
            << std::endl;

  std::cout << "IceCream values: X: " << cachedVector2->GetX()
            << ", Y: " << cachedVector2->GetY()
            << ", Z: " << cachedVector2->GetZ() << std::endl;

  vector1 = nullptr;

  std::shared_ptr<MyVector<int>> cachedVector1 = cache.Get("Candy");

  assert(cachedVector1 == nullptr);
}

int main() {
  Test_UniquePointer();
  Test_UniquePointer_move();
  Test_SharedPointer();
  Test_WeakPointer();

  // example (cache using shared_ptr, weak_ptr)
  CacheExample();

  return 0;
}

void PrintTestHeader(char const *name) {
  std::cout << "==========================================" << std::endl;
  std::cout << " " << name << std::endl;
  std::cout << "------------------------------------------" << std::endl;
}