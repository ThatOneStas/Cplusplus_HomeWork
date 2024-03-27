#pragma once

#include "iostream"
#include "guestClass.h"
#include <ctime>

using namespace std;

class Guest;

static int rand_int(int lowerLimit, int upperLimit) {
    return (rand() % (upperLimit - lowerLimit + 1) + lowerLimit);
}

class invalid_number_input {
private:
    string error_msg;
public:
    invalid_number_input(string err_msg) : error_msg(err_msg.c_str()) {}
    const char* what() {
        return error_msg.c_str();
    }
};

class Game {
protected:
    // вибір складності
    int chooseDifficulty() {
        do {
            int mode;
            cout << "Choose difficulty:" << endl;
            cout << "1 - Easy, 2 - Medium, 3 - Hard: ";
            cin >> mode;
            if (mode == 1 || mode == 2 || mode == 3) {
                return mode;
            }
            else
            {
                cout << "Your number wasn`t correct. Try again:\n";
            }
        } while (true);
        /*try {
            if (mode >= 1 && mode <= 3) {
                return mode;
            }
            else {
                throw invalid_argument("Your number wasn`t correct. Try again:");
            }
        }
        catch (const invalid_argument error) {
            cout << error.what() << endl;
            chooseDifficulty();
        }*/
    }
    // отримуємо фішки гостя, які він хоче поставити
    int getUserAmountOfChips(Guest guest) {
        int user_chips;
        do {
            cout << "Input amount of chips to put: ";
            cin >> user_chips;

            if (user_chips <= guest.getMoneyOrChip(1)) {
                return user_chips;
            }
            else
            {
                cout << "Your chips' amount was bigger than expected. Try again:\n";
            }
        } while (true);
        /*try {
            if (user_chips <= guest.getMoneyOrChip(1)) {
                return user_chips;
            }
            else {
                throw invalid_number_input("Your chips' amount was bigger than expected. Try again:");
            }
        }
        catch (invalid_number_input& error) {
            cout << error.what() << endl;
            getUserAmountOfChips(guest);
        }*/
    }
    // перевіряємо чи є у гостя бонус х2 чи х4, якщо нема то х1
    int checkIfUserHasX2X4(Guest guest) {
        if (guest.getUserX4()) {
            cout << "Your bonus: x4" << endl;
            return 4;
        }
        else if (guest.getUserX2()) {
            cout << "Your bonus: x2" << endl;
            return 2;
        }
        else
        {
            return 1;
        }
    }
public:
    virtual void gameInfo()  {
        cout << "Game template." << endl;
    }
};