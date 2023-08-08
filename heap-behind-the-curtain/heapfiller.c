// Reserving infinite dynamic memory aka Filling heap

// allocation does not happen util you use the memory by writing something on it without memset function 
// you will a large ammount of memory allocation out of memory range in system.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MB 1024 * 1024

int main()
{
    char *ptr = NULL;
    int ctr = 0;

    while (1)
    {
        ptr = (char *)malloc(MB);
        // memset(ptr, '\0', MB);   // intializing memory with null byte
        printf("Currently allocating %d MB\n", ++ctr);
    }
    exit(0);
}