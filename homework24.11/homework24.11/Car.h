#pragma once
#include <iostream>
#include "Wheel.h"

using namespace std;

class Car
{
private:
	Wheel wheel;
public:
	Car(Wheel data) : wheel(wheel) {
	}
};

