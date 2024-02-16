#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

class Point2D {
public:
  float x;
  float y;

  Point2D() noexcept : x(0), y(0) {}
  Point2D(float x_, float y_) noexcept : x(x_), y(y_) {}
};

void worker(std::atomic<int> &counter) {
  // void worker(int& counter) {
  for (int i = 0; i < 10000; i++) {
    counter++;
  }
}

// void worker(std::atomic<Point2D> &point) {
//   for (int i = 0; i < 10000; i++) {
//     point.store(point.load());
//     // point.load().x += 1.0f;
//     // point.load().y -= 1.0f;
//   }
// }

int main() {
  std::atomic<int> counter(0);
  // int counter{0};

  std::cout << "is lock free ? : " << std::boolalpha << counter.is_lock_free()
            << std::endl;

  std::atomic<Point2D> point{};
  std::cout << "is lock free ? : " << std::boolalpha << point.is_lock_free()
            << std::endl;

  std::vector<std::thread> workers;
  for (int i = 0; i < 4; i++) {
    workers.push_back(std::thread(worker, std::ref(counter)));
  }

  for (int i = 0; i < 4; i++) {
    workers[i].join();
  }

  std::cout << "Counter 최종 값 : " << counter << std::endl;

  return 0;
}