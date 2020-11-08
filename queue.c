#include "queue.h"

struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};

int IsEmpty(Queue Q)
{
    return Q->Size == 0;
}

int IsFull(Queue Q)
{
    return Q->Size == Q->Capacity;
}

Queue CreateQueue(int MaxElements)
{
    Queue Q;

    if(MaxElements < MinQueueSize)
        printf("Queue size is too small!");

    Q = malloc(sizeof(struct QueueRecord));
    if(Q == NULL)
        printf("Out of space!");

    Q->Array = malloc(sizeof(ElementType) * MaxElements);
    if(Q == NULL)
        printf("Out of space!");
    Q->Capacity = MaxElements;
    MakeEmpty(Q);

    return Q;
}

void DisposeQueue(Queue Q)
{
    if(Q != NULL)
    {
        free(Q->Array);
        free(Q);
    }
}

void MakeEmpty(Queue Q)
{
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

static int Succ(int value, Queue Q)
{
    if(++value == Q->Capacity)
        value = 0;
    return value;
}

void EnQueue(ElementType X, Queue Q)
{
    if(IsFull(Q))
        printf("Full Queue");
    else
    {
        Q->Size++;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}

ElementType Front(Queue Q)
{
    if(IsEmpty(Q))
    {
        printf("Empty Queue");
        return 0;
    }
    else
        return Q->Array[Q->Front];
}

void DeQueue(Queue Q)
{
    if(IsEmpty(Q))
        printf("Empty Queue");
    else
    {
        Q->Size--;
        Q->Front = Succ(Q->Front, Q);
    }
}

ElementType FrontAndDequeue(Queue Q)
{
    ElementType front;
    if(IsEmpty(Q))
    {
        printf("Empty Queue");
        return 0;
    }
    else
    {
        front = Q->Array[Q->Front];
        Q->Size--;
        Q->Front = Succ(Q->Front, Q);
        return front;
    }
}

int main(void)
{
    Queue Q = CreateQueue(5);
    EnQueue(10, Q);
    EnQueue(20, Q);
    EnQueue(30, Q);
    EnQueue(40, Q);
    printf("%d\n", Front(Q));
    DeQueue(Q);
    printf("%d\n", Front(Q));
    printf("%d\n", FrontAndDequeue(Q));
    printf("%d\n", Front(Q));
}
