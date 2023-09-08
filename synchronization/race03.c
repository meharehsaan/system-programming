#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

long balance = 0; // global variable
void *inc(void *arg);
void *dec(void *arg);

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

int main()
{
    pthread_t t1, t2;
    pthread_create(&t1, NULL, inc, NULL);
    pthread_create(&t2, NULL, dec, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Value of balance is :%ld\n", balance);
    return 0;
}

void *inc(void *arg)
{
    for (long i = 0; i < 100000000; i++)
    {
        pthread_mutex_lock(&mut);
        balance++;
        pthread_mutex_unlock(&mut);
    }
    pthread_exit(NULL);
}
void *dec(void *arg)
{
    for (long j = 0; j < 100000000; j++)
    {
        pthread_mutex_lock(&mut);
        balance--;
        pthread_mutex_unlock(&mut);
    }
    pthread_exit(NULL);
}