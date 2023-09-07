/**
 * Copyright ART Team, HMC
 * 
 * ebImuV5 IMU sensor communicator
 * 
 * 센서에서 데이터를 읽기 위해서 다음 절차를 따름
 * {
 *    CEbImuV5 imu;
 *    SEbImuV5Data& imu_data = imu.GetData();
 *    imu.Open("/dev/ttyUSB0");   // open serial port
 *    imu.SetPort(921600);        // set baudrate
 *    imu.Init();
 *    while (bRun) {
 *        imu.ReadSome();
 * 
 *        __do_some_useful_job_using_imu_data__(imu_data);
 * 
 *    }
 *    imu.Close();
 * }
 * 
 * Note)
 *  1. Ascii format 은 완벽히 구현(테스트)되지 않았음. Binary format(HEX) 만 사용함.
 *  2. IMU 센서 초기화 후 SetOutputForm, SetGyroOut, SetAcclOut, SetMagnOut, 
 *     SetDistOut, SetTempOut, SetTimeOut 함수로 sensor output 을 변경하게되면
 *     하나의 패킷을 구성하는 payload length가 달라지므로 문제가 될 수 있음.
 *     호출후 payload length를 다시 계산하려면 CalcPacketLen() 함수 호출해야 함.
 */
#ifndef EBIMU_H
#define EBIMU_H

#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <termios.h>
#include <unistd.h>

#define PRINT_IMU_CFG_MSG // whether display imu configuration data on screen or not

#define BUFFERSIZE 256          // maximum payload length of a imu data packet
#define EB_SOP (0x55)

typedef struct _EbImuV5Param {
  uint8_t baudRate = 8;    // 1:9600  ~5:115200 ~ 8:921600
  uint16_t outputRate = 1;   // 0:polling, 1~1000 (1ms * outputRate)
  uint8_t outputCode = 2;     // ASCII(1) / HEX(2)
  uint8_t outputForm = 1;     // Euler(1)/Quaternion(2)
  uint8_t gyroOut = 1;
  uint8_t acclOut = 0;
  uint8_t magnOut = 0;
  uint8_t distOut = 0;
  uint8_t tempOut = 0;
  uint8_t timeOut = 1;
  uint8_t magnEnable = 0;     // magnetometer OFF(0), ON(1), ON2(2)(active anti-distortion)
  uint8_t gyroSens = 5;       // 1:125dps ~ 5:2000dps
  uint8_t acclSens = 4;       // 1:3g ~ 3:12g, 4:24g
  uint8_t gyroLpf = 3;        // 0:12Hz ~ 3:47Hz ~ 7:532Hz
  uint8_t acclLpf = 7;        // 0:1Hz ~ 5:40Hz ~ 9:280Hz
  uint8_t acclFltFactor = 1;
  uint8_t magnFltFactor = 10;
  double raaLvl = 0.01f;
  uint32_t raaTime = 10000;
  double rhaLvl = 0.075;
  uint32_t rhaTime = 10000;
  uint8_t agcEnable = 1;//1      // Auto Gyroscope Calibration Param
  double agcThreshold = 0.8;
  double agcDrift = 0.5;
  uint8_t avcGyro = 0;        // Gyro Active Vibration Cancellation Param
  uint8_t avcAccl = 0;        // Accl Active Vibration Cancellation Param
  uint8_t pons = 1;           // Power on start
  int packetLen = 0;

#ifdef PRINT_IMU_CFG_MSG  
  void DumpParams(const char* header) {
    fprintf(stdout, "----------------------------------------\n");
    fprintf(stdout, "IMU Params (%s)\n", header);
    fprintf(stdout, "----------------------------------------\n");
    fprintf(stdout, "baudRate      = %d\n", baudRate);
    fprintf(stdout, "outputRate    = %u\n", outputRate);
    fprintf(stdout, "outputCode    = %u\n", outputCode);
    fprintf(stdout, "outputForm    = %u\n", outputForm);
    fprintf(stdout, "gyroOut       = %u\n", gyroOut);
    fprintf(stdout, "acclOut       = %u\n", acclOut);
    fprintf(stdout, "magnOut       = %u\n", magnOut);
    fprintf(stdout, "distOut       = %u\n", distOut);
    fprintf(stdout, "tempOut       = %u\n", tempOut);
    fprintf(stdout, "timeOut       = %u\n", timeOut);
    fprintf(stdout, "magnEnable    = %u\n", magnEnable);
    fprintf(stdout, "gyroSens      = %u\n", gyroSens);
    fprintf(stdout, "acclSens      = %u\n", acclSens);
    fprintf(stdout, "gyroLpf       = %u\n", gyroLpf);
    fprintf(stdout, "acclLpf       = %u\n", acclLpf);
    fprintf(stdout, "acclFltFactor = %u\n", acclFltFactor);
    fprintf(stdout, "magnFltFactor = %u\n", magnFltFactor);
    fprintf(stdout, "raaLvl        = %.lf\n", raaLvl);
    fprintf(stdout, "raaTime       = %u\n", raaTime);
    fprintf(stdout, "rhaLvl        = %.lf\n", rhaLvl);
    fprintf(stdout, "rhaTime       = %u\n", rhaTime);
    fprintf(stdout, "agcEnable     = %u\n", agcEnable);
    fprintf(stdout, "agcThreshold  = %.lf\n", agcThreshold);
    fprintf(stdout, "agcDrift      = %.lf\n", agcDrift);
    fprintf(stdout, "avcGyro       = %u\n", avcGyro);
    fprintf(stdout, "avcAccl       = %u\n", avcAccl);
    fprintf(stdout, "pons          = %u\n", pons);
    fprintf(stdout, "packetLen     = %d\n", packetLen);
    fprintf(stdout, "----------------------------------------\n");
  }
#endif
} SEbImuV5Param;

