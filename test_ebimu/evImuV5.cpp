#include "ebImuV5.h"
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

CEbImuV5::CEbImuV5() {
  m_fd = -1;
  memset(m_rawData, 0, BUFFERSIZE); // 255
}

CEbImuV5::~CEbImuV5() {}

int8_t CEbImuV5::Open(const char *devFile) {
  // Read/Write | Not Controlling terminal(prevent Ctrl-C Signal) | Non-block
  // for open()
  m_fd = open(devFile, O_RDWR | O_NOCTTY | O_NONBLOCK);
  if (m_fd < 0) {
    fprintf(stderr, "SerialComm Open() Error: %s", devFile);
    return -1;
  }

  return 0;
}

void CEbImuV5::SetPort(const uint32_t baudrate, const uint8_t timeout_decisec,
                       const uint8_t minLen) {
  //    struct termios oldtio, newtio;
  //    m_comTermio
  //    m_oriTermio

  //    tcgetattr(m_fd,&m_oriTermio);
  //    m_comTermio=m_oriTermio;

  tcgetattr(m_fd, &m_oriTermio); // save current serial port settings
  memset(&m_comTermio, 0,
         sizeof(m_comTermio)); // clear struct for new port settings

  // control mode flags
  switch (baudrate) {
  case 9600:
    m_comTermio.c_cflag = B9600;
    break;
  case 19200:
    m_comTermio.c_cflag = B19200;
    break;
  case 38400:
    m_comTermio.c_cflag = B38400;
    break;
  case 57600:
    m_comTermio.c_cflag = B57600;
    break;
  case 115200:
    m_comTermio.c_cflag = B115200;
    break;
  case 230400:
    m_comTermio.c_cflag = B230400;
    break;
  case 460800:
    m_comTermio.c_cflag = B460800;
    break;
  case 921600:
  default:
    m_comTermio.c_cflag = B921600;
    break;
  }

  m_comTermio.c_cflag |= CS8;    // 8N1 (8bit, no parity, 1stopbit)
  m_comTermio.c_cflag |= CLOCAL; // Local connection, Ignore modem control lines
  m_comTermio.c_cflag |= CREAD;  // Enable receiver, transmit is default

  // input mode flags
  m_comTermio.c_iflag = IGNPAR; // Ignore faming errors and parity errors

  // output mode flags
  m_comTermio.c_oflag = 0;

  // local mode flags
  m_comTermio.c_lflag = 0; // non-canonical mode, disable all echo functionality
                           // and don't send signals to calling program

  // control characters
  // VMIN = 0, VTIME = 0, non block, if data is available, read() returns
  // immediately VMIN > 0, VTIME = 0, VMIN is the minimum num of char, VTIME(0)
  // mean infinitly wait VMIN = 0, VTIME > 0, timer is started when read() is
  // called. read() returns either when at least one byte of data is available,
  // or when the timer expires. VMIN > 0, VTIME > 0,

  m_comTermio.c_cc[VTIME] =
      timeout_decisec; // Wait infinitly, Timeout in deciseconds for
                       // noncanonical read
  m_comTermio.c_cc[VMIN] =
      minLen; // Minimum number of characters for non-canonical read

  tcflush(m_fd, TCIFLUSH);                // flush data received but not read
  tcsetattr(m_fd, TCSANOW, &m_comTermio); // set attribute
}

bool CEbImuV5::IsOpen() const {
  if (m_fd < 0)
    return false;

  return true;
}

void CEbImuV5::Close() {
  if (m_fd >= 0) {
    tcsetattr(m_fd, TCSANOW, &m_oriTermio); // set attribute
    close(m_fd);
    m_fd = -1;
  }
}

int8_t CEbImuV5::Init() {
  printf("initializing...(2-0)\n");
  if (m_fd < 0)
    return -1;

  int8_t rtn = 0;
  int n_byte = 0;
  int rxSize = 0;
  char rxData[4095] = {
      0,
  };
  char txData[6];

  // para init
  chkSumErr = 0;

  sprintf(txData, "<cfg>");

  if (Stop())
    return -1;

  printf("initializing...(2-1)\n");

  m_blockRead = true;

  // usleep(10000);               // wait 5ms
  tcflush(m_fd, TCIFLUSH); // flush data received but not read
  printf("initializing...(2-2)\n");

  n_byte = write(m_fd, txData, strlen(txData));
  printf("initializing...(2-3)\n");

  if (n_byte < 0) {
    fprintf(stderr, "SerialComm. Write() Error:%s(%d)", strerror(-n_byte),
            n_byte);
    m_blockRead = false;
    return -1;
  }

  for (int i = 0; i < 500; i++) {
    usleep(10000);

    n_byte = read(m_fd, m_rawData, BUFFERSIZE); // 255

    if (n_byte > 0) {
      m_rawData[n_byte] = 0;
      rxSize += n_byte;

      if (rxSize >= 4095) {
        rxData[0] = 0;
        rxSize = n_byte;
      }

      strcat(rxData, (char *)m_rawData);

      if (strchr(rxData, '>') != nullptr) {
        rtn = 0;
        break;
      }
    } else if (n_byte < 0) {
      fprintf(stderr, "SerialComm. Read() Error:%s(%d)", strerror(-n_byte),
              n_byte);
      rtn = -1;
      break;
    }
  }
  printf("initializing...(2-4)\n");

  if (!rtn) {
    // Parsing Configuration param
    if (ParsingConfig(rxData))
      rtn = -1;
  }

  printf("initializing...(2-5)\n");
  sprintf(txData, ">");

  if (WriteCmd(txData, strlen(txData)))
    rtn = -1;

  printf("initializing...(2-6)\n");

  if (!rtn) {
    // Set Default Parameter & Calc. Packet length
    if (SetDefaultParam())
      rtn = -1;
  }

  printf("initializing...(2-7)\n");

  if (Start())
    rtn = -1;

  printf("initializing...(2-8)\n");

  m_blockRead = false;

  return rtn;
}

int CEbImuV5::Write(const void *buf, size_t size_byte) {
  int rtn = write(m_fd, buf, size_byte);

  if (rtn < 0) {
    fprintf(stderr, "SerialComm. Write() Error:%s(%d)", strerror(-rtn), rtn);
  }

  return rtn; // the number of bytes write
}

int8_t CEbImuV5::PowerOnStart(bool enable) {
  if (m_fd < 0)
    return -1;

  char txData[8];

  sprintf(txData, (enable) ? "<pons1>" : "<pons0>");

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.pons = enable ? 1 : 0;

  return 0;
}

int8_t CEbImuV5::Start() {
  if (m_fd < 0)
    return -1;

  char txData[8];

  sprintf(txData, "<start>");

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  return 0;
}

