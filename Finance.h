#pragma once
#include <string>
using namespace ::std;

class Finance
{
	double balance;
public:

	Finance(double a);
	Finance();
	Finance(const Finance& other);
	~Finance();

	double get_balance();
	void set_balance(double a);

	Finance& operator=(const Finance& other);
	bool operator==(const Finance& other);
	bool operator>(const Finance& other);
	bool operator<(const Finance& other);
	friend ostream& operator<<(ostream& out, const Finance& other);
	friend istream& operator>>(istream& in, Finance& other);
	friend fstream& operator>>(fstream& in, Finance& other);
};

