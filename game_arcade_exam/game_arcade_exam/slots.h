#pragma once

#include "iostream"
#include "additional.h"
#include <fcntl.h>

using namespace std;

class Slots : public Game {
private:
	string getRandItem() {
		int rand_num = rand_int(1, 12);
		if (rand_num == 1) {
			return "7";
		}
		else if (rand_num > 1 && rand_num <= 3) {
			return "$";
		}
		else if (rand_num > 3 && rand_num <= 7) {
			return "&";
		}
		else if (rand_num > 7 && rand_num <= 12) {
			return "J";
		}
	}
public:
	void gameInfo() override {
		cout << "========================info========================" << endl;
		cout << "Slots. It's a game where 3 slots are being spun together." << endl <<
			"There are 4 different items you can get:" << endl <<
			// не проходить ♠ ♥ ♣ ♦ :(
			"> J (Pik) - 40%" << endl <<
			"> & (Hearts) - 30%" << endl <<
			"> $ (Clubs) - 20%" << endl <<
			"> 7 (Diamonds) - 10%" << endl <<
			"You get one of these items randomly." << endl <<
			"> If you get x3 J (Pik) you get: x1" << endl <<
			"> If you get x3 & (Hearts)  you get: x1.5" << endl <<
			"> If you get x3 $ (Clubs) you get: x2" << endl <<
			"> If you get x3 7 (Diamonds) you get: x5" << endl <<
			"> If you get only 2 identical items, you get a x0.5 of their x3 prize (x2 -> x1)" << endl <<
			"But if you get 3 different you get x0.25" << endl;
		cout << "========================info========================" << endl;
	}
	void spinSlots(Guest& guest) {
		cout << "========================casino========================" << endl;
		// копіюємо рахунок
		tuple<int, int> guest_balance_copy = guest.money$chip;
		// отримаємо суму для ставки
		int user_chips = Game::getUserAmountOfChips(guest);
		get<1>(guest_balance_copy) -= user_chips;
		// розраховуємо шанси
		string slot_1 = getRandItem();
		string slot_2 = getRandItem();
		string slot_3 = getRandItem();
		if (slot_1 == slot_2 && slot_2 == slot_3) {
			if (slot_1 == "7") {
				user_chips *= 5;
			}
			else if (slot_1 == "$") {
				user_chips *= 2;
			}
			else if (slot_1 == "&") {
				user_chips *= 1.5;
			}
			else if (slot_1 == "J") {
				user_chips *= 1;
			}
		}
		else if (slot_1 == slot_2) {
			if (slot_1 == "7") {
				user_chips *= 2.5;
			}
			else if (slot_1 == "$") {
				user_chips *= 1;
			}
			else if (slot_1 == "&") {
				user_chips *= 0.75;
			}
			else if (slot_1 == "J") {
				user_chips *= 0.5;
			}
		}
		else if (slot_2 == slot_3) {
			if (slot_2 == "7") {
				user_chips *= 2.5;
			}
			else if (slot_2 == "$") {
				user_chips *= 1;
			}
			else if (slot_2 == "&") {
				user_chips *= 0.75;
			}
			else if (slot_2 == "J") {
				user_chips *= 0.5;
			}
		}
		else if (slot_1 == slot_3) {
			if (slot_1 == "7" || slot_2 == "7") {
				user_chips *= 2.5;
			}
			else if (slot_1 == "$") {
				user_chips *= 1;
			}
			else if (slot_1 == "&") {
				user_chips *= 0.75;
			}
			else if (slot_1 == "J") {
				user_chips *= 0.5;
			}
		}
		else {
			user_chips *= 0.25;
		}
		cout << "You got: " << "[| " << slot_1 << " | " << slot_2 << " | " << slot_3 << " |]" << endl;
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