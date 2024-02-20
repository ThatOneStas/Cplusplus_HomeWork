#include <iostream>
#include "vector"
#include "ex2.h"
#include "ex3.h"

using namespace std;

class BasePasport {
protected:
    string first_name;
    string second_name;
    string nationality;
    string residence_place;
public:
    BasePasport(string first_name,string second_name,string nationality,string residence_place) :
        first_name(first_name), second_name(second_name), nationality(nationality), residence_place(residence_place)
    {}
    virtual void getPasportData() {
        cout << "Name: " << first_name << " " << second_name << endl;
        cout << "- Nationality: " << nationality << endl;
        cout << "- Residence place: " << residence_place << endl;
    }
};

class UAPasport : public BasePasport {
private:
    string passport_id;
    vector<string> visas;
    void getVisas() {
        for (int i = 0;i < visas.size();i++) {
            cout << visas[i] << " ";
        }
        cout << endl;
    }
public:
    UAPasport(string first_name, string second_name, string nationality, string residence_place, string passport_id, vector<string> visas) :
        passport_id(passport_id), BasePasport(first_name,second_name,nationality,residence_place) {
        for (int i = 0; i < visas.size();i++) {
            this->visas.push_back(visas[i]);
        }
    }
    void getPasportData() override {
        BasePasport::getPasportData();
        cout << "- Passport: " << passport_id << endl;
        cout << "- Visas: "; getVisas(); cout << endl;
    }
};

void ex1() {
    BasePasport ps_base("Josh", "Doe", "USA", "Wash. DC");
    vector<string> visas_temp = { "UA", "PL", "EN" };
    UAPasport ps1("Josh", "Doe", "USA", "Wash. DC", "ID1234DEF", visas_temp);
    ps_base.getPasportData();
    cout << endl;
    ps1.getPasportData();
}

int main()
{
    // 1,2 - лаболаторна (1 і 2)
    // ex1();
    // ex2();
    // 3 - домашнє 1-ше завдання
    ex3();
}
