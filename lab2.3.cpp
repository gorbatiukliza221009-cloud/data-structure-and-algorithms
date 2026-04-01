#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void print(int a[5][5])
{
    for(int i=0;i<5;i++)
	{
        for(int j=0;j<5;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    srand(time(0));
    int a[5][5];

    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            a[i][j]=rand()%201-100;

    cout<<"Matrix:"<<endl;
    
    clock_t start,end;
    start=clock();
    print(a);
    

    int max=a[0][0],r=0,c=0;

    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(a[i][j]>max)
			{
                max=a[i][j];
                r=i;
                c=j;
            }

    for(int j=0;j<5;j++)
        swap(a[0][j],a[r][j]);
        
	end=clock();
    double time=(double)(end-start)/CLOCKS_PER_SEC;

    cout<<"After row swap:"<<endl;
    print(a);

    for(int i=0;i<5;i++)
        swap(a[i][0],a[i][c]);

    cout<<"After column swap:"<<endl;
    print(a);
    
    cout<<"Time="<<time<<" sec"<<endl;

    return 0;
}