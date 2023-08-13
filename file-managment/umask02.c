#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int n;
    char buff[10] = "Mehar Ehsaan";
    umask(00); // using function
    int fd = open("myfile.txt", O_CREAT | O_RDWR, 0633); // file opened in write mode
    if (fd == -1)
    {
        printf("Error in creating file\n");
        exit(1);
    }
    if (write(fd, buff, 10) < 0)
    {
        printf("Error in writing file\n");
        exit(1);
    };
    close(fd);
    return 0;
}