#include <stdio.h>
#include <termios.h>
#include <term.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


#define BUF_SIZE 8

static struct termios oriTerm;
static struct termios newTerm;
static int setupTerm = false;

// Set up terminal for one-char-at-a-time reads
void SetupTerminal()
{
    if (setupTerm)
        return;
    
    tcgetattr(0, &oriTerm);
    newTerm = oriTerm;
    newTerm.c_lflag &= ~(ICANON|ECHO);
    newTerm.c_cc[VMIN] = 1;
    newTerm.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &newTerm);
    setupTerm = true;
}

// Restore terminal state as normal
void RestoreTerminal()
{
    if (!setupTerm)
        return;

    tcsetattr(0, TCSANOW, &oriTerm);
}

void PrintPrompt()
{
    printf("\n(press q to quit)$>");
    fflush(stdout);
}

int main(int argc, char *argv[])
{
    fd_set retfds, readfds;
    struct timeval tv;
    int retval;
    char key_pressed;
    char buf[BUF_SIZE] = {0,};

    PrintPrompt();

    SetupTerminal();

    /* Watch stdin (fd 0) to see when it has input. */
    FD_ZERO(&readfds);
    FD_SET(0, &readfds);

    while(1){


        /* Wait up to five seconds. */
        tv.tv_sec = 5;
        tv.tv_usec = 0;


        //readfds를 retfds로 옮기는 이유는 select를 통해서 readfds가 바뀔 수 있다.
        retfds = readfds;

        //열린 파일 디스크립터의 최대값 +1
        retval = select(1, &retfds, NULL, NULL, &tv);


        if (retval == -1) {
            perror("select()");
            break;
        }
        else if (retval) {
            //printf("Data is available now.\n");  // i.e. doStuff()
            /* FD_ISSET(0, &rfds) will be true. */

            //한줄 처리를 위해서 fgets를 사용
            //fgets(buf, sizeof(buf), stdin);
            //printf("\n$> %s\n", buf);

            key_pressed = getchar();
            printf("%c\n", key_pressed);

            if (key_pressed == 'q')
                break;
            else {
                PrintPrompt();
            }
        }
        else {
            printf(" <No data within five seconds.> "); // i.e. key not pressed
            PrintPrompt();
        }
    }

    RestoreTerminal();

    return 0;
}
