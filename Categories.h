#pragma once
#include "Finance.h"
#include "MyDate.h"
#include <string.h>
using namespace::std;

class Categories
{
protected:
	int name_of_category;
	double cost;
	string name;
	MyDate date;
public:
	enum All_categories { Health, Family, Shopping, Food, Entertainment, Presents, Transport, Other };
	Categories();
	Categories(int, double, string, MyDate);
	~Categories() {};
	Categories(const Categories& other);

	int get_name_of_category() { return name_of_category; };
	double get_cost() { return cost; };
	string get_name() { return name; };
	MyDate get_date() { return date; };
	int get_day() { return date.get_day(); }
	int get_month() { return date.get_month(); }
	int get_year() { return date.get_year(); }
	void set_cost(double a) { cost = a; };
	void set_name(string a) { name = a; };
	void set_cost(MyDate a) { date = a; };

	Categories& operator=(const Categories& other);
	bool operator==(const Categories& other);
	bool operator>(const Categories& other);
	bool operator<(const Categories& other);
	friend ostream& operator<<(ostream& out, Categories& other);
	friend istream& operator>>(istream& in, Categories& other);
	friend fstream& operator<<(fstream& out, const Categories& other);
	friend fstream& operator>>(fstream& in, Categories& other);
};

class Income
{
protected:
	double cost;
	MyDate date;
public:
	Income();
	Income(double, MyDate);
	~Income() {};

	double get_cost() { return cost; };
	MyDate get_date() { return date; };
	int get_month() { return date.get_month(); }
	int get_year() { return date.get_year(); }
	void set_cost(double cost) { this->cost = cost; };
	void set_date(MyDate date) { this->date = date; };
	Income& operator=(const Income& other);
	friend ostream& operator<<(ostream& out, Income& other);
	friend istream& operator>>(istream& in, Income& other);
	friend fstream& operator<<(fstream& out, const Income& other);
	friend fstream& operator>>(fstream& in, Income& other);
};