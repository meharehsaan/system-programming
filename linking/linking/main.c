#include <stdio.h>

void change(); // undefined external symbol function
int num = 10;  // global defined symbol in text section
char *str = "Hy";      // undefined str symbol in bss section

int main()
{
    change(); // calling function
    printf("%d\n", num);
    printf("%s\n", str);
}