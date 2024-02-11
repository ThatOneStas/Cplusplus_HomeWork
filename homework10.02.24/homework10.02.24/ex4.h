#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include "funcs.h"

class Array {
private:
    int size;
public:
    int* arr;
    Array(int size) : size(size) {
        arr = new int[size];
        for (int i = 0;i < size;i++) {
            arr[i] = rand_int(1, 100);
        }
    }
    void getArrData() {
        for (int i = 0;i < size;i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void getArrData(int* arr,int size) {
    for (int i = 0;i < size;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
void getMaxItem(T* arr, int size) {
    int max_item = arr[0];
    for (int i = 0;i < size;i++) {
        if (arr[i] > max_item) {
            max_item = arr[i];
        }
    }
    cout << "Max item in list is: " << max_item << endl;
}

template <typename T>
void getMinItem(T* arr, int size) {
    int max_item = arr[0];
    for (int i = 0;i < size;i++) {
        if (arr[i] < max_item) {
            max_item = arr[i];
        }
    }
    cout << "Min item in list is: " << max_item << endl;
}

void ex4() {
    srand(static_cast<unsigned int>(time(0)));

    int size_1 = 10;
    int* arr_1 = new int[size_1];
    for (int i = 0;i < size_1;i++) {
        arr_1[i] = rand_int(1, 100);
    }
    getArrData(arr_1, size_1);

    int size_2 = 10;
    Array arr_2(size_2);
    arr_2.getArrData();

    cout << endl;
    getMaxItem(arr_1,size_1);
    getMinItem(arr_1, size_1);
    cout << endl;
    getMaxItem(arr_2.arr, size_2);
    getMinItem(arr_2.arr, size_2);
}