int8_t CEbImuV5::Stop() {
  if (m_fd < 0)
    return -1;

  char txData[7];

  sprintf(txData, "<stop>");

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  return 0;
}

int8_t CEbImuV5::Reset() {
  if (m_fd < 0)
    return -1;

  char txData[8];

  sprintf(txData, "<reset>");

  int rtn = write(m_fd, txData, strlen(txData));
  if (rtn < 0) {
    fprintf(stderr, "SerialComm. Write() Error:%s(%d)", strerror(-rtn), rtn);
    return -1;
  }

  return 0;
}

int8_t CEbImuV5::FactoryReset() {
  if (m_fd < 0)
    return -1;

  char txData[5];

  sprintf(txData, "<lf>");

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  return 0;
}

// int8_t CEbImuV5::ReadParam()
//{
//     if (m_fd < 0) return -1;
//
//     int8_t rtn = 0;
//     int n_byte = 0;
//     int rxSize = 0;
//     char rxData[4095] = {0,};
//     char txData[6];
//
//     sprintf(txData, "<cfg>");
//
//     if (Stop()) return -1;
//
//     m_blockRead = true;
//
//     //usleep(10000);               // wait 5ms
//     tcflush(m_fd, TCIFLUSH);    // flush data received but not read
//     n_byte = write(m_fd, txData, strlen(txData));
//
//     if (n_byte < 0)
//     {
//         fprintf(stderr, "SerialComm. Write() Error:%s(%d)",
//         strerror(-n_byte), n_byte); m_blockRead = false; return -1;
//     }
//
//     for (int i=0; i<500; i++)
//     {
//         usleep(10000);
//
//         n_byte = read(m_fd, m_rawData, BUFFERSIZE); //255
//
//         if (n_byte > 0)
//         {
//             m_rawData[n_byte] = 0;
//             rxSize += n_byte;
//
//             if (rxSize >= 4095)
//             {
//                 rxData[0] = 0;
//                 rxSize = n_byte;
//             }
//
//             strcat(rxData, (char*)m_rawData);
//
//             if (strchr(rxData, '>') != nullptr)
//             {
//                 rtn = 0;
//                 break;
//             }
//         }
//         else if (n_byte < 0)
//         {
//             fprintf(stderr, "SerialComm. Read() Error:%s(%d)",
//             strerror(-n_byte), n_byte); rtn = -1; break;
//         }
//     }
//
//     if (!rtn)
//     {
//         // Parsing Configuration param
//         if (ParsingConfig(rxData)) rtn = -1;
//     }
//
//     if (!rtn)
//     {
//         if (CalcPacketLen()) rtn = -1;
//     }
//
//     sprintf(txData, ">");
//
//     if (WriteCmd(txData, strlen(txData))) rtn = -1;
//
//     if (Start()) rtn = -1;
//
//     m_blockRead = false;
//
//     return rtn;
// }

int8_t CEbImuV5::SetDefaultParam() {
  int8_t rtn = 0;

  if (m_param.outputRate != 1) { // 1ms
    rtn = SetOutputRate(1);
    if (rtn)
      return rtn;
  }

  if (m_param.outputCode != 2) { // Hex
    rtn = SetOutputCode(2);
    if (rtn)
      return rtn;
  }

  if (m_param.outputForm != 1) { // Euler
    rtn = SetOutputForm(1);
    if (rtn)
      return rtn;
  }

  if (m_param.gyroOut != 1) {
    rtn = SetGyroOut(1);
    if (rtn)
      return rtn;
  }

  //    if (m_param.acclOut != 1) //ADH: Global acc
  //    {
  //        rtn = SetAcclOut(1);
  //        if (rtn) return rtn;
  //    }
  if (m_param.acclOut != 0) // ADH: Local acc
  {
    rtn = SetAcclOut(0);
    if (rtn)
      return rtn;
  }
  //    if (m_param.acclOut != 2) //ADH: Local acc
  //    {
  //        rtn = SetAcclOut(2);
  //        if (rtn) return rtn;
  //    }
  //    if (m_param.acclOut != 3) //ADH: Local acc
  //    {
  //        rtn = SetAcclOut(3);
  //        if (rtn) return rtn;
  //    }

  if (m_param.magnOut != 0) {
    rtn = SetMagnOut(0);
    if (rtn)
      return rtn;
  }

  if (m_param.distOut != 0) {
    rtn = SetDistOut(0);
    if (rtn)
      return rtn;
  }

  if (m_param.tempOut != 0) {
    rtn = SetTempOut(0);
    if (rtn)
      return rtn;
  }

  if (m_param.timeOut != 1) // 0->1
  {
    rtn = SetTimeOut(1);
    if (rtn)
      return rtn;
  }

  if (m_param.magnEnable != 0) // 2->0
  {
    rtn = SetMagnEnable(0);
    if (rtn)
      return rtn;
  }

  //    if (m_param.gyroSens != 5)
  //    {
  //        rtn = SetGyroSens(5);
  //        if (rtn) return rtn;
  //    }
  //
  //    if (m_param.acclSens != 3)
  //    {
  //        rtn = SetAcclSens(3);
  //        if (rtn) return rtn;
  //    }

  //    if (m_param.gyroLpf != 5)
  //    {
  //        rtn = SetGyroLPF(5);
  //        if (rtn) return rtn;
  //    }
  //
  //    if (m_param.acclLpf != 7)
  //    {
  //        rtn = SetAcclLPF(7);
  //        if (rtn) return rtn;
  //    }

  //    if (m_param.acclFltFactor != 20) //10 ->1
  //    {
  //        rtn = SetAcclFltFactor(20);
  //        if (rtn) return rtn;
  //    }
  //
  //    if (m_param.magnFltFactor != 10)
  //    {
  //        rtn = SetMagnFltFactor(10);
  //        if (rtn) return rtn;
  //    }
  //
  //    if (m_param.raaLvl != 0.01) // 0.2 -> 0.01
  //    {
  //        rtn = SetRaaLevel(0.01);
  //        if (rtn) return rtn;
  //    }
  //
  //    if (m_param.raaTime != 10000) // 10000 -> 1000
  //    {
  //        rtn = SetRaaTimeout(10000);
  //        if (rtn) return rtn;
  //    }
  //
  if (m_param.agcEnable != 1) {
    rtn = SetAutoGyroCalib(1);
    if (rtn)
      return rtn;
  }
  //
  //    if (m_param.agcThreshold != 0.8f)
  //    {
  //        rtn = SetAutoGyroCalibThreshold(0.8f);
  //        if (rtn) return rtn;
  //    }
  //
  //    if (m_param.agcDrift != 0.5f)
  //    {
  //        rtn = SetAutoGyroCalibDrift(0.5f);
  //        if (rtn) return rtn;
  //    }
  //
  //    if (m_param.avcGyro != 0)
  //    {
  //        rtn = SetAvcGyro(0);
  //        if (rtn) return rtn;
  //    }
  //
  //    if (m_param.avcAccl != 0)
  //    {
  //        rtn = SetAvcAccl(0);
  //        if (rtn) return rtn;
  //    }

  if (m_param.pons != 1) {
    rtn = PowerOnStart(true);
  }

  if (CalcPacketLen())
    return -1;

  return 0;
}

