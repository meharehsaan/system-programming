#include <stdio.h>
#include <stdlib.h>

// ps -x | grep ./a.out
// Us above command to find the process and kill then

int fork();
int getpid();
int getppid();

int main(int argc, char const *argv[])
{
    pid_t cpid = fork();
    if (cpid != 0)
    {
        printf("I am a parent process with pid = %d having ppid = %d\n", getpid(), getppid());
        exit(0);
    }
    else
    {
        printf("I am a child process with pid = %d having ppid = %d\n", getpid(), getppid());
        while (1)
        {
            printf("Yes i am process without parent\n");
        }
    }
    return 0;
}
