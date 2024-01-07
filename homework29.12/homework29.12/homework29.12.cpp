
#include <iostream>
using namespace std;

void lineSearch(int* arr, int size, int num) {
	int circle = 1;
	int index = 0;
	while (true) {
		if (circle > size - 1) {
			cout << endl << "Index: not found" << endl;
			break;
		}
		else if (arr[index] == num) {
			cout << "Index: " << index << endl;
			cout << "Circles: " << circle << endl;
			break;
		}
		else {
			index++;
			circle++;
			continue;
		}
	}
}

void binSearch(int* arr, int size, int num) {
	int circle = 1;
	int index = (size / 2) - ((size % 2)/2);
	int border_1 = 0;
	int border_2 = size - 1;
	while (true) {
		//cout << "index -- " << index << endl;
		//cout << "num -- " << arr[index] << endl;
		if (circle > size - 1) {
			cout << endl << "Index: not found" << endl;
			break;
		}

		else if (arr[index] == num) {
			cout << endl << "Index: " << index << endl;
			cout << "Circles: " << circle << endl;
			break;
		}

		else if (arr[index] > num) {
			border_2 = index;
			index = (index / 2) - (index % 2);
			circle++;
			continue;
		}
		else if (arr[index] < num) {
			border_1 = index;
			index = ((index + border_2) / 2) - (((index + border_2) % 2) / 2);
			circle++;
			continue;
		}
	}
}

int main()
{
	int size = 12;
	int* arr = new int[size];
	arr[0] = 11;
	arr[1] = 22;
	arr[2] = 33;
	arr[3] = 44;
	arr[4] = 55;
	arr[5] = 66;
	arr[6] = 77;
	arr[7] = 88;
	arr[8] = 99;
	arr[9] = 111;
	arr[10] = 122;
	arr[11] = 133;
	lineSearch(arr, size, 55);
	// не може найти останній елемент списку (133)..
	// .. коли воно хоче піднятись вище 122 воно мусить..
	// .. взяти середину між 10 та 11. В мене щоб не були ніяких проблем..
	// .. кожного разу при діленні число заокруглюється до меншого тобто:..
	// .. 11+10=21 -> 21/2=10.5 тоді воно перетворює в 10 і воно ніколи не дійде до 11.
	binSearch(arr, size, 55);
}