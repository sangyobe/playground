#include "ebImuV5.h"
#include <stdio.h>

bool fRunMain = true;
CEbImuV5 ebImu;

int InitIMU() {
  printf("initializing...(0)\n");
  if (ebImu.Open("/dev/ttyUSB0"))
    return -1;
  printf("initializing...(1)\n");
  ebImu.SetPort(921600, 0, 0);
  printf("initializing...(2)\n");
  //usleep(1000000);
  if (ebImu.Init())
     return -1;

  printf("initializing...(3)\n");
  return 0;
}

int main() {
  printf("initializing...\n");
  InitIMU();
  printf("initialized.\n");

  int imu_rtn;
  SEbImuV5Data& imu_data = ebImu.GetData();
  while (true) {
    imu_rtn = ebImu.ReadSome();
    printf("length = %d \n", imu_rtn);
    printf("r: %.3f\t,p: %.3f\t,y: %.3f\n", imu_data.eulerZYX_rad[0], imu_data.eulerZYX_rad[1], imu_data.eulerZYX_rad[2]);
    usleep(1000);
  }

  return 0;
}