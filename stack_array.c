#include "stack.h"

struct Node
{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};

int IsEmpty(Stack S)
{
    return S->TopOfStack == EmptyTOS;
}

int IsFull(Stack S)
{
    return S->TopOfStack == S->Capacity;
}

Stack CreateStack(int MaxElements)
{
    Stack S;

    if(MaxElements < MinStackSize)
        printf("Stack size is too small!");

    S = malloc(sizeof(struct Node));
    if(S == NULL)
        printf("Out of space!");

    S->Array = malloc(sizeof(ElementType) * MaxElements);
    if(S->Array == NULL)
        printf("Out of space!");
    S->Capacity = MaxElements;
    MakeEmpty(S);

    return S;   
}

void DisposeStack(Stack S)
{
    if(S != NULL)
    {
        free(S->Array);
        free(S);
    }
}
void MakeEmpty(Stack S)
{
    S->TopOfStack = EmptyTOS;
}

ElementType Top(Stack S)
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack];
    printf("Empty stack!");
    return 0;
}
void Pop(Stack S)
{
    if(IsEmpty(S))
        printf("Empty Stack");
    else
        S->TopOfStack--;
}

void Push(ElementType X, Stack S)
{
    if(IsFull(S))
        printf("Full Stack");
    else
        S->Array[++S->TopOfStack] = X;
}

ElementType TopAndPop(Stack S)
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack--];
    printf("Empty stack!");
    return 0;
}

int main(void)
{
    Stack S;
    S = CreateStack(5);
    Push(10, S);
    Push(20, S);
    Push(30, S);
    printf("%d\n", TopAndPop(S));
    Pop(S);
    Push(40, S);
    printf("%d\n", Top(S));
    DisposeStack(S);
    return 0;
}