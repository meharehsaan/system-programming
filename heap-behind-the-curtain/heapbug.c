// While checking with splint it will give warning 
// splint heapbug.c

// gcc heapbug.c -lefence
// ./a.out

// unlimit -c unlimited
// ./a.out to see the core file 
// gdb a.out core


#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
extern int errno;
int main()
{
    char *arr = (char *)malloc(sizeof(char) * 10);
    if (arr == NULL)
    {
        perror("Malloc failed:");
        exit(errno);
    }
    arr[0] = 'H';
    arr[1] = 'e';
    arr[2] = 'l';
    arr[3] = 'o';
    arr[4] = '\0';
    printf("%s\n", arr);
    free(arr);
    arr[0] = 'b';    // after freeing memoring we are exessing it bug in program 
    return 0;
}