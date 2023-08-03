#include "joyPs4Input.h"
#include <chrono>
#include <thread>

using namespace UserCtrl::UserCtrlUtil;

void dumpJoyData(JoyPs4Input& joy);

int main() 
{
    JoyPs4Input joyInput;
    joyInput.joyOpen("/dev/input/js1");
    int loop_count = 10000; // msec
    while (loop_count-- > 0) {

        joyInput.joyInput();
        dumpJoyData(joyInput);
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    joyInput.joyClose();
    return 0;
}

void dumpJoyData(JoyPs4Input& joy)
{
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "cmd_Icon: " << joy.PS4_result[0] << std::endl;
    std::cout << "cmd_Share: " <<  joy.PS4_result[23] << std::endl;
    std::cout << "cmd_Option: " <<  joy.PS4_result[24] << std::endl;

    std::cout << "cmd_L1: " <<  joy.PS4_result[1] << std::endl;
    std::cout << "cmd_R1: " <<  joy.PS4_result[2] << std::endl;
    std::cout << "cmd_L2: " <<  joy.PS4_result[21] << std::endl;
    std::cout << "cmd_R2: " <<  joy.PS4_result[22] << std::endl;

    std::cout << "cmd_triangle: " <<  joy.PS4_result[3] << std::endl;
    std::cout << "cmd_circle: " <<  joy.PS4_result[4] << std::endl;
    std::cout << "cmd_cross: " <<  joy.PS4_result[5] << std::endl;
    std::cout << "cmd_square: " <<  joy.PS4_result[6] << std::endl;

    std::cout << "cmd_Up: " <<  joy.PS4_result[7] << std::endl;
    std::cout << "cmd_Right: " <<  joy.PS4_result[8] << std::endl;
    std::cout << "cmd_Down: " <<  joy.PS4_result[9] << std::endl;
    std::cout << "cmd_Left: " <<  joy.PS4_result[10] << std::endl;

    std::cout << "cmd_Lx: " <<  joy.PS4_result[13] / 32767.0 << std::endl;
    std::cout << "cmd_Ly: " <<  joy.PS4_result[14] / 32767.0 << std::endl;

    std::cout << "cmd_Rx: " <<  joy.PS4_result[15] / 32767.0 << std::endl;
    std::cout << "cmd_Ry: " <<  joy.PS4_result[19] / 32767.0 << std::endl;
}
