#include<iostream>
#include<stdio.h>
#include<malloc.h>
//数组实现
#define MAXSIZE 100
struct SNode {
    int *Data; /* 存储元素的数组 */
    int Top;      /* 栈顶指针 */
    int MaxSize;       /* 堆栈最大容量 */
};
typedef struct SNode *Stack;

Stack CreateStack( int MaxSize )
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (int *)malloc(MaxSize * sizeof(int));
    S->Top=-1;
    S->MaxSize = MaxSize;
    return S;
}

bool IsFull( Stack S )
{
    return (S->Top == S->MaxSize-1);
}

bool Push( Stack S, int X )
{
    if ( IsFull(S) ) {
        printf("堆栈满");
        return false;
    }
    else {
        S->Data[++(S->Top)] = X;
        return true;
    }
}

bool IsEmpty( Stack S )
{
    return (S->Top == -1);
}

int Pop( Stack S )
{
    if ( IsEmpty(S) ) {
        printf("堆栈空");
        return NULL; /* ERROR是int的特殊值，标志错误 */
    }
    else 
        return ( S->Data[(S->Top)--] );
}