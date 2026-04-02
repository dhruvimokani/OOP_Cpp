#include <iostream>
using namespace std;

// Display array
template <class T>
void display(T arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Find maximum
template <class T>
T findMax(T arr[], int size) {
    T max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Reverse array
template <class T>
void reverseArray(T arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        T temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

// Find leader elements
template <class T>
void leaders(T arr[], int size) {
    T leader = arr[size - 1];
    cout << "Leader elements: " << leader << " ";

    for (int i = size - 2; i >= 0; i--) {
        if (arr[i] > leader) {
            leader = arr[i];
            cout << leader << " ";
        }
    }
    cout << endl;
}

int main() {
    int intArr[] = {16, 17, 4, 3, 5, 2};
    float floatArr[] = {1.1, 5.5, 2.2, 6.6, 3.3};
    char charArr[] = {'a', 'z', 'b', 'y', 'c'};

    int size1 = 6, size2 = 5, size3 = 5;

    // Integer array
    cout << "Integer Array: ";
    display(intArr, size1);
    cout << "Maximum: " << findMax(intArr, size1) << endl;
    leaders(intArr, size1);
    reverseArray(intArr, size1);
    cout << "Reversed: ";
    display(intArr, size1);

    cout << endl;

    // Float array
    cout << "Float Array: ";
    display(floatArr, size2);
    cout << "Maximum: " << findMax(floatArr, size2) << endl;
    leaders(floatArr, size2);
    reverseArray(floatArr, size2);
    cout << "Reversed: ";
    display(floatArr, size2);

    cout << endl;

    // Character array
    cout << "Character Array: ";
    display(charArr, size3);
    cout << "Maximum: " << findMax(charArr, size3) << endl;
    leaders(charArr, size3);
    reverseArray(charArr, size3);
    cout << "Reversed: ";
    display(charArr, size3);

    return 0;
}
