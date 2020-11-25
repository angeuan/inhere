#include<stdio.h>
#include<malloc.h>
#include<iostream>

#define Maxsize 100
typedef int item ;

struct PolyNode{
    int coef;
    int expon;
    struct PolyNode *link;
};

typedef struct PolyNode *Polynomial;

int Compare(int i,int j);
void Attach(int i,int j,Polynomial * pRear);
Polynomial ReadPoly()
{
    Polynomial P,Rear,t;
    int c,e,N;
    scanf("%d",&N);
    P=(Polynomial)malloc(sizeof(struct PolyNode));
    Rear=P;
    while(N--)
    {
        scanf("%d %d",&c,&e);
        
    }
}
Polynomial PolyMult(Polynomial P1,Polynomial P2)
{

}


