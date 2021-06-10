#include "MyDate.h"
#include <iostream>
#include <fstream>
#include <time.h>

#pragma warning (disable : 4996)
using namespace::std;

MyDate::MyDate()
{
	day = 0;
	month = 0;
	year = 0;
}

MyDate::MyDate(int a, int b, int c)
{
	day = a;
	month = b;
	year = c;
}

MyDate::MyDate(string a)
{
	if (a == "now")
	{
		time_t now;
		struct tm nowLocale;
		now = time(NULL);
		nowLocale = *localtime(&now);

		day = nowLocale.tm_mday;
		month = nowLocale.tm_mon;
		year = nowLocale.tm_year;
	}
	else
	{
		day = 0;
		month = 0;
		year = 0;
	}
}

MyDate::MyDate(const MyDate& other)
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
}

MyDate::~MyDate()
{

}

int MyDate::get_day()
{
	return day;
}

int MyDate::get_month()
{
	return month;
}

int MyDate::get_year()
{
	return year;
}

void MyDate::set_day(int a)
{
	this->day = a;
}

void MyDate::set_month(int a)
{
	this->month = a;
}

void MyDate::set_year(int a)
{
	this->year = a;
}

void MyDate::scan()
{
	cout << "Введите дату: " << endl;
	do
	{
		do
		{
			cout << "День: ";
			cin.clear();
			rewind(stdin);
		} while (!(cin >> day));
	} while (day < 1 || day > 31);
	do
	{
		do
		{
			cout << "Месяц: ";
			cin.clear();
			rewind(stdin);
		} while (!(cin >> month));
	} while (month < 1 || month > 12);
	month -= 1;
	do
	{
		cout << "Год: ";
		cin.clear();
		rewind(stdin);
	} while (!(cin >> year));
	year -= 1900;
}

void MyDate::print()
{
	cout << "Дата - " << day << "." << month + 1 << "." << year + 1900;
}

MyDate& MyDate::operator=(const MyDate& other)
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
	return (*this);
}

MyDate& MyDate::operator=(int a)
{
	this->day = a;
	this->month = a;
	this->year = a;
	return (*this);
}


bool MyDate::operator==(const MyDate& other)
{
	if (this->day == other.day && this->month == other.month && this->year == other.year)
		return (1);
	return (0);
}

bool MyDate::operator>(const MyDate& other)
{
	if (this->year > other.year)
		return 1;
	else if (this->month > other.month)
		return 1;
	else if (this->day > other.day)
		return 1;
	return 0;
}

bool MyDate::operator<(const MyDate& other)
{
	if (this->year < other.year)
		return 1;
	else if (this->month < other.month)
		return 1;
	else if (this->day < other.day)
		return 1;
	return 0;
}

ostream& operator<<(ostream& out, const MyDate& other)
{
	out << other.day << '\n' << other.month << '\n' << other.year;
	return out;
}

istream& operator>>(istream& in, MyDate& other)
{
	in >> other.day;
	in >> other.month;
	in >> other.year;
	return in;
}