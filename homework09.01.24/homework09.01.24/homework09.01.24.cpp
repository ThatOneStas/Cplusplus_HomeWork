#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int compareStrings(string str_1, string str_2) {
    if (str_1.length() > str_2.length()) {
        return 1;
    }
    else if (str_1.length() < str_2.length()) {
        return (-1);
    }
    else
    {
        return 0;
    }
}

int stringToNum(string str) {
    //char num[] = "0";
    //for (int i = 0;i < str.length();i++) {
    //    num[i] = str[i];
    //}
    //return atoi(num);
    return stoi(str);
}

string intToString(int num) {
    return to_string(num);
}

string Uppercase(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}

string Lowercase(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

string reverseString(string str) {
    reverse(str.begin(), str.end());
    return str;
}

bool palindromChecker(string str) {
    if (str == reverseString(str)) {
        return true;
    }
    else 
    {
        return false;
    }
}

int main()
{
    string str_1 = "Random small text";
    string str_2 = "Random bigger text";
    cout << "Compare result: " << compareStrings(str_1, str_2) << endl;
    cout << endl;


    cout << "String to int:" << endl;
    string str_number = "123";
    cout << str_number << " + 1 = " << stringToNum(str_number) + 1 << endl;
    cout << endl;


    cout << "Int to string:" << endl;
    int number = 123;
    cout << intToString(number) << " + 1 = " << number + 1 << endl;
    cout << endl;


    cout << "Lowercase to Uppercase:" << endl;
    string lowcase_str = "abc def";
    cout << lowcase_str << " to " << Uppercase(lowcase_str) << endl;
    cout << endl;

    cout << "Uppercese to Lowercase:" << endl;
    string uppcase_str = "ABC DEF";
    cout << uppcase_str << " to " << Lowercase(uppcase_str) << endl;
    cout << endl;

    cout << "Reverse:" << endl;
    string reverse_str = "Some Text";
    cout << reverse_str << " to " << reverseString(reverse_str) << endl;
    cout << endl;

    cout << "Check if palindrom (0 or 1):" << endl;
    cout << "(0 - false, 1 - true)" << endl;
    string palindrom_str = "abc cba";
    cout << "'" << palindrom_str << "'" << " is: " << palindromChecker(palindrom_str) << endl;
    cout << endl;
}
