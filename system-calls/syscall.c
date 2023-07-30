/* Using write system call in C to print  */

#include <unistd.h>
#include <sys/syscall.h>

int main(){
    char str[] = {"A system call using c without any library wrapper\n"};
    int len = sizeof str;

    //syscall(syscall_number, file_discripter, message, message_length)
    int rv = syscall(1, 1, str, len);
    int rt = myfunction();
    return rv, rt;
}
    
int myfunction(){
    char str1[] = {"I am also a system call\n"};
    int len1 = sizeof str1;

    //passing SYS_write name to syscall instead of write call number (1)
    int rt = syscall(SYS_write, 1, str1, len1);
    return rt;
}