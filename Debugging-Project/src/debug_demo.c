#include <stdio.h>
#include <stdlib.h>

void segmentation_fault() {
    int *ptr = NULL;

    printf("Attempting to access NULL pointer...\n");

    *ptr = 100;   // SEGMENTATION FAULT
}

void memory_bug() {
    int *arr = malloc(5 * sizeof(int));

    printf("Writing beyond allocated memory...\n");

    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;   // MEMORY BUG: arr[5] is out of bounds
    }

    free(arr);
}

int main() {
    printf("=== OSSP Debugging Demonstration ===\n");

    printf("\n[1] Testing Segmentation Fault\n");
   // segmentation_fault();

    printf("\n[2] Testing Memory Bug\n");
    memory_bug();

    return 0;
}
