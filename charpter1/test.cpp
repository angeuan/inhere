
#include<iostream>
#include<math.h>
using namespace std;
void out(int space,int k,char ch){
	for(int i=0;i<space;i++) cout<<" ";
	for(int i=0;i<k;i++) cout<<ch;
	cout<<endl;
}
void print(int space,int k,char ch){
	out(space,k,ch);
	if(k!=1){
		print(space+1,k-2,ch);
		out(space,k,ch);
	}
}
int main(){
	int n,plies;
	char ch;
	cin>>n>>ch;
	plies=sqrt((n+1)/2);
	print(0,plies*2-1,ch);
	cout<<n-pow(plies,2)*2+1<<endl;
}
