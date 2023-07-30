/* System call using library call as a wrapper upon the call */

#include <unistd.h>

int main(){
    char str[] = {"A system call using library wrapper\n"};
    int len = sizeof str;
    return write(1, str, len);
}