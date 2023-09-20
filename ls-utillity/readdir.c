#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>

extern int errno;

int main(int argc, char const *argv[])
{
    DIR *dp = opendir("/home");
    chdir("/home");
    errno = 0;
    struct dirent *ent;

    while (1)
    {
        ent = readdir(dp);
        if (errno != 0 && ent == NULL)
        {
            printf("Something went wrong");
            return errno;
        }
        if (ent == NULL && errno == 0)
        {
            printf("\nTraversed whole directory");
            return 0;
        }

        printf("%s\t", ent->d_name);
    }
    closedir(dp);
    return 0;
}
