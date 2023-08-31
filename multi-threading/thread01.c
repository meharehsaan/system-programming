#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

/* create two child threads and wait for their termination */

void *f1(void *);
void *f2(void *);

int main()
{
    pthread_t tid1, tid2;

    pthread_create(&tid1, NULL, f1, NULL);
    pthread_create(&tid2, NULL, f2, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("\nBye Bye from main thread\n");
    return 0;
}

void *f1(void *arg)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%s", "Mehar");
        fflush(stdout);
        sleep(1);
    }
    pthread_exit(NULL);
}

void *f2(void *arg)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%s", "Ehsaan");
        fflush(stdout);
        sleep(1);
    }
    return NULL;
}
