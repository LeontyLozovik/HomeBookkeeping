#include "Finance.h"
#include <iostream>
#include <fstream>
using namespace ::std;

Finance::Finance()
{
	balance = 0;
}

Finance::Finance(double a)
{
	balance = a;
}

Finance::Finance(const Finance& other)
{
	this->balance = other.balance;
}

Finance::~Finance()
{ };

void Finance::set_balance(double a)
{
	this->balance = a;
}

double Finance::get_balance()
{
	return balance;
}

Finance& Finance::operator=(const Finance& other)
{
	this->balance = other.balance;
	return (*this);
}

bool Finance::operator==(const Finance& other)
{
	if (this->balance == other.balance)
		return (1);
	return (0);
}

bool Finance::operator>(const Finance& other)
{
	if (this->balance > other.balance)
		return (1);
	return (0);
}

bool Finance::operator<(const Finance& other)
{
	if (this->balance < other.balance)
		return (1);
	return (0);
}

ostream& operator<<(ostream& out, const Finance& other)
{
	out << other.balance << endl;
	return out;
}

istream& operator>>(istream& in, Finance& other)
{
	do
	{
		system("CLS");
		cout << "Баланс: ";
		cin.clear();
		rewind(stdin);
	} while (!(in >> other.balance));
	return in;
}

fstream& operator>>(fstream& in, Finance& other)
{
	in >> other.balance;
	return in;
}