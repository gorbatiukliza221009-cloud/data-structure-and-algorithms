#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void sortUp(int a[],int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
}

void sortDown(int a[],int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]<a[j+1])
                swap(a[j],a[j+1]);
}

void sortArray(int a[],int n){
    int even[1000],odd[1000];
    int e=0,o=0;

    for(int i=0;i<n;i++){
        if(a[i]%2==0)
            even[e++]=a[i];
        else
            odd[o++]=a[i];
    }

    sortUp(even,e);
    sortDown(odd,o);

    for(int i=0;i<e;i++)
        a[i]=even[i];
    for(int i=0;i<o;i++)
        a[e+i]=odd[i];
}

int main(){
    srand(time(0));
    int n=90,a[1000],b[1000],c[1000],i;


    for(i=0;i<n;i++){
        a[i]=rand()%210-100;
        b[i]=a[i];
        c[i]=a[i];
    }

    cout<<"Array:"<<endl;
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    clock_t start,end;

    start=clock();
    for(int k=0;k<10000;k++)
    sortUp(b,n);
    end=clock();
    double tUp=(double)(end-start)/CLOCKS_PER_SEC;

    start=clock();
    for(int k=0;k<10000;k++)
    sortDown(c,n);
    end=clock();
    double tDown=(double)(end-start)/CLOCKS_PER_SEC;

    sortArray(a,n);

    cout<<"Sort Array:"<<endl;
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    cout<<"Time up="<<tUp<<" sec"<<endl;
    cout<<"Time down="<<tDown<<" sec"<<endl;

    return 0;
}