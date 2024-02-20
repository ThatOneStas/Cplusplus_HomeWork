#pragma once
#include <iostream>
#include "vector"
using namespace std;

class BaseTransport {
protected:
	static const int ticket_price = 0;
public:
	BaseTransport(){}
	virtual int getTicketPrice() {
		return ticket_price;
	}
	virtual string getTransportName() {
		return "Base";
	}
};

class Taxi : public BaseTransport {
private:
	static const int ticket_price = 20;
public:
	Taxi() {}
	int getTicketPrice() override {
		return ticket_price;
	}
	string getTransportName() override {
		return "Taxi";
	}
};

class Train : public BaseTransport {
private:
	static const int ticket_price = 100;
public:
	Train() {}
	int getTicketPrice() override {
		return ticket_price;
	}
	string getTransportName() override {
		return "Train";
	}
};

class Plane : public BaseTransport {
private:
	static const int ticket_price = 500;
public:
	Plane() {}
	int getTicketPrice() override {
		return ticket_price;
	}
	string getTransportName() override {
		return "Plane";
	}
};

template <typename T1, typename T2>
void compareTicketsPrice(T1 transport_1,T2 transport_2) {
	Taxi taxi;
	Plane plane;
	Train train;

	// обробив цей варіант також
	/*if (transport_1.getTicketPrice() > transport_2.getTicketPrice())
	{
		cout << transport_1.getTransportName() << " ticket`s price is higher than " << transport_2.getTransportName()
			<< " ticket`s price (" << transport_1.getTicketPrice() << " > " << transport_2.getTicketPrice() << ")" << endl;
	}
	else if (transport_2.getTicketPrice() > transport_1.getTicketPrice())
	{
		cout << transport_2.getTransportName() << " ticket`s price is higher than " << transport_1.getTransportName()
			<< " ticket`s price (" << transport_2.getTicketPrice() << " > " << transport_1.getTicketPrice() << ")" << endl;
	}
	else if (transport_2.getTicketPrice() == transport_1.getTicketPrice()) {
		cout << "They are equal (" << transport_1.getTicketPrice() << ")" << endl;
	}
	else {
		cout << "It's the same transports." << endl;
	}*/
	//

	// мій колхозний варіант
	if constexpr ((std::is_same<T1, Plane>().value && std::is_same<T2, Train>().value) || (std::is_same<T1, Train>().value && std::is_same<T2, Plane>().value)) {
		if (plane.getTicketPrice() >train.getTicketPrice()) {
			cout << "Plane ticket`s price is higher than Train ticket`s price (" << plane.getTicketPrice() << " > " << train.getTicketPrice() << ")" << endl;
		}
		else if (plane.getTicketPrice() < train.getTicketPrice()) {
			cout << "Train ticket`s price is higher than Plane ticket`s price (" << train.getTicketPrice() << " > " << plane.getTicketPrice() << ")" << endl;
		}
		else {
			cout << "They are equal (" << train.getTicketPrice() << " = " << plane.getTicketPrice() << endl;
		}
	}
	else if constexpr ((std::is_same<T1, Train>().value && std::is_same<T2, Taxi>().value) || (std::is_same<T1, Taxi>().value && std::is_same<T2, Train>().value)) {
		if (plane.getTicketPrice() > train.getTicketPrice()) {
			cout << "Train ticket`s price is higher than Taxi ticket`s price (" << train.getTicketPrice() << " > " << taxi.getTicketPrice() << ")" << endl;
		}
		else if (plane.getTicketPrice() < train.getTicketPrice()) {
			cout << "Taxi ticket`s price is higher than Train ticket`s price (" << taxi.getTicketPrice() << " > " << train.getTicketPrice() << ")" << endl;
		}
		else {
			cout << "They are equal (" << train.getTicketPrice() << " = " << taxi.getTicketPrice() << endl;
		}
	}
	else if constexpr ((std::is_same<T1, Plane>().value && std::is_same<T2, Taxi>().value) || (std::is_same<T1, Taxi>().value && std::is_same<T2, Plane>().value)) {
		if (plane.getTicketPrice() > train.getTicketPrice()) {
			cout << "Plane ticket`s price is higher than Taxi ticket`s price (" << plane.getTicketPrice() << " > " << taxi.getTicketPrice() << ")" << endl;
		}
		else if (plane.getTicketPrice() < train.getTicketPrice()) {
			cout << "Taxi ticket`s price is higher than Plane ticket`s price (" << taxi.getTicketPrice() << " > " << plane.getTicketPrice() << ")" << endl;
		}
		else {
			cout << "They are equal (" << plane.getTicketPrice() << " = " << taxi.getTicketPrice() << endl;
		}
	}
	else {
		cout << "It's the same transports." << endl;
	}
}

void ex2() {
	Taxi taxi;
	Plane plane;
	Train train;
	compareTicketsPrice(taxi, plane);
	compareTicketsPrice(train, taxi);
	compareTicketsPrice(taxi, taxi);
}

