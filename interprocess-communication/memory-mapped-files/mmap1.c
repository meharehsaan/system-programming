#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

// create f1.txt and write a string in it to make program work correctly

int main(int argc, char *argv[])
{
   // open a file
   int fd = open("f1.txt", O_RDONLY);
   // get size of the file
   int fsize = lseek(fd, 0, SEEK_END);
   // memory map the file
   char *filedata = mmap(NULL, fsize, PROT_READ, MAP_PRIVATE, fd, 0);
   printf("Data in the file is:\n%s", filedata);
   // Need to free the mapped memory
   munmap(filedata, fsize);
   // munmap does not close the file discriptor, so we need to do that
   close(fd);
   return 0;
}
