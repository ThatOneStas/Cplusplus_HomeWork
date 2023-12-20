#include <iostream>
using namespace std;

void push_end(int** &arr, int* arr_to_add,int coloums,int rows) {
    int newRows = rows + 1;
    int** newArr = new int* [rows+1];
    for (int i = 0; i < newRows; i++) {
        newArr[i] = new int[coloums];
    }
    for (int i = 0; i < rows; i++) {
        for (int y = 0;y < coloums;y++) {
            newArr[i][y] = arr[i][y];
        }
    }
    for (int y = 0;y < coloums;y++) {
        newArr[newRows-1][y] = arr_to_add[y];
    }
    
    for (int i = 0; i < newRows; i++) {
        for (int j = 0; j < coloums; j++) {
            cout << newArr[i][j] << " ";
        }
        cout << endl;
    }
}

void push_start(int**& arr, int* arr_to_add, int coloums, int rows) {
    int newRows = rows + 1;
    int** newArr = new int* [rows + 1];
    for (int i = 0; i < newRows; i++) {
        newArr[i] = new int[coloums];
    }
    for (int y = 0;y < coloums;y++) {
        newArr[0][y] = arr_to_add[y];
    }
    for (int i = 1; i < rows+1; i++) {
        for (int y = 0;y < coloums;y++) {
            newArr[i][y] = arr[i-1][y];
        }
    }
    for (int i = 0; i < newRows; i++) {
        for (int j = 0; j < coloums; j++) {
            cout << newArr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int rows = 5;
    int coloums = 5;

    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[coloums];
    }

    int* arr_2 = new int[coloums];
    for (int i = 0;i < coloums;i++) {
        arr_2[i] = i + 10;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < coloums; j++) {
            arr[i][j] = j;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < coloums; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "=======================================" << endl;

    push_end(arr, arr_2, coloums, rows);

    cout << "=======================================" << endl;

    push_start(arr, arr_2, coloums, rows);
}