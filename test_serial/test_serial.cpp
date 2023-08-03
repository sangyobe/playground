#include <stdio.h>
#include <string.h>
// Linux headers
#include <errno.h>   // Error integer and strerror() function
#include <fcntl.h>   // Contains file controls like O_RDWR
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h>  // write(), read(), close()

int main() {

  int serial_port;
  serial_port = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NONBLOCK);
  if (serial_port < 0) {
    printf("Error %i from open: %s\n", errno, strerror(errno));
  }

  struct termios tty;

  // Read in existing settings, and handle any error
  if (tcgetattr(serial_port, &tty) != 0) {
    printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
  }

  // control mode (c_cflag)
  tty.c_cflag &= ~PARENB; // Clear parity bit, disabling parity (most common)
  tty.c_cflag &= ~CSTOPB; // Clear stop field, only one stop bit used in
                          // communication (most common)
  tty.c_cflag &=
      ~CSIZE; // Clear all the size bits, then use one of the statements below
  tty.c_cflag |= CS8; // 8 bits per byte (most common)
  tty.c_cflag &=
      ~CRTSCTS; // Disable RTS/CTS hardware flow control (most common)
  tty.c_cflag |=
      CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)
  tty.c_lflag &= ~ICANON;
  tty.c_lflag &= ~ECHO;   // Disable echo
  tty.c_lflag &= ~ECHOE;  // Disable erasure
  tty.c_lflag &= ~ECHONL; // Disable new-line echo
  tty.c_lflag &= ~ISIG;   // Disable interpretation of INTR, QUIT and SUSP

  // input modes (c_iflag)
  tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl
  tty.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR |
                   ICRNL); // Disable any special handling of received bytes

  // output modes (c_oflag)
  tty.c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g.
                         // newline chars)
  tty.c_oflag &=
      ~ONLCR; // Prevent conversion of newline to carriage return/line feed

  // VMIN, VTIME
  tty.c_cc[VTIME] = 10; // Wait for up to 1s (10 deciseconds), returning as soon
                        // as any data is received.
  tty.c_cc[VMIN] = 0;

  // Baud rate
  cfsetispeed(&tty, B230400);
  cfsetospeed(&tty, B230400);

  tcflush(serial_port, TCIFLUSH); // flush data received but not read

  // Save tty settings, also checking for error
  if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
    printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
  }

  char read_buf[256];

  while (true) {
    usleep(1000);
    int num_bytes = read(serial_port, &read_buf, sizeof(read_buf));
    if (num_bytes < 0) {
      printf("Error reading: %s", strerror(errno));
      break;
    }
    printf("Read %i bytes", num_bytes);
    // break;
  }

  close(serial_port);

  return 0;
}