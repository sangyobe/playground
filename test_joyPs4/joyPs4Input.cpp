/*
\file       joyPs4Input.cpp
\brief      joystick PS4 Library for linux
\author     TaeYu Kim
\author
\date       2022. 11. 16
\version    0.0.1
\warning    Do Not delete this comment for document history! This is minimal manners!
*/

#include "joyPs4Input.h"

namespace UserCtrl
{
namespace UserCtrlUtil
{

void JoyPs4Input::setCommand(int fd, js_event *event)
{
    if ((event->number == 10) && (event->value == 1)) // ICON
        PS4_result[0] = 1;
    else if ((event->number == 10) && (event->value == 0))
        PS4_result[0] = 0;

    else if ((event->number == 8) && (event->value == 1)) // SHARE
        PS4_result[23] = 1;
    else if ((event->number == 8) && (event->value == 0))
        PS4_result[23] = 0;

    else if ((event->number == 9) && (event->value == 1)) // OPTIONS
        PS4_result[24] = 1;
    else if ((event->number == 9) && (event->value == 0))
        PS4_result[24] = 0;

    else if ((event->number == 4) && (event->value == 1)) // L1
        PS4_result[1] = 1;
    else if ((event->number == 4) && (event->value == 0))
        PS4_result[1] = 0;

    else if ((event->number == 5) && (event->value == 1)) // R1
        PS4_result[2] = 1;
    else if ((event->number == 5) && (event->value == 0))
        PS4_result[2] = 0;

    else if ((event->number == 2) && (event->value == 1)) // TRIANGLE
        PS4_result[3] = 1;
    else if ((event->number == 2) && (event->value == 0))
        PS4_result[3] = 0;

    else if ((event->number == 1) && (event->value == 1)) // CIRCLE
        PS4_result[4] = 1;
    else if ((event->number == 1) && (event->value == 0))
        PS4_result[4] = 0;

    else if ((event->number == 0) && (event->value == 1)) // CROSS
        PS4_result[5] = 1;
    else if ((event->number == 0) && (event->value == 0))
        PS4_result[5] = 0;

    else if ((event->number == 3) && (event->value == 1)) // SQUARE
        PS4_result[6] = 1;
    else if ((event->number == 3) && (event->value == 0))
        PS4_result[6] = 0;

    if ((event->number == 7) && (event->value == -32767)) // UP
        PS4_result[7] = 1;
    else if ((event->number == 7) && (event->value == 32767)) // DOWN
        PS4_result[9] = 1;
    else if ((event->number == 7) && (event->value == 0))
    {
        PS4_result[7] = 0;
        PS4_result[9] = 0;
    }

    if ((event->number == 6) && (event->value == 32767)) // RIGHT
        PS4_result[8] = 1;
    else if ((event->number == 6) && (event->value == -32767)) // LEFT
        PS4_result[10] = 1;
    else if ((event->number == 6) && (event->value == 0))
    {
        PS4_result[8] = 0;
        PS4_result[10] = 0;
    }

    if (event->type == 2 && (event->number == 0 || event->number == 1)) // LX, LY
    {
        // PS4_result[13] = axes[axis].x;
        // PS4_result[15] = -axes[axis].y;
        PS4_result[13] = axes[axis].x;
        PS4_result[15] = -axes[axis].y;
    }
    else
    {
        PS4_result[13] = 0;
        PS4_result[15] = 0;
    }

    if (event->type == 2 && (event->number == 3 || event->number == 4)) // RX, RY
    {
        PS4_result[17] = axes[axis].y;
        PS4_result[19] = -axes[axis].x;
    }
    else
    {
        PS4_result[17] = 0;
        PS4_result[19] = 0;
    }

    if (event->type == 2 && event->number == 2) // L2
    {
        PS4_result[21] = event->value + 32767; // 0 ~ 65534
    }
    else
    {
        PS4_result[21] = 0;
    }

    if (event->type == 2 && event->number == 5) // R2
    {
        PS4_result[22] = event->value + 32767; // 0 ~ 65534
    }
    else
    {
        PS4_result[22] = 0;
    }
}

int JoyPs4Input::readEvent(int fd, struct js_event *event)
{
    ssize_t bytes;
    bytes = read(fd, event, sizeof(*event));

    if (bytes == sizeof(*event))
        return 0;

    return -1;
}

size_t JoyPs4Input::getButton(int fd)
{
    __u8 buttons;
    if (ioctl(fd, JSIOCGBUTTONS, &buttons) == -1)
        return 0;

    return buttons;
}

size_t JoyPs4Input::axisState(struct js_event *event, struct axisState axes[4])
{
    size_t axis;
    if (event->number == 0 || event->number == 1)
        axis = 0; // LX,LY
    if (event->number == 3 || event->number == 4)
        axis = 1; // RX,RY
    if (axis < 2)
    {
        if (event->number % 2 == 0)
            axes[axis].x = event->value;
        else
            axes[axis].y = event->value;
    }

    return axis;
}

void JoyPs4Input::joyOpen(const char* interface)
{
    js = open(interface, O_RDONLY | O_NONBLOCK);
}

void JoyPs4Input::joyClose()
{
    close(js);
}

void JoyPs4Input::joyInput()
{
    if (readEvent(js, &event) == 0)
    {
        switch (event.type)
        {
        case JS_EVENT_BUTTON:
            setCommand(js, &event);
            break;

        case JS_EVENT_AXIS:
            axis = axisState(&event, axes);
            setCommand(js, &event);
            break;

        default:
            break;
        }

        fflush(stdout);
    }
}

} // namespace UserCtrlUtil
} // namespace UserCtrl
