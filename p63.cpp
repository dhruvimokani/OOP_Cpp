#include <iostream>
using namespace std;

class Fuel {
protected:
    string fuelType;

public:
    Fuel(string f) {
        if (f == "Petrol" || f == "Diesel" || f == "Electric" || f == "CNG") {
            fuelType = f;
        } else {
            fuelType = "Petrol";
        }
    }
};

class Brand {
protected:
    string brandName;

public:
    Brand(string b) {
        brandName = b;
    }
};

class ServiceHistory {
protected:
    string lastServiceDate;

public:
    ServiceHistory(string date) {
        lastServiceDate = date;
    }
};

class Car : public Fuel, public Brand, public ServiceHistory {
public:
    Car(string f, string b, string date)
        : Fuel(f), Brand(b), ServiceHistory(date) {}

    void displayCar() {
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Brand Name: " << brandName << endl;
        cout << "Last Service Date: " << lastServiceDate << endl;
    }

    string getFuel() {
        return fuelType;
    }
};

int main() {
    Car c1("Petrol", "Toyota", "10-01-2026");
    Car c2("Electric", "Tesla", "12-02-2026");
    Car c3("CNG", "Hyundai", "15-03-2026");

    Car queue[3] = {c1, c2, c3};

    cout << "\nPriority Service Queue (Electric First):\n";

    for (int i = 0; i < 3; i++) {
        if (queue[i].getFuel() == "Electric") {
            queue[i].displayCar();
            cout << endl;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (queue[i].getFuel() != "Electric") {
            queue[i].displayCar();
            cout << endl;
        }
    }

    return 0;
}
