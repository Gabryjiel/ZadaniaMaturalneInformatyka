#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Word {
	int counter;
	string number;
};

vector <Word> numbers;

int load_2006() {
	fstream file;
	file.open("dane/2006/dane.txt");

	if (!file.good())
		return 0;

	for (int i = 0; file.is_open(); i++) {
		bool pushback = true;
		string temp = "";

		file >> temp;

		if (numbers.size() != 0) {
			for (int j = 0; j < numbers.size(); j++) {
				if (temp == numbers[j].number) {
					numbers[j].counter++;
					pushback = false;
					break;
				}
			}
		}

		 if (pushback) {
			Word tee = { 1,temp };
			numbers.push_back(tee);
		//	cout << temp << endl;
		}

		if (file.eof()) {
			file.close();
			break;
		}

	}
	return 1;
}

int task_a_2006() {
	Word max = { 0,"" };
	int count = 0;

	for (int i = 0; i < numbers.size() - 1; i++) {
		if (numbers[i].counter > 1) {
			count++;
		}
		if (numbers[i].counter > max.counter) {
			max.counter = numbers[i].counter;
			max.number = numbers[i].number;
		}

	}

	fstream file;
	file.open("dane/2006/wyniki.txt");

	file << count << endl;
	file << max.number << endl;
	file << max.counter << endl;

	return 1;
}

int task_b_2006() {
	int counter = 0;
	for (int i = 0; i < numbers.size()-1; i++) {
		char sign = numbers[i].number[numbers[i].number.length() - 1];
		if (sign == 'A' || sign == 'C' || sign == 'E')
			counter += numbers[i].counter;
	}

	fstream file;
	file.open("dane/2006/wyniki.txt", std::ios::app);

	file << counter << endl;
	file.close();

	return 1;
}

int task_c_2006() {
	int nonpali = 0;
	for (int i = 0; i < numbers.size() - 1; i++) {
		for (int j = 0; j < numbers[i].number.length() - 1; j++) {
			if (numbers[i].number[j] != numbers[i].number[numbers[i].number.length() - 1 - j]) {
				break;
			}
			else if (j == numbers[i].number.length() - 2) {
				nonpali += numbers[i].counter;
			}
		}
	}


	fstream file;
	file.open("dane/2006/wyniki.txt", std::ios::app);
	file << nonpali;
	file.close();

	return 1;
}


int matura_2006() {

	load_2006();
	task_a_2006();
	task_b_2006();
	task_c_2006();
	cin.get();

	return 1;
}