#include <iostream>
#include <pthread.h>
#include <thread>
#include <mutex>
#include <semaphore.h> // sem_init, sem_wait, sem_post, sem_getvalue
#include <chrono>
#include <sys/resource.h>
#include <string.h>

#define USING_PTHREAD
// #define USING_STDTHREAD
#define USING_STDMUTEX

int test_semaphore()
{
  int rtn = 0;

  sem_t sem;
  rtn = sem_init(&sem, PTHREAD_PROCESS_SHARED, 0);
  if (rtn) {
    std::cout << "sem_init error (" << strerror(errno) << ")." << std::endl;
  }

  do {
    rtn = sem_post(&sem);
    if (rtn) {
      std::cout << "sem_post error (" << strerror(errno) << ")." << std::endl;
      break;
    }

    int sval;
    rtn = sem_getvalue(&sem, &sval);
    if (rtn) {
      std::cout << "sem_getvalue error (" << strerror(errno) << ")." << std::endl;
      break;
    }
    std::cout << "sval = " << sval << std::endl;

    sem_wait(&sem);
    
  } while (rtn == 0);

  return rtn;
}

int main() 
{
  int rtn;

  test_semaphore();

#ifdef USING_STDMUTEX
  std::mutex mtx;
  std::mutex::native_handle_type hmutex = mtx.native_handle();
  pthread_mutexattr_t mtx_attr;

  rtn = pthread_mutexattr_init(&mtx_attr);
  if (rtn)
  {
    std::cout << "pthread_mutexattr_init error (" << strerror(errno) << ")." << std::endl;
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
#endif

#ifdef USING_PTHREAD
  pthread_t th;
  void *th_result;

  // int prio = getpriority(PRIO_PROCESS, 0);
  // if (errno) 
  // {
  //   std::cout << "getpriority() failed with error (" << strerror(errno) << ")." << std::endl;
  // }
  // rtn = setpriority(PRIO_PROCESS, 0, 20);
  // if (rtn)
  // {
  //   std::cerr << "Failed to set priority for this process : " << strerror(errno) << std::endl;
  // }


  pthread_attr_t threadAttr;
  cpu_set_t cpuset;
  CPU_ZERO(&cpuset);               // removes all CPUs from cpuset
  CPU_SET(1, &cpuset); // add CPU idx to the cpuset
  struct sched_param schedParam = { .sched_priority = 70 };
  if (pthread_attr_init(&threadAttr)) std::cerr << "pthread_attr_init failed: " << strerror(errno) << std::endl;
  if (pthread_attr_setinheritsched(&threadAttr, PTHREAD_EXPLICIT_SCHED)) std::cerr << "pthread_attr_setinheritsched failed: " << strerror(errno) << std::endl;
  if (pthread_attr_setschedpolicy(&threadAttr, SCHED_OTHER)) std::cerr << "pthread_attr_setschedpolicy failed: " << strerror(errno) << std::endl;
  // if (pthread_attr_setaffinity_np(&threadAttr, sizeof(cpuset), &cpuset)) std::cerr << "pthread_attr_setaffinity_np failed: " << strerror(errno) << std::endl;
  if (pthread_attr_setdetachstate(&threadAttr, PTHREAD_CREATE_JOINABLE)) std::cerr << "pthread_attr_setdetachstate failed: " << strerror(errno) << std::endl;
  if (pthread_attr_setschedparam(&threadAttr, &schedParam)) std::cerr << "pthread_attr_setschedparam failed: " << strerror(errno) << std::endl;

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

  std::cout << "sched_get_priority_min=" << sched_get_priority_min(SCHED_FIFO) << ", sched_get_priority_max=" << sched_get_priority_max(SCHED_FIFO) << std::endl;
  
  if (pthread_setschedprio(th, 0)) std::cerr << "pthread_setschedprio failed: " << strerror(errno) << std::endl;
  
  // rtn = setpriority(PRIO_PROCESS, 0, prio);
  // if (rtn)
  // {
  //   std::cerr << "Failed to set priority for this process : " << strerror(errno) << std::endl;
  // }
#endif

#ifdef USING_STDTHREAD
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
  sch_params.sched_priority = 1;
  rtn = pthread_setschedparam(my_thread.native_handle(), SCHED_FIFO, &sch_params);
  if(rtn) {
    std::cerr << "Failed to set Thread scheduling : " << strerror(errno) << std::endl;
  }
#endif

#ifdef USING_PTHREAD
  pthread_join(th, &th_result);
#endif
#ifdef USING_STDTHREAD
  my_thread.join();
#endif
  
  return 0;
}
