#include "SearchTree.h"

struct TreeNode
{
    ElementType Element;
    SearchTree LeftNode;
    SearchTree RightNode;
};

SearchTree MakeEmpty(SearchTree T)
{
    if(T != NULL)
    {
        MakeEmpty(T->LeftNode);
        MakeEmpty(T->RightNode);
        free(T);
    }
    return NULL;
}

Position Find(ElementType X, SearchTree T)
{
    if(T == NULL)
        return NULL;
    if(X < T->Element)
        return Find(X, T->LeftNode);
    else if (X > T->Element)
        return Find(X, T->RightNode);
    else
        return T;
}

//Use recurse
Position FindMin(SearchTree T)
{
    if(T == NULL)
        return NULL;
    if(T->LeftNode == NULL)
        return T;
    else
        return FindMin(T->LeftNode);
}

//Not use recurse
Position FindMax(SearchTree T)
{
    if(T != NULL)
        while(T->RightNode != NULL)
            T = T->RightNode;
    return T;
}

SearchTree Insert(ElementType X, SearchTree T)
{
    if(T == NULL)
    {
        //Create a one-node tree
        T = malloc(sizeof(struct TreeNode));
        if(T == NULL)
            printf("Out of space!");
        else
        {
            T->Element = X;
            T->LeftNode = NULL;
            T->RightNode = NULL;
        }
    }
    else
    {
        if(X < T->Element)
            T->LeftNode = Insert(X, T->LeftNode);
        else if(X > T->RightNode)
            T->RightNode = Insert(X, T->RightNode);
        //Else X is already exist, cant insert
        return T;
    }
}

SearchTree Delete(ElementType X, SearchTree T)
{
    Position TmpCell;

    if(T == NULL)
        printf("Element not found");
    else if(X <T->LeftNode)
        T->LeftNode = Delete(X, T->LeftNode);
    else if(X >T->RightNode)
        T->RightNode = Delete(X, T->RightNode);
    //Found element
    else if(T->LeftNode && T->RightNode) //Full binary tree
    {
        TmpCell = FindMin(T->RightNode);
        T->Element = TmpCell->Element;
        T->RightNode = Delete(T->Element, T->RightNode);
    }
    else //one or zero child
    {
        TmpCell = T;
        if(T->LeftNode == NULL)
            T = T->RightNode;
        else if(T->RightNode == NULL)
            T = T->LeftNode;
        free(TmpCell);
    }
    return T;
}

ElementType Retrieve(Position P)
{

}
