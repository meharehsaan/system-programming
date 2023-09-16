#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

void *f1(void *);
void *f2(void *);
void *f3(void *);
sem_t semA, semB;

int main()
{
   pthread_t t1, t2, t3;
   sem_init(&semA, 0, 0);
   sem_init(&semB, 0, 0);
   pthread_create(&t1, NULL, f1, NULL);
   pthread_create(&t2, NULL, f2, NULL);
   pthread_create(&t3, NULL, f3, NULL);
   pthread_join(t1, NULL);
   pthread_join(t2, NULL);
   pthread_join(t3, NULL);
   printf("\n");
   return 0;
}

void *f1(void *parm)
{
   sem_wait(&semB);
   printf(" Arif Butt");
}

void *f2(void *parm)
{
   sem_wait(&semA);
   printf(" fun with");
   sem_post(&semB);
}

void *f3(void *parm)
{
   printf(" Learning is");
   sem_post(&semA);
}
