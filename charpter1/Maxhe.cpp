#include<stdio.h>
#include<iostream>
#include<vector>

#include <string>
using namespace std;

int maxseque(int a[],int k)
{
    int i=0,max=0,maxtemp=0;
    for(i=0;i<k;i++)
    {
        maxtemp+=a[i];
        if(maxtemp>max)
        max=maxtemp;
        else if(maxtemp<0)
        maxtemp=0;
    }
    return max;
}

int main(){
    int K,i,output;
    cin>>K;
    int *input=new int[K];
    for(i=0;i<K;i++)
    cin>>input[i];
    output=maxseque(input,K);
    cout<<output;
    delete[] input;
	system("pause");
	return 0;
}