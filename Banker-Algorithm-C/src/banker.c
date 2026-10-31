#include <stdio.h>
#include "banker.h"

int available[R] = {3, 3, 2};

int allocation[P][R] = {
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}
};

int maximum[P][R] = {
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3}
};

int need[P][R];

void calculateNeed()
{
    for (int i = 0; i < P; i++)
    {
        for (int j = 0; j < R; j++)
        {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}

int isSafe(int safeSequence[])
{
    int work[R];
    int finish[P] = {0};

    for (int i = 0; i < R; i++)
        work[i] = available[i];

    int count = 0;

    while (count < P)
    {
        int found = 0;

        for (int i = 0; i < P; i++)
        {
            if (!finish[i])
            {
                int canExecute = 1;

                for (int j = 0; j < R; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        canExecute = 0;
                        break;
                    }
                }

                if (canExecute)
                {
                    for (int j = 0; j < R; j++)
                        work[j] += allocation[i][j];

                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found)
            return 0;
    }

    return 1;
}

int requestResources(int process, int request[])
{
    if (process < 0 || process >= P)
        return 0;

    for (int j = 0; j < R; j++)
    {
        if (request[j] < 0 || request[j] > need[process][j])
            return 0;

        if (request[j] > available[j])
            return 0;
    }

    // Temporary allocation
    for (int j = 0; j < R; j++)
    {
        available[j] -= request[j];
        allocation[process][j] += request[j];
        need[process][j] -= request[j];
    }

    int sequence[P];

    if (isSafe(sequence))
        return 1;

    // Rollback
    for (int j = 0; j < R; j++)
    {
        available[j] += request[j];
        allocation[process][j] -= request[j];
        need[process][j] += request[j];
    }

    return 0;
}
