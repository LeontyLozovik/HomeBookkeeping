#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <fstream>
#include <exception>
#include <conio.h>
#include "Categories.h"
#include "Finance.h"
#include "MyDate.h"
#include "Const_iocome.h"
#include "Credit.h"
#include "MyFile.h"

#pragma warning (disable : 4996)
using namespace::std;

void start_menu(Finance& a)
{
	system("CLS");
	cout << "��� ������: " << a.get_balance() << endl;
	cout << "��������� ��������: " << endl;
	cout << "1 - ������� ���������� �����" << endl;
	cout << "2 - �������� ���������� �����" << endl;
	cout << "3 - �������� �����������" << endl;
	cout << "4 - �������� ������" << endl;
}

string name_of_categories(int a)
{
	switch (a)
	{
	case 0: return("Health"); break;
	case 1: return("Family"); break;
	case 2: return("Shopping"); break;
	case 3: return("Food"); break;
	case 4: return("Entertainment"); break;
	case 5: return("Presents"); break;
	case 6: return("Transport"); break;
	case 7: return("Other"); break;
	}
}
string chouse_file(Categories& a)
{
	switch (a.get_name_of_category())
	{
	case 0: return(name_of_categories(a.get_name_of_category()) + ".txt"); break;
	case 1: return(name_of_categories(a.get_name_of_category()) + ".txt"); break;
	case 2: return(name_of_categories(a.get_name_of_category()) + ".txt"); break;
	case 3: return(name_of_categories(a.get_name_of_category()) + ".txt"); break;
	case 4: return(name_of_categories(a.get_name_of_category()) + ".txt"); break;
	case 5: return(name_of_categories(a.get_name_of_category()) + ".txt"); break;
	case 6: return(name_of_categories(a.get_name_of_category()) + ".txt"); break;
	case 7: return(name_of_categories(a.get_name_of_category()) + ".txt"); break;
	}
};
string chouse_file(int a)
{
	switch (a)
	{
	case 0: return(name_of_categories(a) + ".txt"); break;
	case 1: return(name_of_categories(a) + ".txt"); break;
	case 2: return(name_of_categories(a) + ".txt"); break;
	case 3: return(name_of_categories(a) + ".txt"); break;
	case 4: return(name_of_categories(a) + ".txt"); break;
	case 5: return(name_of_categories(a) + ".txt"); break;
	case 6: return(name_of_categories(a) + ".txt"); break;
	case 7: return(name_of_categories(a) + ".txt"); break;
	}
};

