#pragma once
#include "MyDate.h";
#include <string>
using namespace::std;

class Const_income
{
private:
	double income;
	MyDate date;
public:
	Const_income();
	Const_income(double);
	void set_income(double);
	double get_income();
	int get_day();
	int get_month();
	int get_year();
	friend ostream& operator<<(ostream& out, Const_income& other);
	friend istream& operator>>(istream& in, Const_income& other);
};

class Const_outcome
{
private:
	double outcome;
	MyDate date;
public:
	Const_outcome();
	Const_outcome(double);
	void set_outcome(double);
	double get_outcome();
	int get_day();
	int get_month();
	int get_year();
	friend ostream& operator<<(ostream& out, Const_outcome& other);
	friend istream& operator>>(istream& in, Const_outcome& other);
};