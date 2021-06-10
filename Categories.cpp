#include "Categories.h"
#include "MyDate.h"
#include <iostream>
#include <fstream>
#include <string>
#pragma warning (disable : 4996)
using namespace ::std;

Categories::Categories(int a, double b, string c, MyDate d)
{
	name_of_category = a;
	cost = b;
	name = c;
	date = d;
}

Categories::Categories(const Categories& other)
{
	this->name_of_category = other.name_of_category;
	this->cost = other.cost;
	this->name = other.name;
	this->date = other.date;
}

Categories::Categories()
{
	name_of_category = -1;
	cost = 0;
	name = "unknown";
}

Categories& Categories::operator=(const Categories& other)
{
	this->name_of_category = other.name_of_category;
	this->cost = other.cost;
	this->name = other.name;
	this->date = other.date;
	return (*this);
}

bool Categories::operator==(const Categories& other)
{
	if (this->name_of_category == other.name_of_category && this->cost == other.cost && this->name == other.name && this->date == other.date)
		return (1);
	return (0);
}

bool Categories::operator>(const Categories& other)
{
	if (this->name_of_category > other.name_of_category && this->cost > other.cost && this->name > other.name && this->date > other.date)
		return (1);
	return (0);
}

bool Categories::operator<(const Categories& other)
{
	if (this->name_of_category < other.name_of_category && this->cost < other.cost && this->name < other.name && this->date < other.date)
		return (1);
	return (0);
}

ostream& operator<<(ostream& out, Categories& other)
{
	out << "��������� - ";
	switch (other.name_of_category)
	{
	case 0: out << "��������" << endl; break;
	case 1: out << "�����" << endl; break;
	case 2: out << "������" << endl; break;
	case 3: out << "���" << endl; break;
	case 4: out << "�����������" << endl; break;
	case 5: out << "�������" << endl; break;
	case 6: out << "���������" << endl; break;
	case 7: out << "������" << endl; break;
	}
	out << "��������� - " << other.cost << endl << other.name << endl;
	other.date.print();
	return out;
}

istream& operator>>(istream& in, Categories& other)
{
	cout << "�������� ���������: " << endl;
	cout << "0 - ��������" << endl << "1 - �����" << endl << "2 - ������" << endl << "3 - ���" << endl << "4 - �����������" << endl << "5 - �������" << endl << "6 - ���������" << endl << "7 - ������" << endl;
	do
	{
		do
		{
			cin.clear();
			rewind(stdin);
		} while (!(in >> other.name_of_category));
	} while (other.name_of_category > 7 || other.name_of_category < 0);
	
	cout << "����: ";
	do
	{
		cin.clear();
		rewind(stdin);
	} while (!(in >> other.cost));
	rewind(stdin);
	cout << "���� �� ��������� ������? ";
	getline(in, other.name);

	cout << "1 - ����� ��������� ���� " << endl << "2 - B����� ����������� ���� " << endl;
	int q;
	do
	{
		do
		{
			do
			{
				cin.clear();
				rewind(stdin);
			} while (!(in >> q));
		} while (q < 1 || q > 2);
		switch (q)
		{
		case 1:
		{
			MyDate nowLocale("now");
			other.date = nowLocale;
			break;
		}
		case 2: other.date.scan(); break;
		}
	} while (q != 1 && q != 2);
	return in;
}

fstream& operator<<(fstream& out, const Categories& other)
{
	out << other.name << '\n' << other.cost << '\n' << other.date << '\n' << other.name_of_category;
	return out;
}

fstream& operator>>(fstream& in, Categories& other)
{
	getline(in, other.name);
	in >> other.cost;
	in >> other.date;
	in >> other.name_of_category;
	return in;
}

ostream& operator<<(ostream& out, Income& other)
{
	out << "��������: " << other.cost << endl;
	other.date.print();
	return out;
}

istream& operator>>(istream& in, Income& other)
{
	cout << "������� ��������� �����: ";
	do
	{
		cin.clear();
		rewind(stdin);
	} while (!(in >> other.cost));
	cout << "1 - ����� ��������� ���� " << endl << "2 - B����� ����������� ���� " << endl;
	int q;
	do
	{
		do
		{
			do
			{
				
				cin.clear();
				rewind(stdin);
			} while (!(in >> q));
		} while (q < 1 || q > 2);
		switch (q)
		{
		case 1:
		{
			MyDate nowLocale("now");
			other.date = nowLocale;
			break;
		}
		case 2: other.date.scan(); break;
		}
	} while (q != 1 && q != 2);
	return in;
}

fstream& operator<<(fstream& out, const Income& other)
{
	out << other.cost << '\n' << other.date;
	return out;
}

fstream& operator>>(fstream& in, Income& other)
{
	in >> other.cost;
	in >> other.date;
	return in;
}

Income::Income()
{
	this->cost = 0;
	this->date = 0;
}

Income::Income(double a, MyDate b)
{
	this->cost = a;
	this->date = b;
}

Income& Income::operator=(const Income& other)
{
	this->cost = other.cost;
	this->date = other.date;
	return *this;
}
