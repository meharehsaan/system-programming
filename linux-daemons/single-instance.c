#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main()
{
    // Open a lock file (you can choose any filename you like)
    int fd = open("f1.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Try to acquire an exclusive lock on the file
    struct flock fl;
    fl.l_type = F_WRLCK;

    int ret = fcntl(fd, F_SETLK, &fl);
    if (ret == -1)
    {
        fprintf(stderr, "Another instance is already running.\n");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Main process logic goes here
    while (1)
    {
        printf("hello mehar\n");
        sleep(1);
    }

    // Release the lock and close the file
    fl.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &fl) == -1)
    {
        perror("fcntl unlock");
    }

    close(fd);

    return 0;
}
