#pragma once
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

template <typename T>
class Shape {
public:
    // show
    virtual void getShapeInfo() = 0;
    // save - зберегти у вектор
    virtual void operator>(vector<T> &arr) = 0;
    // load - знайти, та відобразити
    virtual void operator<(vector<T> &arr) = 0;
};

class Square : public Shape<Square> {
private:
    tuple<float, float> position;
    float side;
public:
    Square(float side, float x, float y) : side(side) {
        tuple<float, float> new_pos{ x, y };
        this->position = new_pos;
    }
    tuple<float, float> getShapePos() {
        return this->position;
    }
    float getShapeSide() {
        return this->side;
    }
    void getShapeInfo() override {
        cout << "Square info ->" << endl;
        cout << "- Position(X,Y): " << get<0>(position) << ", " << get<1>(position) << endl;
        cout << "- Side: " << side << endl;
    }
    void operator>(vector<Square> &arr) override {
        arr.push_back(*this);
    }

    void operator<(vector<Square> &arr) override {
        bool flag{ true };
        for (int i = 0;i < arr.size();i++) {
            if (arr[i].getShapeSide() == this->side && arr[i].getShapePos() == this->position) {
                flag = false;
                cout << "Square is in list with index: " << i << endl;
            }
        }
        if (flag) {
            cout << "Square isn`t in list" << endl;
        }
    }
};

// Rectangle2 так як в мене вже є клас з таким ім'ям
class Rectangle2 : public Shape<Rectangle2> {
private:
    tuple<float, float> position;
    tuple<float, float> sides;
public:
    Rectangle2(float side_1, float side_2, float x, float y) {
        tuple<float, float> new_pos{ x, y };
        tuple<float, float> new_sides{ side_1, side_2 };
        this->position = new_pos;
        this->sides = new_sides;
    }
    tuple<float, float> getShapePos() {
        return this->position;
    }
    tuple<float,float> getShapeSide() {
        return this->sides;
    }
    void getShapeInfo() override {
        cout << "Rectangle info ->" << endl;
        cout << "- Position(X,Y): " << get<0>(position) << ", " << get<1>(position) << endl;
        cout << "- Side 1: " << get<0>(sides) << endl;
        cout << "- Side 2: " << get<1>(sides) << endl;
    }
    void operator>(vector<Rectangle2>& arr) override {
        arr.push_back(*this);
    }

    void operator<(vector<Rectangle2>& arr) override {
        bool flag{ true };
        for (int i = 0;i < arr.size();i++) {
            if (arr[i].getShapeSide() == this->sides && arr[i].getShapePos() == this->position) {
                flag = false;
                cout << "Rectangle is in list with index: " << i << endl;
            }
        }
        if (flag) {
            cout << "Rectangle isn`t in list" << endl;
        }
    }
};


// 7-ме завдання
void ex2() {
    Square square1(10,244,75);
    Square square2(15, 212, 55);
    Square square3(20, 115, 85);
    Square square4(30, 352, 124);
    vector<Square> squareArr;
    // saving
    square1 > squareArr;
    square2 > squareArr;
    square3 > squareArr;
    // loading
    square1 < squareArr;
    square2 < squareArr;
    square3 < squareArr;
    square4 < squareArr;

    cout << endl;

    Rectangle2 rectangle1(10, 10, 244, 75);
    Rectangle2 rectangle2(15, 20, 212, 55);
    Rectangle2 rectangle3(20, 50, 115, 85);
    Rectangle2 rectangle4(30, 20, 352, 124);
    vector<Rectangle2> rectangleArr;
    // saving
    rectangle1 > rectangleArr;
    rectangle2 > rectangleArr;
    rectangle3 > rectangleArr;
    // loading
    rectangle1 < rectangleArr;
    rectangle2 < rectangleArr;
    rectangle3 < rectangleArr;
    rectangle4 < rectangleArr;
}