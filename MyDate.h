#pragma once
#include <iostream>
using namespace::std;

class MyDate
{
protected:
	int day;
	int month;
	int year;
public:

	MyDate();
	MyDate(int, int, int);
	MyDate(string);
	MyDate(const MyDate&);
	~MyDate();

	int get_day();
	int get_month();
	int get_year();
	void set_day(int);
	void set_month(int);
	void set_year(int);
	void scan();
	void print();

	MyDate& operator=(const MyDate& other);
	MyDate& operator=(int);
	bool operator==(const MyDate& other);
	bool operator>(const MyDate& other);
	bool operator<(const MyDate& other);
	friend ostream& operator<<(ostream& out, const MyDate& other);
	friend istream& operator>>(istream& in, MyDate& other);
};

