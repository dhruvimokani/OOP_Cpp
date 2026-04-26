#include<iostream>
using namespace std;

class shape {
public:
    virtual double Area() = 0;
};

class Rectangle : public shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double Area() {
        return length * width;
    }
};

class Circle : public shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double Area() {
        return 3.14 * radius * radius;
    }
};

int main() {
    shape* s;

    Rectangle R1(5.5, 5.0);
    Circle C1(5.0);

    s = &R1;
    cout << "Rectangle Area: " << s->Area() << endl;

    s = &C1;
    cout << "Circle Area: " << s->Area() << endl;

    return 0;
}
