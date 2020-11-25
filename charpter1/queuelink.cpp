#include<iostream>
#include<stdio.h>
#include<malloc.h>
//数组实现
#define MAXSIZE 100
typedef int Elem;

struct Node{
    Elem Data;
    struct Node *Next;
};

struct QNode{
    struct Node *rear;
    struct Node *front;
};
typedef struct QNode *Queue;
Queue PtrQ;

void AddQ(Queue PtrQ,Elem item)
{
    struct Node *NodeQ;
    NodeQ=(struct Node *)malloc(sizeof(struct Node));
    NodeQ->Data=item;
    if(PtrQ->front==PtrQ->rear)
        {
            PtrQ->rear=PtrQ->rear->Next;
            PtrQ->rear->Data=item;
        }
    
}

Elem DeleteQ(Queue PtrQ)
{
    struct Node *FrontCell;
    Elem FrontElem;

    if(PtrQ->front==NULL){
        printf("null"); return NULL;
    }
    FrontCell=PtrQ->front;
    if(PtrQ->front==PtrQ->rear)
        PtrQ->front=PtrQ->rear=NULL;
    else
        PtrQ->front=PtrQ->front->Next;
    FrontElem=FrontCell->Data;
    free(FrontCell);
    return FrontElem;
}   