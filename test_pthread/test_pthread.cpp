#include <iostream>
#include <pthread.h>
#include <thread>
#include <mutex>
#include <chrono>

int main() 
{
  bool bRun = true;
  pthread_t th;
  void *th_result;
  int cnt = 0;
  std::mutex mtx;
  std::mutex::native_handle_type hmutex = mtx.native_handle();


  int rtn;

  pthread_mutexattr_t mtx_attr;


  rtn = pthread_mutexattr_init(&mtx_attr);
  if (rtn)
  {
    std::cout << "pthread_mutexattr_init error (" << rtn << ")." << std::endl;
    exit(-1);
  }

  // int mtx_attr_shared;
  // if (!pthread_mutexattr_getpshared(&mtx_attr, &mtx_attr_shared))
  // {
  //   std::cout << "before mtx_attr_shared : " << mtx_attr_shared << std::endl;
  // }
  // rtn = pthread_mutexattr_setpshared(&mtx_attr, PTHREAD_PROCESS_SHARED);
  // if (rtn)
  // {
  //   std::cout << "pthread_mutexattr_setpshared error (" << rtn << ")." << std::endl;
  //   exit(-1);
  // }
  // if (!pthread_mutexattr_getpshared(&mtx_attr, &mtx_attr_shared))
  // {
  //   std::cout << "after mtx_attr_shared : " << mtx_attr_shared << std::endl;
  // }
  
  int mtx_attr_protocol;
  if (!pthread_mutexattr_gettype(&mtx_attr, &mtx_attr_protocol))
  {
    std::cout << "before mtx_attr_protocol : " << mtx_attr_protocol << std::endl;
  }
  rtn = pthread_mutexattr_setprotocol(&mtx_attr, PTHREAD_PRIO_INHERIT);
  if (rtn)
  {
    std::cout << "pthread_mutexattr_setprotocol error (" << rtn << ")." << std::endl;
    exit(-1);
  }
  if (!pthread_mutexattr_gettype(&mtx_attr, &mtx_attr_protocol))
  {
    std::cout << "after mtx_attr_protocol : " << mtx_attr_protocol << std::endl;
  }

  int mtx_attr_type;
  if (!pthread_mutexattr_gettype(&mtx_attr, &mtx_attr_type))
  {
    std::cout << "before mtx_attr_type : " << mtx_attr_type << std::endl;
  }
  rtn = pthread_mutexattr_settype(&mtx_attr, PTHREAD_MUTEX_RECURSIVE);
  if (rtn)
  {
    std::cout << "pthread_mutexattr_settype error (" << rtn << ")." << std::endl;
    exit(-1);
  }
  if (!pthread_mutexattr_gettype(&mtx_attr, &mtx_attr_type))
  {
    std::cout << "after mtx_attr_type : " << mtx_attr_type << std::endl;
  }

  int mtx_attr_prioceiling;
  if (!pthread_mutexattr_getprioceiling(&mtx_attr, &mtx_attr_prioceiling))
  {
    std::cout << "before mtx_attr_prioceiling : " << mtx_attr_prioceiling << std::endl;
  }
  rtn = pthread_mutexattr_setprioceiling(&mtx_attr, 99);
  if (rtn)
  {
    std::cout << "pthread_mutexattr_setprioceiling error (" << rtn << ")." << std::endl;
    exit(-1);
  }
  if (!pthread_mutexattr_getprioceiling(&mtx_attr, &mtx_attr_prioceiling))
  {
    std::cout << "after mtx_attr_prioceiling : " << mtx_attr_prioceiling << std::endl;
  }
  
  rtn = pthread_mutex_init(hmutex, &mtx_attr);
  if (rtn)
  {
    std::cout << "pthread_mutex_init error (" << rtn << ")." << std::endl;
    exit(-1);
  }

  pthread_create(
      &th, NULL,
      [](void *data) -> void * {
        int count = 0;
        bool bRun = true;
        
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));


        std::mutex *mtx = (std::mutex*)(data);
        while (bRun) {
          {
            std::lock_guard<std::mutex> lock(*mtx);
            std::cout << "hello, pthread!" << std::endl;
          }
          std::this_thread::sleep_for(std::chrono::milliseconds(1000));
          count++;
          if (count == 10) {
            bRun = false;
          }
        }
        return 0;
      },
      (void*)&mtx);

  std::thread my_thread = std::thread([&mtx] {
    int count = 0;
    bool bRun = true;
    while (bRun) {
      {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "hello, std::thread!" << std::endl;
      }
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      count++;
      if (count == 10) {
        bRun = false;
      }
    }
    return 0;
  });
  sched_param sch_params;
  sch_params.sched_priority = 10;
  rtn = pthread_setschedparam(my_thread.native_handle(), SCHED_FIFO, &sch_params);
  if(rtn) {
    std::cerr << "Failed to set Thread scheduling : " << rtn << ":" << errno << std::endl;
  }


  pthread_join(th, &th_result);
  my_thread.join();

  
  return 0;
}
