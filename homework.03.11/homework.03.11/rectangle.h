#pragma once

#include <iostream>
#include <math.h>
using namespace std;

class rectangle
{
private:
	int width;
	int height;
	int calcArea() {
		int area = width * height;
		return area;
	};
	int calcPerimeter() {
		int perimeter = width * 2 + height * 2;
		return perimeter;
	}
public:
	rectangle() {
		width = 0;
		height = 0;
	};
	int getArea() {
		return calcArea();
	}

	int getPerimeter() {
		return calcPerimeter();
	}

	void changeWidth(int new_data) {
		this->width = new_data;
	}
	void changeHeight(int new_data) {
		this->height = new_data;
	}
};
