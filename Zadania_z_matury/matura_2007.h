#pragma once
#include <iostream>
#include <cmath>

bool liczb[100001];

int primery() {
	for (int i = 0; i < sizeof(liczb) / sizeof(bool); i++) {
		liczb[i] = true;
		
		if (i == 2)
			liczb[2] = 1;
		else if (i == 1 || i == 0)
			liczb[1] = 0;
		else {
			for (int n = 2; n <= i / 2; n++) {
				if (i % n == 0) {
					liczb[i] = false;
					break;
				}
				else if (n == i / 2) {
					liczb[i] = true;
				}
			}
		}
	}
	return 1;
}

int tobinary(int x) {
	int liczba = 0;
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

int count(int x) {
	int suma = 0;
	while (true) {
		suma += x % 10;
		if (x < 10) break;
		else {
			x = (x - (x % 10)) / 10;
		}
	}
	return suma;
}

int task_a_2007(int start, int end) {
	int counter = 0;
	for (int i = start; i <= end; i++) {
		int temp = count(tobinary(i));
		if (liczb[temp] == 1) counter++;
	}
	return counter;
}

int task_b_2007() {
	int counter = 0;
	for (int i = 100; i <= 10000; i++) {
		int suma = count(i);

		if (liczb[suma] == true)
			counter++;
	}

	return counter;
}

void matura_2007() {


	primery();
	std::cout << task_a_2007(2, 1000) << ", " << task_a_2007(100, 10000) << ", " << task_a_2007(1000, 100000) << std::endl;
	std::cout << task_b_2007();
	std::cin.get();

	std::cout << "a";

}