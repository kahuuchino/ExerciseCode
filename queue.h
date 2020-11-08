#include <stdio.h>
#include <stdlib.h>

#ifndef _Queue_H

struct QueueRecord;
typedef struct QueueRecord *Queue;

typedef int ElementType;

#define MinQueueSize 5

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void EnQueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void DeQueue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

#endif