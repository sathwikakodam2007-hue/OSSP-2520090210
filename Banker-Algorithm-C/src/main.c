#include <stdio.h>
#include "banker.h"

void displayState()
{
    printf("\nAVAILABLE RESOURCES\n");

    for (int j = 0; j < R; j++)
        printf("%d ", available[j]);

    printf("\n\nALLOCATION MATRIX\n");

    for (int i = 0; i < P; i++)
    {
        for (int j = 0; j < R; j++)
            printf("%d ", allocation[i][j]);

        printf("\n");
    }

    printf("\nMAXIMUM MATRIX\n");

    for (int i = 0; i < P; i++)
    {
        for (int j = 0; j < R; j++)
            printf("%d ", maximum[i][j]);

        printf("\n");
    }

    printf("\nNEED MATRIX\n");

    for (int i = 0; i < P; i++)
    {
        for (int j = 0; j < R; j++)
            printf("%d ", need[i][j]);

        printf("\n");
    }
}

int main()
{
    calculateNeed();

    int sequence[P];

    printf("====================================\n");
    printf(" SMART RESOURCE ALLOCATION SYSTEM\n");
    printf(" BANKER'S ALGORITHM\n");
    printf("====================================\n");

    if (isSafe(sequence))
    {
        printf("\nSYSTEM IS SAFE\n");
        printf("Safe Sequence: ");

        for (int i = 0; i < P; i++)
            printf("P%d ", sequence[i]);
    }
    else
    {
        printf("\nSYSTEM IS UNSAFE\n");
    }

    displayState();

    int choice;

    while (1)
    {
        printf("\n\n1. Request Resources");
        printf("\n2. Display System State");
        printf("\n3. Check Safe Sequence");
        printf("\n4. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int process;
            int request[R];

            printf("Enter process number (0-4): ");
            scanf("%d", &process);

            printf("Enter request for A B C: ");

            for (int j = 0; j < R; j++)
                scanf("%d", &request[j]);

            if (requestResources(process, request))
                printf("\nREQUEST GRANTED - System remains SAFE\n");
            else
                printf("\nREQUEST DENIED - Invalid or unsafe request\n");

            displayState();
        }
        else if (choice == 2)
        {
            displayState();
        }
        else if (choice == 3)
        {
            if (isSafe(sequence))
            {
                printf("\nSAFE SEQUENCE: ");

                for (int i = 0; i < P; i++)
                    printf("P%d ", sequence[i]);
            }
            else
            {
                printf("\nSYSTEM IS UNSAFE\n");
            }
        }
        else if (choice == 4)
        {
            printf("\nExiting project...\n");
            break;
        }
        else
        {
            printf("\nInvalid choice!\n");
        }
    }

    return 0;
}
