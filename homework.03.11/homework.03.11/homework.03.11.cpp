
#include <iostream>
#include "right_triangle.h"
#include "rectangle.h"
using namespace std;

int main()
{
    right_triangle triangle;
    rectangle rectangle;

    int condition;
    cout << "Input task number (1,2)," << endl << "When you'll choose the task will repeat itself:" << endl;
    cin >> condition;
    if (condition == 1) {
        cout << "--- If you want to stop task cycle, write anything during the function choosing." << endl;
        while (true)
        {
            int choose;
            cout << endl << "Choose function:" << endl << "1. Get triangle area; 2. Set leg; 3. Get hypotenuse." << endl;
            cin >> choose;
            cout << endl;
            if (choose == 1) {
                cout << "Area: " << triangle.getArea() << endl;
            }
            else if (choose==2){
                int new_leg_1;
                int new_leg_2;

                cout << "Intup first leg: ";
                cin >> new_leg_1;
                triangle.changeFirstLeg(new_leg_1);
                
                cout << "Intup second leg: ";
                cin >> new_leg_2;
                triangle.changeSecondLeg(new_leg_2);
            }
            else if (choose==3){
                cout << "Hypotenuse: " << triangle.getHypotenuse() << endl;
            }
            else
            {
                break;
            }
        }
    }
    else if (condition == 2) {
        cout << "--- If you want to stop task cycle, write anything during the function choosing." << endl;
        while (true)
        {
            int choose_func;
            cout << endl << "Choose function:" << endl << "1. Get rectangle area; 2. Set width, height; 3. Get perimeter." << endl;
            cin >> choose_func;
            cout << endl;
            if (choose_func == 1) {
                cout << "Area: " << rectangle.getArea() << endl;
            }
            else if (choose_func == 2) {
                int new_width;
                int new_height;

                cout << "Intup width: ";
                cin >> new_width;
                rectangle.changeWidth(new_width);

                cout << "Intup height: ";
                cin >> new_height;
                rectangle.changeHeight(new_height);
            }
            else if (choose_func == 3) {
                cout << "Perimeter: " << rectangle.getPerimeter() << endl;
            }
            else
            {
                break;
            }
        }
    }
}