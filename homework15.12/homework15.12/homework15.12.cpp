#include <iostream>
using namespace std;

double invertedNumber(double* ptr) {
	return  *ptr = 1 / *ptr;
}

bool checkIfFibonachi(int* ptr) {
	int a = 1;
	int b = 1;
	bool flag = true;
	while(flag){
		cout << a << " " << b << endl;
		if (*ptr == a || *ptr == b) {
			return true;
			flag == false;
		}
		else if (a > *ptr || b > *ptr) {
			return false;
			flag == false;
		}
		else {
			int c = b;
			b = b + a;
			a = c;
			flag = true;
		}
	}
}

int main()
{
	//Напишіть функцію, яка приймає вказівник на ціле число та повертає його обернене значення.
	double num_1 = 123;
	double* ptr_1 = &num_1;
	cout << invertedNumber(ptr_1) << endl;
	cout << *ptr_1 << endl;

	cout << "----------------------------------------" << endl;
	//Напишіть функцію, яка приймає вказівник на ціле число та перевіряє, чи є воно числом Фібоначчі.
	int num_fibonachi;
	cout << "Input number: ";
	cin >> num_fibonachi;
	int* ptr_fibonachi = &num_fibonachi;
	if (checkIfFibonachi(ptr_fibonachi)) {
		cout << num_fibonachi << " - fibonachi";
	}
	else {
		cout << num_fibonachi << " - not fibonachi";
	}
}
