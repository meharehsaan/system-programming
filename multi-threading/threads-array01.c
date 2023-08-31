#include <sys/types.h>
#include <linux/unistd.h>
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* The main() creates an array of 5 threads Pass a message to each thread and
the thread function displays it */

void *f1(void *arg);
int main(int argc, char *argv[])
{
    char *msg[] = {"Thread 01", "Thread 02", "Thread 03", "Thread 04", "Thread 05"};
    pthread_t tids[5];
    
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&tids[i], NULL, f1, (void *)msg[i]);
        pthread_join(tids[i], NULL);
    }

    printf("Reporting that all child threads have terminated\n");
    exit(0);
}

void *f1(void *arg)
{
    printf("I am child %s\n", (char *)arg);
    pthread_exit(NULL);
}