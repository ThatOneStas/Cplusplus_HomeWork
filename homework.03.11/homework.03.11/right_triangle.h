#pragma once

#include <iostream>
#include <math.h>
using namespace std;

class right_triangle
{
private:
	int leg_1;
	int leg_2;
	int calcArea() {
		int area = (leg_1*leg_2)/2;
		return area;
	};
	double calcHypotenuse() {
		double hypotenuse = (leg_1*leg_1)+(leg_2*leg_2);
		return sqrt(hypotenuse);
	}
public:
	right_triangle() {
		leg_1 = 0;
		leg_2 = 0;
	};
	int getArea() {
		return calcArea();
	}

	double getHypotenuse() {
		return calcHypotenuse();
	}

	void changeFirstLeg(int new_data) {
		this->leg_1 = new_data;
	}
	void changeSecondLeg(int new_data) {
		this->leg_2 = new_data;
	}
};
