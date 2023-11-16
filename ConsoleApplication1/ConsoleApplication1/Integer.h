#pragma once
#include "Number.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class Integer :
    public Number
{
private:
    int num;
public:
    Integer(int user_bid) {
        this->num = user_bid;
    }
    void calcNum() override {
        int random_num = rand() % 50 + -50;
        cout << "You got: " << random_num << endl;
        num += random_num;
        cout << "Your points now: " << num << endl << endl;
    }
    void getNum() override {
        cout << endl << "Your points: " << num << endl << endl;
    }
};