void pay(Finance& a)
{
	Categories pay_info;
	cin >> pay_info;
	a.set_balance(a.get_balance() - pay_info.get_cost());

	string path = chouse_file(pay_info);

	MyFile<Categories> fout;
	try
	{
		if (!fout.Open_to_add(path))
			throw exception("������ �������� ����� ��� ������");
		fout.Fin(pay_info);
		fout.fclose();
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

void date_decryption(MyDate& date)
{
	Categories decrypt;
	MyFile<Categories> fin;
	vector<Categories> vec;
	for (int i = 0; i <= Categories::Other; i++)
	{
		string path = chouse_file(i);
		fin.Open_to_read(path);
		while (fin.Fout(decrypt))
		{
			if (decrypt.get_date() == date)
			{
				vec.push_back(decrypt);
			}
		}
		fin.fclose();
	}
	for (int i = 0; i < vec.size(); i++)
	{
		cout << endl << vec[i] << endl;
	}
	if (vec.empty())
		cout << "� ���� ���� �� ���� ��������" << endl;
	vec.clear();

	cout << "��� ���������� ������� ����� ������...";
	getch();
}

void month_decryption(MyDate& date, int a)
{
	Categories decrypt;
	MyFile<Categories> fin;
	vector<Categories> vec;
	string path = chouse_file(a);
	fin.Open_to_read(path);
	while (fin.Fout(decrypt))
	{
		if (decrypt.get_month() == date.get_month() && decrypt.get_year() == date.get_year())
		{
			vec.push_back(decrypt);
		}
	}
	fin.fclose();

	Categories key;
	int i = 0;
	for (int j = 1; j < vec.size(); j++) 
	{
		key = vec[j];
		i = j - 1;
		while (i >= 0 && vec[i].get_date() > key.get_date()) 
		{
			vec[i + 1] = vec[i];
			i = i - 1;
			vec[i + 1] = key;
		}
	}

	for (int i = 0; i < vec.size(); i++)
	{
		cout << endl << vec[i] << endl;
	}
	if (vec.empty())
		cout << "�� ���� ����� �� ���� �������� � ������ ���������" << endl;
	vec.clear();

	cout << "��� ���������� ������� ����� ������...";
	getch();
}

void month_decryption(MyDate& date)
{
	Categories decrypt;
	MyFile<Categories> fin;
	vector<Categories> vec;
	for (int i = Categories::Health; i <= Categories::Other; i++)
	{
		string path = chouse_file(i);
		fin.Open_to_read(path);
		while (fin.Fout(decrypt))
		{
			if (decrypt.get_month() == date.get_month() && decrypt.get_year() == date.get_year())
			{
				vec.push_back(decrypt);
			}
		}
		fin.fclose();
	}

	Categories key;
	int i = 0;
	for (int j = 1; j < vec.size(); j++)
	{
		key = vec[j];
		i = j - 1;
		while (i >= 0 && vec[i].get_date() > key.get_date())
		{
			vec[i + 1] = vec[i];
			i = i - 1;
			vec[i + 1] = key;
		}
	}

	for (int i = 0; i < vec.size(); i++)
	{
		cout << endl << vec[i] << endl;
	}
	if (vec.empty())
		cout << "�� ���� ����� �� ���� ��������" << endl;
	vec.clear();

	cout << "��� ���������� ������� ����� ������...";
	getch();
}

void income_decryption(MyDate& date)
{
	Income jackpot;
	fstream fout;
	vector<Income> vec;
	fout.open("income.txt");
	while (fout.read((char*)&jackpot, sizeof(Income)))
	{
		if (jackpot.get_month() == date.get_month() && jackpot.get_year() == date.get_year())
		{
			vec.push_back(jackpot);
		}
	}
	fout.close();

	Income key;
	int i = 0;
	for (int j = 1; j < vec.size(); j++)
	{
		key = vec[j];
		i = j - 1;
		while (i >= 0 && vec[i].get_date() > key.get_date())
		{
			vec[i + 1] = vec[i];
			i = i - 1;
			vec[i + 1] = key;
		}
	}

	for (int i = 0; i < vec.size(); i++)
	{
		cout << endl << vec[i] << endl;
	}
	if (vec.empty())
		cout << "�� ���� ����� �� ���� �������" << endl;
	vec.clear();

	cout << "��� ���������� ������� ����� ������...";
	getch();
}

void spent_for_category(MyDate& date)
{
	Categories decrypt;
	MyFile<Categories> fin;
	double spent, spent_all = 0;
	for (int i = Categories::Health; i <= Categories::Other; i++)
	{
		spent = 0;
		string path = chouse_file(i);
		fin.Open_to_read(path);
		while (fin.Fout(decrypt))
		{
			if (decrypt.get_month() == date.get_month() && decrypt.get_year() == date.get_year())
			{
				spent += decrypt.get_cost();
			}
		}
		cout << "� ��������� " << name_of_categories(i) << " ���� ��������� " << spent << endl;
		spent_all += spent;
		fin.fclose();
	}
	cout << endl << "����� �� ����� ���� ���������: " << spent_all << endl << endl;

	cout << "��� ���������� ������� ����� ������...";
	getch();
}

void for_all_time(int a)
{
	Categories decrypt;
	MyFile<Categories> fin;
	vector<Categories> vec;
	string path = chouse_file(a);
	fin.Open_to_read(path);
	while (fin.Fout(decrypt))
		vec.push_back(decrypt);
	fin.fclose();

	Categories key;
	int i = 0;
	for (int j = 1; j < vec.size(); j++)
	{
		key = vec[j];
		i = j - 1;
		while (i >= 0 && vec[i].get_date() > key.get_date())
		{
			vec[i + 1] = vec[i];
			i = i - 1;
			vec[i + 1] = key;
		}
	}
	for (int i = 0; i < vec.size(); i++)
	{
		cout << endl << vec[i] << endl;
	}
	if (vec.empty())
		cout << "�������� ��� �� ����" << endl;
	vec.clear();

	cout << "��� ���������� ������� ����� ������...";
	getch();
}

void decryption()
{
	int q;
	do
	{
		do
		{
			system("CLS");
			cout << "�������� �����������: " << endl << "1 - �� ����" << endl << "2 - �� ��������� �����" << endl << "3 - ��� ���������� ���������" << endl << "4 - ��� ������� �� ��������� �����" << endl;
			cin.clear();
			rewind(stdin);
		} while (!(cin >> q));
	} while (q > 4 || q < 1);
	switch (q)
	{
	case 1:
	{
		MyDate date;
		date.scan();
		date_decryption(date);
		break;
	}
	case 2:
	{
		MyDate date("now");
		month_decryption(date);
		break;
	}
	case 3:
	{

		int cat;
		do
		{
			do
			{
				system("CLS");
				cout << "�������� ��������� : " << endl;
				cout << "0 - ��������" << endl << "1 - �����" << endl << "2 - ������" << endl << "3 - ���" << endl << "4 - �����������" << endl << "5 - �������" << endl << "6 - ���������" << endl << "7 - ������" << endl;
				rewind(stdin);
				cin.clear();
			} while (!(cin >> cat));
		} while (cat > 7 || cat < 0);

		int a;
		do
		{
			system("CLS");
			cout << "��� ������ ��������� �������� ����������� " << endl << "1 - �� �� �����" << endl << "2 - �� ��������� �����" << endl;
			rewind(stdin);
			cin.clear();
		} while (!(cin >> a));
		switch (a)
		{
		case 1:
		{
			for_all_time(cat);
			break;
		}
		case 2:
		{
			MyDate date("now");
			month_decryption(date, cat);
			break;
		}
		}
		break;
	}
	case 4:
	{
		MyDate date("now");
		income_decryption(date);
		break;
	}
	}
}


void pay_for_CI(Const_income& CI, Finance& all_balance)			//������� ��� ��������������� ���������� �������
{
	MyDate last_date;

	ifstream fi;
	fi.open("date_in.txt");
	fi.read((char*)&last_date, sizeof(MyDate));
	fi.close();

	MyDate nowLocale("now");

	int year, size;
	year = nowLocale.get_year() - last_date.get_year();
	if (year != 0 && nowLocale.get_month() != last_date.get_month() && last_date.get_day() >= CI.get_day())
	{
		if ((nowLocale.get_day() - CI.get_day()) >= 0)
			size = year * 12 + nowLocale.get_month() - last_date.get_month();
		else size = year * 12 + nowLocale.get_month() - last_date.get_month() - 1;
		all_balance.set_balance(all_balance.get_balance() + CI.get_income() * size);
	}

	last_date = nowLocale;

	ofstream fo;
	fo.open("date_in.txt");
	fo.write((char*)&last_date, sizeof(MyDate));
	fo.close();
}
void pay_for_CO(Const_outcome& CO, Finance& all_balance)			//������� ��� ��������������� ���������� �������
{
	MyDate last_date;

	ifstream fi;
	fi.open("date_out.txt");
	fi.read((char*)&last_date, sizeof(MyDate));
	fi.close();

	MyDate nowLocale("now");

	int year, size;
	year = nowLocale.get_year() - last_date.get_year();
	if (year != 0 && nowLocale.get_month() != last_date.get_month() && last_date.get_day() >= CO.get_day())
	{
		if ((nowLocale.get_day() - CO.get_day()) >= 0)
			size = year * 12 + nowLocale.get_month() - last_date.get_month();
		else size = year * 12 + nowLocale.get_month() - last_date.get_month() - 1;
		all_balance.set_balance(all_balance.get_balance() - CO.get_outcome() * size);
	}

	last_date = nowLocale;

	ofstream fo;
	fo.open("date_out.txt");
	fo.write((char*)&last_date, sizeof(MyDate));
	fo.close();
}
void pay_for_credit(Finance& all_balance, Credit& my_eq_credit, Credit& my_dif_credit)
{
	MyDate last_date;

	ifstream fi;
	fi.open("date_of_credit.txt");
	fi.read((char*)&last_date, sizeof(MyDate));
	fi.close();

	MyDate nowLocale("now");

	int size, year;
	year = nowLocale.get_year() - last_date.get_year();
	size = year * 12 + nowLocale.get_month() - last_date.get_month();
	for (int i = 0; i < size; i++)
	{
		my_eq_credit.pay_for_credit(my_eq_credit, all_balance);
		my_dif_credit.pay_for_credit(my_dif_credit, all_balance);
	}

	if (last_date.get_day() != 1)
		last_date.set_month(nowLocale.get_day());
	else
		last_date.set_day(1);
	last_date.set_month(nowLocale.get_month());
	last_date.set_year(nowLocale.get_year());

	ofstream fo;
	fo.open("date_of_credit.txt");
	fo.write((char*)&last_date, sizeof(MyDate));
	fo.close();
}

void save_data(Finance& all_balance, int number_of_CI, int number_of_CO, Const_income* CI, Const_outcome* CO, Eq_Credit my_eq_credit, Dif_Credit my_dif_credit)
{
	ofstream fo;
	fo.open("balance.txt");
	fo.write((char*)&all_balance, sizeof(Finance));
	fo.close();

	fo.open("IOcome.txt");
	fo.write((char*)&number_of_CI, sizeof(int));
	for (int i = 0; i < number_of_CI; i++)
	{
		fo.write((char*)&CI[i], sizeof(Const_income));
	}
	fo.write((char*)&number_of_CO, sizeof(int));
	for (int i = 0; i < number_of_CO; i++)
	{
		fo.write((char*)&CO[i], sizeof(Const_outcome));
	}
	fo.close();

	fo.open("credit.txt");
	fo.write((char*)&my_eq_credit, sizeof(Credit));
	fo.write((char*)&my_dif_credit, sizeof(Credit));
	fo.close();

}

void put_last_date()
{
	MyDate last_date("now");

	ofstream fo;
	fo.open("date_in.txt");
	fo.write((char*)&last_date, sizeof(MyDate));
	fo.close();

	fo.open("date_out.txt");
	fo.write((char*)&last_date, sizeof(MyDate));
	fo.close();

	fo.open("date_of_credit.txt");
	fo.write((char*)&last_date, sizeof(MyDate));
	fo.close();
}

void analysis(Finance& all_balance, Eq_Credit& my_eq_credit, Dif_Credit& my_dif_credit, int number_of_CI, int number_of_CO, Const_income* CI, Const_outcome* CO)
{
	bool q = 0;
	cout << "������� ������: " << all_balance << endl;
	if (my_eq_credit.get_main_debt() != 0)
	{
		cout << "������: " << endl << my_eq_credit << endl;
		q = 1;
	}
	else if (my_dif_credit.get_main_debt() != 0)
	{
		cout << "������: " << endl << my_dif_credit << endl;
		q = 1;
	}
	else
		cout << "��� ��������!!! " << endl;

	if (q)
	{
		MyDate last_date;
		ifstream fi;
		fi.open("date_of_credit.txt");
		fi.read((char*)&last_date, sizeof(MyDate));
		fi.close();
		cout << "��������� ����� �� �������: ";
		if (last_date.get_day() == 1)
			last_date.print();
		else cout << "�������� ��� �� ����!";
	}

	MyDate nowLocale("now");
	vector<Const_income> v1;
	vector<Const_outcome> v2;
	int ci = 0, co = 0;
	for (int i = 0; i < number_of_CI; i++)
	{
		if (CI[i].get_day() > (nowLocale.get_day()))
		{
			v1.push_back(CI[i]);
			ci++;
		}
	}
	for (int i = 0; i < number_of_CO; i++)
	{
		if (CO[i].get_day() > (nowLocale.get_day()))
		{
			v2.push_back(CO[i]);
			co++;
		}
	}
	cout << endl << "� ���� ������ ����������� " << ci << " ������(��) � " << co << " �������(��)" << endl;
	if (ci)
	{
		cout << "������: " << endl;
		for (int i = 0; i < ci; i++)
		{
			cout << v1[i].get_day() << " �����, �� ����� " << v1[i].get_income() << endl;
		}
	}
	if (co)
	{
		cout << "�������: " << endl;
		for (int i = 0; i < co; i++)
		{
			cout << v2[i].get_day() << " �����, �� ����� " << v2[i].get_outcome() << endl;
		}
	}
	v1.clear();
	v2.clear();
	cout << endl;
	spent_for_category(nowLocale);
}
