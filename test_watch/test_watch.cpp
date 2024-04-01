/*
 * test gdb watch memory (H/W breakpoint)
 * for testing, use gdb command sequence below.


> gdb test_watch
Reading symbols from bin/test_watch...
(gdb) list main
1       #include <stdio.h>
2       int count = 0;
3       int main(int argc, char **argv)
4       {
5           char  buf[8];
6           if( argc > 1 )
7           {
8               int    x = 1;
9               printf("before [%d]\n", x);
10              char * s = argv[1];
(gdb) break 10
Breakpoint 1 at 0x1186: file /home/sean/Projects/test_ws/playgroud/test_watch/test_watch.cpp, line 10.
(gdb) run 1234567890
Starting program: /home/sean/Projects/test_ws/playgroud/bin/test_watch 1234567890
before [1]

Breakpoint 1, main (argc=2, argv=0x7fffffffd998) at /home/sean/Projects/test_ws/playgroud/test_watch/test_watch.cpp:10
10              char * s = argv[1];
(gdb) watch *(int*)&x
Hardware watchpoint 2: *(int*)&x
(gdb) cont
Continuing.

Hardware watchpoint 2: *(int*)&x

Old value = 1
New value = 57
main (argc=2, argv=0x7fffffffd998) at /home/sean/Projects/test_ws/playgroud/test_watch/test_watch.cpp:12
12              while(*s != '\0')
(gdb) list
7           {
8               int    x = 1;
9               printf("before [%d]\n", x);
10              char * s = argv[1];
11              char * d = buf;
12              while(*s != '\0')
13              {
14                  ++count;
15                  *d++ = *s++;
16              }
(gdb)

 */


#include <stdio.h>
int count = 0;
int main(int argc, char **argv)
{
    char  buf[8];
    if( argc > 1 )
    {
        int    x = 1;
        printf("before [%d]\n", x);
        char * s = argv[1];
        char * d = buf;
        while(*s != '\0')
        {
            ++count;
            *d++ = *s++;
        }
        printf("after [%d]\n", x);
    }
    return 0;
}