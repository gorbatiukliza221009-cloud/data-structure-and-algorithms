#include <iostream>
#include <string>
using namespace std;

struct Worker
{
	string name;
	string dep;
	float salary;
	Worker *next;
	Worker *prev;
} *first=0, *last=0, *firstA=0, *lastA=0, *firstB=0, *lastB=0;

Worker* addLast(Worker* first, Worker*& last, string n, string d, float s)
{
	Worker *c=new Worker;
	c->name=n;
	c->dep=d;
	c->salary=s;
	c->next=0;
	c->prev=last;

	if(first==0)
	{
		first=last=c;
	}
	else
	{
		last->next=c;
		last=c;
	}
	return first;
}

void showList(Worker* first)
{
	Worker *q=first;
	while(q!=0)
	{
		cout<<q->name<<" "<<q->dep<<" "<<q->salary<<endl;
		q=q->next;
	}
	cout<<endl;
}

void showBack(Worker* last)
{
	Worker *q=last;
	while(q!=0)
	{
		cout<<q->name<<" "<<q->dep<<" "<<q->salary<<endl;
		q=q->prev;
	}
	cout<<endl;
}

float avgSalary(Worker* first)
{
	float sum=0;
	int k=0;

	Worker *q=first;
	while(q!=0)
	{
		sum+=q->salary;
		k++;
		q=q->next;
	}

	return sum/k;
}

void splitList(Worker* first)
{
	float avg=avgSalary(first);
	cout<<"Average salary = "<<avg<<endl<<endl;

	Worker *q=first;

	while(q!=0)
	{
		if(q->salary>avg)
			firstA=addLast(firstA,lastA,q->name,q->dep,q->salary);
		else
			firstB=addLast(firstB,lastB,q->name,q->dep,q->salary);

		q=q->next;
	}
}

void clear(Worker*& first)
{
	Worker *q=first;
	while(q!=0)
	{
		Worker *t=q;
		q=q->next;
		delete t;
	}
	first=0;
}

int main()
{
	int n;
cout<<"Enter number of workers: ";
cin>>n;

string name, dep;
float salary;

for(int i=0;i<n;i++)
{
    cout<<"\nWorker "<<i+1<<":"<<endl;
    cout<<"Name: ";
    cin>>name;
    cout<<"Department: ";
    cin>>dep;
    cout<<"Salary: ";
    cin>>salary;

    first=addLast(first,last,name,dep,salary);
}

	cout<<endl<<"All workers:"<<endl;
	showList(first);

	splitList(first);

	cout<<"Above average:"<<endl;
	showList(firstA);
	showBack(lastA);

	cout<<"Below or equal average:"<<endl;
	showList(firstB);
	showBack(lastB);

	cout<<endl<<"Add new worker (name department salary): ";
	cout<<"Name: ";
    cin>>name;
    cout<<"Department: ";
    cin>>dep;
    cout<<"Salary: ";
    cin>>salary;
	firstA=addLast(firstA,lastA,name,dep,salary);

	cout<<endl<<"Updated above-average list:"<<endl;
	showList(firstA);

	clear(first);
	clear(firstA);
	clear(firstB);

	return 0;
}