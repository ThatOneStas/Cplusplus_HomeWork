#include <iostream>
#include "ex2.h"
#include "ex3.h"
#include "ex4.h"
#include "ex5.h"
#include "ex6.h"


using namespace std;

class Dot {
private:
    int x_position;
    int y_position;
public:
    Dot(int x, int y) : x_position(x), y_position(y)
    {}
    void getDotData() {
        cout << "X: " << this->x_position;
        cout << ", Y: " << this->y_position << ";" << endl;
    }
    int getDotX() {
        return this->x_position;
    }
    int getDotY() {
        return this->y_position;
    }
    friend Dot operator+(Dot dot_1, Dot dot_2) {
        Dot new_dot((dot_1.getDotX()+dot_2.getDotX()), (dot_1.getDotY() + dot_2.getDotY()));
        return new_dot;
    }
    friend Dot operator-(Dot dot_1, Dot dot_2) {
        Dot new_dot((dot_1.getDotX() - dot_2.getDotX()), (dot_1.getDotY() - dot_2.getDotY()));
        return new_dot;
    }
    // зразу все запихнув в ==
    friend void operator==(Dot dot_1, Dot dot_2) {
        if (dot_1.x_position == dot_2.x_position && dot_1.y_position == dot_2.y_position) {
            cout << "The dots are equal" << endl;
        }
        else {
            if (dot_1.x_position > dot_2.x_position) {
                cout << "1) dot_1.x > dot_2.x" << endl;
            }
            else if (dot_1.x_position == dot_2.x_position) {
                cout << "1) dot_1.x = dot_2.x" << endl;
            }
            else {
                cout << "1) dot_2.x > dot_1.x" << endl;

            }
            if (dot_1.y_position > dot_2.y_position) {
                cout << "2) dot_1.y > dot_2.y" << endl;
            }
            else if (dot_1.y_position == dot_2.y_position) {
                cout << "2) dot_1.y = dot_2.y" << endl;
            }
            else {
                cout << "2) dot_2.y > dot_1.y" << endl;

            }
        }
    }
    void operator++() {
        this->x_position += 1;
        this->y_position += 1;
    }
    void operator--() {
        this->x_position -= 1;
        this->y_position -= 1;
    }
    void operator++(int) {
        this->x_position += 1;
        this->y_position += 1;
    }
    void operator--(int) {
        this->x_position -= 1;
        this->y_position -= 1;
    }
    friend void operator<<(ostream& out, Dot dot) {
        out << "(out ver) X: " << dot.x_position << ", Y: " << dot.y_position << ";" << endl;
    }
    friend void operator>>(istream& in, Dot& dot) {
        int new_x;
        int new_y;
        cout << "New X: ";
        in >> new_x;
        cout << "New Y: ";
        in >> new_y;
        dot.x_position = new_x;
        dot.y_position = new_y;
    }
};

void ex1() {
    Dot n1(15, 5);
    n1.getDotData();
    Dot n2(18, 4);
    n2.getDotData();
    Dot n3 = n1 + n2;
    n3.getDotData();
    n1 = n1 - n3;
    n1.getDotData();
    ++n1;
    n1++;
    //n1.getDotData();
    cout << n1;
    cin >> n1;
    n1.getDotData();

    //Dot n11( 11,11 );
    //Dot n22(11, 12);
    // n11 == n22;
}

int main()
{
    // ex1();
    // ex2();
    // ex3();
    // ex4();
    // ex5();
    ex6();
}