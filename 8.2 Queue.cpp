#include <iostream>
#include <string>
using namespace std;

struct Bus
{
	int number;
	string dest;
	int passengers;
	Bus* next;
} *first1=0, *last1=0, *first2=0, *last2=0;

void addToQueue(Bus*& first, Bus*& last, int num, string d, int p)
{
	Bus* c=new Bus;
	c->number=num;
	c->dest=d;
	c->passengers=p;
	c->next=0;

	if(first==0)
	{
		first=last=c;
	}
	else
	{
		last->next=c;
		last=c;
	}
}

void showQueue(Bus* first)
{
	Bus* q=first;
	while(q!=0)
	{
		cout<<q->number<<" "<<q->dest<<" "<<q->passengers<<endl;
		q=q->next;
	}
	cout<<endl;
}

void merge(Bus*& first1, Bus*& last1, Bus* first2, Bus* last2)
{
	if(first1==0)
	{
		first1=first2;
		last1=last2;
		return;
	}

	if(first2!=0)
	{
		last1->next=first2;
		last1=last2;
	}
}

void showMore(Bus* first, int x)
{
	Bus* q=first;
	while(q!=0)
	{
		if(q->passengers>x)
			cout<<q->number<<" "<<q->dest<<" "<<q->passengers<<endl;
		q=q->next;
	}
	cout<<endl;
}

void deleteFirst(Bus*& first, Bus*& last)
{
	if(first==0) return;

	Bus* t=first;
	first=first->next;
	delete t;

	if(first==0) last=0;
}

void clear(Bus*& first)
{
	Bus* q=first;
	while(q!=0)
	{
		Bus* t=q;
		q=q->next;
		delete t;
	}
	first=0;
}

int main()
{
	int n,m;
	int num,p;
	string dest;

	cout<<"Enter number of routes (queue1): ";
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cout<<"Route "<<i+1<<endl;

		cout<<"Number: ";
		cin>>num;

		cout<<"Destination: ";
		cin>>dest;

		cout<<"Passengers: ";
		cin>>p;

		addToQueue(first1,last1,num,dest,p);
	}

	cout<<"Enter number of routes (queue2): ";
	cin>>m;

	for(int i=0;i<m;i++)
	{
		cout<<"Route "<<i+1<<endl;

		cout<<"Number: ";
		cin>>num;

		cout<<"Destination: ";
		cin>>dest;

		cout<<"Passengers: ";
		cin>>p;

		addToQueue(first2,last2,num,dest,p);
	}

	cout<<"Queue1:"<<endl;
	showQueue(first1);

	cout<<"Queue2:"<<endl;
	showQueue(first2);

	merge(first1,last1,first2,last2);

	cout<<"Merged queue:"<<endl;
	showQueue(first1);

	int x;
	cout<<"Enter passengers minimum: ";
	cin>>x;

	cout<<"Routes with passengers more than "<<x<<":"<<endl;
	showMore(first1,x);

	deleteFirst(first1,last1);
	deleteFirst(first1,last1);

	cout<<"After deleting first two:"<<endl;
	showQueue(first1);

	clear(first1);

	return 0;
}