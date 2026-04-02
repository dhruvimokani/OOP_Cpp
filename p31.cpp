#include<iostream>
using namespace std;

class employee{
string name;
double basicSalary;
double bonusAmount;

public:
employee()
{
    name=" ";
    basicSalary=0.0;
    bonusAmount=0.0;
}

employee(string n,double bs,double bonus=1000.0)
{
    name=n;

    if(bs < 0)
    {
        cout<<"Invalid salary! Setting to 0\n";
        basicSalary=0;
    }
    else
    {
        basicSalary=bs;
    }

    bonusAmount=bonus;
}

inline double totalSalary()
{
    return basicSalary+bonusAmount;
}

string getGrade()
{
    double ts = totalSalary();

    if(ts >= 50000)
        return "A";
    else if(ts >= 30000)
        return "B";
    else
        return "C";
}

void updateBonus(double newBonus)
{
    if(newBonus >= 0)
        bonusAmount = newBonus;
    else
        cout<<"Invalid bonus!\n";
}

void display()
{
    cout<<"Name: "<<name<<endl;
    cout<<"Basic Salary: "<<basicSalary<<endl;
    cout<<"Bonus Amount: "<<bonusAmount<<endl;
    cout<<"Total Salary: "<<totalSalary()<<endl;
    cout<<"Grade: "<<getGrade()<<endl;
}
};

int main()
{
employee e[2];
string n;
double bs;
double bonus;
int ch;

for(int i=0; i<2; i++)
{
    cout<<"Enter Employee Name:";
    cin>>n;

    cout<<"\nEnter Employee Basic Salary:";
    cin>>bs;

    cout<<"\nPress 1 for customized bonus: ";
    cin>>ch;

    if(ch==1)
    {
        cout<<"\nEnter Employee Bonus Amount:";
        cin>>bonus;
        e[i]=employee(n,bs,bonus);
    }
    else
    {
        e[i]=employee(n,bs);
    }
}

// Display
for(int i=0;i<2;i++)
{
    e[i].display();
}

// Example: Update bonus
cout<<"\nUpdating bonus of first employee...\n";
e[0].updateBonus(2000);
e[0].display();

}
