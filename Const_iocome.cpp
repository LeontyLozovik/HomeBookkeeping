#include "Const_iocome.h"
#include <iostream>
#include <fstream>

using namespace::std;

Const_income::Const_income()
{
	this->income = 0;
}

Const_income::Const_income(double a)
{
	this->income = a;
}

void Const_income::set_income(double a)
{
	income = a;
	date = 0;
}

double Const_income::get_income()
{
	return income;
}

int Const_income::get_day()
{
	return date.get_day();
}

int Const_income::get_month()
{
	return date.get_month();
}

int Const_income::get_year()
{
	return date.get_year();
}

ostream& operator<<(ostream& out, Const_income& other)
{
	out << other.income << endl;
	other.date.print();
	return out;
}

istream& operator>>(istream& in, Const_income& other)
{
	do
	{
		system("CLS");
		cout << "¬ведите сумму, которую вы получаете в этот день: ";
		cin.clear();
		rewind(stdin);
	} while (!(in >> other.income));
	cout << "¬ведите число(мес€ца) поступлени€: ";
	int b;
	do
	{
		do
		{
			cin.clear();
			rewind(stdin);
		} while (!(cin >> b));
	} while (b < 1 || b > 31);
	other.date.set_day(b);
	return in;
}

Const_outcome::Const_outcome()
{
	this->outcome = 0;
}

Const_outcome::Const_outcome(double a)
{
	this->outcome = a;
}

void Const_outcome::set_outcome(double a)
{
	outcome = a;
}

double Const_outcome::get_outcome()
{
	return outcome;
}

int Const_outcome::get_day()
{
	return date.get_day();
}

int Const_outcome::get_month()
{
	return date.get_month();
}

int Const_outcome::get_year()
{
	return date.get_year();
}

ostream& operator<<(ostream& out, Const_outcome& other)
{
	out << other.outcome << endl;
	other.date.print();
	return out;
}

istream& operator>>(istream& in, Const_outcome& other)
{
	do
	{
		system("CLS");
		cout << "¬ведите сколько вы платите в этот день: ";
		cin.clear();
		rewind(stdin);
	} while (!(in >> other.outcome));

	cout << "¬ведите число(мес€ца) поступлени€: ";
	int b;
	do
	{
		do
		{
			cin.clear();
			rewind(stdin);
		} while (!(cin >> b));
	} while (b < 1 || b > 31);
	other.date.set_day(b);
	return in;
}