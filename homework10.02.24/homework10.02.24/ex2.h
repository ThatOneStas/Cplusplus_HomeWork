#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include "funcs.h"

using namespace std;

//template<typename STR>
//class STRexample {
//private:
//    STR item_str;
//public:
//    STRexample(string line) : item_str(line){}
//    STRexample(int) : item_str("default") {}
//    STRexample() : item_str("default") {}
//};

template </*template<typename> typename P,*/ typename T>
class STRcontrol
{
private:
    T item;
public:
    STRcontrol(string line) : item(line){}
    STRcontrol() {}
    void setRandSTR() {
        string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        this->item = "0000000";
        for (int i = 0;i < 8;i++) {
            this->item[i] = alphabet[rand_int(0, 52)];
        }
    }
    void getItemData() {
        cout << item << endl;
    }
    void setItem() {
        string new_line;
        cout << "New string: ";
        cin >> new_line;
        this->item = new_line;
    }
    void findLetter(char letter) {
        if (item.find(letter) != -1) {
            cout << "The letter `" << letter << "` is in `" << item << "`" << endl;
        }
        else {
            cout << "The letter `" << letter << "` is not in `" << item << "`" << endl;
        }
    }
};

void ex2() {
    srand(static_cast<unsigned int>(time(0)));

    STRcontrol<string> item1;
    item1.setRandSTR();
    item1.getItemData();
    item1.findLetter('y');
}