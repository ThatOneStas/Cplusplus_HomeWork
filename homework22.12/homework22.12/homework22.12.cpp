#include <iostream>
using namespace std;

void push_end(int**& arr, int* arr_to_add, int coloums, int& rows) {
    int newRows = rows + 1;
    int** newArr = new int* [rows + 1];
    for (int i = 0; i < newRows; i++) {
        newArr[i] = new int[coloums];
    }
    for (int i = 0; i < rows; i++) {
        for (int y = 0;y < coloums;y++) {
            newArr[i][y] = arr[i][y];
        }
    }
    for (int y = 0;y < coloums;y++) {
        newArr[newRows - 1][y] = arr_to_add[y];
    }

    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    arr = newArr;
    newArr = nullptr;
    rows++;
}

void push_by_index(int**& arr, int* arr_to_add, int coloums, int& rows, int index) {
    int newRows = rows + 1;
    int** newArr = new int* [rows + 1];
    for (int i = 0; i < newRows; i++) {
        newArr[i] = new int[coloums];
    }
    for (int i = 0; i < index; i++) {
        for (int y = 0;y < coloums;y++) {
            newArr[i][y] = arr[i][y];
        }
    }
    for (int y = 0;y < coloums;y++) {
        newArr[index][y] = arr_to_add[y];
    }
    for (int i = index+1; i < newRows; i++) {
        for (int y = 0;y < coloums;y++) {
            newArr[i][y] = arr[i-1][y];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    arr = newArr;
    newArr = nullptr;
    rows++;
}

void del_by_index(int**& arr, int coloums, int& rows, int index) {
    int newRows = rows - 1;
    int** newArr = new int* [rows - 1];
    for (int i = 0; i < newRows; i++) {
        newArr[i] = new int[coloums];
    }
    for (int i = 0; i < index; i++) {
        for (int y = 0;y < coloums;y++) {
            newArr[i][y] = arr[i][y];
        }
    }
    for (int i = index; i < newRows; i++) {
        for (int y = 0;y < coloums;y++) {
            newArr[i][y] = arr[i+1][y];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    arr = newArr;
    newArr = nullptr;
    rows--;
}

void push_start(int**& arr, int* arr_to_add, int coloums, int& rows) {
    int newRows = rows + 1;
    int** newArr = new int* [rows + 1];
    for (int i = 0; i < newRows; i++) {
        newArr[i] = new int[coloums];
    }
    for (int y = 0;y < coloums;y++) {
        newArr[0][y] = arr_to_add[y];
    }
    for (int i = 1; i < rows + 1; i++) {
        for (int y = 0;y < coloums;y++) {
            newArr[i][y] = arr[i - 1][y];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    arr = newArr;
    newArr = nullptr;
    rows++;
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

    cout << "===============================" << endl;
    cout << "Actions:" << endl;
    cout << "1) Push end;" << endl;
    cout << "2) Push start;" << endl;
    cout << "3) Add by index;" << endl;
    cout << "4) Del by index." << endl;
    cout << "===============================" << endl;
    while (true) {
        int choice;
        cout << "Your action (1-4) : ";
        cin >> choice;
        if (choice == 1) {
            push_end(arr, arr_2, coloums, rows);
            cout << "===============================" << endl;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < coloums; j++) {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
            cout << "===============================" << endl;
            continue;
        }
        else if (choice == 2) {
            push_start(arr, arr_2, coloums, rows);
            cout << "===============================" << endl;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < coloums; j++) {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
            cout << "===============================" << endl;
            continue;
        }
        else if (choice == 3) {
            int index;
            cout << "Input index (0,1,2..): ";
            cin >> index;
            if (index <= rows) {
                push_by_index(arr, arr_2, coloums, rows, index);
                cout << "===============================" << endl;
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < coloums; j++) {
                        cout << arr[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << "===============================" << endl;
                continue;
            }
            else {
                break;
            }
        }
        else if (choice == 4) {
            int index;
            cout << "Input index (0,1,2..): ";
            cin >> index;
            if (index <= rows) {
                del_by_index(arr, coloums, rows, index);
                cout << "===============================" << endl;
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < coloums; j++) {
                        cout << arr[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << "===============================" << endl;
                continue;
            }
            else {
                break;
            }
        }
        else {
            break;
        }
    }
}