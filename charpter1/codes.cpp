#include<iostream>
#include<stdio.h>
#include<malloc.h>
typedef int Elem;
Elem X;
typedef struct LNode *List;
struct LNode{
    Elem Data;
    List Next;
};
struct LNode L;
List PtrL;
//求长度 O（n）
int Length(List PtrL)
{
    List p=PtrL;
    int j=0;
    while(p){
        p=p->Next;
        j++;
    }
    return j;
}
//查找 按序号；
List FindKth(int K,List PtrL)
{
    List p=PtrL;
    int i=1;
    while(p!=NULL&&i<K){
        p=p->Next;
        i++;
    }
    if(i==K) return p;
    else return NULL;
}
//按值查找
List Find(Elem X,List PtrL)
{
    List p=PtrL;
    while(p!=NULL&&p->Data!=X)
        p=p->Next;
    return p;
}
//插入
List Insert(Elem X,int i,List PtrL)
{
    List p,s;
    if(i==1){
        s=(List)malloc(sizeof(struct LNode));
        s->Data=X;
        s->Next=PtrL;
        return s;
    }
    p=FindKth(i-1,PtrL);
    if(p==NULL)
    {
        printf("wrong");
        return NULL;
    }else
    {
        s=(List)malloc(sizeof(struct LNode));
        s->Data=X;
        s->Next=p->Next;
        p->Next=s;
        return PtrL;
    }
    
}
//删除
List Delete(int i,List PtrL)
{
    List p,s;
    if(i==1)
    {
        s=PtrL;
        if(p!=NULL) PtrL=PtrL->Next;
        else return NULL;
        free(s);
        return PtrL;
    }
    p=FindKth(i-1,PtrL);
    if(p==NULL){
        printf("i-1 dosn't exist"); return NULL;
    }else if(p->Next==NULL){
        printf("i dosn't exist"); return NULL;
    }else{
        s=p->Next;
        p->Next=s->Next;
        free(s);
        return PtrL;
    }
}

typedef struct GNode *GList;
struct GNode{
    int Tag;/*标志域 0=单元素 1=广义表*/
    union{    /*利用Tag区分union的类型为单元素data还是指针SubList*/
        Elem Data;
        GList SubList;
    }URegion;
    GList Next;
};