int8_t CEbImuV5::SetBuadRate(uint8_t rate) {
  if (m_fd < 0)
    return -1;
  if (rate > Baud921K)
    return -2;
  if (m_param.baudRate == rate)
    return 0;

  char txData[16];

  sprintf(txData, "<sb%d>", rate);

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.baudRate = rate;

  return 0;
}

int8_t CEbImuV5::SetOutputRate(uint16_t rate_ms) {
  if (m_fd < 0)
    return -1;
  if (m_param.outputRate == rate_ms)
    return 0;

  char txData[16];

  sprintf(txData, "<sor%d>", rate_ms);

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.outputRate = rate_ms;

  return 0;
}

int8_t CEbImuV5::SetOutputCode(uint8_t code) {
  if (m_fd < 0)
    return -1;
  if (code > Hex)
    return -2;
  if (m_param.outputCode == code)
    return 0;

  char txData[16];

  sprintf(txData, "<soc%d>", code);

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.outputCode = code;

  return 0;
}

int8_t CEbImuV5::SetOutputForm(uint8_t format) {
  if (m_fd < 0)
    return -1;
  if (format > Quat)
    return -2;
  if (m_param.outputForm == format)
    return 0;

  char txData[16];

  sprintf(txData, "<sof%d>", format);

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.outputForm = format;

  return 0;
}

int8_t CEbImuV5::SetGyroOut(uint8_t enable) {
  if (m_fd < 0)
    return -1;
  if (m_param.gyroOut == enable)
    return 0;

  char txData[7];

  sprintf(txData, (enable) ? "<sog1>" : "<sog0>");

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.gyroOut = enable ? 1 : 0;

  return 0;
}

int8_t CEbImuV5::SetAcclOut(uint8_t enable) {
  if (m_fd < 0)
    return -1;
  if (enable > VeloOut_Global)
    return -2;
  if (m_param.acclOut == enable)
    return 0;

  char txData[16];

  sprintf(txData, "<soa%d>", enable);

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.acclOut = enable;

  return 0;
}

int8_t CEbImuV5::SetMagnOut(uint8_t enable) {
  if (m_fd < 0)
    return -1;
  if (m_param.magnOut == enable)
    return 0;

  char txData[7];

  sprintf(txData, (enable) ? "<som1>" : "<som0>");

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.magnOut = enable ? 1 : 0;

  return 0;
}

int8_t CEbImuV5::SetDistOut(uint8_t enable) {
  if (m_fd < 0)
    return -1;
  if (enable > DistOut_Global)
    return -2;
  if (m_param.distOut == enable)
    return 0;

  char txData[16];

  sprintf(txData, "<sod%d>", enable);

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.distOut = enable;

  return 0;
}

int8_t CEbImuV5::SetTempOut(uint8_t enable) {
  if (m_fd < 0)
    return -1;
  if (m_param.tempOut == enable)
    return 0;

  char txData[7];

  sprintf(txData, enable ? "<sot1>" : "<sot0>");

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.tempOut = enable ? 1 : 0;

  return 0;
}

int8_t CEbImuV5::SetTimeOut(uint8_t enable) {
  if (m_fd < 0)
    return -1;
  if (m_param.timeOut == enable)
    return 0;

  char txData[8];

  sprintf(txData, enable ? "<sots1>" : "<sots0>");

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.timeOut = enable ? 1 : 0;
  return 0;
}

int8_t CEbImuV5::SetMagnEnable(uint8_t enable) {
  // 0:Magnetometer Off
  // 1:Magnetometer On
  // 2:Magnetometer On2 : Active anti-distortion
  if (m_fd < 0)
    return -1;
  if (enable > MagnOn2)
    return -2;
  if (m_param.magnEnable == enable)
    return 0;

  char txData[16];

  sprintf(txData, "<sem%d>", enable);

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.magnEnable = enable;

  return 0;
}

int8_t CEbImuV5::SetGyroSens(uint8_t sens) {
  // 5:2000dps (default)
  if (m_fd < 0)
    return -1;
  if (sens > Sens2000dps)
    return -2;
  if (m_param.gyroSens == sens)
    return 0;

  char txData[16];

  sprintf(txData, "<ssg%d>", sens);

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.gyroSens = sens;

  return 0;
}

int8_t CEbImuV5::SetAcclSens(uint8_t sens) {
  // 3:12G (default)
  if (m_fd < 0)
    return -1;
  if (sens > Sens24g)
    return -2;
  if (m_param.acclSens == sens)
    return 0;

  char txData[16];

  sprintf(txData, "<ssa%d>", sens);

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.acclSens = sens;

  return 0;
}

int8_t CEbImuV5::SetGyroLPF(uint8_t flt) {
  // 3:47Hz-ODR 400Hz (default)
  if (m_fd < 0)
    return -1;
  if (flt > GyroFlt532Hz)
    return -2;
  if (m_param.gyroLpf == flt)
    return 0;

  char txData[24];

  sprintf(txData, "<lpfg%d>", flt);

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.gyroLpf = flt;

  return 0;
}

int8_t CEbImuV5::SetAcclLPF(uint8_t flt) {
  // 5:40Hz-ODR 400Hz (default)
  if (m_fd < 0)
    return -1;
  if (flt > AcclFlt280Hz)
    return -2;
  if (m_param.acclLpf == flt)
    return 0;

  char txData[24];

  sprintf(txData, "<lpfa%d>", flt);

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.acclLpf = flt;

  return 0;
}

int8_t CEbImuV5::SetFltFactor(uint8_t factor) {
  // 10 (default)
  // may be.. it is a gain of ahrs algorithm
  // so if factor value inc., response time dec. but precision is poor.
  if (m_fd < 0)
    return -1;
  if (factor < 1 || factor > 50)
    return -2;
  if (m_param.acclFltFactor == factor && m_param.magnFltFactor == factor)
    return 0;

  char txData[16];

  sprintf(txData, "<sff%d>", factor);

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.acclFltFactor = factor;
  m_param.magnFltFactor = factor;

  return 0;
}

int8_t CEbImuV5::SetAcclFltFactor(uint8_t factor) {
  // 10 (default)
  if (m_fd < 0)
    return -1;
  if (factor < 1 || factor > 50)
    return -2;
  if (m_param.acclFltFactor == factor)
    return 0;

  char txData[24];

  sprintf(txData, "<sffa%d>", factor);

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.acclFltFactor = factor;

  return 0;
}

