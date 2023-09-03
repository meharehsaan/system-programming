#include <stdio.h>
#include <sys/fcntl.h>
#include <sys/resource.h>
#include <signal.h>
#include <stdlib.h>

// ps -x | grep ./a.out 
// Us above command to find the process and kill then

int main(int argc, char const *argv[])
{

    pid_t cpid = fork();
    if (cpid != 0)
    {
        exit(0);
    }

    // closing all file descriptors except std
    struct rlimit r;
    getrlimit(RLIMIT_NOFILE, &r);
    for (int fd = 3; fd < r.rlim_cur; fd++)
    {
        close(fd);
    }

    // Make std descriptors point to /dev/null
    int fd0 = open("/dev/null", O_RDWR);
    dup2(fd0, 0);
    dup2(fd0, 1);
    dup2(fd0, 2);
    close(fd0);

    // Make the daemon session leader
    setsid();

    // Set umask to 0 and its pwd to /
    umask(0);
    chdir("/");

    // Ignore the SIGHUP signal
    signal(SIGHUP, SIG_IGN);

    while (1)
    {
        printf("hello mehar");
        // sleep(1000);
    }

    return 0;
}
