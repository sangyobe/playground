/*
\file       keyboard.h
\brief      keyboard event handler
\author     Sangyup Yi, sean.yi@hyundai.com
\author
\date       2024. 03. 06
\version    0.0.1
*/

#ifndef SYSTEM_DEVICE_KEYBOARD_H_
#define SYSTEM_DEVICE_KEYBOARD_H_

//* C/C++ System Headers -----------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>
#include <termios.h>

//* Other Lib Headers --------------------------------------------------------*/
//* Project Headers ----------------------------------------------------------*/
//* System-Specific Headers --------------------------------------------------*/

namespace dt
{
//* Public(Exported) Macro ---------------------------------------------------*/
#define KB_KEY_A 0  //

//* Public(Exported) Types ---------------------------------------------------*/

class Keyboard
{
public:
    Keyboard();
    ~Keyboard();

public:
    // set-up & restore terminal settings
    void SetupTerminal();
    void RestoreTerminal();

    // key pressed state accessor
    int KeyPressed(uint8_t key); //<! 0: key is not pressed, 1: key is pressed 
    int KeyWasPressed(uint8_t key); //<! 0: key was not pressed, 1: key was pressed

public:
    int ReadRawData();

private:
    uint8_t m_keys[256];    // recent key pressed state
    uint8_t m_keysWas[256]; // previous key pressed state


    struct termios m_oriTerm;
    struct termios m_newTerm;
    int m_setupTerm{0};
};

} // namespace dt

#endif // SYSTEM_DEVICE_KEYBOARD_H_
