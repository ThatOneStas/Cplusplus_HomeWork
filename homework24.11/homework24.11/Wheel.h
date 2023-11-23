#pragma once
#include <iostream>

using namespace std;

class Wheel
{
private:
	int diameter;
	string rubber_type;
public:
	Wheel(int user_d, string user_rubber){
		this->diameter = user_d;
		this->rubber_type = user_rubber;
	}
	string getRubberType() {
		return rubber_type;
	}
	int getDiameter() {
		return diameter;
	}
};

