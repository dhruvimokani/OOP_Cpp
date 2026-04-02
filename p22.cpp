#include <iostream>
using namespace std;

class Student
{
private:
    int roll;
    string name;
    int marks[3];   
public:
    
    void getData()
    {
        cout << "Enter roll number: ";
        cin >> roll;

        cout << "Enter name: ";
        cin >> name;

        for (int i = 0; i < 3; i++)
        {
            cout << "Enter marks of subject " << i + 1 << ": ";
            cin >> marks[i];

            if (marks[i] < 0 || marks[i] > 100)
            {
                cout << "Invalid marks, set to 0\n";
                marks[i] = 0;
            }
        }
    }

    float average()
    {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }

    char grade()
    {
        float avg = average();

        if (avg >= 75) return 'A';
        else if (avg >= 60) return 'B';
        else if (avg >= 50) return 'C';
        else return 'F';
    }

    void display()
    {
        cout << "\nRoll No: " << roll;
        cout << "\nName: " << name;
        cout << "\nMarks: ";
        for (int i = 0; i < 3; i++)
        {
            cout << marks[i] << " ";
        }
        cout << "\nAverage: " << average();
        cout << "\nGrade: " << grade() << endl;
    }
};

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student s[10];   

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details of student " << i + 1 << endl;
        s[i].getData();
    }

    cout << "\n----- Student Records -----\n";
    for (int i = 0; i < n; i++)
    {
        s[i].display();
    }

    return 0;
}