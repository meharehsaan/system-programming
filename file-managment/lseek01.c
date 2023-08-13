#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// see the holes using od -s f1.txt after execution.

int main(int argc, char const *argv[])
{
    int fd = open("f1.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    lseek(fd, 18, SEEK_CUR);
    write(fd, "Mehar Ehsaans file " ,19);
    close(fd);
    return 0;
}
