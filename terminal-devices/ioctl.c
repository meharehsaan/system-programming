#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
int main(int argc, char *argv[])
{
    char passwd[50];
    struct termios info;
    printf("Password:");

    ioctl(0, TCGETS, &info);
    struct termios save = info;

    info.c_lflag &= ~ECHO;
    ioctl(0, TCSETS, &info);
    fgets(passwd, 50, stdin);

    char *q;
    q = strchr(passwd, '\n');
    *q = '\0';
    ioctl(0, TCSETS, &save);

    int rv = strcmp(passwd, "mypass");
    if (rv == 0)
        printf("\nThe password is correct\n");
        
    else
        printf("\nThe password is incorrect\n");

    return 0;
}