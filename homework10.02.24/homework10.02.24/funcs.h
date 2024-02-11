#pragma once
#include <iostream>
#include <ctime>
using namespace std;

int rand_int(int lowerLimit, int upperLimit) {
    return (rand() % (upperLimit - lowerLimit + 1) + lowerLimit);
}

string Lowercase(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}