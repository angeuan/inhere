#include<stdio.h>
int main()
{
    unsigned int i=0;
    unsigned int k=0;
    int j=0;
    k=i-1;
    while(k!=0){
        k=k/2;
        j++;
    }
    printf("%u  %d  %d",i-1,i-1,j);
}