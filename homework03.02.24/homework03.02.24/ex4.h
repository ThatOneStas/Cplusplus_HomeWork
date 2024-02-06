#pragma once
#include <iostream>
using namespace std;

class DistanceCm;
class DistanceM;

class DistanceFt {
private:
	float distance;
public:
	DistanceFt(float ft) : distance(ft) {}
	void getDistanceData() {
		cout << "Funts: " << distance << endl;
	}
	operator DistanceM() const;
	operator DistanceCm() const;
};

class DistanceCm {
private:
	float distance;
public:
	DistanceCm(float cm) : distance(cm) {}
	void getDistanceData() {
		cout << "Cms: " << distance << endl;
	}
	operator DistanceM() const;
	operator DistanceFt() const;
};

class DistanceM {
private:
	float distance;
public:
	DistanceM(float d) : distance(d){}
	void getDistanceData() {
		cout << "Metres: " << distance << endl;
	}
	operator DistanceFt() const;
	operator DistanceCm() const;
};

DistanceM::operator DistanceFt() const {
	return this->distance * 3.28;
}
DistanceM::operator DistanceCm() const {
	return this->distance / 100;
}

DistanceCm::operator DistanceM() const {
	return this->distance * 100;
}
DistanceCm::operator DistanceFt() const {
	return this->distance * 30.48;
}

DistanceFt::operator DistanceM() const {
	return this->distance / 3.28;
}
DistanceFt::operator DistanceCm() const {
	return this->distance * 0.032;
}

void ex4() {
	DistanceFt ft(10);
	DistanceM m(10);
	DistanceCm cm(10);
	ft.getDistanceData();
	m.getDistanceData();
	cm.getDistanceData();

	cout << endl;
	ft = (DistanceFt)ft;
	m = (DistanceFt)ft;
	cm = (DistanceFt)ft;

	ft.getDistanceData();
	m.getDistanceData();
	cm.getDistanceData();
}