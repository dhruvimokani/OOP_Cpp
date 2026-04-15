#include <iostream>
#include<math.h>
using namespace std;

class Point {
private:
    int x, y;
    const int LIMIT = 10000;

    void validate() {
        if (x > LIMIT || y > LIMIT || x < -LIMIT || y < -LIMIT) 
        {
            cout << "Overflow detected! Resetting to (0,0)\n";
            x = 0;
            y = 0;
        }
    }

public:

    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    void display() {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    Point& move(int a, int b) {
        this->x += a;
        this->y += b;
        validate();
        return *this;
    }

    double distanceFromOrigin() {
        return sqrt(x * x + y * y);
    }

    void setPosition(int newX, int newY) {
        this->x = newX;
        this->y = newY;
        validate();
    }

    friend void resetPoint(Point* p);
};

void resetPoint(Point* p) {
    p->setPosition(0, 0);
}

int main() {
    Point p(1, 2);

    cout << "Initial Point: ";
    p.display();

    p.move(4, 9).move(-3, 8);

    cout << "After chained move: ";
    p.display();

    cout << "Distance from origin: " << p.distanceFromOrigin() << endl;

    p.setPosition(10, 20);
    cout << "After setting absolute position: ";
    p.display();

    resetPoint(&p);
    cout << "After reset using pointer: ";
    p.display();

    return 0;
}
