#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Employee : public Person {
protected:
    int empID;

public:
    Employee(string n, int a, int id) : Person(n, a) {
        empID = id;
    }

    void displayEmployee() {
        displayPerson();
        cout << "Employee ID: " << empID << endl;
    }
};

class Manager : public Employee {
private:
    string department;

public:
    Manager(string n, int a, int id, string dept)
        : Employee(n, a, id) {
        department = dept;
    }

    void updateDepartment(string newDept) {
        department = newDept;
    }
    string getDepartment() {
    return department;
}
    void displayManager() {
        displayEmployee();
        cout << "Department: " << department << endl;
    }
};

class AssistantManager : public Manager {
private:
    string role;

public:
    AssistantManager(string n, int a, int id, string dept, string r)
        : Manager(n, a, id, dept) {
        role = r;
    }

    void displayAssistantManager() {
        displayManager();
        cout << "Role: " << role << endl;
    }
};

int main() {
    Manager m1("Dhruvi", 18, 1, "CS");
    Manager m2("Vedant", 17, 2, "CIVIL");

    cout << "\nManager 1 Details:\n";
    m1.displayManager();

    cout << "\nManager 2 Details:\n";
    m2.displayManager();

    AssistantManager a1("Vishwa", 17, 3, "CS", "Team Support");

    cout << "\nAssistant Manager Details:\n";
    a1.displayAssistantManager();

    a1.updateDepartment("CIVIL");
    cout << "After Update Dep.."<<endl;
    a1.displayAssistantManager();

string dept;
cout << "\nEnter department to search: ";
cin >> dept;

cout << "\nSearch Results:\n";

if (m1.getDepartment() == dept) {
    m1.displayManager();
}

if (m2.getDepartment() == dept) {
    m2.displayManager();
}

    return 0;
}
