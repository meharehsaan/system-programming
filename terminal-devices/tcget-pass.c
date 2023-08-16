#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char passwd[50];
    printf("Password:");
    struct termios info;
    tcgetattr(0, &info);
    struct termios save = info;

    // make the echo bit off and set attributes
    info.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &info);

    // get password from user
    fgets(passwd, 50, stdin);

    char *q;
    q = strchr(passwd, '\n');
    *q = '\0';
    // now set the attributes back to original
    tcsetattr(0, TCSANOW, &save);

    // compare password and print appropriate message
    int rv = strcmp(passwd, "password");
    if (rv == 0)
        printf("\nThe password is correct\n");
    else
        printf("\nThe password is incorrect\n");
    return 0;
}