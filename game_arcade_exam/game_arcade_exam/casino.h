#pragma once

#include "iostream"
#include "guestClass.h"
#include "string"
#include "vector"

#include "fortuneWheel.h"
#include "slots.h"
#include "guessTheNum.h"
#include "shop.h"

using namespace std;

class Casino {
private:
    // заготовлені об'єкти ігор та магазу
    FortuneWheel FW;
    Slots Slots;
    GuessTheNum GTN;
    Shop Shop;

    Guest currentGuest;
    vector<Guest> guestList;

    // перевіряємо чи гість є у списку
    bool checkIfGuestExists(string name) {
        for (Guest guest : guestList) {
            if (guest.getGuestName() == name) {
                return true;
            }
        }
        return false;
    }
    // знаходим гостя за індексом
    int findGuestInList(string name) {
        int i = 0;
        for (Guest guest : guestList) {
            if (guest.getGuestName() == name) {
                return i;
            }
            i++;
        }
    }
    // знаходим гостя за індексом
    Guest getGuestFromList(string name) {
        int i = 0;
        for (Guest guest : guestList) {
            if (guest.getGuestName() == name) {
                return guest;
            }
            i++;
        }
    }
    // методи для вибору дій
    void FWaction() {
        cout << "Choose Fortune Wheel action:" << endl
            << "1) Get info" << endl
            << "2) Start" << endl
            << "3) Back" << endl
            << "Your choice: " << endl;
        do {
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
                FW.gameInfo();
                FWaction();
            case 2:
                FW.spinWheel(currentGuest);
                updateGuest(currentGuest);
                FWaction();
            case 3:
                chooseGameAction();
            default:
                cout << "Choice wasn't correct. Try again: ";
                continue;
            }
        } while (true);
    }
    void SLOTSaction() {
        cout << "Choose Slots action:" << endl
            << "1) Get info" << endl
            << "2) Start" << endl
            << "3) Back" << endl
            << "Your choice: " << endl;
        do {
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
                Slots.gameInfo();
                SLOTSaction();
            case 2:
                Slots.spinSlots(currentGuest);
                updateGuest(currentGuest);
                SLOTSaction();
            case 3:
                chooseGameAction();
            default:
                cout << "Choice wasn't correct. Try again: ";
                continue;
            }
        } while (true);
    }
    void GTNaction() {
        cout << "Choose Guess the number action:" << endl
            << "1) Get info" << endl
            << "2) Start" << endl
            << "3) Back" << endl
            << "Your choice: " << endl;
        do {
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
                GTN.gameInfo();
                GTNaction();
            case 2:
                GTN.startGame(currentGuest);
                updateGuest(currentGuest);
                GTNaction();
            case 3:
                chooseGameAction();
            default:
                cout << "Choice wasn't correct. Try again: ";
                continue;
            }
        } while (true);
    }
    void SHOPaction() {
        cout << "Choose Shop action:" << endl
            << "1) Get info" << endl
            << "2) Buy x2" << endl
            << "3) Buy x4" << endl
            << "4) Back" << endl
            << "Your choice: " << endl;
        do {
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
                Shop.shopInfo();
                SHOPaction();
            case 2:
                Shop.buyX2(currentGuest);
                updateGuest(currentGuest);
                SHOPaction();
            case 3:
                Shop.buyX4(currentGuest);
                updateGuest(currentGuest);
                SHOPaction();
            case 4:
                chooseAction();
            default:
                cout << "Choice wasn't correct. Try again: ";
                continue;
            }
        } while (true);
    }

    void chooseSettingsAction() {
        cout << "Choose an game action:" << endl
            << "1) Add new guest" << endl
            << "2) Delete guest" << endl
            << "3) Get casino guests" << endl
            << "4) Back" << endl
            << "Your choice: " << endl;
        do {
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
                addNewGuest();
                chooseSettingsAction();
            case 2:
                delGuest();
                chooseSettingsAction();
            case 3:
                getGuestsList();
                chooseSettingsAction();
            case 4:
                chooseAction();
            default:
                cout << "Choice wasn't correct. Try again: ";
                continue;
            }
        } while (true);
    }
    void chooseGameAction() {
        cout << "Choose an game action:" << endl
            << "1) Fortune wheel" << endl
            << "2) Slots" << endl
            << "3) Guess the number" << endl
            << "4) Back" << endl
            << "Your choice: " << endl;
        do {
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
                FWaction();
            case 2:
                SLOTSaction();
            case 3:
                GTNaction();
            case 4:
                chooseAction();
            default:
                cout << "Choice wasn't correct. Try again: ";
                continue;
            }
        } while (true);
    }
    void chooseCurrentGuestSettings() {
        cout << "Choose currenct guest action:" << endl
            << "1) Get current guest info" << endl
            << "2) Convert cash in chips" << endl
            << "3) Convert chips in cash" << endl
            << "4) Back" << endl
            << "Your choice: " << endl;
        do {
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
                currentGuest.getGuestData();
                chooseCurrentGuestSettings();
            case 2:
                currentGuest.convertCash();
                chooseCurrentGuestSettings();
            case 3:
                currentGuest.convertChips();
                chooseCurrentGuestSettings();
            case 4:
                chooseAction();
            default:
                cout << "Choice wasn't correct. Try again: ";
                continue;
            }
        } while (true);
    }

    void chooseAction() {
        cout << "Choose an action:" << endl
            << "1) Change guest" << endl
            << "2) Current guest settings" << endl
            << "3) Casino settings" << endl
            << "4) Play" << endl
            << "5) Shop" << endl
            << "Your choice: ";
        do {
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
                changeGuest();
                chooseAction();
            case 2:
                chooseCurrentGuestSettings();
                chooseAction();
            case 3:
                chooseSettingsAction();
            case 4:
                chooseGameAction();
            case 5:
                SHOPaction();
            default:
                cout << "Choice wasn't correct. Try again: ";
                continue;
            }
        } while (true);
    }
