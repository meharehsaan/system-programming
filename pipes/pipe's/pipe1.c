#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 25
int main()
{
   const char *msg = "Hello, Pipes!\n";
   char buf[SIZE];
   memset(buf, '\0', SIZE);
   int fd[2];
   int rv = pipe(fd);
   if (rv == -1)
   {
      printf("\n Pipe failed");
      exit(1);
   }

   int cw = write(fd[1], msg, strlen(msg));
   int cr = read(fd[0], buf, cw);
   write(1, buf, cr);
   return (0);
}
