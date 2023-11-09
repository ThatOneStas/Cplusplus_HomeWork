#pragma once
#include <iostream>
#include "Vehicle.h"
class Car :
    public Vehicle
{
private:

public:
    Car() : Vehicle(){}
    void startEngine() override {
        Vehicle::startEngine();
        afterStartAction();
    }
    void afterStartAction() {
        int choice;
        cout << "What do u want to do?" << endl << "(1. go to the park, 2. go shopping)" << endl;
        cin >> choice;
        if (choice == 1) {
            cout << "You went to the park.." << endl << "..you had a great time there." << endl;
        }
        else if (choice == 2) {
            cout << "You went shopping.." << endl << "..you bought jojo hoodie." << endl;
        }
        else {
            cout << "error 418" << endl;
        }
    }
};

