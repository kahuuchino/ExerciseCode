#include "list.h"

struct Node
{
    ElementType Element;
    Position Next;
};

List MakeEmpty(List L)
{
    L->Next = NULL;
    return L;
}

int IsEmpty(List L)
{
    return L->Next == NULL;
}

int IsLast(Position P, List L)
{
    return P->Next == NULL;
}

Position Find(ElementType X, List L)
{
    Position P;
    P = L->Next;
    while (P != NULL && P->Element != X)
    {
        P = P->Next;
    }
    return P;
}

void Delete(ElementType X, List L)
{
    Position P, TmpCell;

    P = FindPrevious(X, L);

    if(!IsLast(P, L))
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

Position FindPrevious(ElementType X, List L)
{
    Position P;

    P = L;

    while (P->Next != NULL && P->Next->Element != X)
    {
        P = P->Next;
    }
    return P;
}

void Insert(ElementType X, List L, Position P)
{
    Position TmpCell;

    TmpCell = malloc(sizeof(struct Node));
    if(TmpCell == NULL)
        printf("Out of space!");
        //FatalError("Out of space!");

    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

void Append(ElementType X, List L)
{
    Position P, TmpCell;

    TmpCell = malloc(sizeof(struct Node));
    if(TmpCell == NULL)
        printf("Out of space!");

    TmpCell->Element = X;

    if(L->Next == NULL)
    {
        L->Next = TmpCell;
        TmpCell->Next = NULL;
    }
    else
    {
        P = L->Next;
        while(P->Next != NULL)
        {
            P = P->Next;
        }
        P->Next = TmpCell;
        TmpCell->Next = NULL;
    }
}

void DeleteList(List L)
{
    Position P, TmpCell;

    P = L->Next;
    L->Next = NULL;

    while(P->Next != NULL)
    {
        TmpCell = P->Next;
        free(P);
        P = TmpCell;
    }
}

Position Header(List L)
{
    return L;
}

Position First(List L)
{
    return L->Next;
}

Position Advance(Position P)
{
    return P->Next;
}

ElementType Retrieve(Position P)
{
    return P->Element;
}

void DisplyNode(List L)
{
    Position P;
    P = L->Next;
    int j = 1;
    while (P->Next != NULL)  //若不是表尾，则循环打印节点的数值
    {
        printf("%5d%10d\n", j, P->Element);//打印第j个节点数据
        P = P->Next;  //让p指向下一个节点
        j++; 
    }
}

int main(void)
{
    List L;
    L = malloc(sizeof(struct Node));
    L->Next = NULL;
    Insert(10, L, L);
    Insert(20, L, Find(10, L));
    Append(30, L);
    Append(0, L);
    DisplyNode(L);
    Delete(20, L);
    DisplyNode(L); 
    Append(20, L);
    DisplyNode(L);
    Insert(40, L, Find(30, L));
    DisplyNode(L);
    return 0;
}