typedef struct _EbImuV5Data
{
  double eulerZYX_rad[3] = {0,}; // z, y, x
  double quat[4] = {0,};      // w, x, y, z
  double gyro_rps[3] = {0,};
  double accl_G[3] = {0,};     // 1G is 9.8m/(s2)
  double velo_mps[3] = {0,};
  double magn_uT[3] = {0,};   // xy:+/-1300uT, z:+/-2500uT
  double dist_m[3] = {0,};
  double temp_C = 0;
  uint16_t timeStamp = 0;
  uint16_t chkSum = 0;
} SEbImuV5Data;


typedef struct _EbImuRxPacket {
  int idx = 0;
  uint8_t buf[BUFFERSIZE];
} SEbImuPacket;

class CEbImuV5 {
public:
  enum BuadRate {
    Baud9600 = 1,
    Baud19K = 2,
    Baud38K = 3,
    Baud57K = 4,
    Baud115K = 5,
    Baud230K = 6,
    Baud460K = 7,
    Baud921K = 8
  };

  enum OutputCode { Ascii = 1, Hex = 2 };

  enum OutputForm { Euler = 1, Quat = 2 };

  enum AcclOut {
    AcclOutDiable = 0,
    AcclOut = 1,
    AcclOutWoG_Local = 2,  // without Gravity
    AcclOutWoG_Global = 3, // without Gravity
    VeloOut_Local = 4,
    VeloOut_Global = 5
  };

  enum DistOut { DistOutDisable = 0, DistOut_Local = 1, DistOut_Global = 2 };

  enum MagnEnable { MagnOff = 0, MagnOn = 1, MagnOn2 = 2 };

  enum GyroSens {
    Sens125dps = 1,
    Sens250dps = 2,
    Sens500dps = 3,
    Sens1000dps = 4,
    Sens2000dps = 5,
  };

  enum AcclSens { Sens3g = 1, Sens6g = 2, Sens12g = 3, Sens24g = 4 };

  enum GyroLpf {
    GyroFlt12Hz = 0,
    GyroFlt23Hz = 1,
    GyroFlt32Hz = 2,
    GyroFlt47Hz = 3,
    GyroFlt64Hz = 4,
    GyroFlt116Hz = 5,
    GyroFlt230Hz = 6,
    GyroFlt532Hz = 7,
  };

