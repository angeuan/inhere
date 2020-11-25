#include<iostream>
#include<stdio.h>
#include<malloc.h>
//数组实现
#define MAXSIZE 100
typedef int Elem;
typedef struct SNode *Stack;
struct SNode{
    Elem Data[MAXSIZE];
    int Top;
};
struct DStack{
    Elem Data[MAXSIZE];
    int Top1;
    int Top2;
}S;



//入栈
void Push(Stack PtrS,Elem item)
{
    if(PtrS->Top==MAXSIZE-1){
        printf("堆栈满"); return;
    }else{
        PtrS->Data[++(PtrS->Top)]=item;
        return ;
    }
}

//出栈
Elem Pop(Stack PtrS)
{
    if(PtrS->Top==-1){
        printf("FULL STACK");
        return 0;
    }else
        return (PtrS->Data[(PtrS->Top)--]);
}

void DPush(struct DStack *PtrS,Elem item,int Tag)
{
    if(PtrS->Top2-PtrS->Top1==1) printf("堆栈满");
    if(Tag==1)
        PtrS->Data[++(PtrS->Top1)]=item;
    else
        PtrS->Data[--(PtrS->Top2)]=item;
}

Elem DPop(struct DStack *PtrS,int Tag)
{
    if(Tag==1){
        if(PtrS->Top1==-1){
            printf("NULL"); return NULL;
        }else{
            return PtrS->Data[(PtrS->Top1)--];
        }
    }else{
        if(PtrS->Top2==MAXSIZE){
            printf("NULL2"); return NULL;
        }else return PtrS->Data[(PtrS->Top2)++];
    }
}