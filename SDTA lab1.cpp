#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void Kratnist(int &n)
{
	while(n%4!=0||n<=0)
	{
		cout<<"n must be positive and multiple of 4\n";
        cout << "n = ";
        cin >> n;
	}
}

void Masyv(double a[], int n)
{
	for(int i=0;i<n;i++)
	a[i]=(rand()%600-150)/100.0;
	
	cout<<"Array: "<<endl;
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;	
	cout << endl;   
}

void Matrycya(double a[], double b[][4], int n)
{
	int rows=n/4;
	cout<<"Matrix:"<<endl;
	for(int i = 0; i < rows; i++)
        for(int j = 0; j < 4; j++)
            b[i][j] = a[i*4 + j];
            
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < 4; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
    cout << endl;        
}

void Sort(double b[][4], int rows)
{
	for(int i = 0; i < rows; i++)
    {
        for(int k = 0; k < 3; k++)          
        {
            for(int j = 0; j < 3; j++)     
            {
                if(i % 2 == 0)   
                {
                    if(b[i][j] > b[i][j+1])
                    {
                        double t = b[i][j];
                        b[i][j] = b[i][j+1];
                        b[i][j+1] = t;
                    }
                }
                else        
                {
                    if(b[i][j] < b[i][j+1])
                    {
                        double t = b[i][j];
                        b[i][j] = b[i][j+1];
                        b[i][j+1] = t;
                    }
                }
            }
        }
    }

    cout << "Sort matrix:"<<endl;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < 4; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
	cout<<endl;
}

void MaxColumn(double b[][4],int rows){
    cout<<"Max in columns:"<<endl;
    for(int j=0;j<4;j++){
        double max=b[0][j];
        for(int i=1;i<rows;i++)
            if(b[i][j]>max)
                max=b[i][j];
        cout<<"Column "<<j+1<<" = "<<max<<endl;
    }
    cout<<endl;
}

int main()
{
	srand(time(0));
	int n;
	int rows = n / 4;
	double a[1000];
	double b[250][4];
	cout<<"n=";
	cin>>n;
	
	clock_t start,end;
    start=clock();
    
	Kratnist(n);
	Masyv(a, n);
	Matrycya(a, b, n);
	Sort( b, rows);
	MaxColumn(b,rows);
	
	end=clock();
    double time=(double)(end-start)/CLOCKS_PER_SEC;
    cout<<"Time="<<time<<" sec"<<endl;

    size_t space=sizeof(a)+sizeof(b);
    cout<<"Space="<<space<<" bytes"<<endl;
	
	return 0;
}