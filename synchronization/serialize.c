#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// gcc serialize.c -lpthread -D_REENTRANT

void *f1(void *arg);

int main()
{
    pthread_t t1, t2, t3;
    char *msg1 = "Learning linux";
    char *msg2 = "is fun";
    char *msg3 = "but needs consistancy";
    pthread_create(&t1, NULL, f1, (void *)msg1);
    pthread_create(&t2, NULL, f1, (void *)msg2);
    pthread_create(&t3, NULL, f1, (void *)msg3);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    printf("\n\n");
    return 0;
}

void *f1(void *arg)
{
    char *msg = (char *)arg;
    printf("%s", msg);
    pthread_exit(NULL);
}