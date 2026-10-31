#include <stdio.h>
#include <stdlib.h>

int main() {
    int *data = malloc(5 * sizeof(int));

    if (data == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        data[i] = (i + 1) * 10;
    }

    printf("Allocated values:\n");

    for (int i = 0; i < 5; i++) {
        printf("%d ", data[i]);
    }

    printf("\n");

    // BUG: memory allocated using malloc is never freed

    return 0;
}
