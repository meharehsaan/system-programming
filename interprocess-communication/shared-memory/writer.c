#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/stat.h>

int main()
{
    // ftok to generate unique key
    key_t key = ftok("f1.txt", 65);
    // shmget returns an identifier in shmid
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    // shmat to attach to shared memory
    char *buffer = (char *)shmat(shmid, NULL, 0);
    printf("Please enter a string to write on SM\n");
    fgets(buffer, 512, stdin);
    printf("\nData has been written in shared memory\n");
    // detach from shared memory
    shmdt(buffer);
    return 0;
}