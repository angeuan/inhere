#include<iostream>
#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef int item;

typedef struct LNode *List;
struct LNode{
    item it[MaxSize];
    int length;
};

int SequentialSearch(List T,item K)
{
    int i;
    T->it[0]=K;/*哨兵,也说明数组从下标为1开始储存*/
    for(i=T->length;T->it[i]!=K;i--);
    return i;
}
int BinarySearch(List T,item K)
{
    int left ,right,mid,Nofound=-1;
    left=1; right=T->length;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(K<T->it[mid])
        {
            right=mid-1;
        }else if(K>T->it[mid])
        {
            left=mid+1;
        }else return mid;
    }
    return Nofound;
}

