#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include "funcs.h"
using namespace std;

class PairList;

template <typename T1, typename T2>
class PairItem {
private:
    T1 name;
    T2 value;
public:
    friend class PairList;
    PairItem(string name,int value) : name(name), value(value) {}
    PairItem(){}
    void getItemData() {
        cout << name << ": " << value << endl;
    }
    void setName() {
        string new_name;
        cout << "New name: ";
        cin >> new_name;
        this->name = new_name;
    }
    void setValue() {
        string new_val;
        cout << "New value: ";
        cin >> new_val;
        this->name = new_val;
    }
};

class PairList {
private:
    PairItem<string,int>* arr;
    int size;
public:
    PairList(int size) {
        if (size == 0) {
            size += 1;
            this->size = size;
        }
        else
        {
            this->size = size;
        }
        this->arr = new PairItem<string, int>[(this->size)];
        for (int i = 0; i < (this->size);i++) {
            this->arr[i] = { "Joe_" + to_string(i+1), rand_int(1,100)};
        }
    }
    void getListData() {
        for (int i = 0;i < size;i++) {
            arr[i].getItemData();
        }
    }
    void findByName(string target_name) {
        bool flag = true;
        for (int i = 0;i < size;i++) {
            if (Lowercase(arr[i].name) == Lowercase(target_name)) {
                flag = false;
                cout << "Index: " << i << ", ";
                arr[i].getItemData();
            }
        }
        if (flag) {
            cout << "Item wasn`t found." << endl;
        }
    }
    void pushBack() {
        string name;
        int value;
        cout << "Input name: ";
        cin >> name;
        cout << "Input value: ";
        cin >> value;
        int new_size = this->size + 1;
        PairItem<string, int>* new_arr = new PairItem<string, int>[new_size];
        for (int i = 0; i < new_size - 1; i++) {
            new_arr[i] = this->arr[i];
        }
        new_arr[new_size - 1] = { name,value };
        this->arr = new_arr;
        new_arr = nullptr;
        this->size++;
    }
    void delByIndex(int index) {
        int new_size = this->size - 1;
        PairItem<string, int>* new_arr = new PairItem<string, int>[new_size];
        for (int i = 0; i < index; i++) {
            new_arr[i] = this->arr[i];
        }
        for (int i = index + 1; i < new_size + 1; i++) {
            new_arr[i - 1] = this->arr[i];
        }
        this->arr = new_arr;
        new_arr = nullptr;
        this->size--;
    }
};

void ex3() {
    srand(static_cast<unsigned int>(time(0)));

    PairList arr{ 6 };
    arr.getListData();
    arr.findByName("Joe_3");
    arr.pushBack();
    arr.delByIndex(0);
    arr.getListData();
}