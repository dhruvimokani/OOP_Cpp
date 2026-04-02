#include <iostream>
using namespace std;

class Wallet
{
private:
    int walletID;
    string userName;
    int balance;   

public:
    void setWallet(int id, string name)
    {
        walletID = id;
        userName = name;
        balance = 0;
    }

   
    void loadMoney(int amount)
    {
        balance = balance + amount;
        cout << "Money loaded successfully\n";
    }

  
    void transferMoney(Wallet w, int amount)
    {
        if (balance >= amount)
        {
            balance = balance - amount;
            w.balance = w.balance + amount;
            cout << "Transfer successful\n";
        }
        else
        {
            cout << "Error: Insufficient balance\n";
        }
    }

    
    void display()
    {
        cout << "\nWallet ID: " << walletID;
        cout << "\nUser Name: " << userName;
        cout << "\nBalance: " << balance << endl;
    }
};

int main()
{
    Wallet w1, w2;

    w1.setWallet(101, "Dhruvi");
    w2.setWallet(102, "Aarya");

    w1.loadMoney(1000);
    w1.transferMoney(w2, 400);

    w1.display();
    w2.display();

    return 0;
}
