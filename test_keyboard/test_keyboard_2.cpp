#include "keyboard.h"
#include <iostream>
#include <thread>
#include <chrono>

dt::Keyboard keyboard;

int ReadKeyboardRaw()
{
    int rtn = 0;
    int recvBytes = 0;
    static int retryCnt = 0;

//    do {
        rtn = keyboard.ReadRawData();
//    } while (rtn > 0);

    return rtn;
}

void ReadKeyboard()
{

    printf("A|%d B|%d C|%d D|%d E|%d F|%d G|%d H|%d I|%d J|%d K|%d L|%d M|%d\n"
            , keyboard.KeyPressed('a')
            , keyboard.KeyPressed('b')
            , keyboard.KeyPressed('c')
            , keyboard.KeyPressed('d')
            , keyboard.KeyPressed('e')
            , keyboard.KeyPressed('f')
            , keyboard.KeyPressed('g')
            , keyboard.KeyPressed('h')
            , keyboard.KeyPressed('i')
            , keyboard.KeyPressed('j')
            , keyboard.KeyPressed('k')
            , keyboard.KeyPressed('l')
            , keyboard.KeyPressed('m'));
}

int main() {
    keyboard.SetupTerminal();

    bool bRun = true;
    while (bRun) {
        ReadKeyboardRaw();
        ReadKeyboard();

        if (keyboard.KeyPressed('a')) {
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    keyboard.RestoreTerminal();

    return 0;
}