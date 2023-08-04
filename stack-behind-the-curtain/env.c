/* Environmental variables */

#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main()
{
    int num = 42;
    int *ptr = num;
    int *ptr1 = 37;
    char *historysize = getenv("HISTSIZE");

    printf("Pointer address: %p\n", (void *)ptr);
    printf("Pointer address: %p\n", &num);
    printf("Pointer address: %d\n", ptr1);

    putenv("HISTSIZE=537");           // puts 537 value in this variable
    historysize = getenv("HISTSIZE"); // to get env variable value
    printf("Changed value of HISTSIZE after getenv: %s\n", historysize);

    setenv("HISTSIZE", "454", 1); // sets the env variable value
    historysize = getenv("HISTSIZE");
    printf("Changed value of HISTSIZE after setenv: %s\n", historysize);

    // prints all the env variables
    printf("\n Environment variable passed are:\n");
    for (int i = 0; environ[i] != NULL; i++)
        printf("environ[%d]:%s\n", i, environ[i]);

    return 0;
}
