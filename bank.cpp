#include<iostream>
#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<conio.h>
#include<process.h>
using namespace std;

class bank
{
    unsigned long accno;
    char name[30];
    char atype;
    float balance;

    public:
        unsigned long getact();
        void getdata();
        void dispdata();
        void deposit();
        void withdraw();
};

void bank :: getdata()
{
    cout<<"\nEnter Account Number :";
    cin>>accno;
    cout<<"\nEnter Customer Name : ";
    gets(name);
    cout<<"\nEnter Account Type(S for Saving / C for Current) : ";
    cin>>atype;
    cout<<"\nEnter Initial Amount : ";
    cin>>balance;
}

void bank :: dispdata()
{
    cout<<"\nAccount Number : "<<accno;
    cout<<"\nCustomer Name : "<<name;
    cout<<"\nAccount Type : "<<atype;
    cout<<"\nBalance Amount : "<<balance;
}

unsigned long bank :: getact()
{
    return accno;
}

void bank :: deposit()
{
    float amount;

    cout<<"\nEnter amount to be deposited : ";
    cin>>amount;
    balance += amount;
    cout<<"\nAmount Deposited\nNew Balance : "<<balance;
}

void bank :: withdraw()
{
    float amount;

    cout<<"\nEnter amount to be withdrawn : ";
    cin>>amount;

    if((balance-amount) > 1000)
    {
        balance -= amount;
        cout<<"\nAmount Withdrawn\nNew Balance : "<<balance;
    }

    else
    {
        cout<<"\nNOT ENOUGH BALANCE!!!!!";
    }
}

int main(void)
{
    //system(cls);
    bank customer[100];
    int n, i, ch, pos;
    unsigned long ano;

    cout<<"\nHow many customers : ";
    cin>>n;
    for(i=0; i<n; i++)
    {
        customer[i].getdata();
    }

    do
    {
        //system(cls);

        cout<<"\n\tBANK TRANSACTION";
        cout<<"\n1.Deposit";
        cout<<"\n2.Withdraw";
        cout<<"\n3.Display one customer record";
        cout<<"\n4.Display all cutomers record";
        cout<<"\n5.Exit";
        cout<<"\nEnter your choice";
        cin>>ch;

        switch(ch)
        {
            case 1 : cout<<"\nEnter Account Number : ";
                     cin>>ano;
                     pos =- 1;
                     for(i=0; i<n; ++i)
                     if(customer[i].getact == ano)
                     {
                         customer[i].deposit();
                         pos = i;
                         break;
                     }

                     if(pos == -1)
                     {
                         cout<<"\nINVALID ACCOUNT NUMBER";
                     }
                
            case 2 : cout<<"\nEnter account number : ";
                     cin>>ano;
                     pos = -1;
                     for(i=0; i<n; ++i)
                     if(customer[i].getact() == ano)
                     {
                         customer[i].withdraw();
                         pos = i;
                         break;
                     }

                     if(pos == -1)
                     {
                         cout<<"\nINVALID ACCOUNT NUMBER";
                     }

            case 3 : cout<<"\nEnter Account Number : ";
                     cin>>ano;
                     pos = -1;
                     for(i=0; i<n; ++i)
                     if(customer[i].getact() == ano)
                     {
                         customer[i].dispdata();
                         pos = i;
                         break;
                     }

                     if(pos == -1)
                     {
                         cout<<"\nINVALID ACCOUNT NUMBER";
                     }

            case 4 : for(i=0; i<n; ++i)
                     {
                         cout<"\nCustomer Record No."<<i+1<<"\n";
                         customer[i].dispdata();
                     }
                     break;

            case 5 : exit(0);

        }
    }while(1);
}