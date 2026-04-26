#include<iostream>
#include<iomanip>
using namespace std;

ostream& currency(ostream& out)
{
    out<<"Rs. ";
    return out;
}

int main()
{
    string name[3] = {"Amit","Neha","Rahul"};
    float marks1[3] = {85.5, 90.0, 78.25};
    float marks2[3] = {88.0, 76.5, 82.0};
    float fees[3] = {25000.5, 26000.75, 24000.25};

    cout<<setfill('*')<<setw(75)<<"*"<<endl;

    cout<<setfill(' ');
    cout<<left<<setw(15)<<"Name"
        <<right<<setw(10)<<"M1"
        <<setw(10)<<"M2"
        <<setw(15)<<"Percentage"
        <<setw(15)<<"Fees"<<endl;

    cout<<setfill('-')<<setw(75)<<"-"<<endl;
    cout<<setfill(' ');

    for(int i=0;i<3;i++)
    {
        float percent = (marks1[i] + marks2[i]) / 2;

        cout<<left<<setw(15)<<name[i]
            <<right<<setw(10)<<fixed<<setprecision(2)<<marks1[i]
            <<setw(10)<<marks2[i]
            <<setw(15)<<percent;

        cout<<setw(5)<<currency<<setw(10)<<fees[i]<<endl;
    }

    cout<<setfill('*')<<setw(75)<<"*"<<endl;

    return 0;
}
