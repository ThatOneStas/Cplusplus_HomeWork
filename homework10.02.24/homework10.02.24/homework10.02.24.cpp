#include <iostream>
#include <ctime>
#include "funcs.h"
#include "ex2.h"
#include "ex3.h"
#include "ex4.h"
#include "ex5.h"
using namespace std;

template<typename T>
class Randomizer {
private:
	T item;
public:
	Randomizer(T item) : item(item) {}
	Randomizer() {}
	void getItemData() {
		cout << std::boolalpha << item << endl;
	}
	void randINT() {
		this->item = rand_int(1, 1000);
	}
	void randSTR() {
		string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		this->item = "0000000";
		for (int i = 0;i < 8;i++) {
			this->item[i] = alphabet[rand_int(0,52)];
		}
	}
	void randBOOL() {
		if (rand_int(1, 2) == 1) {
			this->item = true;
		}
		else {
			this->item = false;
		}
	}
};

void ex1() {
	srand(static_cast<unsigned int>(time(0)));

	Randomizer<int> item1(1);
	item1.randINT();
	item1.getItemData();
	Randomizer<bool> item2;
	item2.randBOOL();
	item2.getItemData();
	Randomizer<string> item3;
	item3.randSTR();
	item3.getItemData();
}

int main()
{
	//ex1();
	//ex2();
	//ex3();
	//ex4();
	ex5();
}