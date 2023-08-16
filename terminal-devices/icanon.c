#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// By default terminal is in canonical mode

int main()
{
    int ch;
    system("stty -icanon"); // going in non-canonical mode
    while ((ch = getchar()) != EOF){
        putchar(ch);
    }
} 