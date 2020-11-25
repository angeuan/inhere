#include"iostream"
#include"windows.h"
#include"stdio.h"

using namespace std;

bool lock[4]={false,false,false,false};
int buffer[4]={0,0,0,0};

void display()
{
    cout<<"------------"<<endl;
    cout<<"缓冲区 0 1 2 3"<<endl;
    for(int i=0;i<4;i++) cout<<" "<<buffer[i]<<"  ";
    cout<<endl;
}

DWORD WINAPI Producer(LPVOID lpParameter){
    cout<<endl;
    while(true){
        for(int j=0;j<4;j++){
            if(buffer[j]==0){
                if(lock[j]==false){
                    lock[j]=true;
                    if (buffer[j]<1)
                    {
                        ++buffer[j];
                        cout<<"生产一个资源，放入缓冲区"<<j<<"中"<<endl;
                        lock[j]=false;
                        break;
                    }    
                }
                if(j==3){
                    cout<<"找不到空缓冲区，等待中"<<endl;
                    Sleep(2000);
                }
            }
        }
    }
    return 0;
}

DWORD WINAPI Customer(LPVOID lpParameter)
{
    cout<<endl;
    while(true){
        for(int n=0;n<4;n++){
            if(buffer[n]==1){
                if(lock[n]==false){
                    lock[n]=true;
                    if(buffer[n]>=1){
                        --buffer[n];
                        cout<<"消费一个资源 从缓冲区"<<n<<"中取出"<<endl;
                        lock[n]=false;
                        break;
                    }
                }
            }
            if(n==3){
                cout<<"找不到满缓冲区，等待中"<<endl;
                Sleep(2000);
            }
        }
    }
        return 0;
}

int main(int argc,char* argv[])
{
    display();
    HANDLE handle[3];
    DWORD dw1,dw2,dw3,dw4,dw0;

    handle[0]=CreateThread(NULL,0,Producer,NULL,0,&dw1);
    handle[1]=CreateThread(NULL,0,Producer,NULL,0,&dw2);
    handle[2]=CreateThread(NULL,0,Producer,NULL,0,&dw3);
    handle[3]=CreateThread(NULL,0,Customer,NULL,0,&dw4);
    handle[4]=CreateThread(NULL,0,Customer,NULL,0,&dw0);

    display();

    Sleep(3000);
    display();
}