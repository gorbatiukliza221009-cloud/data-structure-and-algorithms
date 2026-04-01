#include <iostream>
#include <string>
using namespace std;

struct Book
{
	string name;
	string author;
	int year;
	Book *next;
	Book *prev;
} *first1=0, *last1=0, *first2=0, *last2=0;

Book* addLast(Book* first, Book*& last, string n, string a, int y)
{
	Book *c=new Book;
	c->name=n;
	c->author=a;
	c->year=y;
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

void showList(Book* first)
{
	Book *q=first;
	while(q!=0)
	{
		cout<<q->name<<" "<<q->author<<" "<<q->year<<endl;
		q=q->next;
	}
	cout<<endl;
}

void showBack(Book* last)
{
	Book *q=last;
	while(q!=0)
	{
		cout<<q->name<<" "<<q->author<<" "<<q->year<<endl;
		q=q->prev;
	}
	cout<<endl;
}

Book* merge(Book* first1, Book*& last1, Book* first2, Book* last2)
{
	if(first1==0) return first2;

	if(first2!=0)
	{
		last1->next=first2;
		first2->prev=last1;
		last1=last2;
	}
	return first1;
}

void clear(Book*& first)
{
	Book *q=first;
	while(q!=0)
	{
		Book *t=q;
		q=q->next;
		delete t;
	}
	first=0;
}

int main()
{
	int n,m;
	string name,author;
	int year;

	cout<<"Enter number of books (list1): ";
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cout<<"Book "<<i+1<<endl;

		cout<<"Name: ";
		cin>>name;

		cout<<"Author: ";
		cin>>author;

		cout<<"Year: ";
		cin>>year;

		first1=addLast(first1,last1,name,author,year);
	}

	cout<<"Enter number of books (list2): ";
	cin>>m;

	for(int i=0;i<m;i++)
	{
		cout<<"Book "<<i+1<<endl;

		cout<<"Name: ";
		cin>>name;

		cout<<"Author: ";
		cin>>author;

		cout<<"Year: ";
		cin>>year;

		first2=addLast(first2,last2,name,author,year);
	}
	
	cout<<"--------------------------------------"<<endl;

	cout<<"List1:"<<endl;
	showList(first1);
	showBack(last1);

	cout<<"List2:"<<endl;
	showList(first2);
	showBack(last2);

	first1=merge(first1,last1,first2,last2);

	cout<<"Merged:"<<endl;
	showList(first1);

	clear(first1);

	return 0;
}