#pragma once

#include "iostream"
#include "additional.h"

using namespace std;


class Shop {
public:
	void shopInfo() {
		cout << "========================info========================" << endl;
		cout << "Shop is a place where you can buy bonuses for your money." << endl <<
			"Avaible bonuses:" << endl <<
			"> X2 next game - 100$" << endl <<
			"> X4 next game - 200$" << endl;
		cout << "========================info========================" << endl;
	}
	void buyX2(Guest& guest) {
		cout << "========================shop========================" << endl;
		// копіюємо рахунок
		tuple<int, int> guest_balance_copy = guest.money$chip;
		// перевіряємо чи гість має достатньо грошей та чи він володіє бонусом
		if (guest.x2nextGame == true) {
			cout << "- You already own the x2 bonus" << endl;
		}
		else if (get<0>(guest_balance_copy) >= 100) {
			get<0>(guest_balance_copy) -= 100;
			guest.x2nextGame = true;
			cout << "- x2 bonus successfuly was bought" << endl;
			// оновлюємо рахунок
			guest.money$chip = guest_balance_copy;
			cout << "- Your money now: " << get<0>(guest_balance_copy) << endl;
		}
		else {
			cout << "- You don't have enough money" << endl;
			cout << "- Your money now: " << get<0>(guest_balance_copy) << endl;
			cout << "- Required money: 100" << endl;
		}
		cout << "========================shop========================" << endl;
	}
	void buyX4(Guest& guest) {
		cout << "========================shop========================" << endl;
		// копіюємо рахунок
		tuple<int, int> guest_balance_copy = guest.money$chip;
		// перевіряємо чи гість має достатньо грошей та чи він володіє бонусом
		if (guest.x4nextGame == true) {
			cout << "- You already own the x4 bonus" << endl;
		}
		else if (get<0>(guest_balance_copy) >= 200) {
			get<0>(guest_balance_copy) -= 200;
			guest.x4nextGame = true;
			cout << "- x4 bonus successfuly was bought" << endl;
			// оновлюємо рахунок
			guest.money$chip = guest_balance_copy;
			cout << "- Your money now: " << get<0>(guest_balance_copy) << endl;
		}
		else {
			cout << "- You don't have enough money" << endl;
			cout << "- Your money now: " << get<0>(guest_balance_copy) << endl;
			cout << "- Required money: 200" << endl;
		}
		cout << "========================shop========================" << endl;
	}
};