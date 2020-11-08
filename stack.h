#include <stdio.h>
#include <stdlib.h>

//#define list 0

#define EmptyTOS -1
#define MinStackSize 5 

#ifndef _Stack_h

struct Node;
#ifdef list
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
#else
typedef struct Node *Stack;
#endif

typedef int ElementType;

int IsEmpty(Stack S);
int IsFull(Stack S);
#ifdef list
Stack CreateStack(void);
#else
Stack CreateStack(int MaxElemens);
#endif
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
void Push(ElementType X, Stack S);
ElementType TopAndPop(Stack S);

#endif