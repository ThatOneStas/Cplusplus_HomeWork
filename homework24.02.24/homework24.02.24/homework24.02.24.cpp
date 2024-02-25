#include "ex2.h"
using namespace std;

// глобальна змінна
const float π = 3.14;

class Figure {
public:
    virtual void getFigInfo() = 0;
};

class Rectangle : public Figure {
private:
    float side_1;
    float side_2;
    float area = side_1 * side_2;
public:
    Rectangle(float side_1, float side_2) : side_1(side_1), side_2(side_2){}
    void getFigInfo() override {
        cout << "Your rectangle ->" << endl;
        cout << "Area: " << area << endl;
        cout << "Side 1: " << side_1 << endl;
        cout << "Side 2: " << side_2 << endl;
    }
};

class Circle : public Figure {
private:
    float radius;
    float area = π * radius * 2;
public:
    Circle(float radius) : radius(radius) {}
    void getFigInfo() override {
        cout << "Your circle ->" << endl;
        cout << "Area: " << area << endl;
        cout << "Radius: " << radius << endl;
    }
};

class RightTriangle : public Figure {
private:
    // зробив за катетами
    float katet_1;
    float katet_2;
    float area = (katet_1 * katet_2) / 2;
public:
    RightTriangle(float katet_1, float katet_2) : katet_1(katet_1), katet_2(katet_2) {}
    void getFigInfo() override {
        cout << "Your right triangle ->" << endl;
        cout << "Area: " << area << endl;
        cout << "Katet 1: " << katet_1 << endl;
        cout << "Katet 2: " << katet_2 << endl;
    }
};

class Trapezoid : public Figure {
private:
    float base_1;
    float base_2;
    float height;
    float area = ((base_1 + base_2) / 2) * height;
public:
    Trapezoid(float base_1, float base_2, float height) : base_1(base_1), base_2(base_2), height(height) {}
    void getFigInfo() override {
        cout << "Your rectangle ->" << endl;
        cout << "Area: " << area << endl;
        cout << "base 1: " << base_1 << endl;
        cout << "base 2: " << base_2 << endl;
        cout << "Height: " << height << endl;
    }
};


// 5-те завдання
void ex1() {
    Rectangle rectangle(10, 5);
    rectangle.getFigInfo();
    cout << endl;
    Circle circle(5);
    circle.getFigInfo();
    cout << endl;
    RightTriangle RTriangle(10, 5);
    RTriangle.getFigInfo();
    cout << endl;
    Trapezoid trapezoid(10, 15, 5);
    trapezoid.getFigInfo();
}

int main()
{
    // ex1();
    // 2-ге чуть не то
    ex2();
}
