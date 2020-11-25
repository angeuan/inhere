typedef struct LNode *List;
struct LNode{
    ElementType Data[MAXSIZE];
    int Last;
};
struct LNode L;
List PtrL;

List MakeEmpty()
{
    List PtrL;
    PtrL=(List)malloc(sizeof(struct LNode));
    PtrL->last=-1;
    return PtrL;
}
int Find (ElementType X,List PtrL){
    int i=0;
    while(i<=PtrL->Last||PtrL->Data[i]!=X)
        i++;
    if(i>PtrL->Last) return -1;
    else return i;
}
void Insert(ELementType X,int i,List PtrL)
{

}

typedef int ElementType;

typedef struct Lnode *list;
struct Lnode{
    ElementType Data;
    list Next;
};
struct Lnode l;
list Ptrl;
int length(list Ptrl)
{
    list p=Ptrl;
    int j=0;
    while(p){
        p=p->Next;
        j++
    }
    return j;
}

list FindKth(int K,list Ptrl)
{
    List p=Ptrl;
    int i=1;
    while(p!=NULL&&i<K)
    {
        p=p->Next;
        i++;
    }
}
list Findvalue(ElementType X,list Ptrl)
{
    list p=Ptrl;
    while(p!=NULL&&p->Data!=X)
    p=p->Next;
    return p;
}