int8_t CEbImuV5::SetMagnFltFactor(uint8_t factor) {
  // 10 (default)
  if (m_fd < 0)
    return -1;
  if (factor < 1 || factor > 50)
    return -2;
  if (m_param.magnFltFactor == factor)
    return 0;

  char txData[24];

  sprintf(txData, "<sffm%d>", factor);

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.magnFltFactor = factor;

  return 0;
}

int8_t CEbImuV5::SetRaaLevel(double level) {
  // 0.2 (default)
  if (m_fd < 0)
    return -1;
  if (level < 0 || level > 100)
    return -2;
  if (m_param.raaLvl == level)
    return 0;

  char txData[16];

  sprintf(txData, "<raa_l%.2f>", level);

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.raaLvl = level;

  return 0;
}

int8_t CEbImuV5::SetRaaTimeout(uint32_t time_ms) {
  // 10000(10sec)
  if (m_fd < 0)
    return -1;
  if (time_ms > 4000000000)
    return -2;
  if (m_param.raaTime == time_ms)
    return 0;

  char txData[19];

  sprintf(txData, "<raa_t%d>", time_ms);

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.raaTime = time_ms;

  return 0;
}

int8_t CEbImuV5::SetRhaLevel(double level) {
  // 0.1 (default)
  if (m_fd < 0)
    return -1;
  if (level < 0 || level > 100)
    return -2;
  if (m_param.rhaLvl == level)
    return 0;

  char txData[16];

  sprintf(txData, "<rha_l%.2f>", level);

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.rhaLvl = level;

  return 0;
}

int8_t CEbImuV5::SetRhaTimeout(uint32_t time_ms) {
  // 10000(10sec)
  if (m_fd < 0)
    return -1;
  if (time_ms > 4000000000)
    return -2;
  if (m_param.rhaTime == time_ms)
    return 0;

  char txData[24];

  sprintf(txData, "<rha_t%d>", time_ms);

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.rhaTime = time_ms;

  return 0;
}

int8_t CEbImuV5::SetAutoGyroCalib(uint8_t enable) {
  if (m_fd < 0)
    return -1;
  if (m_param.agcEnable == enable)
    return 0;

  char txData[9];

  sprintf(txData, (enable) ? "<agc_e1>" : "<agc_e0>");

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.agcEnable = enable ? 1 : 0;

  return 0;
}

int8_t CEbImuV5::SetAutoGyroCalibThreshold(double threshold) {
  // 0.8 (default)
  if (m_fd < 0)
    return -1;
  if (threshold < 0 || threshold > 100)
    return -2;
  if (m_param.agcThreshold == threshold)
    return 0;

  char txData[16];

  sprintf(txData, "<agc_d%.2f>", threshold);

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.agcThreshold = threshold;

  return 0;
}

int8_t CEbImuV5::SetAutoGyroCalibDrift(double drift) {
  // 0.5 (default)
  if (m_fd < 0)
    return -1;
  if (drift < 0 || drift > 10)
    return -2;
  if (m_param.agcDrift == drift)
    return 0;

  char txData[16];

  sprintf(txData, "<agc_d%.2f>", drift);

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.agcDrift = drift;

  return 0;
}

int8_t CEbImuV5::SetAvcGyro(uint8_t enable) {
  if (m_fd < 0)
    return -1;
  if (m_param.avcGyro == enable)
    return 0;

  char txData[10];

  sprintf(txData, (enable) ? "<avcg_e1>" : "<avcg_e0>");

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.avcGyro = enable ? 1 : 0;

  return 0;
}

int8_t CEbImuV5::SetAvcAccl(uint8_t enable) {
  if (m_fd < 0)
    return -1;
  if (m_param.avcAccl == enable)
    return 0;

  char txData[10];

  sprintf(txData, (enable) ? "<avca_e1>" : "<avca_e0>");

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_param.avcAccl = enable ? 1 : 0;

  return 0;
}

int8_t CEbImuV5::CalibGyro() {
  if (m_fd < 0)
    return -1;

  char txData[5];

  sprintf(txData, "<cg>");

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  return 0;
}

int8_t CEbImuV5::CalibAcclSimple() {
  if (m_fd < 0)
    return -1;

  char txData[6];

  sprintf(txData, "<cas>");

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  return 0;
}

int8_t CEbImuV5::CalibMagnetometerStart() {
  if (m_fd < 0)
    return -1;
  if (m_bCalib)
    return -2;

  char txData[6];

  sprintf(txData, "<cmf>");

  int rtn = write(m_fd, txData, strlen(txData));

  if (rtn < 0) {
    fprintf(stderr, "SerialComm. Write() Error:%s(%d)", strerror(-rtn), rtn);
    return rtn;
  }

  m_bCalib = true;

  return 0;
}

int8_t CEbImuV5::CalibMagnetometerStop() {
  if (m_fd < 0)
    return -1;
  if (!m_bCalib)
    return -2;

  char txData[2];

  sprintf(txData, ">");

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  m_bCalib = false;

  return 0;
}

int8_t CEbImuV5::SetMotionOffset() {
  if (m_fd < 0)
    return -1;

  char txData[6];

  sprintf(txData, "<cmo>");

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  return 0;
}

int8_t CEbImuV5::ResetMotionOffset() {
  if (m_fd < 0)
    return -1;

  char txData[7];

  sprintf(txData, "<cmco>");

  if (WriteCmd(txData, strlen(txData)))
    return -3;

  return 0;
}

SEbImuV5Param &CEbImuV5::GetParam() { return m_param; }

SEbImuV5Data &CEbImuV5::GetData() { return m_data; }

int CEbImuV5::GetPacketLen() { return m_param.packetLen; }

