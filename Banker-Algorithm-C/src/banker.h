#ifndef BANKER_H
#define BANKER_H

#define P 5
#define R 3

extern int available[R];
extern int maximum[P][R];
extern int allocation[P][R];
extern int need[P][R];

void calculateNeed();
int isSafe(int safeSequence[]);
int requestResources(int process, int request[]);

#endif
