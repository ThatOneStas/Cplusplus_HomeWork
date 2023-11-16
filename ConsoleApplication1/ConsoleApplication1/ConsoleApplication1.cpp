#include <iostream>
#include "Number.h"
#include "Integer.h"
#include "Real.h"

using namespace std;

int main()
{
	int user_choice;
	cout << "Input task. 1st - Wheel of Fortune, 2nd - Guess the Number." << endl << "( 1 / 2 ): ";
	cin >> user_choice;
	if (user_choice == 1) {
		int user_bid;
		cout << "Input your bid (points): ";
		cin >> user_bid;
		Integer bid = user_bid;
		while (true) {
			string user_choice;
			cout << endl << "Choose action: (Any key to break)" << endl << "- 1) Try your LUCK! (spin), - 2) Show points," << endl << "-->  ";
			cin >> user_choice;
			if (user_choice == "1") {
				bid.calcNum();
				continue;
			}
			if (user_choice == "2") {
				bid.getNum();
			}
			else
			{
				break;
			}
		}
		
	}
	else if (user_choice == 2) {
		int user_bid;
		cout << "Input your bid (points): ";
		cin >> user_bid;
		Real bid = user_bid;
		while (true) {
			string user_choice;
			cout << endl << "Choose action: (Any key to break)" << endl << "- 1) Try your LUCK! (spin), - 2) Show points," << endl << "-->  ";			cin >> user_choice;
			if (user_choice == "1") {
				bid.calcNum();
				continue;
			}
			if (user_choice == "2") {
				bid.getNum();
			}
			else
			{
				break;
			}
		}
	}
}