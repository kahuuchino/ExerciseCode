#include "stack.h"

struct Node
{
    ElementType Element;
    PtrToNode Next;
};


int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

Stack CreateStack(void)
{
    Stack S;
    S = malloc(sizeof(struct Node));

    S->Next = NULL;
    MakeEmpty(S);

    return S;
}

void DisposeStack(Stack S)
{
    if(!IsEmpty(S))
    {
        PtrToNode Cell;
        while(S->Next != NULL)
        {
            Cell = S->Next;
            S->Next = S->Next->Next;
            free(Cell);
        }
        free(S);
    }
    else
        printf("Empty Stack!");
}

void MakeEmpty(Stack S)
{
    if(S == NULL)
        printf("Not init stack!");
    else
        while(!IsEmpty(S))
            Pop(S);
}

ElementType Top(Stack S)
{
    if(!IsEmpty(S))
        return S->Next->Element;
    printf("Empty stack!");
    return 0;
}

void Pop(Stack S)
{
    PtrToNode FirstCell;

    if(IsEmpty(S))
        printf("Empty stack!");
    else
    {
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        free(FirstCell);
    }
}

/*

+-----+
|  1  |  <--S(Header,empty node)
+-----+
   ↓
+-----+
|  2  |  <--TmpCell(Push element)
+-----+
   ↓
+-----+
|  3  |  <--S->Next(Origin top)
+-----+

*/
void Push(ElementType X, Stack S)
{
    PtrToNode TmpCell;

    TmpCell = malloc(sizeof(struct Node));
    if(TmpCell == NULL)
        printf("Out of space!");
    else
    {
        TmpCell->Element = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

int main(void)
{
    Stack S;
    S = CreateStack();
    Push(10, S);
    Push(20, S);
    Push(30, S);
    printf("%d\n", Top(S));
    Pop(S);
    printf("%d\n", Top(S));
    DisposeStack(S);
    return 0;
}