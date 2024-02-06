#pragma once
#include <iostream>
#include <string>

using namespace std;

class Verification;

class User {
private:
	string email;
	string password;
	bool verificationStatus = false;
public:
	friend class Verification;
	User() {};
	void singIn(Verification verification);
	void getUserData() {
		cout << "User email: " << email << endl;
		cout << "User password: " << password << endl;
		cout << "User ver. status: " << std::boolalpha << verificationStatus << endl;
	}
};

class Verification {
private:
	bool emailStatus = false;
	bool passwordStatus = false;
public:
	void verifyUser(User& user);
};

void User::singIn(Verification verification) {
	string email;
	string password;
	cout << "E: Input email: ";
	cin >> email;
	cout << "P: Input password: ";
	cin >> password;
	this->email = email;
	this->password = password;
	verification.verifyUser(*this);
	if (!this->verificationStatus) {
		cout << "Try again:" << endl;
		User::singIn(verification);
	}
}

void Verification::verifyUser(User& user) {
	if (user.email.empty())
	{
		cout << "- Email field is empty." << endl;
	}
	else if (user.email.find('@') == -1)
	{
		cout << "- Email has to contain `@`." << endl;
	}
	else
	{
		this->emailStatus = true;
	}

	if (user.password.empty())
	{
		cout << "- Password field is empty." << endl;
	}
	else if (user.password.length() < 8)
	{
		cout << "- Password has to contain atleast 8 symbols." << endl;
	}
	else
	{
		this->passwordStatus = true;
	}
	if (emailStatus && passwordStatus) {
		user.verificationStatus = true;
	}
}

void ex6() {
	User newUser;
	Verification ver;
	newUser.singIn(ver);
	newUser.getUserData();
}