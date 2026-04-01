#include <iostream>
using namespace std;

enum PaymentType
{
    CASH,
    CARD,
    TRANSFER
};

union Data
{
    int cashDesk;
    long cardNumber;
    long accountNumber;
};

struct Payment
{
    int number;
    PaymentType type;
    Data data;
};

int main()
{
    int n;
    cout<<"n=";
    cin>>n;

    Payment p[100];

    int cash=0, card=0, transfer=0;

    for(int i=0;i<n;i++)
    {
        cout<<"Payment number: ";
        cin>>p[i].number;

        cout<<"Type (0-cash,1-card,2-transfer): ";
        int t;
        cin>>t;
        p[i].type=(PaymentType)t;

        if(p[i].type==CASH)
        {
            cout<<"Cash desk: ";
            cin>>p[i].data.cashDesk;
            cash++;
        }
        else if(p[i].type==CARD)
        {
            cout<<"Card number: ";
            cin>>p[i].data.cardNumber;
            card++;
        }
        else
        {
            cout<<"Account number: ";
            cin>>p[i].data.accountNumber;
            transfer++;
        }

        cout<<endl;
    }

    cout<<"Payments:"<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<"Number: "<<p[i].number<<endl;

        if(p[i].type==CASH)
            cout<<"Cash desk: "<<p[i].data.cashDesk<<endl;

        else if(p[i].type==CARD)
            cout<<"Card number: "<<p[i].data.cardNumber<<endl;

        else
            cout<<"Account number: "<<p[i].data.accountNumber<<endl;

        cout<<endl;
    }

    cout<<"Cash payments: "<<cash<<endl;
    cout<<"Card payments: "<<card<<endl;
    cout<<"Transfer payments: "<<transfer<<endl;

    return 0;
}