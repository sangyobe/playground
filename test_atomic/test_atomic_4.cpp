#include <atomic>
#include <iostream>
#include <thread>
#include <vector>
using std::memory_order_relaxed;
using std::memory_order_acquire;
using std::memory_order_release;
using std::memory_order_acq_rel;

void producer(std::atomic<bool>* is_ready, int* data) {
  *data = 10;
  is_ready->store(true, memory_order_relaxed);
  //is_ready->store(true, memory_order_release);
}

void consumer(std::atomic<bool>* is_ready, int* data) {
  // data 가 준비될 때 까지 기다린다.
  while (!is_ready->load(memory_order_relaxed)) 
  //while (!is_ready->load(memory_order_acquire)) 
  {
  }

  std::cout << "Data : " << *data << std::endl;
}

int main() {
  std::vector<std::thread> threads;

  std::atomic<bool> is_ready(false);
  int data = 0;

  threads.push_back(std::thread(producer, &is_ready, &data));
  threads.push_back(std::thread(consumer, &is_ready, &data));

  for (int i = 0; i < 2; i++) {
    threads[i].join();
  }
}