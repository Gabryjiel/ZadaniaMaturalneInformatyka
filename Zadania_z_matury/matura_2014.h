#pragma once

#include <fstream>
#include <iostream>
#include <string>


using namespace std;

string napisy[1000];
int liczby[1000];
int prime = 0;
int growing = 0;

int load_2014()
{
	fstream plik;
	plik.open("2014/NAPIS.TXT");

	if (!plik.good())
		return -1;

	for (int i = 0; i < 1000; i++)
	{
		string temp = "";

		plik >> temp;
		napisy[i] = temp;
	}
	return 1;
}

int task1_2014()
{
	for (int i = 0; i < 1000; i++)
	{
		int temp = 0;

		for (int n = 0; n < napisy[i].length(); n++)
		{
			temp += (int)napisy[i][n];
		}
		liczby[i] = temp;
	}

	for (int i = 0; i < 1000; i++)
	{
		for (int n = 2; n < liczby[i]/2 + 1; n++)
		{
			if (liczby[i] % n == 0)
				break;
			else if (n == liczby[i] / 2)
				prime++;
		}
	}

	cout << "Liczby pierwsze: " << prime << endl;

	return 1;
}

int task2_2014()
{
	for (int i = 0; i < 1000; i++)
	{
		bool isGrowing = true;

		for (int n = 0; n < napisy[i].length() - 1; n++)
		{
			if (napisy[i][n] >= napisy[i][n + 1])
			{
				isGrowing = false;
			}
		}

		if (isGrowing == true)
		{
			cout << napisy[i] << endl;
			growing++;
		}
	}

	cout << "Rosnace: " << growing << endl;

	return 1;
}

#include <vector>

int task3_2014()
{
	vector <string> doubler;

	for (int i = 0; i < 1000; i++)
	{
		for (int n = 0; n < 1000; n++)
		{
			if (napisy[i] == napisy[n] && i != n)
			{
				doubler.push_back(napisy[i]);
				break;
			}
		}
	}

	for (int i = 0; i < doubler.size(); i++)
	{
		for (int n = 0; n < doubler.size(); n++)
		{
			if (doubler[i] == doubler[n] && i != n)
				doubler[n].erase();
		}
	}

	for (int i = 0; i < doubler.size(); i++)
	{
		if (doubler[i] == "")
		{
			continue;
		}
		cout << doubler[i] << endl;
	}

	return 1;
}

int matura_2014()
{
	load_2014();
	task1_2014();
	cout << endl << "------------" << endl;
	task2_2014();
	cout << endl << "------------" << endl;
	task3_2014();

	cin.get();

	return 1;
}