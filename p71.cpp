#include<iostream>
using namespace std;

class Calculator {
    float result[20];
    int i = 0;

public:
    int add(int a, int b, int c, int d) {
        result[i++] = a + b + c + d;
        return a + b + c + d;
    }

    float add(float a, float b) {
        result[i++] = a + b;
        return a + b;
    }

    float add(float a, float b, float c) {
        result[i++] = a + b + c;
        return a + b + c;
    }

    int subtract(int a, int b) {
        result[i++] = a - b;
        return a - b;
    }

    float subtract(float a, float b) {
        result[i++] = a - b;
        return a - b;
    }

    int multiply(int a, int b) {
        result[i++] = a * b;
        return a * b;
    }

    float multiply(float a, float b) {
        result[i++] = a * b;
        return a * b;
    }

    float divide(float a, float b) {
    if (b == 0) {
        cout << "Error: Division by zero not allowed\n";
        return 0;
    }
    float res = a / b;
    result[i++] = res;
    return res;
}

    void displayResults() {
        cout << "\nStored Results:\n";
        for (int j = 0; j < i; j++) {
            cout << result[j] << endl;
        }
    }
};

int main() {
    Calculator f;

    cout << "Add. of 2, 5, 4, 7 : "<< f.add(2, 5, 4, 7) << endl;
    cout << "Add. of 10.5, 2.5, 2.5 : "<< f.add(10.5f, 2.5f,2.5f) << endl;

    cout << "Subtract 10.3, 3 : "<< f.subtract(10.3, 3) << endl;

    cout << "Multiply 4.5, 5 : "<< f.multiply(4.5, 5) << endl;
    cout << "Divide 20.0f, 4.0f : "<< f.divide(20.0f, 4.0f) << endl;

    f.displayResults();

    return 0;
}
