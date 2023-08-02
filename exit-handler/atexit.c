#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void bye(void)
{
    printf("That was all, folks\n");
}

int main(void)
{
    long a;
    int i;

    a = sysconf(_SC_ATEXIT_MAX);
    printf("ATEXIT_MAX = %ld\n", a);

    i = atexit(bye);   //returns zero if successfully executed
    if (i != 0)
    {
        fprintf(stderr, "cannot set exit function\n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
