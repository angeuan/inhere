#include<iostream>
#include<stdio.h>
#include<malloc.h>
//链表实现
#define MAXSIZE 100
typedef int Elem;

typedef struct SNode *Stack;
struct SNode{
    Elem Data;
    struct SNode *Next;
};

Stack CreatStack()
{
    Stack S;
    S=(Stack)malloc(sizeof(struct SNode));
    S->Next=NULL;
    return S;
}

int Isempty(Stack S)
{
    return (S->Next==NULL);
}

void Push(Elem item,Stack S)
{
    struct SNode *TempCell;
    TempCell=(struct SNode *)malloc(sizeof(struct SNode));
    TempCell->Data=item;
    TempCell->Next=S->Next;
    S->Next=TempCell;
}
Elem Pop(Stack S)
{
    struct SNode *FirstCell;
    Elem TopElem;
    if(Isempty(S)){
        printf("empty");return NULL;
    }else{
        FirstCell=S->Next;
        S->Next=FirstCell->Next;
        TopElem=FirstCell->Data;
        free(FirstCell);
        return TopElem;
    }
}