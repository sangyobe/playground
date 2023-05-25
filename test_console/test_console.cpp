#include <stdio.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_BGCOLOR_RED "\x1b[41m"
#define ANSI_BGCOLOR_GREEN "\x1b[42m"
#define ANSI_BGCOLOR_YELLOW "\x1b[43m"
#define ANSI_BGCOLOR_BLUE "\x1b[44m"
#define ANSI_BGCOLOR_MAGENTA "\x1b[45m"
#define ANSI_BGCOLOR_CYAN "\x1b[46m"

int main() {
  printf(ANSI_COLOR_RED "This text is RED!" ANSI_COLOR_RESET "\n");
  printf(ANSI_COLOR_GREEN "This text is GREEN!" ANSI_COLOR_RESET "\n");
  printf(ANSI_COLOR_YELLOW "This text is YELLOW!" ANSI_COLOR_RESET "\n");
  printf(ANSI_COLOR_BLUE "This text is BLUE!" ANSI_COLOR_RESET "\n");
  printf(ANSI_COLOR_MAGENTA "This text is MAGENTA!" ANSI_COLOR_RESET "\n");
  printf(ANSI_COLOR_CYAN "This text is CYAN!" ANSI_COLOR_RESET "\n");
  printf(ANSI_BGCOLOR_RED "This background color is RED!" ANSI_COLOR_RESET
                          "\n");
  printf(ANSI_BGCOLOR_GREEN "This background color is GREEN!" ANSI_COLOR_RESET
                            "\n");
  printf(ANSI_BGCOLOR_YELLOW "This background color is YELLOW!" ANSI_COLOR_RESET
                             "\n");
  printf(ANSI_BGCOLOR_BLUE "This background color is BLUE!" ANSI_COLOR_RESET
                           "\n");
  printf(ANSI_BGCOLOR_MAGENTA
         "This background color is MAGENTA!" ANSI_COLOR_RESET "\n");
  printf(ANSI_BGCOLOR_CYAN "This background color is CYAN!" ANSI_COLOR_RESET
                           "\n");
  return 0;
}