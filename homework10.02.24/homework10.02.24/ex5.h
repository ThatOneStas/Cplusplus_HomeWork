#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include "funcs.h"

template <typename T>
class Array_ex5 {
private:
    int size;
    T* arr;
public:
    Array_ex5(int size,string type) : size(size) {
        arr = new T[size];
        if (type == "int") {
            for (int i = 0;i < size;i++) {
                arr[i] = rand_int(1, 100);
            }
        }
        else {
            string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
            for (int i = 0;i < size;i++) {
                arr[i] = alphabet[rand_int(0, 52)];
            }
        }
    }
    void getArrData() {
        for (int i = 0;i < size;i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void operator+(T item) {
        size += 1;
        T* new_arr = new T[size];
        for (int i = 0; i < size - 1; i++) {
            new_arr[i] = this->arr[i];
        }
        if constexpr (std::is_same<T, int>().value) {
            new_arr[size-1] = item;
        }
        else {
            string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
            new_arr[size-1] = item;
        }
        this->arr = new_arr;
        new_arr = nullptr;
    }
    void operator-(T item) {
        int index = -1;
        for (int i = 0;i < size;i++) {
            if (arr[i] == item) {
                index = i;
            }
        }
        if (index != -1) {
            size -= 1;
            T* new_arr = new T[size];
            for (int i = 0; i < index; i++) {
                new_arr[i] = this->arr[i];
            }
            for (int i = index + 1; i < size + 1; i++) {
                new_arr[i - 1] = this->arr[i];
            }
            this->arr = new_arr;
            new_arr = nullptr;
        }
        else {
            cout << "Item isn`t in array." << endl;
        }
    }
};

void ex5() {
    srand(static_cast<unsigned int>(time(0)));


    Array_ex5<int> arr_int(10, "int");
    arr_int.getArrData();
    Array_ex5<string> arr_str(10, "str");
    arr_str.getArrData();

    //arr_int + 13;
    //arr_int.getArrData();
    //arr_str + "ABC";
    //arr_str.getArrData();
    arr_int + 11;
    arr_int + 11;
    arr_int.getArrData();
    arr_int - 11;
    arr_int.getArrData();
    arr_int - 9999;

}    