int8_t CEbImuV5::CalcPacketLen() {
  m_param.packetLen = 4; // SOP(0x5555, 2byte) + CHK(2byte)

  if (m_param.outputForm == Quat) {
    m_param.packetLen += 8; // 4 * 2;
  } else {
    m_param.packetLen += 6; // 3 * 2;
  }

  if (m_param.gyroOut) {
    m_param.packetLen += 6; // 3 * 2;
  }

  if (m_param.acclOut) {
    m_param.packetLen += 6;
  }

  if (m_param.magnOut) {
    m_param.packetLen += 6;
  }

  if (m_param.distOut) {
    m_param.packetLen += 6;
  }

  if (m_param.tempOut) {
    m_param.packetLen += 2;
  }

  if (m_param.timeOut) {
    m_param.packetLen += 2;
  }

  //    --m_param.packetLen; // for index count

  //    printf("\n\n\n\n\n\n\n m_param.packetLen = %d\n",m_param.packetLen);

  if (m_param.packetLen < 0)
    return -1;

  return 0;
}
void CEbImuV5::PacketAssembly_ADH(bool &isInitialized, uint8_t data) {
  static uint8_t prevData = 0;

  //    if (isInitialized == false)
  //    {
  //        isInitialized = true;
  //        m_imuStep = 0;
  //        prevData = 0;
  //    }
  //    printf(",%X ",data);
  //    printf("m_imuStep = %d, ",m_imuStep);

  switch (m_imuStep) {
  case 0:
    if (data == 0x55 && prevData == 0x55) {
      m_packet.buf[0] = 0x55;
      m_packet.buf[1] = 0x55;
      prevData = 0;
      m_packet.idx = 2;
      m_imuStep = 1;
    } else {
      prevData = data;
    }
    break;
  case 1:
    m_packet.buf[m_packet.idx] = data;

    m_packet.idx++;

    if (m_param.packetLen == m_packet.idx) {
      int chkSum1 = 0;
      int chkSum2 = 0;
      /* CheckSum*/
      chkSum1 = (uint8_t)m_packet.buf[m_packet.idx - 2] << 8 |
                (uint8_t)m_packet.buf[m_packet.idx - 1];

      for (int i = 0; i < m_packet.idx - 2; i++) {
        chkSum2 += (uint8_t)m_packet.buf[i];
      }
      //            printf("\n chksum1 = %d, chksum2 = %d\n",chkSum1,chkSum2);
      if (chkSum2 == chkSum1) {
        ParsingHexPacket(m_packet.buf);
      } else {
        chkSumErr++;
        printf("checksum error! chkSumErr count = %d \n", chkSumErr);
      }
      memset(m_packet.buf, 0, sizeof(m_packet.buf)); // clear buffer
      prevData = 0;
      m_packet.idx = 0;
      m_imuStep = 0; // 2;

      //            printf("euler = %f, %f,
      //            %f\n",m_data.eulerZYX_rad[2],m_data.eulerZYX_rad[1],m_data.eulerZYX_rad[0]);
      //            printf("angVel = %f, %f,
      //            %f\n",m_data.gyro_rps[0],m_data.gyro_rps[1],m_data.gyro_rps[2]);
      //            printf("timeStamp = %d\n",m_data.timeStamp);
    }
    break;
  case 2:
    break;
  }
}

// void CEbImuV5::PacketAssembly(uint8_t data)
//{
//     static uint8_t prevData = 0;
//     static bool m_bSOP = false;
//
//     if (!m_bSOP)
//     {
//         if (data == 0x55 && prevData == 0x55)
//         {
//             m_packet.buf[0] = 0x55;
//             m_packet.buf[1] = 0x55;
//             prevData = 0;
//             m_packet.idx = 2;
//             m_bSOP = true;
//         }
//         else
//         {
//             prevData = data;
//         }
//     }
//     else
//     {
//         m_packet.buf[m_packet.idx] = data;
//
//         m_packet.idx++;
//
//         if (m_param.packetLen == m_packet.idx)
//         {
//             int chkSum1 = 0;
//             int chkSum2 = 0;
//             /* CheckSum*/
//             chkSum1 = (uint8_t)m_packet.buf[m_packet.idx - 2] << 8 |
//             (uint8_t)m_packet.buf[m_packet.idx - 1];
//
//             for (int i = 0; i<m_packet.idx-2; i++){
//                 chkSum2 += (uint8_t)m_packet.buf[i];
//             }
//
////            printf("\n chksum1 = %d, chksum2 = %d\n",chkSum1,chkSum2);
//            if (chkSum2 == chkSum1)
//            {
////                ParsingHexPacket(m_packet.buf);
////                rtn = 1;
//                ParsingHexPacket(m_packet.buf);
//            }
//            else{
//                chkSumErr++;
////                printf("checksum error! chkSumErr count = %d \n",chkSumErr);
//
//            }
//            memset(m_packet.buf, 0, sizeof(m_packet.buf)); // clear buffer
//
//            m_packet.idx = 0;
//            m_bSOP = false;
//        }
//    }
//}

// int8_t CEbImuV5::PacketAssembly(const uint8_t &data)
//{
//     int8_t rtn = 0;
//     uint16_t chkSum = 0;
//     static bool bSOP = false;
//
//     switch (m_param.outputCode)
//     {
//     case Ascii:
//         if (data == '*')
//         {
//             m_packet.idx = 0;
//             m_packet.buf[m_packet.idx++] = data;
//         }
//         else if (data == '\n' && m_packet.buf[0] == '*')
//         {
//             m_packet.buf[m_packet.idx++] = data;
//             ParsingAsciiPacket((char*)m_packet.buf);
//             memset(m_packet.buf, 0, sizeof(m_packet.buf));
//             rtn = 1;
//         }
//         else
//         {
//             m_packet.buf[m_packet.idx++] = data;
//         }
//         break;
//     case Hex:
//         if (data == 0x55 && !bSOP)
//         {
////            printf("[1]\n");
//            if (m_packet.idx > 0 && m_packet.buf[m_packet.idx - 1] == 0x55)
//            {
//                m_packet.buf[0] = data;
//                m_packet.buf[1] = data;
//                m_packet.idx = 2;
//                bSOP = true;
//            }
//            else
//            {
//                m_packet.buf[m_packet.idx++] = data;
//                bSOP = false;
//            }
//        }
//        else if (bSOP && (m_param.packetLen == m_packet.idx))
//        {
////            printf("[2]\n");
//            m_packet.buf[m_packet.idx++] = data;
//
//            /* CheckSum*/
//            m_data.chkSum = (uint8_t)m_packet.buf[m_packet.idx - 2] << 8 |
//            (uint8_t)m_packet.buf[m_packet.idx - 1];
//
//            for (int i = 0; i<m_packet.idx-2; i++)
//                chkSum += (uint8_t)m_packet.buf[i];
//
//            if (chkSum == m_data.chkSum)
//            {
//                ParsingHexPacket(m_packet.buf);
//                rtn = 1;
//            }
////            else{
////                printf("checksum error!\n");
////            }
//            memset(m_packet.buf, 0, sizeof(m_packet.buf));
//            bSOP = false;
//        }
//        else
//        {
////            printf("[3]\n");
//            m_packet.buf[m_packet.idx++] = data;
//        }
//        break;
//    }
//
//    if (m_packet.idx >= 18) m_packet.idx = 0; //255
//
//    return rtn;
//}

