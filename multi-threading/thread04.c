#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

/* Threads using struct to pass more than one arguments to function f1() */

struct mystruct
{
    char character;
    int count;
};

void *f1(void *);

int main()
{
    pthread_t tid1, tid2;
    struct mystruct t1_args;
    struct mystruct t2_args;

    // create a child thread to print 1000 Xs
    t1_args.character = 'X';
    t1_args.count = 1000;
    pthread_create(&tid1, NULL, f1, (void *)&t1_args);

    // create a child thread to print 800 Os
    t2_args.character = 'O';
    t2_args.count = 800;
    pthread_create(&tid2, NULL, f1, (void *)&t2_args);

    // wait for the child threads to terminate
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("\nBye Bye from main thread.\n");
    return 0;
}

void *f1(void *args)
{
    struct mystruct p = *(struct mystruct *)args;
    for (int i = 0; i < p.count; i++)
        putc(p.character, stdout);
    pthread_exit(NULL);
}