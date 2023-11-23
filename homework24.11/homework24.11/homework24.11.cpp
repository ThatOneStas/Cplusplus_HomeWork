
#include <iostream>
#include "Car.h"
#include "Wheel.h"

using namespace std;

int main()
{
    int diameter;
    string rubber_type;
    cout << "Input wheel diameter (cm): ";
    cin >> diameter;
    cout << "Input wheel type: ";
    cin >> rubber_type;
    Wheel wheel(diameter, rubber_type);
    Car car(wheel);
    cout << endl << "Car's wheel diameter: " << wheel.getDiameter() << " cm;"
        << endl << "Car's wheel type: " << wheel.getRubberType() << endl;
}
