#include "ebImuV5.h"
#include <stdio.h>

bool fRunMain = true;
CEbImuV5 ebImu;

int InitIMU() {
  printf("initializing...(0)\n");
  if (ebImu.Open("/dev/ttyUSB0"))
    return -1;
  printf("initializing...(1)\n");
  //    ebImu.SetPort(921600, 0, 0);
  ebImu.SetPort(921600, 0, 0);
  printf("initializing...(2)\n");
  //    usleep(1000000);
  if (ebImu.Init())
     return -1;

  printf("initializing...(3)\n");
  return 0;
}

void ReadImuTaskProc(void *arg) {
  int imu_rtn;

  //     RTIME imu_startTime_ns, imu_endTime_ns, imu_prevTime_ns;
  // //    RTIME imu_time;

  //     imu_startTime_ns = rt_timer_read() + 1*1000000;
  //     imu_prevTime_ns = imu_startTime_ns;

  //    imu_rtn = rt_task_set_periodic(NULL, imu_startTime_ns, 1*1000000); //
  //    period is 1ms if (imu_rtn)
  //    {
  //        fprintf(stderr, "error: rt_task_set_periodic(...), %s(%d)\n",
  //        strerror(-imu_rtn), imu_rtn); return;
  //    }

  int rtn;
  while (fRunMain) {
    //        rt_task_wait_period(&imuOverRun);
    // rtn = rt_sem_p(&g_imuSem, TM_INFINITE);
    //        printf("rtn = %d\n",rtn);
    // if (rtn)
    // {
    //     fprintf(stderr, "error: rt_sem_p(...), %s(%d)\n", strerror(-rtn),
    //     rtn);
    // }
    // imu_startTime_ns = rt_timer_read();
    // imu_thread_time = imu_startTime_ns - imu_prevTime_ns;
    // imu_prevTime_ns = imu_startTime_ns;

    // sumImuOverRun = sumImuOverRun + imuOverRun;

    // if (sumImuOverRun > 5)
    // {
    //     printf("[ERROR] sumImuOverRun > 5 \n");
    //     m_emergencyFlag = true;
    // }

    imu_rtn = ebImu.ReadRawData();
    //        printf("imu_rtn = %d\n",imu_rtn);
    //        time_stamp = ebImu.GetData().timeStamp;
    // m_actEulerAng(0) = ebImu.GetData().eulerZYX_rad[2];
    // m_actEulerAng(1) = ebImu.GetData().eulerZYX_rad[1];
    // m_actEulerAng(2) = ebImu.GetData().eulerZYX_rad[0];

    // m_actAngVel(0) = ebImu.GetData().gyro_rps[0];
    // m_actAngVel(1) = ebImu.GetData().gyro_rps[1];
    // m_actAngVel(2) = ebImu.GetData().gyro_rps[2];

    // m_imuTimeStamp = ebImu.GetData().timeStamp;
    // m_imuDataLength = imu_rtn;

    // imu_endTime_ns = rt_timer_read();
    // imuAlgoTime_ns = imu_endTime_ns - imu_startTime_ns;
    //            printf("imu_time = %f, imu_overrun =
    //            %d\n",imu_time/1000000.0f,imu_overrun);
    //        if (imuAlgoTime_ns > m_maxImuAlgoTime_ns)
    //        {
    //            m_maxImuAlgoTime_ns = imuAlgoTime_ns;
    //        }

    //        static int imuCnt = 0;
    // if (imuAlgoTime_ns > m_maxImuAlgoTime_ns)
    // {
    //     m_maxImuAlgoTime_ns = imuAlgoTime_ns;

    // }
    //        if (imuCnt > 10*500)
    //        {
    //            m_maxImuAlgoTime_ns = 0.0;
    //            imuCnt = 0;
    //        }
    //        imuCnt++;
  }
}

int main() {
  printf("initializing...\n");
  InitIMU();
  printf("initialized.\n");

  int imu_rtn;
  while (true) {
    imu_rtn = ebImu.ReadRawData();
    usleep(1000);
  }

  return 0;
}