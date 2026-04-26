#include <iostream>
using namespace std;

class Account {
protected:
    int accNo;
    float balance;
    float lastTransaction;

public:
    Account(int a, float b) {
        accNo = a;
        balance = b;
        lastTransaction = 0;
    }

    void deposit(float amount) {
        balance += amount;
        lastTransaction = amount;
    }

    void withdraw(float amount) {
        balance -= amount;
        lastTransaction = -amount;
    }

    void undoTransaction() {
        balance -= lastTransaction;
        lastTransaction = 0;
    }

    void display() {
        cout << "Account No: " << accNo << endl;
        cout << "Balance: " << balance << endl;
    }

    ~Account() {
        cout << "Account Closed\n";
    }
};

class SavingsAccount : public Account {
private:
    float interestRate;

public:
    SavingsAccount(int a, float b, float r)
        : Account(a, b) {
        interestRate = r;
    }

    void displaySavings() {
        display();
        cout << "Interest Rate: " << interestRate << endl;
    }
};

class CurrentAccount : public Account {
private:
    float overdraftLimit;

public:
    CurrentAccount(int a, float b, float limit)
        : Account(a, b) {
        overdraftLimit = limit;
    }

    void withdraw(float amount) {
        if (balance - amount >= -overdraftLimit) {
            balance -= amount;
            lastTransaction = -amount;
        } else {
            cout << "Overdraft limit exceeded\n";
        }
    }

    void displayCurrent() {
        display();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main() {
    SavingsAccount s1(1, 1000, 5);
    CurrentAccount c1(2, 2000, 500);



    cout << "Savings Account:\n";
    s1.displaySavings();
    cout<<"\nDeposit 500 and withdrawing 200"<<endl;
    s1.deposit(500);
    s1.withdraw(200);
    s1.displaySavings();

    cout << "\nUndo Last Transaction\n";
    s1.undoTransaction();
    s1.displaySavings();

    cout << "\nCurrent Account:\n";

    c1.displayCurrent();

    return 0;
}
