#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

bool exists(int a[],int n,int value){
    for(int i=0;i<n;i++)
        if(a[i]==value)
            return true;
    return false;
}

void fill(int a[],int n){
    for(int i=0;i<n;i++){
        int x;
        do{
            x=rand()%201-100;
        }while(exists(a,i,x));
        a[i]=x;
    }
}

void remove(int a[],int n,int X){
    int temp[1000];
    int k=0,removed=0;

    for(int i=0;i<n;i++){
        if(a[i]>X)
            temp[k++]=a[i];
        else
            removed++;
    }

    for(int i=0;i<removed;i++)
        temp[k++]=0;

    for(int i=0;i<n;i++)
        a[i]=temp[i];
}

int main(){
    srand(time(0));
    int n,X,a[1000];

    cout<<"n=";
    cin>>n;

    cout<<"X=";
    cin>>X;

    fill(a,n);

    cout<<"Array:"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    remove(a,n,X);

    cout<<"Result:"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    
    size_t space=sizeof(a)+sizeof(int)*1000;
    cout<<"Space="<<space<<" bytes"<<endl;

    return 0;
}