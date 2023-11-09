#pragma once
#include <iostream>
#include "Vehicle.h"
using namespace std;
class Motorcycle :
    public Vehicle
{
private:
    int points;
public:
    Motorcycle()  : Vehicle() { this->points = 0; }
    void startEngine() override {
        Vehicle::startEngine();
        doAStunt();
    }
    void doAStunt()  {
        string choice;
        cout << "Do u want to do a stunt? (y/n)" << endl;
        cin >> choice;
        if(choice=="y"){
            this->points += 20;
            cout << "You did the stunt +20 points.";
        }
    }
    void getPoints() {
        cout << "Your points: " << points << endl;
    }
};

