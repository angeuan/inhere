#include<stdio.h>
void Show_Array(int *p,int len)
{
    int i=0;
    for(i=0;i<len;i++){
        printf("%d",p[i]);
    }
}
int main()
{
    int a[16]={1,2,3,4,5};
    
    Show_Array(a,5);
    printf("%p\n",a+15);
    return 0;
}