#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
#include <sys/ioctl.h>

int main()
{
    struct termios info;
    int rv = ioctl(0, TCGETS, &info); // read values from driver

    if (rv == -1)
    {
        perror("ioctl");
        exit(1);
    }

    int ch;
    if (info.c_lflag & ICANON)
    {
        printf("Terminal driver is in canonical mode\n");
        while ((ch = getchar()) != EOF)
        {
            putchar(ch);
        }
    }
    else
    {
        printf("Terminal driver is in non-canonical mode\n");
        while ((ch = getchar()) != EOF)
        {
            putchar(ch);
        }
    }
    return 0;
}