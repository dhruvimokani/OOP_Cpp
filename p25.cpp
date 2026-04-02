
#include<iostream>
#include<math.h>
using namespace std;

class Loan {

int LoanID;
string ApplicantName;
double TotalLoanAmount;
float AnnualInterestRate;
int LoanTenure;
public:
 Loan() {
        LoanID = 0;
        ApplicantName = "";
        TotalLoanAmount = 0.0;
        AnnualInterestRate = 0.0;
        LoanTenure = 0;
    }

    Loan(int id, string name, double amount, float interest, int tenure) {
        LoanID = id;
        ApplicantName = name;
        TotalLoanAmount = amount;
        AnnualInterestRate = interest;
        LoanTenure = tenure;
    }

    double calculateEMI(){
        double monthlyInterestRate = AnnualInterestRate / 1200;
        double emi = (TotalLoanAmount * monthlyInterestRate * pow(1 + monthlyInterestRate, LoanTenure)) / (pow(1 + monthlyInterestRate, LoanTenure) - 1);
        return emi;
    }

    void displayLoan() {
        cout << "Loan ID: " << LoanID << endl;
        cout << "Applicant Name: " << ApplicantName << endl;
        cout << "Total Loan Amount: " << TotalLoanAmount << endl;
        cout << "Annual Interest Rate: " << AnnualInterestRate << "%" << endl;
        cout << "Loan Tenure: " << LoanTenure << " months" << endl;
        cout << "EMI: " << calculateEMI() << endl;
    }
};


int main() {
int n;

cout << "Enter the number of Loans: ";
cin >> n;

Loan loans[n];
 int id;
    string name;
    double amount;
    float interest;
    int tenure;

for (int i = 0; i < n; i++) {
   
    cout << "Enter Loan ID: ";
    cin >> id;
    cout << "Enter Applicant Name: ";
    cin >> name;
    cout << "Enter Total Loan Amount: ";
    cin >> amount;
    cout << "Enter Annual Interest Rate: ";
    cin >> interest;
    cout << "Enter Loan Tenure (in months): ";
    cin >> tenure;

    loans[i] = Loan(id, name, amount, interest, tenure);
    loans[i].displayLoan();
}
   
   

    return 0;
}