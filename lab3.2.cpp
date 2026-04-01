#include <iostream>
#include <string>
using namespace std;

enum Faculty
{
    IT,
    ECONOMICS,
    LAW,
    MANAGEMENT
};

struct Student
{
    string surname;
    int course;
    float average;
    Faculty faculty;
};

int main()
{
    const int n = 5;
    Student st[n];

    cout<<"Enter data for students:"<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<endl<<"Student "<<i+1<<endl;

        cout<<"Surname: ";
        cin>>st[i].surname;

        cout<<"Course: ";
        cin>>st[i].course;

        cout<<"Average mark: ";
        cin>>st[i].average;

        cout<<"Faculty (0-IT, 1-ECONOMICS, 2-LAW, 3-MANAGEMENT): ";
        int f;
        cin>>f;
        st[i].faculty=(Faculty)f;
    }

    cout<<endl<<"Students of IT faculty:"<<endl;

    for(int i=0;i<n;i++)
    {
        if(st[i].faculty==IT)
        {
            cout<<st[i].surname<<" "
                <<"Course: "<<st[i].course<<" "
                <<"Average: "<<st[i].average<<endl;
        }
    }

    float sum=0;

    for(int i=0;i<n;i++)
        sum+=st[i].average;

    float avg=sum/n;

    cout<<endl<<"Average mark of group: "<<avg<<endl;

    return 0;
}