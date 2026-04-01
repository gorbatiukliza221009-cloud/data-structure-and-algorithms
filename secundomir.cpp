#include <ctime>
#include <iostream>
using namespace std;
int main()
{
	clock_t start, end;
	
	double sum=0, t=0;
	cout<<sizeof(start)+sizeof(end)+sizeof(sum)+sizeof(t)<<endl;
	start=clock();
	for( int i=1;i<=10000;i++)
	{
		sum+=i;
		cout<<i<<" ";
	}
	end=clock();
	t=((double)end-start)/CLOCKS_PER_SEC;
	cout<<endl<<"time="<<t<<"sec";
	
	return 0;
}