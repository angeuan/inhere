#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct Arr{
    int * pHead;
    int len;
    int cnt;
};

void init_arr(struct Arr* pArr,int len);
bool append_Arr();
bool insert_arr();
bool delete_arr();
int get();
bool is_empty(struct Arr *pArr);
bool is_full();
bool sort_arr();
void show_arr(struct Arr* pArr);
void inversion_arr();

int main()
{
    struct Arr arr;
    init_arr(&arr,6);
    show_arr(&arr);


    return 0;
}

void init_arr(struct Arr *pArr,int len)
{
    pArr->pHead=(int *)malloc(sizeof(int)*len);
    if(pArr->pHead==NULL)
    {
        printf("failue\n");
        exit(-1);
    }else{
        pArr->len=len;
        pArr->cnt=0;
    }
    return;
}

bool is_empty(struct Arr *pArr)
{
    if(pArr->cnt==0)
        return true;
    else return false;
}

void show_arr(struct Arr* pArr)
{
    if(is_empty(pArr)){
        printf("Array is empty\n");
    }else{
        for(int i=0;i<pArr->cnt;i++)
            printf("%d",pArr->pHead[i]);
        printf("\n");
    }
}