#include<iostream>
#include<stdio.h>
#include"stack.h"
#include"queue.h"
typedef struct TNode *Position;
typedef Position BinTree; /* 二叉树类型 */
struct TNode{ /* 树结点定义 */
    int Data; /* 结点数据 */
    BinTree Left;     /* 指向左子树 */
    BinTree Right;    /* 指向右子树 */
    int Visit;
};

bool IsEmpty(BinTree BT);
void Traversal(BinTree BT);
void PreOrderTraversal(BinTree BT);
void InOrderTraversal(BinTree BT);
void PostOrderTraversal(BinTree BT);
void LevelOrderTraversal(BinTree BT);
BinTree CreatBinTree();

void PreOrderTraversal(BinTree BT)
{
    if(BT)
    {
        printf("%d",BT->Data);
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Right);
    }
}
void InOrderTraversal(BinTree BT)
{
    if(BT){
        InOrderTraversal(BT->Left);
        printf("%d",BT->Data);
        InOrderTraversal(BT->Right);
    }
}
void PostOrderTraversal(BinTree BT)
{
    if(BT){
        PostOrderTraversal(BT->Left);
        PostOrderTraversal(BT->Right);
        printf("%d",BT->Data);
    }
}

void IOT(BinTree BT)
{
    BinTree T=BT;
    Stack S = CreateStack(MAXSIZE);
    while(T||!IsEmpty(S)){
        while(T){
            Push(S,(int)T);
            T=T->Left;
        }
        if(!IsEmpty(S)){
            T=(BinTree)Pop(S);
            printf("%5d",T->Data);
            T=T->Right;
        }
    }
}
void PreOT(BinTree BT)
{
    BinTree T=BT;
    Stack S=CreateStack(MAXSIZE);
    while(T||!IsEmpty(S)){
        while(T){
            Push(S,(int)T);
            printf("%5d",T->Data);
            T=T->Left;
        }
        if(!IsEmpty(S))
        {
            T=(BinTree)Pop(S);
            T=T->Right;
        }
    }
}
void PostOT(BinTree BT) {  //给节点增加访问次数的属性Visit，初始化为0
    BinTree T=BT;
    int Visit;
    Stack S = CreateStack(MAXSIZE);
    while (T || !IsEmpty(S)) {
        while (T) {
            if (T->Visit == 0) {//虽然没必要判断，为便于理解
                T->Visit++;
                Push(S, (int)T);  //第一次入栈，不访问
            }
            T = T->Left;   //转向左子树
        }
        if (!IsEmpty(S)) {
            T =(BinTree) Pop(S);
            if (T->Visit == 2)    {
                printf("%d", T->Data);//第三次碰到它，访问节点，可以彻底从堆栈弹出了
                T = NULL;//左右子数均已经访问过
            }
            else {
                T->Visit++;
                Push(S, (int)T);  //第二次入栈，不访问，（相当于T没有出栈）
                T = T->Right;  //转向右子树
            }
        }
    }

void LevelOrderTraversal(BinTree BT){
    Queue Q; BinTree T;
    if(!BT) return;
    Q=CreateQueue(MAXSIZE);
    AddQ(Q,BT);
    while(!IsEmpty(Q))
    {
        T=DeleteQ(Q);
        printf("%d\n",T->Data);
        if(T->Left) AddQ(Q,T->Left);
        if(T->Right) AddQ(Q,T->Right); 
    }
}