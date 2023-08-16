#include <sys/ioctl.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    struct winsize buf;
    ioctl(0, TIOCGWINSZ, &buf);
    printf("%d rows x %d cols \n", buf.ws_row, buf.ws_col);
    return 0;
}