int CEbImuV5::ReadRawData() {
  //    static int zero_cnt = 0;

  if (m_blockRead)
    return 0;

  //    int rtn = read(m_fd, m_rawData, 16); //255
  int rtn = read(m_fd, m_rawData, BUFFERSIZE); // 255
  printf("length = %d \n", rtn);

  //    if(rtn == 0){
  //        zero_cnt++;
  //        printf("zero cnt = %d\n",zero_cnt);
  //    }

  //    if (rtn != 16)
  //    {
  //        static int rtnCnt = 0;
  //        printf("\n\n\n\n\n\n [WALRNIG] rtn = %d, rtnCnt =
  //        %d\n\n\n\n\n",rtn,rtnCnt); rtnCnt++;
  //    }

  //    uint8_t rawData[1];
  //    int rtn = 0;
  //    bool isInitialized = false;
  //
  //    for (int i=0; i<18; i++)
  //    {
  //
  //        rtn = read(m_fd, rawData, 1); //255
  ////            printf("%X, ",m_rawData[i]);
  ////            PacketAssembly(m_rawData[i]);
  //        PacketAssembly_ADH(isInitialized,rawData[0]);
  //
  ////        printf(",%X ",rawData[0]);
  ////        if (rtn == 0)
  ////        {
  ////            rtn = i;
  ////            break;
  ////        }
  //    }
  //    printf("\n");

  if (rtn > 0) {
    bool isInitialized = false;
    for (int i = 0; i < rtn; i++) {
      //            printf("%X, ",m_rawData[i]);
      //            PacketAssembly(m_rawData[i]);
      PacketAssembly_ADH(isInitialized, m_rawData[i]);
    }
    //        printf("\n");
  } else if (rtn < 0) {
    fprintf(stderr, "SerialComm. Read() Error:%s(%d)", strerror(-rtn), rtn);
  }

  return rtn;
}

int8_t CEbImuV5::ParsingConfig(char *config) {
  char *ptrName = nullptr;
  char *ptrEnd = nullptr;

  if (config[0] != '<')
    return -4;

  ptrEnd = config;

  ptrName = strstr(ptrEnd, "sb:");
  if (ptrName == nullptr)
    return -4;
  m_param.baudRate = strtol(ptrName + 3, &ptrEnd, 10);
  if (ptrEnd == nullptr)
    return -4;

  ptrName = strstr(ptrEnd, "sor:");
  if (ptrName == nullptr)
    return -4;
  m_param.outputRate = strtol(ptrName + 4, &ptrEnd, 10);
  if (ptrEnd == nullptr)
    return -4;

  ptrName = strstr(ptrEnd, "soc:");
  if (ptrName == nullptr)
    return -4;
  m_param.outputCode = strtol(ptrName + 4, &ptrEnd, 10);
  if (ptrEnd == nullptr)
    return -4;

  ptrName = strstr(ptrEnd, "sof:");
  if (ptrName == nullptr)
    return -4;
  m_param.outputForm = strtol(ptrName + 4, &ptrEnd, 10);
  if (ptrEnd == nullptr)
    return -4;

  ptrName = strstr(ptrEnd, "sog:");
  if (ptrName == nullptr)
    return -4;
  m_param.gyroOut = strtol(ptrName + 4, &ptrEnd, 10);
  if (ptrEnd == nullptr)
    return -4;

  ptrName = strstr(ptrEnd, "soa:");
  if (ptrName == nullptr)
    return -4;
  m_param.acclOut = strtol(ptrName + 4, &ptrEnd, 10);
  if (ptrEnd == nullptr)
    return -4;

  ptrName = strstr(ptrEnd, "som:");
  if (ptrName == nullptr)
    return -4;
  m_param.magnOut = strtol(ptrName + 4, &ptrEnd, 10);
  if (ptrEnd == nullptr)
    return -4;

  ptrName = strstr(ptrEnd, "sod:");
  if (ptrName == nullptr)
    return -4;
  m_param.distOut = strtol(ptrName + 4, &ptrEnd, 10);
  if (ptrEnd == nullptr)
    return -4;

  ptrName = strstr(ptrEnd, "sot:");
  if (ptrName == nullptr)
    return -4;
  m_param.tempOut = strtol(ptrName + 4, &ptrEnd, 10);
  if (ptrEnd == nullptr)
    return -4;

  ptrName = strstr(ptrEnd, "sots:");
  if (ptrName == nullptr)
    return -4;
  m_param.timeOut = strtol(ptrName + 5, &ptrEnd, 10);
  if (ptrEnd == nullptr)
    return -4;

  ptrName = strstr(ptrEnd, "sem:");
  if (ptrName == nullptr)
    return -4;
  m_param.magnEnable = strtol(ptrName + 4, &ptrEnd, 10);
  if (ptrEnd == nullptr)
    return -4;

  ptrName = strstr(ptrEnd, "ssg:");
  if (ptrName == nullptr)
    return -4;
  m_param.gyroSens = strtol(ptrName + 4, &ptrEnd, 10);
  if (ptrEnd == nullptr)
    return -4;

  ptrName = strstr(ptrEnd, "ssa:");
  if (ptrName == nullptr)
    return -4;
  m_param.acclSens = strtol(ptrName + 4, &ptrEnd, 10);
  if (ptrEnd == nullptr)
    return -4;

  ptrName = strstr(ptrEnd, "lpfg:");
  if (ptrName == nullptr)
    return -4;
  m_param.gyroLpf = strtol(ptrName + 5, &ptrEnd, 10);
  if (ptrEnd == nullptr)
    return -4;

  ptrName = strstr(ptrEnd, "lpfa:");
  if (ptrName == nullptr)
    return -4;
  m_param.acclLpf = strtol(ptrName + 5, &ptrEnd, 10);
  if (ptrEnd == nullptr)
    return -4;

  ptrName = strstr(ptrEnd, "sffa:");
  if (ptrName == nullptr)
    return -4;
  m_param.acclFltFactor = strtol(ptrName + 5, &ptrEnd, 10);
  if (ptrEnd == nullptr)
    return -4;

  ptrName = strstr(ptrEnd, "sffm:");
  if (ptrName == nullptr)
    return -4;
  m_param.magnFltFactor = strtol(ptrName + 5, &ptrEnd, 10);
  if (ptrEnd == nullptr)
    return -4;

  ptrName = strstr(ptrEnd, "raa_l:");
  if (ptrName == nullptr)
    return -4;
  m_param.raaLvl = strtof(ptrName + 6, &ptrEnd);
  if (ptrEnd == nullptr)
    return -4;

  ptrName = strstr(ptrEnd, "raa_t:");
  if (ptrName == nullptr)
    return -4;
  m_param.raaTime = strtol(ptrName + 6, &ptrEnd, 10);
  if (ptrEnd == nullptr)
    return -4;

  ptrName = strstr(ptrEnd, "rha_l:");
  if (ptrName == nullptr)
    return -4;
  m_param.rhaLvl = strtof(ptrName + 6, &ptrEnd);
  if (ptrEnd == nullptr)
    return -4;

  ptrName = strstr(ptrEnd, "rha_t:");
  if (ptrName == nullptr)
    return -4;
  m_param.rhaTime = strtol(ptrName + 6, &ptrEnd, 10);
  if (ptrEnd == nullptr)
    return -4;

  ptrName = strstr(ptrEnd, "agc_e:");
  if (ptrName == nullptr)
    return -4;
  m_param.agcEnable = strtol(ptrName + 6, &ptrEnd, 10);
  if (ptrEnd == nullptr)
    return -4;

  ptrName = strstr(ptrEnd, "agc_t:");
  if (ptrName == nullptr)
    return -4;
  m_param.agcThreshold = strtof(ptrName + 6, &ptrEnd);
  if (ptrEnd == nullptr)
    return -4;

  ptrName = strstr(ptrEnd, "agc_d:");
  if (ptrName == nullptr)
    return -4;
  m_param.agcDrift = strtof(ptrName + 6, &ptrEnd);
  if (ptrEnd == nullptr)
    return -4;

  ptrName = strstr(ptrEnd, "avca_e:");
  if (ptrName == nullptr)
    return -4;
  m_param.avcAccl = strtol(ptrName + 7, &ptrEnd, 10);
  if (ptrEnd == nullptr)
    return -4;

  ptrName = strstr(ptrEnd, "avcg_e:");
  if (ptrName == nullptr)
    return -4;
  m_param.avcGyro = strtol(ptrName + 7, &ptrEnd, 10);
  if (ptrEnd == nullptr)
    return -4;

  ptrName = strstr(ptrEnd, "pons:");
  if (ptrName == nullptr)
    return -4;
  m_param.pons = strtol(ptrName + 5, &ptrEnd, 10);
  if (ptrEnd == nullptr)
    return -4;

  return 0;
}

