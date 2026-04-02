#include <iostream>
using namespace std;

class bank
{
private:
    string accName;
    int A_id;
    float balance;

public:
    bank()
    {
        A_id = 0;
        balance = 0;
    }

    bank(int id, string name, float initialBalance)
    {
        A_id = id;
        accName = name;
        balance = initialBalance;
    }

    void deposit(float amount)
    {
        if(amount <= 0)
        {
            cout << "Invalid deposit amount\n";
        }
        else
        {
            balance += amount;
            cout << "Deposit successful. New Balance: " << balance << endl;
        }
    }

    void withdraw(float amount)
    {
        if(amount <= 0)
        {
            cout << "Invalid withdrawal amount\n";
        }
        else if(amount > balance)
        {
            cout << "Insufficient balance\n";
        }
        else
        {
            balance -= amount;
            cout << "Withdrawal successful. Remaining Balance: " << balance << endl;
        }
    }

    void applyInterest(float rate)
    {
        if(rate > 0)
        {
            balance += balance * rate / 100;
            cout << "Interest applied. New Balance: " << balance << endl;
        }
    }

    void display()
    {
        cout << "\nAccount ID: " << A_id;
        cout << "\nCustomer Name: " << accName;
        cout << "\nCurrent Balance: " << balance << endl;
    }
};

int main()
{
    bank b[3];

    int id;
    string name;
    float bal;

    for(int i=0;i<3;i++)
    {
        cout<<"\nEnter Account ID: ";
        cin>>id;

        cout<<"Enter Name: ";
        cin>>name;

        cout<<"Enter Initial Balance: ";
        cin>>bal;

        b[i] = bank(id,name,bal);
    }

    int accChoice;
    int choice;
    float amount;
    float rate;

    while(true)
    {
        cout<<"\nSelect Account (1-3): ";
        cin>>accChoice;

        if(accChoice < 1 || accChoice > 3)
        {
            cout<<"Invalid account selection\n";
            continue;
        }

        cout<<"\n1. Deposit";
        cout<<"\n2. Withdraw";
        cout<<"\n3. Display";
        cout<<"\n4. Apply Interest";
        cout<<"\n0. Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter deposit amount: ";
                cin>>amount;
                b[accChoice-1].deposit(amount);
                break;

            case 2:
                cout<<"Enter withdrawal amount: ";
                cin>>amount;
                b[accChoice-1].withdraw(amount);
                break;

            case 3:
                b[accChoice-1].display();
                break;

            case 4:
                cout<<"Enter interest rate (%): ";
                cin>>rate;
                b[accChoice-1].applyInterest(rate);
                break;

            case 0:
                cout<<"Exiting...\n";
                return 0;

            default:
                cout<<"Invalid choice\n";
        }
    }

    return 0;
}