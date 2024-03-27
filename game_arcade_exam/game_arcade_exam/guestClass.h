#pragma once

#include "iostream"
//#include "additional.h"
//#include "fortuneWheel.h"
#include <tuple>

using namespace std;

class Guest {
private:
    string name;
    string password;
    tuple<int, int> money$chip;
    // 0 - cash (cash to chip: 5>1)
    // 1 - chips (chip to cash: 1>5)
    bool x2nextGame;
    bool x4nextGame;
    // отримуємо фішки
    int chipsToCONV() {
        int quantity;
        cout << "Input quant. of chips to convert( 1 > 5 ): ";
        cin >> quantity;
        return quantity;
    }
    // отримуємо гроші
    int cashToCONV() {
        int quantity;
        cout << "Input quant. of cash to convert( 5 > 1 ): ";
        cin >> quantity;
        return quantity;
    }
public:
    friend class FortuneWheel;
    friend class Slots;
    friend class GuessTheNum;
    friend class Shop;
    friend class Casino;

    Guest() {}
    Guest(string name, string password) : name(name), password(password), x2nextGame(false), x4nextGame(false) {
        get<0>(money$chip) = 100;
        get<1>(money$chip) = 20;
    }
    Guest(string name) : name(name), password("1234"), x2nextGame(false), x4nextGame(false) {
        get<0>(money$chip) = 100;
        get<1>(money$chip) = 20;
    }
    // конвертуємо фішки у гроші за опреділеним курсом
    void convertChips() {
        int quantity = chipsToCONV();
        if (quantity > get<1>(money$chip)) {
            cout << "You don`t have enough chips to convert. You got: " << get<1>(money$chip) << endl;
            convertChips();
        }
        else {
            get<0>(money$chip) += quantity * 5;
            get<1>(money$chip) -= quantity;
        }
    }
    // конвертуємо гроші у фішки за опреділеним курсом
    void convertCash() {
        int quantity = cashToCONV();
        if (quantity > get<0>(money$chip)) {
            cout << "You don`t have enough cash to convert. You got: " << get<0>(money$chip) << endl;
            convertCash();
        }
        else {
            get<1>(money$chip) += quantity / 5;
            get<0>(money$chip) -= quantity;
        }
    }
    // данні користувача
    void getGuestData() {
        cout << "Guest name: " << name << endl;
        cout << "- Money: " << get<0>(money$chip) << endl;
        cout << "- Chips: " << get<1>(money$chip) << endl;
    }
    // нижче прописанні методи для отримання даних, де не використовується дружність
    string getGuestName() {
        return name;
    }
    int getMoneyOrChip(int zeroORone) {
        return (zeroORone == 0) ? get<0>(money$chip) : get<1>(money$chip);
    }
    int getUserX2() {
        return x2nextGame;
    }
    int getUserX4() {
        return x4nextGame;
    }
};