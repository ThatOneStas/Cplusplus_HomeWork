#include <iostream>
using namespace std;

string Lowercase(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

class Reservoir {
private:
    string name;
    string type;
    int lenght;
    int deepness;
    int width;
public:
    Reservoir(string name, string type, int lenght, int deepness, int width) :
        name(name),type(type), lenght(lenght), deepness(deepness), width(width)
    {}
    Reservoir(string name, string type) :
        Reservoir(name, type, 0, 0, 0)
    {}
    // незнаю нащо просто зробив дефолтний ctor
    Reservoir(){}
    void getResData() {
        cout << "Name/type: " << this->name << ", " << this->type << endl;
        cout << "W/L/D: " << this->width << ", " << this->lenght << ", " << this->deepness << endl;
    }
    string getResType() {
        return this->type;
    }
    string getResName() {
        return this->name;
    }
    int calcResArea() {
        return lenght * width;
    }
    void roundCapacity() {
        cout << "Approximate capacity: " << this->width * this->lenght * this->deepness << endl;
    }

    // порівнюєм їхні типи (типу типи)
    friend bool operator==(Reservoir res1, Reservoir res2) {
        if (res1.getResType() == res2.getResType()) {
            return true;
        }
        else {
            return false;
        }
    }
    
    static void compareResTypes(Reservoir res1, Reservoir res2) {
        if ((res1 == res2) == true) {
            cout << "They are " << res1.getResType() << "s" << endl;
        }
        else {
            cout << "They are " << res1.getResType() << " and " << res2.getResType() << endl;
        }
    }
    static void compareResAreas(Reservoir res1, Reservoir res2) {
        if ((res1 == res2) == true) {
            if (res1.calcResArea() > res2.calcResArea()) {
                cout << res1.getResName() << " is bigger than " << res2.getResName() << " (" <<
                    res1.calcResArea() << ">" << res2.calcResArea() << ")" << endl;
            }
            else if (res1.calcResArea() < res2.calcResArea()) {
                cout << res2.getResName() << " is bigger than " << res1.getResName() << " (" <<
                    res2.calcResArea() << ">" << res1.calcResArea() << ")" << endl;
            }
            else {
                cout << res2.getResName() << " and " << res1.getResName() << " got equal ares " << " (" <<
                    res1.calcResArea() << "=" << res2.calcResArea() << ")" << endl;
            }
        }
        else {
            cout << "They are not the same type." << endl;
        }
    }
};

class Book {
private:
    string name;
    string author;
    string publisher;
    int pages_count;
public:
    Book(string name, string author, string publisher, int pages_count) :
        name(name), author(author), publisher(publisher), pages_count(pages_count) 
    {}
    Book() {}
    void getBookData() const {
        cout << "Name/A/P./P_C: " << this->name <<
        ", " << this->author <<
        ", " << this->publisher <<
        ", " << this->pages_count << endl;
    }
    string getAuthor() {
        return this->author;
    }
    string getPublisher() {
        return this->publisher;
    }
};

class Section {
private:
    Book* section_list;
    int list_size;
    string name;
public:
    Section(string name) : name(name) 
    {}
    void setListData(Book* arr, int arr_size, string section_theme) {
        int el_count = 0;
        for (int i = 0; i < arr_size;i++) {
            if (Lowercase(arr[i].getAuthor()) == Lowercase(section_theme) || Lowercase(arr[i].getPublisher()) == Lowercase(section_theme)) {
                el_count++;
            }
        }
        this->list_size = el_count;
        this->section_list = new Book[this->list_size];
        for (int i = 0, j = 0; i < arr_size;i++) {
            if (Lowercase(arr[i].getAuthor()) == Lowercase(section_theme) || Lowercase(arr[i].getPublisher()) == Lowercase(section_theme)) {
                section_list[j] = arr[i];
                j++;
            }
        }
    }
    void getListData() {
        cout << this->name << endl;
        for (int i = 0; i < this->list_size;i++) {
            this->section_list[i].getBookData();
        }
    }
};

int main()
{
    // homework
    Reservoir res1("Name1", "Lake", 150, 15, 200);
    res1.getResData();
    res1.roundCapacity();
    cout << res1.getResType() << endl;
    cout << endl;
    Reservoir res2("Name2", "Lake", 380, 30, 700);
    Reservoir res3("Name3", "River", 12000, 8, 20);
    Reservoir::compareResTypes(res1, res2);
    Reservoir::compareResTypes(res1, res3);
    cout << endl;
    Reservoir::compareResAreas(res1, res2);
    cout << endl;
    // lab. work
    int list_size = 9;
    Book* base_list = new Book[list_size];
    base_list[0] = { "Steel Ball Run", "William", "David. Prod.", 144 };
    base_list[1] = { "Chainsow man", "John", "David. Prod.", 169 };
    base_list[2] = { "Fate", "Arthur", "David. Prod.", 100 };
    base_list[3] = { "Diamond is unbreakeble", "William", "Ufotable", 81 };
    base_list[4] = { "Battle tendancy", "William", "Ufotable", 144 };
    base_list[5] = { "JJK", "Arthur", "Ufotable", 100 };
    base_list[6] = { "Chainsow man 2", "John", "Ufotable", 169 };
    base_list[7] = { "Demon slayer", "Arthur", "Mappa", 100 };
    base_list[8] = { "Stardust crusaders", "William", "Mappa", 169 };
    Section section_1("Person_1 list");
    section_1.setListData(base_list, list_size, "filliam");
    section_1.getListData();
    section_1.setListData(base_list, list_size, "Mappa");
    section_1.getListData();
}
