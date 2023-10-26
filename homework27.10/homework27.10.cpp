#include <iostream>
#include <algorithm> 
using namespace std;
int main()
{
    cout << "---------------FIRST TASK---------------" << endl;
    int seconds=0;
    int minutes=0;
    int hours=0;
    int days=0;
    cout << "input seconds qty: ";
    cin >> seconds;
    while (seconds >= 60) {
        seconds -= 60;
        minutes += 1;
    }
    while (minutes >= 60) {
        minutes -= 60;
        hours += 1;
    }
    while (hours >= 24) {
        hours -= 24;
        days += 1;
    }
    if (days == 0) {
        cout << hours << ":" << minutes << ":" << seconds << endl;
        cout << "Time till midnight - ";
        cout << 23-hours << ":" << 59-minutes << ":" << 60-seconds << endl;
    }
    else {
        cout << days << ":" << hours << ":" << minutes << ":" << seconds << endl;
        cout << "Midnight had already passed.";
    }
    // це був мій перший математичний спосіб, проте чуть інший результат
    // cout <<"Hours:" << ((seconds-(seconds%60))/60)/60 << endl << "Minutes:" << (seconds-(seconds%60))/60 << endl <<"Seconds:" <<seconds;

    cout << endl << "---------------SECOND TASK---------------" << endl;

    int number;
    cout << "Input number : ";
    cin >> number;
    int reversed_number = 0;
    while (number > 0) {
        // кожного разу знаходимо останню цифру та добавляєм її
        reversed_number = reversed_number * 10 + number % 10;
        // після чого ми зменшуєм то число щоб позбутися цифри яку ми знайшли
        number = number / 10;
    }
    cout << "Reversed: " << reversed_number;
}