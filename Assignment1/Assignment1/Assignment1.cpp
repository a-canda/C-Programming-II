/*
Aaron Canda
Programming II


*/

#include "pch.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void getSauceNames();
void getBbqPrices();
void displayTable();
void gatherInputs();
void calculateData();
void highestLowest();


string sauceNames[6];
double bbqPrices[6];
int amountSold[6];

int bottles = 0;
double totalSales = 0;
string sauce;

int main()
{
	getSauceNames();
	getBbqPrices();
	gatherInputs();
	displayTable();
	highestLowest();

	system("pause");
	return 0;
}

void getSauceNames() {
	int  index = 0;
	ifstream inputFile;
	inputFile.open("C:\\Users\\ANC\\Desktop\\Programming II\\Assignment1\\SauceNames.txt");
	if (inputFile) {
		while (index < 6) {
			inputFile >> sauceNames[index];
			index++;
		}
		inputFile.close();
	}
	else {
		cout << "Error opening the file.\n";
	}
}

void getBbqPrices() {
	int index = 0;
	ifstream inputFile;
	inputFile.open("C:\\Users\\ANC\\Desktop\\Programming II\\Assignment1\\BbqPrices.txt");
	if (inputFile) {
		while (index < 6 && inputFile >> bbqPrices[index]) {
			index++;
		}
		inputFile.close();
	}
	else {
		cout << "Error opening the file.\n";
	}
}


void calculateData() {

	
}
void gatherInputs() {
	for (int index = 0; index < 6; index++) {
		if (amountSold[index] > 0) {
			cout << "Enter the amount of " << sauceNames[index] << " sold: ";
			cin >> amountSold[index];

		}
	
		}
	}
void displayTable() {
	cout << "Sales of BBQ Sauces" << endl << endl;
	cout << "SAUCE" << "\tPRICE" << "\tSOLD" << "\tTOTAL" << endl;

	for (int index = 0; index < 6; index++) {
		cout << sauceNames[index] << "\t" << bbqPrices[index] << "\t" << amountSold[index];
		cout << fixed << setprecision(2) << showpoint;
		cout << "\t" << bbqPrices[index] * amountSold[index] << endl;
	}

}
