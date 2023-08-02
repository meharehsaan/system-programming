#include <stdio.h>
#include <stdlib.h>

void cleanupFunction1() {
    printf("Cleanup Function 1\n");
}

void cleanupFunction2() {
    printf("Cleanup Function 2\n");
}

int main() {
    atexit(cleanupFunction1); // Register cleanupFunction1
    atexit(cleanupFunction2); // Register cleanupFunction2

    printf("Main Function\n");

    return 0;    // calls the exit handler in reverse
}
