#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector <string> liczby;

int load_2013() {
	fstream file;
	file.open("Dane/2013/dane.txt");


	for (int i = 0; i < 5000 ; i++) {
		string temp = " ";
		file >> temp;
		liczby.push_back(temp);
	}

	return 1;
}

int task_one_2013() {
	int counter = 0;

	for (unsigned int i = 0; i < liczby.size(); i++) {
		if (liczby[i][0] == liczby[i][liczby[i].length() - 1])
			counter++;
	}

	return counter;
}

int task_two_2013() {
	int counter = 0;

	for (unsigned int i = 0; i < liczby.size(); i++) {
		int decimal = 0;
		for (int z = 0; z < liczby[i].length() - 1; z++) {
			decimal += pow((int)liczby[i][z] - 48, liczby[i].length() - 1 - z);
		}
		int first = 0;
		int last = decimal % 10;
		for (int z = 0; ; z++) {
			if (decimal % (int)pow(10, z) == decimal)
				break;
			else {
				first = decimal % (int)pow(10,z);
			}
		}
		if (first == last)
			counter++;
	}

	return counter;
}

int task_three_2013() {
	int counter = 0;

	for (unsigned int i = 0; i < liczby.size(); i++) {
		if (liczby)
	}
}

void matura_2013() {
	load_2013();
	cout << task_one_2013() << endl;
	cout << task_two_2013() << endl;
	cout << task_three_2013() << endl;
	cin.get();
}