#pragma once
#include "Finance.h"
class Credit
{
protected:
	double main_debt;
	double percent;
	int term;
	double payment;
public:
	Credit() { main_debt = 0; percent = 0; term = 0; payment = 0; }
	~Credit() {}
	double get_main_debt() { return main_debt; }
	double get_percent() { return percent; }
	int get_term() { return term; }
	double get_payment() { return payment; }
	void set_payment(double a) { payment = a; }
	void set_main_debt(double a) { main_debt = a; }
	void set_percent(double a) { percent = a; }
	void set_term(int a) { term = a; }
	virtual void pay_for_credit(Credit&, Finance&) = 0;
	friend ostream& operator<<(ostream& out, const Credit& other);
	friend istream& operator>>(istream& in, Credit& other);
	friend fstream& operator<<(fstream& out, const Credit& other);
	friend fstream& operator>>(fstream& in, Credit& other);
};

class Dif_Credit : public Credit
{
public:
	void set_payment()
	{
		payment = main_debt / term;
	}
	void pay_for_credit(Credit&, Finance&) override;
};

class Eq_Credit : public Credit
{
public:
	void set_payment()
	{
		payment = (main_debt + (main_debt * percent / 100 * term / 12)) / term;
	}
	void pay_for_credit(Credit&, Finance&) override;
};
