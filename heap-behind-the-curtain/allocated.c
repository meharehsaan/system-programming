// ***When a process requests 1-24 B on heap, why the memory allocated is 32 B?***

// ***When a process requests 25-40 B on heap, why the memory allocated is 48 B?***

// ***When a process requests 41-56 B on heap, why the memory allocated is 64 B?***

// ***When a process requests 57-72 B on heap, why the memory allocated is 80 B?***


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int size = atoi(argv[1]);
    char *a = (char *)malloc(size);
    char *b = (char *)malloc(size);
    char *c = (char *)malloc(size);
    char *d = (char *)malloc(size);
    printf("a = %p\nb = %p\nc = %p\nd = %p\n", a, b, c, d);
}