  enum AcclLpf {
    AcclFlt1Hz = 0,
    AcclFlt3Hz = 1,
    AcclFlt5Hz = 2,
    AcclFlt10Hz = 3,
    AcclFlt20Hz = 4,
    AcclFlt40Hz = 5,
    AcclFlt80Hz = 6,
    AcclFlt145Hz = 7,
    AcclFlt234Hz = 8,
    AcclFlt280Hz = 9,
  };

private:
  int m_fd; // file descriptor
  struct termios m_comTermio, m_oriTermio;

  SEbImuPacket m_packet;
  SEbImuV5Param m_param;
  SEbImuV5Data m_data;

  bool m_bCalib = false;
  bool m_blockRead = false;

  int m_imuStep = 0;
  int m_chkSumErrCount = 0;

public:
  explicit CEbImuV5();
  ~CEbImuV5();

  int8_t Open(const char *devFile);
  void SetPort(const uint32_t baudrate, const uint8_t timeout_decisec = 0,
               const uint8_t minLen = 0);
  bool IsOpen() const;
  void Close();
  int ReadSome(); // Read some data from serial buffer and parse it if possible
  int Write(const void *buf, size_t size_byte);
  int8_t Init(); // Read parameter & set default param

  int8_t PowerOnStart(bool enable);
  int8_t Start();
  int8_t Stop();
  int8_t Reset();
  int8_t FactoryReset();
  int8_t ReadParam();
  int8_t SetDefaultParam();

  int8_t SetBuadRate(uint8_t rate);
  int8_t SetOutputRate(uint16_t rate_ms);
  int8_t SetOutputCode(uint8_t code);
  int8_t SetOutputForm(uint8_t format);
  int8_t SetGyroOut(uint8_t enable);
  int8_t SetAcclOut(uint8_t enable);
  int8_t SetMagnOut(uint8_t enable);
  int8_t SetDistOut(uint8_t enable);
  int8_t SetTempOut(uint8_t enable);
  int8_t SetTimeOut(uint8_t enable);
  int8_t SetMagnEnable(uint8_t enable);
  int8_t SetGyroSens(uint8_t sens);
  int8_t SetAcclSens(uint8_t sens);
  int8_t SetGyroLPF(uint8_t flt);
  int8_t SetAcclLPF(uint8_t flt);
  int8_t SetFltFactor(uint8_t factor);
  int8_t SetAcclFltFactor(uint8_t factor);
  int8_t SetMagnFltFactor(uint8_t factor);
  int8_t SetRaaLevel(double level);
  int8_t SetRaaTimeout(uint32_t time_ms);
  int8_t SetRhaLevel(double level);
  int8_t SetRhaTimeout(uint32_t time_ms);
  int8_t SetAutoGyroCalib(uint8_t enable);
  int8_t SetAutoGyroCalibThreshold(double threshold);
  int8_t SetAutoGyroCalibDrift(double drift);
  int8_t SetAvcGyro(uint8_t enable);
  int8_t SetAvcAccl(uint8_t enable);
  int8_t CalibGyro();
  // int8_t CalibAccl();
  int8_t CalibAcclSimple();
  int8_t CalibMagnetometerStart();
  int8_t CalibMagnetometerStop();
  int8_t SetMotionOffset();
  int8_t ResetMotionOffset();

  SEbImuV5Param &GetParam();
  SEbImuV5Data &GetData();
  int GetPacketLen();
  int8_t CalcPacketLen();

private:
  void PacketAssembly(uint8_t data);
  int8_t ParsingConfig(char *config);
  inline void ParsingAsciiPacket(char *packet);
  inline void ParsingHexPacket(uint8_t *packet);
  inline int8_t WriteCmd(const char *cmd, size_t size_byte);
  inline void SetBlockRead(bool block, const char* msg);
};

#endif // EBIMU_H
