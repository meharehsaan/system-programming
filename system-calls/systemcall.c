#include <unistd.h>
#include <fcntl.h>

int main()
{
    // file discriptor
    int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1)
    {
        // Error handling for file open failure
        perror("Error opening file");
        return 1;
    }

    const char *message = "Hello, Mehar!\n";
    // ssize_t => signed integer data type
    ssize_t bytes_written = write(fd, message, strlen(message));
    close(fd);

    if (bytes_written == -1)
    {
        // Error handling for write failure in file
        perror("Error writing to file");
        return 1;
    }

    return 0;
}
