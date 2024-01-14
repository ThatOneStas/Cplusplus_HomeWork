#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


// взяв з минулої дз, яку я робив
struct Book;

string Lowercase(string str);
bool compareBooks(const Book& book1, const Book& book2);
bool compareBooksREV(const Book& book1, const Book& book2);

void qwerty()
{

}

struct Book {
    string name;
    string author;
    string genre;
    string publisher;
};

class Library {
private:
    Book books_list[3] = {
    {"ZName1", "Author1","Genre1","Publisher1",},
    {"XName2", "Author2","Genre2","Publisher2",},
    {"AName3", "Author3","Genre3","Publisher3",},
    };
public:
    void getAllBooks() {
        for (Book el : books_list) {
            cout << el.name << ", " << el.author << ", " << el.genre << ", " << el.publisher << endl;
        }
    }
    void editBook(int size, int index) {
        for (int i = 0;i < size;i++) {
            if (i == index - 1) {
                string name;
                string author;
                string genre;
                string publisher;

                cout << "Input new book data:" << endl;
                cout << "Name: "; cin >> name;
                books_list[i].name = name;
                cout << "Author: "; cin >> author;
                books_list[i].author = author;
                cout << "Genre: "; cin >> genre;
                books_list[i].genre = genre;
                cout << "Publisher: "; cin >> publisher;
                books_list[i].publisher = publisher;
            }
        }
    }

    void findBookByIndex(int size, int index) {
        for (int i = 0;i < size;i++) {
            if (i == index - 1) {
                cout << books_list[i].name << ", " << books_list[i].author << ", " << books_list[i].genre << ", " << books_list[i].publisher << endl;
            }
        }
    }

    void findBookByName(int size, string name) {
        for (int i = 0;i < size;i++) {
            if (Lowercase(books_list[i].name) == Lowercase(name)) {
                cout << books_list[i].name << ", " << books_list[i].author << ", " << books_list[i].genre << ", " << books_list[i].publisher << endl;
            }
        }
    }

    //friend bool compareBooks(const Book& book1, const Book& book2);

    void sortByName(int size) {
        std::sort(books_list, books_list + size, compareBooks);
    }
    void sortByNameREV(int size) {
        std::sort(books_list, books_list + size, compareBooksREV);
    }
};



int main()
{
    Library library;
    int size = 3; //hardcode



    cout << "Actions:" << endl;
    cout << "1. Show books;               0. - end" << endl;
    cout << "2. Edit book;" << endl;
    cout << "3. Find by index;" << endl;
    cout << "4. Find by name." << endl;
    cout << "5. Sort by name (A-Z)." << endl;
    cout << "6. Sort by name (Z-A)." << endl;

    while (true) {
        cout << endl << "Choose action: ";
        int action;
        cin >> action;
        if (action == 0) {
            break;
        }
        else if (action == 1) {
            cout << endl;
            library.getAllBooks();
            continue;
        }
        else if (action == 2) {
            cout << "Book index(1-3): ";
            int index;
            cin >> index;
            cout << endl;
            library.editBook(size, index);
            continue;
        }
        else if (action == 3) {
            cout << "Book index(1-3): ";
            int index;
            cin >> index;
            cout << endl;
            library.findBookByIndex(size, index);
            continue;
        }
        else if (action == 4) {
            cout << "Book name: ";
            string name;
            cin >> name;
            cout << endl;
            library.findBookByName(size, name);
            continue;
        }
        else if (action == 5) {
            cout << endl;
            library.sortByName(size);
            library.getAllBooks();
            continue;
        }
        else if (action == 6) {
            cout << endl;
            library.sortByNameREV(size);
            library.getAllBooks();
            continue;
        }
        else {
            cout << endl << "Try again." << endl;
            continue;
        }
    }
}

string Lowercase(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

bool compareBooks(const Book& book1, const Book& book2)
{
    return book1.name < book2.name;
}

bool compareBooksREV(const Book& book1, const Book& book2)
{
    return book1.name > book2.name;
}