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

void CacheExample() {
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
  // example (cache using shared_ptr, weak_ptr)
  CacheExample();

  return 0;
}