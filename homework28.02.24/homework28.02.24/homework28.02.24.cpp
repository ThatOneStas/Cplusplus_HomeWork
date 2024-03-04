#include <iostream>
#include <vector>
using namespace std;

class ArrayOutOfMemo {
private:
    string error_msg;
public:
    ArrayOutOfMemo(string err_msg) : error_msg(err_msg.c_str()){}
    const char* what() {
        return error_msg.c_str();
    }
};

class ArrayOutOfRange : public std::out_of_range {
public:
    ArrayOutOfRange(string err_msg) : out_of_range(err_msg.c_str()) {}
};

class ArrayIsEmpty {
private:
    string error_msg;
public:
    ArrayIsEmpty(string err_msg) : error_msg(err_msg.c_str()) {}
    const char* what() {
        return error_msg.c_str();
    }
};

class InvalidArgument : public std::invalid_argument {
public:
    InvalidArgument(string err_msg) : invalid_argument(err_msg.c_str()) {}
};

template <typename T>
class MyFixedVector {
private:
    vector<T> arr;
    int fixedSize;
public:
    MyFixedVector(int fixed_size) : fixedSize(fixed_size){}
    MyFixedVector(){}
    template <typename T2>
    void add(T2 item) {
        try {
            if constexpr (!is_same<T2, T>().value) {
                throw InvalidArgument("Item type doesn`t have the type of the array.");
            }
            else if (arr.size() == fixedSize) {
                throw ArrayOutOfMemo("Array doesn`t have avaible space.");
            }
            else {
                arr.push_back(item);
            }
        }
        catch (const InvalidArgument& ex) {
            cout << "Error: " << ex.what() << endl;
        }
        catch (ArrayOutOfMemo ex){
            cout << "Error: " << ex.what() << endl;
        }
    }
    template <typename T2>
    void del(T2 index) {
        try {
            if constexpr (!is_same<T2, int>().value) {
                throw InvalidArgument("Index has to be the INT type.");
            }
            else if ((int)index > fixedSize - 1) {
                throw ArrayOutOfRange("Item with that index doesn`t exist.");
            }
            else if (arr.empty()) {
                throw ArrayIsEmpty("Array is empty.");
            }
            else {
                arr.erase(arr.begin() + index);
            }
        }
        catch (const InvalidArgument& ex) {
            cout << "Error: " << ex.what() << endl;
        }
        catch (const ArrayOutOfRange& ex) {
            cout << "Error: " << ex.what() << endl;
        }
        catch (ArrayIsEmpty ex) {
            cout << "Error: " << ex.what() << endl;
        }
    }
    template <typename T2>
    T operator[](T2 index) {
        try {
            if constexpr (!is_same<T2, int>().value) {
                throw InvalidArgument("Index has to be the INT type.");
            }
            else if (arr.empty()) {
                throw ArrayIsEmpty("Array is empty.");
            }
            else if ((int)index > fixedSize - 1) {
                throw ArrayOutOfRange("Item with that index doesn`t exist.");
            }
            else {
                return arr[index];
            }
        }
        catch (const InvalidArgument& ex) {
            cout << "Error: " << ex.what() << endl;
        }
        catch (ArrayIsEmpty ex) {
            cout << "Error: " << ex.what() << endl;
        }
        catch (const ArrayOutOfRange& ex) {
            cout << "Error: " << ex.what() << endl;
        }
    }
    void print() {
        try {
            if (arr.empty()) {
                throw ArrayIsEmpty("Array is empty.");
            }
            else {
                cout << "Array: ";
                for (int i = 0;i < fixedSize;i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
        catch (ArrayIsEmpty ex) {
            cout << "Error: " << ex.what() << endl;
        }  
    }
};

int main()
{
    MyFixedVector<int> my_arr(5);
    my_arr.add(11);
    my_arr.add(12);
    my_arr.add(13);
    my_arr.add(14);
    my_arr.add(15);

    my_arr.print();

    my_arr.add(999);
    my_arr.add("XXX");
    cout << my_arr[5] << endl;
    cout << my_arr["XXX"] << endl;
    
    MyFixedVector<int> my_arr_2(5);
    my_arr_2.print();
    my_arr_2.del(0);
    my_arr_2.del("XXX");
}