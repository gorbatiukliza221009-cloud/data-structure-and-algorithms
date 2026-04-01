#include <iostream>
#include <string>
using namespace std;

struct School
{
    string name;
    int clas;
    int subject[5];
};

void searchExcellent(School a[], int n)
{
    cout<<"Excellent graduates:"<<endl;

    for(int i=0;i<n;i++)
    {
        if(a[i].clas==11)
        {
            bool excellent=true;  // зрозуміла назва щоб інші зрозуміли що виконується
            for(int j=0;j<5;j++)
            if(a[i].subject[j]!=5)
            excellent=false;

            if(excellent)
            cout<<a[i].name<<" "<<endl;
        }
    }
}

void searchStudentsWithRate(School a[], int n, int rateMark)  зрозуміла назва функції щоб інші зрозуміли що виконується
{
	if (rateMark > 5&& rateMark<1) 
	{
		cout<<" Not correct mark"<<endl;	
	}
	
    bool found=false;

    for(int i=0;i<n;i++)
        for(int j=0;j<5;j++)
            if(a[i].subject[j]==rateMark)
            {
                cout<<a[i].name<<" "<<a[i].clas<<endl;
                found=true;
                break;
            }

    if(!found)
        cout<<"No students with mark "<<rateMark<<endl;
}

void sort(School a[], int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(a[i].clas<a[j].clas)
                swap(a[i],a[j]);
}

void printInfo(School a[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i].name<<" "<<a[i].clas<<" ";
        for(int j=0;j<5;j++)
            cout<<a[i].subject[j]<<" ";
        cout<<endl;
    }
}

int deleteClass(School a[], int n, int k)
{
    int j=0;

    for(int i=0;i<n;i++)
        if(a[i].clas!=k)
            a[j++]=a[i];

    return j;
}

int main()
{
    int n;
    cout<<"n=";
    cin>>n;
    int rateMark=2;  // оцінка передається в int main() а це в функції тому що якщо треба буде шукати не 2 а якусь іншу оцінку, то не треба буде переписувати усю функцію,змінювати назву і т.д.

    School a[100];

    for(int i=0;i<n;i++)
    {
        cout<<"Name: ";
        cin>>a[i].name;

        cout<<"Class: ";
        cin>>a[i].clas;

        cout<<"Marks: ";
        for(int j=0;j<5;j++)
            cin>>a[i].subject[j];
    }

    cout<<endl<<"------------------------------"<<endl;
	searchExcellent(a,n);

    cout<<endl<<"Students with mark "<<rateMark<<":"<<endl;
    searchStudentsWithRate(a,n, rateMark);

    sort(a,n);

    cout<<endl<<"Sorted:"<<endl;
    printInfo(a,n);

    int k;
    cout<<"Class to delete: ";
    cin>>k;

    n=deleteClass(a,n,k);

    cout<<"After deletion:"<<endl;
    printInfo(a,n);

    return 0;
}