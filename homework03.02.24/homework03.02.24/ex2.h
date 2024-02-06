#pragma once
#include <iostream>
#include <ctime>
using namespace std;

int rand_int(int lowerLimit, int upperLimit) {
	return (rand() % (upperLimit - lowerLimit + 1) + lowerLimit);
}

class Array {
private:
	int size;
	int* arr;
public:
	Array(int size) : size(size) {
		this->arr = new int[this->size];
		for (int i = 0; i < size;i++) {
			arr[i] = rand_int(1, 100);
		}
	}
	int getArrSize() {
		return this->size;
	}
	void getArrData() {
		for (int i = 0;i < this->size;i++) {
			cout << this->arr[i] << " ";
		}
		cout << endl;
	}
	int& operator[]( int index) {
		for (int i = 0; i < this->size;i++) {
			if (i == index - 1) {
				return this->arr[i];
			}
		}
	}
	void operator=(Array arr_2) {
		if (this->size != arr_2.getArrSize()) {
			this->size = arr_2.getArrSize();
			this->arr = new int[this->size];
		}
		for (int i = 0; i < this->size; i++) {
			this->arr[i] = arr_2.arr[i];
		}
	}
};

void ex2() {
	srand(static_cast<unsigned int>(time(0)));

	Array arr(5);
	arr.getArrData();
	cout << arr[1];
	arr[1] = 23;
	cout << endl << arr[1] << endl;
	Array arr_2(8);
	cout << endl;
	arr.getArrData();
	arr_2.getArrData();
	arr = arr_2;
	arr.getArrData();
}