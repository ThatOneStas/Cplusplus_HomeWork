#pragma once

#include "iostream"
#include "additional.h"

using namespace std;


class GuessTheNum : public Game {
private:
	int chooseTheNum(int difficulty) {
		do {
			int num;
			cout << "Choose number: ";
			cin >> num;
			if (difficulty == 1 && (num > 0 && num <= 50)){
				return num;
			}
			else if (difficulty == 2 && (num > 0 && num <= 100)) {
				return num;
			}
			else if (difficulty == 3 && (num > 0 && num <= 150)) {
				return num;
			}
			else 
			{
				cout << "Your number was out of range. Try again:\n";
			}
		} while (true);
	}
public:
	void gameInfo() override {
		cout << "========================info========================" << endl;
		cout << "Guess the number, a game where you have to guess the correct number." << endl <<
			"So what's difficult about this? Before you put the amount of money" << endl <<
			"you have to choose difficulty. There are 3 modes of difficulty:" << endl <<
			"> 1) Easy, range 50" << endl <<
			"> 2) Medium, range 100" << endl <<
			"> 3) Hard, range 150" << endl <<
			"And now about how does it work, and what can you get here." << endl <<
			"> For guessing the correct number you`ll get x5, x10, x15 (easy, medium, hard)" << endl <<
			"> Also, in the diapason from +-6 from the correct number, you'll get 1/3 of the main prize (x5 -> x1)" << endl <<
			"> In the diapason from +-2 from the correct number, you'll get 1/2 of the main prize (x5 -> x2.5)" << endl <<
			"> If non of that are right you get 0.25" << endl;
		cout << "========================info========================" << endl;
	}
	void startGame(Guest& guest) {
		cout << "========================casino========================" << endl;
		// копіюємо рахунок
		tuple<int, int> guest_balance_copy = guest.money$chip;
		// вибираємо складність
		int difficulty = chooseDifficulty();
		// отримаємо суму для ставки
		int user_chips = Game::getUserAmountOfChips(guest);
		get<1>(guest_balance_copy) -= user_chips;
		// гра вибираэ число
		int rand_num;
		if (difficulty == 1) {
			rand_num = rand_int(1, 50);
		}
		else if (difficulty == 2) {
			rand_num = rand_int(1, 100);
		}
		else if (difficulty == 3) {
			rand_num = rand_int(1, 150);
		}
		// гість вибирає число
		int guest_num = chooseTheNum(difficulty);
		// розраховуємо шанси
		if (difficulty == 1) {
			if (guest_num == rand_num) {
				user_chips *= 5;
			}
			else if (guest_num >= (rand_num - 2) && guest_num <= (rand_num + 2)) {
				user_chips *= 2;
			}
			else if (guest_num >= (rand_num - 6) && guest_num <= (rand_num + 6)) {
				user_chips *= 1.25;
			}
			else {
				user_chips *= 0.25;
			}
		}
		else if (difficulty == 2) {
			if (guest_num == rand_num) {
				user_chips *= 10;
			}
			else if (guest_num >= (rand_num - 2) && guest_num <= (rand_num + 2)) {
				user_chips *= 3;
			}
			else if (guest_num >= (rand_num - 6) && guest_num <= (rand_num + 6)) {
				user_chips *= 2;
			}
			else {
				user_chips *= 0.25;
			}
		}
		else if (difficulty == 3) {
			if (guest_num == rand_num) {
				user_chips *= 15;
			}
			else if (guest_num >= (rand_num - 2) && guest_num <= (rand_num + 2)) {
				user_chips *= 5;
			}
			else if (guest_num >= (rand_num - 6) && guest_num <= (rand_num + 6)) {
				user_chips *= 3;
			}
			else {
				user_chips *= 0.25;
			}
		}
		cout << "- Your number: " << guest_num << ", correct number: " << rand_num << endl;
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