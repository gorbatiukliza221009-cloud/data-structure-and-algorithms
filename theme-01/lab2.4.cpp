#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void print(int a[10][10],int n)
{
    for(int i=0;i<n;i++)
	{
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    srand(time(0));
    int n=6,a[10][10];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j]=rand()%21-10;
            
    cout<<"Matrix:"<<endl;
print(a,n);

clock_t start,end;
start=clock();

for(int i=0;i<n;i++)
    a[i][i]=0;

int max=a[0][0],row=0;

for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        if(a[i][j]>max){
            max=a[i][j];
            row=i;
        }

for(int i=row;i<n-1;i++)
    for(int j=0;j<n;j++)
        a[i][j]=a[i+1][j];

n--;

end=clock();

    cout<<"After deleting row with max:"<<endl;
    print(a,n);
    
    end=clock();
    double time=(double)(end-start)/CLOCKS_PER_SEC;
    cout<<"Time="<<time<<" sec"<<endl;

    return 0;
}