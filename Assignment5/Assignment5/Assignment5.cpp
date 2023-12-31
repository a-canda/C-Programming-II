/*
Aaron Canda
Programming II
Assignment 5

This program asks a user for a file name and will search for the given name.
If there is no file, an error message will display. Otherwise, it will then ask
the user to enter in a string to search the file. The program will then search the file
for the specified string. The program will begin to read every line to search for the string
and then displays the line. It will then move on to the next line until the string is found again.
It will keep count of how many strings it fines within the file until the whole file is read completely.
*/


#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	ifstream file;				//file stream object
	string name;				//holds file name
	string inputLine;			//holds a line of input
	string stringSearch;		//hold user input for string
	int count = 0;				//count string
	int lineNum = 0;			//holds line number

	//get file name
	cout << "Enter the file name: ";
	getline(cin, name);

	//open file
	file.open(name, ios::in);

	//display message when file is not found
	if (!file) {
		cout << "Error opening " << name << endl;
	}

	//ask user to enter string
	cout << "Enter a string to be searched: ";
	getline(cin, stringSearch);
	cout << endl;

	// this reads the first line in the file
	getline(file, inputLine);

	while (file) {
		lineNum++;										//updates line counter
		bool found = false;					
		int index = inputLine.find(stringSearch);		//finds first occurence of string in line

		while (index >= 0) {
			found = true; 
			cout << "'" << stringSearch << "' is found in this line: " << endl;
			cout << inputLine << endl;					//displays line
			count++;									//accumulate number of times string appears
			inputLine = inputLine.substr(index + stringSearch.length());
			index = inputLine.find(stringSearch);		//update index
			
		}

		// when string is found, it will display the line number
		if (found) {						
			cout << "--------------------" << endl;
			cout << "The above text is found in line " << lineNum << "." << endl;
			cout << "--------------------" << endl << endl;
			
		}

		//reads the next line in the loop
		getline(file, inputLine);	
	}

	// displays the number of time the string appeared in the file.
	cout << endl;
	cout << "'" << stringSearch << "' appeared " << count
		<< " time(s) in the file." << endl;

	cout << lineNum << " lines have been read completely." << endl << endl;

	system("Pause");

	return 0;
}