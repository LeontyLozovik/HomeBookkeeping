#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include "Finance.h"
#include "Const_iocome.h"
#include "Credit.h"
#include "functional.h"


#pragma warning (disable : 4996)
using namespace::std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Finance all_balance;
	int number_of_CI = 0, number_of_CO = 0;
	Const_income *CI = nullptr;
	Const_outcome *CO = nullptr;
	Dif_Credit my_dif_credit;
	Eq_Credit my_eq_credit;

	bool save = 0;
	ifstream fi;
	fi.open("balance.txt");
	if (fi.read((char*)&all_balance, sizeof(Finance)))
		save = 1;
	fi.close();

	fi.open("IOcome.txt");
	if (fi.read((char*)&number_of_CI, sizeof(int)))
		save = 1;
	else save = 0;
	CI = new Const_income[number_of_CI];
	for (int i = 0; i < number_of_CI; i++)
	{
		if (fi.read((char*)&CI[i], sizeof(Const_income)))
			save = 1;
		else save = 0;
	}
	if (fi.read((char*)&number_of_CO, sizeof(int)))
		save = 1;
	else save = 0;
	CO = new Const_outcome[number_of_CO];
	for (int i = 0; i < number_of_CO; i++)
	{
		if (fi.read((char*)&CO[i], sizeof(Const_outcome)))
			save = 1;
		else save = 0;
	}
	fi.close();

	fi.open("credit.txt");
	if (fi.read((char*)&my_eq_credit, sizeof(Credit)))
		save = 1;
	else save = 0;
	if (fi.read((char*)&my_dif_credit, sizeof(Credit)))
		save = 1;
	else save = 0;
	fi.close();

	if (!save)
	{
		double balance;
		do
		{
			do
			{
				system("CLS");
				cout << "Добро пожаловать в домашнюю бухгалтерию!" << endl << "Эта программа позволит вам ситематизировать свои расходы " << endl << "А теперь внесите некоторые данные в систему " << endl;
				cout << "Что бы начать успешно пользоваться программой введите ваш бюджет на данный момент: ";
				cin.clear();
				rewind(stdin);
			} while (!(cin >> balance));
		} while (balance < 0);
		all_balance.set_balance(balance);

		int p = 0, a;
		do
		{
			do
			{
				system("CLS");
				cout << "Скорее всего у вас есть постоянные поступления в конкретную дату каждого месяца (зарплата, аванс ну или ещё что-нибудь). Ответьте пожалуйста на пару вопросов что бы такие поступления прибавлялиь автоматически! Если хотите вносить из вручную введите 0" << endl;
				cout << "Сколько раз в месяц эти поступления происходят? " << endl;
				cin.clear();
				rewind(stdin);
			} while (!(cin >> a));
			if (a > 10)
			{
				do
				{
					do
					{
						system("CLS");
						cout << "Вы уверены?" << endl << "1 - Да" << endl << "2 - Нет" << endl;
						cin.clear();
						rewind(stdin);
					} while (!(cin >> p));
				} while (p != 1 && p != 2);
			}
		} while (p != 1 && p != 0);
		number_of_CI = a;
		CI = new Const_income[a];
		for (int i = 0; i < a; i++)
		{
			cin >> CI[i];
		}

		do
		{
			do
			{
				system("CLS");
				cout << "У вас есть кредит? " << endl << "1 - да" << endl << "2 - нет" << endl;
				cin.clear();
				rewind(stdin);
			} while (!(cin >> a));
		} while (a != 1 && a != 2);
		switch (a)
		{
		case 1:
		{
			int credit = 0;
			do
			{
				system("CLS");
				cout << "К сожалению мы знаем только эти 2 типа выпдат, если они не соответствуют вашим условиям выберете вариант 3"
					<< endl << "Выберете тип выплат: " << endl << "1 - Равными долями" << endl << "2 - Дифиренцированный платёж" << endl
					<< "3 - Вводить платежи самостоятельно" << endl;
				do
				{
					cin.clear();
					rewind(stdin);
				} while (!(cin >> credit));
			} while (credit != 1 && credit != 2 && credit != 3);
			system("CLS");
			cout << "Платежи будут происходить первого числа каждого месяца" << endl;
			switch (credit)
			{
			case 1:
			{
				cin >> my_eq_credit;
				my_eq_credit.set_payment();
				break;
			}
			case 2:
			{
				cin >> my_dif_credit;
				my_dif_credit.set_payment();
			}
			case 3: break;
			}
			break;
		}
		case 2: break;
		}

		do
		{
			do
			{
				system("CLS");
				cout << "Скорее всего у вас также есть постоянные расходы(комуналка или кредит например). Ответьте пожалуйста на пару вопросов что бы такие расходы отнимались автоматически! Если хотите вносить из вручную введите 0" << endl;;
				cout << "Сколько раз в месяц эти расходы происходят? (БЕЗ УЧЁТА КРЕДИТА) ";
				cin.clear();
				rewind(stdin);
			} while (!(cin >> a));
			if (a > 10)
			{
				do
				{
					do
					{
						system("CLS");
						cout << "Вы уверены?" << endl << "1 - Да" << endl << "2 - Нет" << endl;
						cin.clear();
						rewind(stdin);
					} while (!(cin >> p));
				} while (p != 1 && p != 2);
			}
		} while (p != 1 && p != 0);

		number_of_CO = a;
		CO = new Const_outcome[a];
		for (int i = 0; i < a; i++)
		{
			cin >> CO[i];
		}
		put_last_date();
		save_data(all_balance, number_of_CI, number_of_CO, CI, CO, my_eq_credit, my_dif_credit);
	}
	for (int i = 0; i < number_of_CI; i++)
		pay_for_CI(CI[i], all_balance);
	for (int i = 0; i < number_of_CO; i++)
		pay_for_CO(CO[i], all_balance);
	pay_for_credit(all_balance, my_eq_credit, my_dif_credit);

	do
	{
		ofstream fo;
		fo.open("balance.txt");
		fo.write((char*)&all_balance, sizeof(Finance));
		fo.close();

		fo.open("credit.txt");
		fo.write((char*)&my_eq_credit, sizeof(Credit));
		fo.write((char*)&my_dif_credit, sizeof(Credit));
		fo.close();

		int q;
		do
		{
			start_menu(all_balance);
			cin.clear();
			rewind(stdin);
		} while (!(cin >> q));
		switch (q)
		{
		case 1:system("CLS"); pay(all_balance); break;
		case 2:
		{
			system("CLS");
			Income jackpot;
			cin >> jackpot;
			fstream fin;
			fin.open("income.txt", ios_base::app);
			fin.write((char*)&jackpot, sizeof(Income));
			fin.close();
			all_balance.set_balance(all_balance.get_balance() + jackpot.get_cost()); break;
		}
		case 3: system("CLS"); decryption(); break;
		case 4: system("CLS"); analysis(all_balance, my_eq_credit, my_dif_credit, number_of_CI, number_of_CO, CI, CO); break;
		default: break;
		}
	} while (1);
	return 0;
}