#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector <string> binary;
int maxlength = 0;

int load_2011()
{
	fstream plik;
	plik.open("liczby.txt");

	if (!plik.good())
		return 0;

	string temp = "";

	for (int i = 0; i < 1000; i++)
	{
		plik >> temp;

		if (temp.length() > maxlength)
			maxlength = temp.length();

		binary.push_back(temp);
	}

	return 1;
}

long long binnadec_2011(string binary, int mode)
{
	long long x = 0;

	for (int i = 0; i < binary.length(); i++)
	{
		if (binary[binary.length() - i - 1] == '1')
		{
			x += pow(10, i);
		}
	}

	//Postaæ binarna w typie int

	if (mode == 1)
	{
		unsigned long long liczba = 0;

		for (int i = 0; ; i++)
		{
			if (x % 10 == 1)
			{
				liczba += pow(2, i);
			}

			x = x / 10;

			if (x == 0)
				break;
		}
		return liczba;
	}

	return x;
}

long long decnabin_2011(long long x)
{
	long long liczba = 0;

	for (int i = 0; ; i++)
	{
		if (x % 2 == 1)
		{
			liczba += pow(10, i);
		}

		x = x / 2;

		if (x == 0)
		{
			break;
		}
	}

	return liczba;
}

int task1_2011()
{
	int liczba = 0;

	for (int i = 0; i < (int)binary.size(); i++)
	{
		if (binary[i][binary[i].length() - 1] == '0')
			liczba++;
	}

	return liczba;
}

int task2_2011()
{
	vector <string> maxes;

	for (int i = 0; i < (int)binary.size(); i++)
	{
		if (binary[i].length() == maxlength)
			maxes.push_back(binary[i]);
	}

	for (int i = 0; i < (int)maxes.size(); i++)
	{
		for (int n = 0; n < (int)maxes.size(); n++)
		{
			if (maxes[i] > maxes[n])
				swap(maxes[i], maxes[n]);
		}
	}

	cout << "Bin: " << maxes[0] << " Dec: ";
	cout << binnadec_2011(maxes[0], 1);

	return 1;
}

int task3_2011()
{
	vector <string> nine;

	for (int i = 0; i < binary.size(); i++)
	{
		if (binary[i].length() == 9)
			nine.push_back(binary[i]);
	}

	unsigned long long x = 0;

	for (int i = 0; i < 101; i++)
	{
		int y = 0;
		y = binnadec_2011(nine[i], 1);
		x += y;
	}

	cout << endl << "Zadanie 3: ";
	cout << decnabin_2011(x);
	return 1;
}

int matura_2011()
{
	load_2011();
	cout << task1_2011() << endl;
	task2_2011();
	task3_2011();


	cin.get();

	return 1;
}