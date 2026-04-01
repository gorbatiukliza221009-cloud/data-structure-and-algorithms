#include <iostream>
#include <string.h>
using namespace std;

class Worker
{
	string name, surname, position;
	int year, salary;
	
public:
	
	Worker()
	{}
	
	Worker(string n, string s, int y, int s1)
	{
		name=n;
		surname=s;
		year=y;
		salary=s1;
	}
	
	void Expirience(int currentYear)
	{
		int e;
		if (currentYear < year) return 0
		e=currentYear-year;
		cout<<"Experience: "<<e<<" years"<<endl;
	}
	
	void Salary()
	{
		float s2;
		s2=salary-(salary*33/100);
		cout<<"Salary after taxes: "<<s2<<" grn."<<endl<<endl;
	}
};

int main()
{
	int currentYear=2026;
	Worker  a[10];
	string name,surname;
    int year,salary;
	int n, i;
	cout<<"n=";
	cin>>n;
	for(i=0;i<n;i++)
    {
        cout<<"name: ";
        cin>>name;

        cout<<"surname: ";
        cin>>surname;

        cout<<"year: ";
        cin>>year;

        cout<<"salary: ";
        cin>>salary;

        a[i]=Worker(name,surname,year,salary);
    }
	
	cout<<endl;
	for(i=0;i<n;i++)
{
    a[i].Expirience(currentYear);
    a[i].Salary();
}
	
	
	return 0;
}