public:
    Casino() {
        // base guests
        guestList.push_back({ "John" });
        guestList.push_back({ "Joe" });
        guestList.push_back({ "Josh" });
    }
    void getGuestsList() {
        for (int i = 0;i < guestList.size();i++) {
            guestList[i].getGuestData();
        }
    }
    // додаєм гостя
    void addNewGuest() {
        string new_name;
        do {
            string name;
            cout << "Input guest name: ";
            cin.ignore(256, '\n');
            getline(cin, name);
            if (!checkIfGuestExists(new_name)) {
                new_name = name;
                break;
            }
            else {
                cout << "Guest with this name already exists. Try again:" << endl;
                continue;
            }
        } while (true);
        string new_password;
        do {
            string password;
            cout << "Input guest passwrod: ";
            cin >> password;
            if (password.length() >= 4) {
                new_password = password;
                break;
            }
            else {
                cout << "Password is too small. Try again" << endl;
                continue;
            }
        } while (true);
        guestList.push_back({ new_name, new_password });
    }
    // видаляєм гостя
    bool delGuest() {
        string name;
        cout << "Input guest name: ";
        cin.ignore(256, '\n');
        getline(cin, name);
        if (!checkIfGuestExists(name)) {
            cout << "Guest with this name doesn`t exist. Try again:" << endl;
            delGuest();
            return 0;
        }
        int index = findGuestInList(name);
        guestList.erase(guestList.begin() + index);
        return 0;
    }
    // апдейтим гостя зі списку
    void updateGuest(Guest update_guest) {
        int index = findGuestInList(update_guest.getGuestName());
        this->guestList[index] = update_guest;
    }
    // вибираєм гостя за якого будем грати
    void changeGuest() {
        Guest guest_to_choose;
        do {
            string name;
            cout << "Input guest name: ";
            cin.ignore(256, '\n');
            getline(cin, name);
            if (checkIfGuestExists(name)) {
                guest_to_choose = getGuestFromList(name);
                break;
            }
            else { 
                cout << "Guest with this name doesn`t exist. Try again" << endl;
                continue;
            }
        } while (true);

        do {
            string password;
            cout << "Input guest passwrod: ";
            cin >> password;
            if (guest_to_choose.password == password) {
                currentGuest = guest_to_choose;
                break;
            }
            else { 
                cout << "Password is incorrect. Try again" << endl;
                continue;
            }
        } while (true);
    }
    // стартуєм
    void startCasino() {
        cout << "Choose action to set you first guest" << endl
            << "1) Change guest (for existing ones)" << endl
            << "2) Add new guest and choose him later" << endl
            << "Your choice: ";
        do {
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
                getGuestsList();
                changeGuest();
                chooseAction();
            case 2:
                addNewGuest();
                chooseAction();
            default:
                cout << "Choice wasn't correct. Try again: ";
                continue;
            }
        } while (true);
    }
};