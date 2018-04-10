#pragma once
#include <iostream>
#include <cmath>
#include <Windows.h>

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

int tobinary(int l) {
	int liczba = 0;
	int x = l;
	for (int i = 0; ; i++) {
		if (x % 2 == 1) {
			liczba += 1;
		}

		x = x / 2;

		if (x == 0) {
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
		int temp = tobinary(i);
		int temp2 = count(i);
		if (liczb[temp] == true && liczb[i] == true && liczb[temp2] == true) {
			counter++;
		}
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

bool task_c_2007(int start, int end) {
	long counter = 0;

	for (int i = start; i <= end; i++) {
		int temp1 = tobinary(i);
		int temp2 = count(i);
		if (liczb[i] == true && liczb[temp1] == true && liczb[temp2] == true) {
			counter += i;
		}
	}

	for (int i = 2; ; i++) {
		if (counter % i == 0) {
			return false;
		}
	}

	return true;
}

void matura_2007() {

	primery();
	std::cout << "A: " << task_a_2007(2, 1000) << ", ";
	std::cout << task_a_2007(100, 10000) << ", ";
	std::cout << task_a_2007(1000, 100000) << std::endl;
	std::cout << "B: " << task_b_2007() << std::endl;
	std::cout << "C: " << task_c_2007(100,10000);
	std::cin.get();

	std::cout << "a";

}