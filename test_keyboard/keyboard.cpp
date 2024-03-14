//* Related Headers ----------------------------------------------------------*/
#include "keyboard.h"

//* C/C++ System Headers -----------------------------------------------------*/
#include <cmath>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <termios.h>
#include <string.h>
#include <unistd.h>

//* Other Lib Headers --------------------------------------------------------*/
//* Project Headers ----------------------------------------------------------*/

//* System-Specific Headers --------------------------------------------------*/

namespace dt
{

Keyboard::Keyboard() 
{
    memset(m_keys, 0, sizeof(m_keys));
    memset(m_keysWas, 0, sizeof(m_keysWas));
}
    
Keyboard::~Keyboard() {}
    
int Keyboard::KeyPressed(uint8_t key)
{
    return static_cast<int>(m_keys[key]);
}

// Set up terminal for one-char-at-a-time reads
void Keyboard::SetupTerminal()
{
    if (m_setupTerm)
        return;
    
    tcgetattr(0, &m_oriTerm);
    m_newTerm = m_oriTerm;
    m_newTerm.c_lflag &= ~(ICANON|ECHO);
    m_newTerm.c_cc[VMIN] = 1;
    m_newTerm.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &m_newTerm);
    m_setupTerm = true;
}

// Restore terminal state as normal
void Keyboard::RestoreTerminal()
{
    if (!m_setupTerm)
        return;

    tcsetattr(0, TCSANOW, &m_oriTerm);
}

int Keyboard::KeyWasPressed(uint8_t key)
{
    if (!m_keys[key] && m_keysWas[key])
    {
        return 1;
    }
    return 0;
}

int Keyboard::ReadRawData()
{
    memcpy(m_keysWas, m_keys, sizeof(m_keys));
    memset(m_keys, 0, sizeof(m_keys));

    struct termios oriTerm;
    struct termios newTerm;

    // Set up terminal for one-char-at-a-time reads
    tcgetattr(0, &oriTerm);
    newTerm = oriTerm;
    newTerm.c_lflag &= ~(ICANON|ECHO);
    newTerm.c_cc[VMIN] = 1;
    newTerm.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &newTerm);

    // Get pressed keys
    fd_set fds;
    struct timeval tv;
    char key_pressed;
    int ret;
    int read_bytes = 0;

    do {
        FD_ZERO(&fds);
        FD_SET(0, &fds);
        tv.tv_sec = 0;
        tv.tv_usec = 0;

        ret = select(1, &fds, NULL, NULL, &tv);

        if (ret > 0) {
            key_pressed = getchar();
            if (key_pressed > 0 && key_pressed < 256)
            m_keys[key_pressed] = 1;
            read_bytes += ret;
        }
        else {
            break;
        }
    } while (true);

    // Restore terminal state as normal
    tcsetattr(0, TCSANOW, &oriTerm);

    if (ret < 0)
        return ret;
    else
        return read_bytes;
}

} // namespace dt