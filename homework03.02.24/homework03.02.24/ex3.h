#pragma once
#include <iostream>
using namespace std;

class Point {
private:
	int n_position;
public:
	Point(int position) : n_position(position)
	{}
	void getPointData() {
		cout << "N: " << n_position << endl;
	}
	int getPointPosition() {
		return this->n_position;
	}
	template<typename Functor>
	static void ComparePoints(Point p_1, Point p_2, Functor functor) {
		if (functor(p_1,p_2) == 1) {
			cout << "P_1 is bigger then P_2 - by " << p_1.n_position - p_2.n_position << endl;
		}
		else if (functor(p_1, p_2) == 2) {
			cout << "P_2 is bigger then P_1 - by " << p_2.n_position - p_1.n_position << endl;
		}
		else if(functor(p_1, p_2) == 3) {
			cout << "Their position are equal - " << p_1.n_position << endl;
		}
	}
};

struct Functor {
public:
	int operator()(Point p_1, Point p_2) {
		if (p_1.getPointPosition() > p_2.getPointPosition()) {
			return 1;
		}
		else if (p_2.getPointPosition() > p_1.getPointPosition()) {
			return 2;
		}
		else {
			return 3;
		}
	}
};

void ex3() {
	Point n1(10);
	Point n2(15);
	Functor functor;
	n1.getPointData();
	n2.getPointData();
	Point::ComparePoints(n1,n2,functor);
}