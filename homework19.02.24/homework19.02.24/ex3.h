#pragma once
#include <iostream>
#include "vector"
using namespace std;

class Student {
private:
	string name;
	string institution;
	string ID;
public:
	Student(string name,string institution, string ID) : name(name), institution(institution), ID(ID) 
	{}
	void getStudentData() {
		cout << "Name: " << name << endl;
		cout << "Inst.: " << institution << endl;
		cout << "ID: " << ID << endl;
	}
};

class Aspirant : public Student {
private:
	// статус за яким аспірант готується до захисту курсової
	bool prepare_status = false;
public:
	Aspirant(string name, string institution, string ID) : Student(name,institution,ID) 
	{}
	void getAspirantData() {
		getStudentData();
		cout << "Status: " << std::boolalpha << prepare_status << endl;
	}
	void prepareForDefExam() {
		if (!prepare_status) {
			prepare_status = true;
		}
		else {
			prepare_status = false;
		}
	}
};

void ex3() {
	Aspirant asp("Josh", "Oxford", "ID123DEF");
	asp.getAspirantData();
	asp.prepareForDefExam();
	cout << endl;
	asp.getAspirantData();
	asp.prepareForDefExam();
	cout << endl;
	asp.getAspirantData();
}

