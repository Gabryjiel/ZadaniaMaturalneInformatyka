#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector <string> to_code;
vector <string> cipher;
vector <string> to_decode;
vector <string> decipher;
vector <string> coded;
vector <string> decoded;

int load_2012(string dir)
{
	fstream plik(dir);
	
	if (!plik.good())
		return -1;

	for (int i = 0; ; i++)
	{
		string temp = "";

		plik >> temp;

		if (temp == "")
			break;
		else if (dir == "2012/tj.txt")
			to_code.push_back(temp);
		else if (dir == "2012/klucze1.txt")
			cipher.push_back(temp);
		else if (dir == "2012/sz.txt")
			to_decode.push_back(temp);
		else if (dir == "2012/klucze2.txt")
			decipher.push_back(temp);
	}

	plik.close();

	return 1;
}

int time_to_code()
{
	for (int i = 0; i < to_code.size(); i++)
	{
		string temp = "";
		int a = 0;

		for (int n = 0; n < to_code[i].length(); n++)
		{	
			if (n != 0)
			{
				a = n % cipher[i].length();
				temp += to_code[i][n] + (cipher[i][a] - 64);
			}
			else
				temp += to_code[i][n] + (cipher[i][0] - 64);
		
			if (temp[n] > 90)
				temp[n] -= 26;
		}

		coded.push_back(temp);
	}

	return 1;
}

int time_to_decode()
{
	for (int i = 0; i < to_decode.size(); i++)
	{
		string temp;
		int a = 0;

		for (int n = 0; n < to_decode[i].length(); n++)
		{
			if (n != 0)
			{
				a = n % decipher[i].length();
				temp += to_decode[i][n] - (decipher[i][a] - 64);
			}
			else
				temp += to_decode[i][n] - (decipher[i][0] - 64);

			if (temp[n] < 65)
				temp[n] += 26;
		}

		decoded.push_back(temp);
	}

	return 1;
}

int save_2012(string what)
{

	if (what == "coded")
	{
		fstream plik("2012/wyniki4a.txt");

		for (int i = 0; i < coded.size(); i++)
		{
			plik << coded[i] << endl;
		}
	}
	else if (what == "decoded")
	{
		fstream plik("2012/wyniki4b.txt");

		for (int i = 0; i < decoded.size(); i++)
		{
			plik << decoded[i] << endl;
		}
	}

	return 1;
}

int matura_2012()
{
	load_2012("2012/tj.txt");
	load_2012("2012/klucze1.txt");
	load_2012("2012/sz.txt");
	load_2012("2012/klucze2.txt");

	time_to_code();
	time_to_decode();

	save_2012("coded");
	save_2012("decoded");

	return 1;
}