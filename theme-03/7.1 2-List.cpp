#include <iostream>
using namespace std;

struct Mark
{
	int day;
	int temp;
	Mark *next;
	Mark *prev;
} *first1=0, *last1=0, *first2=0, *last2=0;

Mark* addLast(Mark* first, Mark*& last, int d, int t)
{
	Mark *c=new Mark;
	c->day=d;
	c->temp=t;
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

void showList(Mark* first)
{
	Mark *q=first;
	if(q==0)
	{
		cout<<"empty"<<endl;
		return;
	}
	while(q!=0)
	{
		cout<<"day"<<q->day<<": "<<q->temp<<" ";
		q=q->next;
	}
	cout<<endl;
}

void showListBack(Mark* last)
{
	Mark *q=last;
	if(q==0)
	{
		cout<<"empty"<<endl;
		return;
	}
	while(q!=0)
	{
		cout<<"day"<<q->day<<": "<<q->temp<<" ";
		q=q->prev;
	}
	cout<<endl;
}

Mark* merge(Mark* first1, Mark*& last1, Mark* first2, Mark* last2)
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

void minMax(Mark* first)
{
	if(first==0) return;

	int min=first->temp;
	int max=first->temp;

	Mark *q=first;

	while(q!=0)
	{
		if(q->temp<min) min=q->temp;
		if(q->temp>max) max=q->temp;
		q=q->next;
	}

	cout<<"min="<<min<<endl;
	cout<<"max="<<max<<endl;
}

void clear(Mark*& first)
{
	Mark *q=first;
	while(q!=0)
	{
		Mark *t=q;
		q=q->next;
		delete t;
	}
	first=0;
}

int main()
{
	first1=addLast(first1,last1,1,10);
	first1=addLast(first1,last1,2,12);
	first1=addLast(first1,last1,3,8);

	first2=addLast(first2,last2,4,15);
	first2=addLast(first2,last2,5,7);
	first2=addLast(first2,last2,6,11);

	cout<<"list1:"<<endl;
	showList(first1);

	cout<<"list2:"<<endl;
	showList(first2);
	cout<<endl;

	first1=merge(first1,last1,first2,last2);

	cout<<"merged:"<<endl;
	showList(first1);
	cout<<endl;

	cout<<"back:"<<endl;
	showListBack(last1);

	minMax(first1);

	clear(first1);

	return 0;
}