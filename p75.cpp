#include<iostream>
using namespace std;

class Grading {
protected:
    int marks;

public:
    Grading(int m) {
        marks = m;
    }

    virtual void computeGrade() = 0;
};

class Undergraduate : public Grading {
public:
    Undergraduate(int m) : Grading(m) {}

    void computeGrade() {
        if (marks >= 75)
            cout << "Grade: A" << endl;
        else if (marks >= 60)
            cout << "Grade: B" << endl;
        else if (marks >= 50)
            cout << "Grade: C" << endl;
        else
            cout << "Grade: Fail" << endl;
    }
};

class Postgraduate : public Grading {
public:
    Postgraduate(int m) : Grading(m) {}

    void computeGrade() {
        if (marks >= 80)
            cout << "Grade: A" << endl;
        else if (marks >= 65)
            cout << "Grade: B" << endl;
        else if (marks >= 55)
            cout << "Grade: C" << endl;
        else
            cout << "Grade: Fail" << endl;
    }
};

int main() {
    Grading* g;
int m1,m2;
    cout<<"Enter Marks of UnderGraduation:";
    cin>>m1;
    Undergraduate u1(m1);
    cout<<"Enter Marks of PostGraduation:";
    cin>>m2;
    Postgraduate p1(m2);

    cout << "Undergraduate Result:\n";
    g = &u1;
    g->computeGrade();

    cout << "\nPostgraduate Result:\n";
    g = &p1;
    g->computeGrade();

    return 0;
}
