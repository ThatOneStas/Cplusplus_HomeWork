#pragma once
#include "Number.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class Real :
    public Number
{
private:
    int num;
public:
    Real(int user_bid) {
        this->num = user_bid;
    }
    void calcNum() override {
        int random_num = rand() % 10 + 1;
        cout << random_num << endl;
        int user_num;
        cout << endl << "Input your number (10 - 1): ";
        cin >> user_num;
        if (user_num == random_num) {
            cout << endl << "You got it! (+100)" << endl;
            num += 100;
            cout << "Your points now: " << num << endl << endl;
        }
        else
        {
            cout << endl << "Better luck next time.. (-25)" << endl;
            num -= 25;
            cout << "Your points now: " << num << endl << endl;
        }
    }
    void getNum() override {
        cout<< endl << "Your points: " << num << endl << endl;
    }
};

