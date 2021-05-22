#include<stdio.h>
#include<malloc.h>

int main()
{
    int a[5]={1,2,3,4,5};

    int len;
    printf("enter the lenth");
    scanf("%d",len);
    int *pArr=(int *)malloc(sizeof(int)*len);
    *pArr=4;
    pArr[1]=10;

    printf("");

    free(pArr);

    return 0;
}