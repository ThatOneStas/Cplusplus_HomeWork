#pragma once

#include "iostream"
#include "additional.h"

using namespace std;


class FortuneWheel : public Game {
public:
	void gameInfo() override {
		cout << "========================info========================" << endl;
		cout << "Fortune wheel. Wheel of fortune is a simple game of your luck" << endl <<
			"where you can eaily get a lot of money, but also you can easily lose 'em all." << endl <<
			"You just need to input the amount of chips that you want to put." << endl <<
			"Here are your chances:" << endl <<
			"> x100 (JACKPOT) - 1%" << endl <<
			"> x5 - 10%" << endl <<
			"> x2 - 15%" << endl <<
			"> x1.5 - 15%" << endl <<
			"> x1 - 18%" << endl <<
			"> x0.75 - 15%" << endl <<
			"> x0.5 - 15%" << endl <<
			"> x0.2 - 10%" << endl <<
			"> x0.01 (Lose All) - 1%" << endl;
		cout << "========================info========================" << endl;
	}
	void spinWheel(Guest &guest) {
		cout << "========================casino========================" << endl;
		// копіюємо рахунок
		tuple<int, int> guest_balance_copy = guest.money$chip;
		// отримаємо суму для ставки
		int user_chips = Game::getUserAmountOfChips(guest);
		get<1>(guest_balance_copy) -= user_chips;
		// розраховуємо шанси
		int rand_num = rand_int(1, 106);
		if (rand_num == 1) {
			cout << "You got.. nothing.. you lost everything.." << endl;
			user_chips *= 0.01;
		}
		else if (rand_num > 1 && rand_num <= 11) {
			cout << "You got.. x0.2, terrible" << endl;
			user_chips *= 0.2;
		}
		else if (rand_num > 11 && rand_num <= 27) {
			cout << "You got.. x0.5, quite bad" << endl;
			user_chips *= 0.5;
		}
		else if (rand_num > 27 && rand_num <= 43) {
			cout << "You got.. x0.75, quite bad" << endl;
			user_chips *= 0.75;
		}
		else if (rand_num > 43 && rand_num <= 62) {
			cout << "You got.. nothing, x1" << endl;
			user_chips *= 1;
		}
		else if (rand_num > 62 && rand_num <= 78) {
			cout << "You got.. x1.5!" << endl;
			user_chips *= 1.5;
		}
		else if (rand_num > 78 && rand_num <= 94) {
			cout << "You got.. x2!" << endl;
			user_chips *= 2;
		}
		else if (rand_num > 94 && rand_num <= 105) {
			cout << "You got.. x5!" << endl;
			user_chips *= 5;
		}
		else if (rand_num == 106) {
			cout << "You got.. JACKPOT!!!" << endl;
			user_chips *= 100;
		}
		// перевіряємо чи є у гостя бонус х2 чи х4, якщо нема то х1
		int user_bonus = checkIfUserHasX2X4(guest);
		user_chips *= user_bonus;
		switch (user_bonus)
		{
		case 2:
			guest.x2nextGame = false;
		case 4:
			guest.x4nextGame = false;
		default:
			break;
		}
		// оновлюємо рахунок
		get<1>(guest_balance_copy) += user_chips;
		guest.money$chip = guest_balance_copy;
		cout << "- Your chips now: " << get<1>(guest_balance_copy) << endl;
		cout << "========================casino========================" << endl;
	}
};