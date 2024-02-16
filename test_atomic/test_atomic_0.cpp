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

void worker(int& counter) {
  for (int i = 0; i < 10000; i++) {
    counter++;
  }
}

int main() {
  int counter{0};

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