#include <stdio.h>

int main() {
    int *ptr = NULL;

    printf("Program started\n");

    *ptr = 100;

    printf("Value: %d\n", *ptr);

    return 0;
}
