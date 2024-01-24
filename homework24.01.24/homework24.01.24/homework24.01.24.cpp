#include <iostream>
#include "string"
using namespace std;

class Student {
private:
    string first_name;
    string last_name;
    string birth;
    string phone_num = "(123)-456-78-99";
    string institution;
public:
    Student(string fname, string lname, string birth, string phone_num, string institution) {
        this->first_name = fname;
        this->last_name = lname;
        this->birth = birth;
        this->institution = institution;
        // вирішив красиво зробити
        this->phone_num[1] = phone_num[0];
        this->phone_num[2] = phone_num[1];
        this->phone_num[3] = phone_num[2];
        this->phone_num[6] = phone_num[3];
        this->phone_num[7] = phone_num[4];
        this->phone_num[8] = phone_num[5];
        this->phone_num[10] = phone_num[6];
        this->phone_num[11] = phone_num[7];
        this->phone_num[13] = phone_num[8];
        this->phone_num[14] = phone_num[9];
    }
    void getStudentInfo() {
        cout << "Ім'я/Прізв.: " << this->first_name << " " << this->last_name << endl;
        cout << "Дата народження: " << this->birth << endl;
        cout << "Номер тел.: " << this->phone_num << endl;
        cout << "Навчальний заклад: " << this->institution << endl;
    }
};

class Person {
private:
    string name;
    string phone_num;
public:
    Person(string name, string phone_num) {
        this->name = name;
        this->phone_num = phone_num;
    }
    Person() {}
    void getPersonData() {
        cout << this->name << " " << this->phone_num << endl;
    }
    string getName() {
        return this->name;
    }
    string getPhoneNum() {
        return this->phone_num;
    }
};

class TelBook {
private:
    int size;
    Person* book_list;
public:
    TelBook(int size) {
        if (size == 0) {
            size += 1;
            this->size = size;
        }
        else
        {
            this->size = size;
        }
        this->book_list = new Person[(this->size)];
        for (int i = 0; i < (this->size);i++) {
            this->book_list[i] = { "Joe_" + to_string(i),to_string(i + 1000000000) };
        }
    }
    void getListData() {
        for (int i = 0; i < (this->size); i++) {
            this->book_list[i].getPersonData();
        }
    }
    void pushBack(string name,string phone_num) {
        int newSize = this->size + 1;
        Person* newBookList = new Person[newSize];
        for (int i = 0; i < newSize-1; i++) {
            newBookList[i] = this->book_list[i];
        }
        newBookList[newSize-1] = { name,phone_num };
        this->book_list = newBookList;
        newBookList = nullptr;
        this->size++;
    }
    void delByIndex(int index) {
        int newSize = this->size - 1;
        Person* newBookList = new Person[newSize];
        for (int i = 0; i < index; i++) {
            newBookList[i] = this->book_list[i];
        }
        for (int i = index+1; i < newSize+1; i++) {
            newBookList[i-1] = this->book_list[i];
        }
        this->book_list = newBookList;
        newBookList = nullptr;
        this->size--;
    }
};

int main()
{
    Student student("John","Doe","10.11.12","1239998877","Academy");
    student.getStudentInfo();

    cout << endl;

    TelBook book_1(4);
    book_1.getListData();
    cout << endl;
    book_1.pushBack("Wilbur", "1239998877");
    book_1.getListData();
    cout << endl;
    book_1.delByIndex(2);
    book_1.getListData();
}