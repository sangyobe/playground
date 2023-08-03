/*
\file       joyPs4Input.cpp
\brief      joystick PS4 Library for linux
\author     TaeYu Kim
\author     ChanMook Lim
\author     Joonhee Jo
\author
\date       2023. 06. 08
\version    0.0.1
\warning    Do Not delete this comment for document history! This is minimal manners!
*/

#ifndef JOYPS4INPUT_H
#define JOYPS4INPUT_H

#include <fcntl.h>
#include <iostream>
#include <linux/joystick.h>
#include <stdio.h>
#include <unistd.h>

namespace UserCtrl
{
namespace UserCtrlUtil
{

class JoyPs4Input
{
public:
    int32_t PS4_result[25] = {
        0,
    };

    void joyOpen(const char* interface);
    void joyClose();
    void joyInput();

private:

    struct axisState
    {
        short x, y;
    };

    js_event event;
    axisState axes[4] = {0};

    int js;
    size_t axis;

    int readEvent(int fd, js_event *event);
    size_t getButton(int fd);
    size_t axisState(js_event *event, axisState axes[3]);
    void setCommand(int fd, js_event *event);
};

} // namespace UserCtrlUtil
} // namespace UserCtrl

#endif // JOYPS4INPUT_H
