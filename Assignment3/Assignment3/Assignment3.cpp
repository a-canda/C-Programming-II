/*
Aaron Canda
Programming II

This program allows the user to search for a name and phone number.
The user may enter in a name or part of a name and the program will
spit out any results with those characters. For example, entering in
"pal" will give two results.
*/

//#include "pch.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

// global constant
const int SIZE = 11;

// function prototype
void searchArray(string, string[], int);

int main()
{
	cout << "PHONE DIRECTORY\n";

	string phoneDirectory[SIZE] = { "Renee Javens, 678-1223", "Joe Looney, 586-0097",
									"Geri Palmer, 223-8787", "Lynn Presnell, 887-1212",
									"Bill Wolfe, 223-8878", "Sam Wiggins, 486-0998",
									"Bob Kain, 586-8712", "Tim Haynes, 586-7676",
									"John Johnson, 223-9037", "Jean James, 678-4939",
									"Ron Palmer, 486-2783" };
	
	string findNames;
	
	cout << "Enter in a name to search for phone number(s): ";

	cin.ignore();				// skips a newline character
	getline(cin, findNames);	// gets user input

	cout << endl;

	searchArray(findNames, phoneDirectory, SIZE);	// call method
	

	system("pause");
	return 0;
}

// this function will search the array for the string typed in.
// the string(s) that are searched will be displayed if found
// A no result message will display if no strings matched
void searchArray(string findNum, string arr[], int size){
	cout << "Results:" << endl;
	bool found = false;
	for (int index = 0; index < size; index++) {	// loop through index
		if (arr[index].find(findNum) != -1) {		// find function used here to search array
			cout << "\t" << arr[index] << endl;		// display strings found
			found = true;
		}
	}
	if (!found)										// Display no result message
		cout << "None available." << endl;
}