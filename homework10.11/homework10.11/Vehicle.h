#pragma once
#include <iostream>
using namespace std;

class Vehicle
{
private:
	string engine;
public:
	Vehicle() {
		engine = "stopped";
	}
	virtual void startEngine() {
		this->engine = "started";
		cout << "Your engine was " << engine << endl;
	}

	virtual void stopEngine() {
		this->engine = "stopped";
		cout << "Your engine was " << engine << endl;
	}
};