void CEbImuV5::ParsingAsciiPacket(char *packet) {
  char *ptrStart = nullptr;
  char *ptrEnd = packet;

  switch (m_param.outputForm) {
  case Euler:
    ptrStart = ptrEnd + 1;
    m_data.eulerZYX_rad[2] =
        strtof(ptrStart, &ptrEnd) * 0.0174532925f; // deg to radian

    ptrStart = ptrEnd + 1;
    m_data.eulerZYX_rad[1] =
        strtof(ptrStart, &ptrEnd) * -0.0174532925f; // deg to radian

    ptrStart = ptrEnd + 1;
    m_data.eulerZYX_rad[0] =
        strtof(ptrStart, &ptrEnd) * -0.0174532925f; // deg to radian
    break;
  case Quat:
    ptrStart = ptrEnd + 1;
    m_data.quat[3] = strtof(ptrStart, &ptrEnd);

    ptrStart = ptrEnd + 1;
    m_data.quat[2] = strtof(ptrStart, &ptrEnd);

    ptrStart = ptrEnd + 1;
    m_data.quat[1] = strtof(ptrStart, &ptrEnd);

    ptrStart = ptrEnd + 1;
    m_data.quat[0] = strtof(ptrStart, &ptrEnd);
    break;
  }

  if (m_param.gyroOut) {
    ptrStart = ptrEnd + 1;
    m_data.gyro_rps[0] =
        strtof(ptrStart, &ptrEnd) * 0.0174532925f; // deg to radian

    ptrStart = ptrEnd + 1;
    m_data.gyro_rps[1] =
        strtof(ptrStart, &ptrEnd) * 0.0174532925f; // deg to radian

    ptrStart = ptrEnd + 1;
    m_data.gyro_rps[2] =
        strtof(ptrStart, &ptrEnd) * 0.0174532925f; // deg to radian
  }

  //    fprintf(stderr, "m_param.acclOut = %d\n", m_param.acclOut);

  switch (m_param.acclOut) {
  case AcclOut:
  case AcclOutWoG_Local:
  case AcclOutWoG_Global:
    ptrStart = ptrEnd + 1;
    m_data.accl_G[0] = strtof(ptrStart, &ptrEnd);

    ptrStart = ptrEnd + 1;
    m_data.accl_G[1] = strtof(ptrStart, &ptrEnd);

    ptrStart = ptrEnd + 1;
    m_data.accl_G[2] = strtof(ptrStart, &ptrEnd);
    break;
  case VeloOut_Local:
  case VeloOut_Global:
    ptrStart = ptrEnd + 1;
    m_data.velo_mps[0] = strtof(ptrStart, &ptrEnd);

    ptrStart = ptrEnd + 1;
    m_data.velo_mps[1] = strtof(ptrStart, &ptrEnd);

    ptrStart = ptrEnd + 1;
    m_data.velo_mps[2] = strtof(ptrStart, &ptrEnd);
    break;
  }

  if (m_param.magnOut) {
    ptrStart = ptrEnd + 1;
    m_data.magn_uT[0] = strtof(ptrStart, &ptrEnd);

    ptrStart = ptrEnd + 1;
    m_data.magn_uT[1] = strtof(ptrStart, &ptrEnd);

    ptrStart = ptrEnd + 1;
    m_data.magn_uT[2] = strtof(ptrStart, &ptrEnd);
  }

  if (m_param.distOut) {
    ptrStart = ptrEnd + 1;
    m_data.dist_m[0] = strtof(ptrStart, &ptrEnd);

    ptrStart = ptrEnd + 1;
    m_data.dist_m[1] = strtof(ptrStart, &ptrEnd);

    ptrStart = ptrEnd + 1;
    m_data.dist_m[2] = strtof(ptrStart, &ptrEnd);
  }

  if (m_param.tempOut) {
    ptrStart = ptrEnd + 1;
    m_data.temp_C = strtof(ptrStart, &ptrEnd);
  }

  if (m_param.timeOut) {
    ptrStart = ptrEnd + 1;
    m_data.timeStamp = strtof(ptrStart, &ptrEnd);
  }
}

