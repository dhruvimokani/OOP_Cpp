#include<iostream>
using namespace std;

class Acc{
    int Acc_no;
    string name;
    double balance;
    static int totalAcc;
   static int transactionCount;

   public:
    Acc()
    {
Acc_no=0;
    name="";
    balance=0;
    }
    Acc(int no,string n,double b)
    {
Acc_no=no;
name=n;
balance=b;

totalAcc++;
    }
   static int getTotalAcc()
    {
return totalAcc;
    }
    void withdraw(double amt)
    {
        if(amt <= 0)
    {
         cout<<"Invalid Amount"<<endl;
        return;
    }

        if(amt>balance)
        {
            cout<<"Not Sufficient Balance";
        }
        else if(balance - amt < 500)
        {
        cout<<"Minimum Balance Violation"<<endl;
        return;
        }
        else
        {
            balance-=amt;
             transactionCount++;
        }
    }
    void deposit(double amt)
    {
        if(amt <= 0)
    {
    cout<<"Invalid Amount"<<endl;
    return;
    }

        balance+=amt;
     transactionCount++;
    }
    void display()
    {
     cout<<"Acc. No.:"<<Acc_no<<endl;
     cout<<"Acc. Holder Name:"<<name<<endl;
     cout<<"Balance:"<<balance<<endl;
  

    }
    int get_AccNo()
    {
        return Acc_no;
    }
    static int trans_count()
    {
 return transactionCount;
    }

};
int Acc::totalAcc=0;
int Acc::transactionCount=0;
int main()
{
Acc a[2];
int no;
string n;
double b;

for(int i=0;i<2;i++)
{
    cout<<"Enter Acc Number:";
    cin>>no;
    cout<<"Enter Acc Holder's Name:";
    cin>>n;
    cout<<"Enter Balance:";
    cin>>b;
a[i]=Acc(no,n,b);
}
int w,d,ch;
double amt;

cout<<"Enter 1 for Withdraw Enter 2 for Deposit Enter 3 for Transfer"<<endl;
cin>>ch;

switch (ch)
{
case 1:cout<<"Enter Acc Number from you want to withdraw:"<<endl;
cin>>w;
cout<<"Enter Amount:"<<endl;
cin>>amt;
for(int i=0;i<2;i++)
{
    if(a[i].get_AccNo()==w)
    {
        a[i].withdraw(amt);
    }
}
    break;
    case 2:cout<<"Enter Acc Number from you want to Deposit:"<<endl;
cin>>d;
cout<<"Enter Amount:"<<endl;
cin>>amt;
for(int i=0;i<2;i++)
{
   if(a[i].get_AccNo()==d)
    {
        a[i].deposit(amt);
    }
}
    break;
case 3:
cout<<"Enter Acc Number from you want to withdraw:"<<endl;
cin>>w;
cout<<"Enter Acc Number from you want to Deposit:"<<endl;
cin>>d;
cout<<"Enter Amount:"<<endl;
cin>>amt;

    for(int i=0;i<2;i++)
{
    if(a[i].get_AccNo()==w)
    {
        a[i].withdraw(amt);
    }
    else if(a[i].get_AccNo()==d)
    {
        a[i].deposit(amt);
    }
    else
    {
        cout<<"Acc NO. Not Found"<<endl;
    }
}

break;

}
for(int i=0;i<2;i++)
{
    a[i].display();
}
 cout<<"Total Accounts Created: "<<Acc::getTotalAcc()<<endl;
 cout<<"Total Transection:"<<Acc::trans_count()<<endl;
 
    return 0;
}