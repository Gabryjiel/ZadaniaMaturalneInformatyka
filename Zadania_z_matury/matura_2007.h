#pragma once
#include <vector>
#include <iostream>
#include <cmath>

struct Liczba {
	long liczba;
	bool pierwsza;
	bool superpierwsza;
	bool superpierwszaB;
};

vector <Liczba> liczbya;

bool ifPrime(long a) {
	if (a == 2)
		return true;
	else if (a % 2 == 0)
		return false;
	else if (a > 2) {
		for (long i = 3; i < a; i++) {
			if (a % i == 0)
				return false;
		}
		return true;
	}
}

bool ifSuperPrime(long a) {
	int sum = 0;
	for (int i = 10; ;) {
		if (a % i != a) {
			sum += a % i;
			a /= 10;
		}
		else break;
	}

	return ifPrime(sum);
}

bool ifSuperPrimeB(long a) {
	long binary = 0;
	for (int i = 0; ; i++) {
		if (a % 2 == 1)
			binary += pow(10, i);
		a = a / 2;
		if (a == 0)
			break;
	}

	int sum = 0;
	for (int i = 10; ;) {
		if (binary % i != binary) {
			sum += binary % i;
			binary /= 10;
		}
		else break;
	}

	return ifPrime(sum);
}

bool check(long a, long b) {
	for (long i = a; i <= b; i++) {
		Liczba temp;
		temp.liczba = i;
		temp.pierwsza = ifPrime(i);
		temp.superpierwsza = ifSuperPrime(i);
		temp.superpierwszaB = ifSuperPrimeB(i);
		liczbya.push_back(temp);
		if (temp.superpierwszaB) 
			std::cout << i << std::endl;
	}
	return 0;
}


void matura_2007() {

	check(2, 100);

	std::cout << "a";

}