#include<iostream>
#include<stdio.h>
#include<malloc.h>
//数组实现
#define MAXSIZE 100
typedef int Elem;

struct QNode{
    Elem *Data;
    int rear;
    int front;
    int MaxSize;
};
typedef struct QNode *Queue;
Queue CreateQueue(int MaxSize)
{
    Queue Q=(Queue)malloc(sizeof(struct QNode));
    Q->Data=(Elem*)malloc(MaxSize * sizeof(Elem));
    Q->front=Q->rear=0;
    Q->MaxSize=MaxSize;
    return Q;
}
bool IsFull(Queue Q)
{
    return ((Q->rear+1)%Q->MaxSize==Q->front);
}
bool IsEmpty(Queue Q)
{
    return (Q->front==Q->rear);
}
void AddQ(Queue PtrQ,Elem item)
{
    if((PtrQ->rear+1)%MAXSIZE==PtrQ->front){
        printf("full");
        return;
    }
    PtrQ->rear=(PtrQ->rear+1)%MAXSIZE;
    PtrQ->Data[PtrQ->rear]=item;
}

Elem DeleteQ(Queue PtrQ)
{
    if(PtrQ->front==PtrQ->rear){
        printf("empty");
        return NULL;
    }else{
        PtrQ->front=(PtrQ->front+1)%MAXSIZE;
        return PtrQ->Data[PtrQ->front];
    }
}

