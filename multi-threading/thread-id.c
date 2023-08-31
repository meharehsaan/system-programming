#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>

/* Displaying the thread IDs using getpid(), gettid(), and pthread_self() */

void *f1(void *);

int main()
{
    char *msg[] = {"Thread 01", "Thread 02", "Thread 03"};
    pthread_t tids[3];

    for (int i = 0; i < 3; i++)
    {
        pthread_create(&tids[i], NULL, f1, (void *)msg[i]);
        pthread_join(tids[i], NULL);
    }

    return 0;
}

void *f1(void *arg)
{
    printf("PID of %s using getpid(): %ld\n", (char *)arg, (long)getpid());
    printf("TID of %s using gettid():%ld\n", (char *)arg, (long)syscall(SYS_gettid));
    printf("TID of %s using pthread_self():%ld\n\n", (char *)arg, (long)pthread_self());
    pthread_exit(NULL);
}