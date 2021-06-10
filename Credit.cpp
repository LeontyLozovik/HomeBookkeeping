#include "Credit.h"
#include <iostream>
#include <fstream>

using namespace::std;

void Dif_Credit::pay_for_credit(Credit& credit, Finance& balance)
{
	double this_month_pay = 0, percent_pay = 0;
	percent_pay = ((credit.get_main_debt() - credit.get_payment()) * percent / 100) / 12;
	this_month_pay = credit.get_payment() + percent_pay;
	balance.set_balance(balance.get_balance() - this_month_pay);
	credit.set_main_debt(credit.get_main_debt() - credit.get_payment());
	credit.set_term(credit.get_term() - 1);
}

void Eq_Credit::pay_for_credit(Credit& credit, Finance& balance)
{
	balance.set_balance(balance.get_balance() - credit.get_payment());
	credit.set_main_debt(credit.get_main_debt() - credit.get_payment());
	credit.set_term(credit.get_term() - 1);
}

ostream& operator<<(ostream& out, const Credit& other)
{
	out << "ќсновной долг: " << other.main_debt << endl << "ѕроценты по кредиту: " << other.percent << endl << "ќставшийс€ срок в мес€цах: " << other.term << endl << "—дедующий платЄж: " << other.payment << endl;
	return out;
}

istream& operator>>(istream& in, Credit& other)
{
	cout << "¬ведите основной долг: ";
	do
	{
		cin.clear();
		rewind(stdin);
	} while (!(in >> other.main_debt));
	cout << "¬ведите проценты по кредиту: ";
	do
	{
		cin.clear();
		rewind(stdin);
	} while (!(in >> other.percent));
	cout << "¬ведите срок в мес€цах: ";
	do
	{
		cin.clear();
		rewind(stdin);
	} while (!(in >> other.term));
	return in;
}

fstream& operator<<(fstream& out, const Credit& other)
{
	out << other.main_debt << '\n' << other.percent << '\n' << other.term << '\n' << other.payment;
	return out;
}

fstream& operator>>(fstream& in, Credit& other)
{
	in >> other.main_debt;
	in >> other.percent;
	in >> other.term;
	in >> other.payment;
	return in;
}