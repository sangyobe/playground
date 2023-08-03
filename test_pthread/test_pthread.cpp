#include <iostream>
#include <pthread.h>

int main() {
  pthread_t th;
  void *th_result;
  int cnt = 0;
  pthread_create(
      &th, NULL,
      [](void *data) -> void * {
        (void)data;
        std::cout << "hello, pthread!" << std::endl;
        return 0;
      },
      NULL);

  pthread_join(th, &th_result);
  return 0;
}