void CEbImuV5::ParsingHexPacket(uint8_t *packet) {
  int idx = 2;
  uint16_t tmpData = 0;

  switch (m_param.outputForm) {
  case Euler:
    tmpData = (uint8_t)packet[idx++] << 8;
    tmpData |= (uint8_t)packet[idx++];
    m_data.eulerZYX_rad[2] =
        (int16_t)tmpData *
        0.000174532925f; // deg to radian, deg: (int16_t)tmpData / 100.0f;

    tmpData = (uint8_t)packet[idx++] << 8;
    tmpData |= (uint8_t)packet[idx++];
    m_data.eulerZYX_rad[1] =
        (int16_t)tmpData *
        -0.000174532925f; // deg to radian, deg: (int16_t)tmpData / 100.0f;

    tmpData = (uint8_t)packet[idx++] << 8;
    tmpData |= (uint8_t)packet[idx++];
    m_data.eulerZYX_rad[0] =
        (int16_t)tmpData *
        -0.000174532925f; // deg to radian, deg: (int16_t)tmpData / 100.0f;
    break;
  case Quat:
    tmpData = (uint8_t)packet[idx++] << 8;
    tmpData |= (uint8_t)packet[idx++];
    m_data.quat[3] = (int16_t)tmpData / 10000.0f;

    tmpData = (uint8_t)packet[idx++] << 8;
    tmpData |= (uint8_t)packet[idx++];
    m_data.quat[2] = (int16_t)tmpData / 10000.0f;

    tmpData = (uint8_t)packet[idx++] << 8;
    tmpData |= (uint8_t)packet[idx++];
    m_data.quat[1] = (int16_t)tmpData / 10000.0f;

    tmpData = (uint8_t)packet[idx++] << 8;
    tmpData |= (uint8_t)packet[idx++];
    m_data.quat[0] = (int16_t)tmpData / 10000.0f;
    break;
  }

  if (m_param.gyroOut) {
    tmpData = (uint8_t)packet[idx++] << 8;
    tmpData |= (uint8_t)packet[idx++];
    m_data.gyro_rps[0] =
        (int16_t)tmpData *
        0.00174532925f; // deg to radian, deg: (int16_t)tmpData / 10.0f;

    tmpData = (uint8_t)packet[idx++] << 8;
    tmpData |= (uint8_t)packet[idx++];
    m_data.gyro_rps[1] =
        (int16_t)tmpData *
        0.00174532925f; // deg to radian, deg: (int16_t)tmpData / 10.0f;

    tmpData = (uint8_t)packet[idx++] << 8;
    tmpData |= (uint8_t)packet[idx++];
    m_data.gyro_rps[2] =
        (int16_t)tmpData *
        0.00174532925f; // deg to radian, deg: (int16_t)tmpData / 10.0f;
  }

  //    printf("m_param.acclOut = %d\n",m_param.acclOut);
  switch (m_param.acclOut) {
  case AcclOut:
  case AcclOutWoG_Local:
  case AcclOutWoG_Global:
    tmpData = (uint8_t)packet[idx++] << 8;
    tmpData |= (uint8_t)packet[idx++];
    m_data.accl_G[0] = (int16_t)tmpData / 1000.0f; // ADH: + -> -

    tmpData = (uint8_t)packet[idx++] << 8;
    tmpData |= (uint8_t)packet[idx++];
    m_data.accl_G[1] = (int16_t)tmpData / 1000.0f;

    tmpData = (uint8_t)packet[idx++] << 8;
    tmpData |= (uint8_t)packet[idx++];
    m_data.accl_G[2] = (int16_t)tmpData / 1000.0f;
    break;
  case VeloOut_Local:
  case VeloOut_Global:
    tmpData = (uint8_t)packet[idx++] << 8;
    tmpData |= (uint8_t)packet[idx++];
    m_data.velo_mps[0] = (int16_t)tmpData / 1000.0f;

    tmpData = (uint8_t)packet[idx++] << 8;
    tmpData |= (uint8_t)packet[idx++];
    m_data.velo_mps[1] = (int16_t)tmpData / 1000.0f;

    tmpData = (uint8_t)packet[idx++] << 8;
    tmpData |= (uint8_t)packet[idx++];
    m_data.velo_mps[2] = (int16_t)tmpData / 1000.0f;
    break;
  }

  if (m_param.magnOut) {
    tmpData = (uint8_t)packet[idx++] << 8;
    tmpData |= (uint8_t)packet[idx++];
    m_data.magn_uT[0] = (int16_t)tmpData / 10.0f;

    tmpData = (uint8_t)packet[idx++] << 8;
    tmpData |= (uint8_t)packet[idx++];
    m_data.magn_uT[1] = (int16_t)tmpData / 10.0f;

    tmpData = (uint8_t)packet[idx++] << 8;
    tmpData |= (uint8_t)packet[idx++];
    m_data.magn_uT[2] = (int16_t)tmpData / 10.0f;
  }

  if (m_param.distOut) {
    tmpData = (uint8_t)packet[idx++] << 8;
    tmpData |= (uint8_t)packet[idx++];
    m_data.dist_m[0] = (int16_t)tmpData / 1000.0f;

    tmpData = (uint8_t)packet[idx++] << 8;
    tmpData |= (uint8_t)packet[idx++];
    m_data.dist_m[1] = (int16_t)tmpData / 1000.0f;

    tmpData = (uint8_t)packet[idx++] << 8;
    tmpData |= (uint8_t)packet[idx++];
    m_data.dist_m[2] = (int16_t)tmpData / 1000.0f;
  }

  if (m_param.tempOut) {
    tmpData = (uint8_t)packet[idx++] << 8;
    tmpData |= (uint8_t)packet[idx++];
    m_data.temp_C = (int16_t)tmpData / 10.0f;
  }

  if (m_param.timeOut) {
    tmpData = (uint8_t)packet[idx++] << 8;
    tmpData |= (uint8_t)packet[idx++];
    m_data.timeStamp = tmpData;
  }
}

int8_t CEbImuV5::WriteCmd(const char *cmd, size_t size_byte) {
  int8_t rtn = 0;
  int n_byte = 0;
  int rxSize = 0;
  char rxData[4095] = {
      0,
  };

  m_blockRead = true;

  tcflush(m_fd, TCIFLUSH); // flush data received but not read
  n_byte = write(m_fd, cmd, size_byte);
  if (n_byte < 0) {
    fprintf(stderr, "SerialComm. Write() Error:%s(%d)", strerror(-n_byte),
            n_byte);
    m_blockRead = false;
    return -1;
  }

  for (int i = 0; i < 500; i++) {
    n_byte = read(m_fd, m_rawData, 255); // 255

    if (n_byte > 0) {
      m_rawData[n_byte] = 0;
      rxSize += n_byte;

      if (rxSize >= 4095) {
        rxData[0] = 0;
        rxSize = n_byte;
      }

      strcat(rxData, (char *)m_rawData);

      if (strstr((char *)m_rawData, "<ok>") != nullptr) {
        rtn = 0;
        break;
      } else if (strstr((char *)m_rawData, "<er>") != nullptr) {
        rtn = 1;
        break;
      }
    } else if (n_byte < 0) {
      fprintf(stderr, "SerialComm. Read() Error:%s(%d)", strerror(-n_byte),
              n_byte);
      rtn = -1;
      break;
    }

    usleep(10000);
  }

  m_blockRead = false;

  return rtn;
}
