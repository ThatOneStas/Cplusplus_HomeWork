#include <iostream>
using namespace std;

void getItems(int* arr,int size) {
	for (int i = 0;i < size;i++) {
		cout << arr[i];
	}
}

void pushItems(int* arr, int size) {
	for (int i = 0;i < size;i++) {
		arr[i] = i + 10;
	}
}

void function()
{
	int size = 6;
	int* arr = new int[size];
	pushItems(arr, size);
	getItems(arr, size);
}
