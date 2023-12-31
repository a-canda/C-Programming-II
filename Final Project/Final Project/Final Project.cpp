/*
Aaron Canda
Programming II
Final Project

This project keeps a collection of DVDs and its information. Information includes
the DVD title, movie length, year released, and two main actors. The program contains two
classes; DVD class and a DVD_Manager class. The DVD class creates the DVDs, while the DVD_Manager
will manage the DVD. Management of the DVD includes adding DVDs, deleting DVDs, and updating existing
DVDs. The program will be able to store 5 DVDs.
*/

//#include "pch.h"
#include <iostream>
#include <string>
#include "DVD_Manager.h"
#include "DVD.h"

using namespace std;

// function prototypes
void displayMenu(DVD[]);
void addDVD(DVD[]);
void deleteDVD(DVD[]);
void updateDVD(DVD[]);
void showDVDs(DVD[]);

int main()
{
	DVD collectionOfDVDs[5];

	displayMenu(collectionOfDVDs);

	cout << endl;
	system("pause");
	return 0;
}

// displays the dvd collection menu, then asks the user to enter a selection. Validation included.
void displayMenu(DVD movies[])
{
	int choice;
	
	cout << "-------------------------" << endl;
	cout << "DVD Collection Menu" << endl;
	cout << "-------------------------" << endl << endl;

	// menu options
	cout << "1. Add a DVD" << endl
		<< "2. Delete a DVD" << endl
		<< "3. Update a DVD" << endl
		<< "4. Show all DVDs" << endl
		<< "5. Exit" << endl;
	cout << "Please select a number (1-5): ";
	cin >> choice;
	cout << endl;

	// validation
	while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
	{
		cout << "Invalid menu option." << endl;
		cout << "Please select a number 1 - 5: ";
		cin >> choice;
	}

	// switch will call the respective function based on the user's choice.
	switch (choice)
	{
	case 1:
		addDVD(movies);
		break;
	case 2:
		deleteDVD(movies);
		break;
	case 3:
		updateDVD(movies);
		break;
	case 4:
		showDVDs(movies);
		break;
	case 5:
		std::exit;
	}

}

/* 
This function adds DVD information when case 1 is selected. 
Function will only add a DVD if there is an available space open.
It will also add to the first existing spot open.
*/
void addDVD(DVD movies[])
{
	DVD_Manager manage;

	for (int index = 0; index < 5; index++)
	{
		if (movies[index].getTitle() == "(Empty)")
		{
			manage.addDVD(movies[index]);
			break;
		}
	}

	displayMenu(movies);
}

/*
This funciton deletes a DVD and all its information.
User will be prompted to type in a title to delete.
Function will then call the DVD manager to delete DVD.
*/
void deleteDVD(DVD movies[])
{
	DVD_Manager manage;
	string input;

	cout << "Enter DVD title you wish to delete: ";
	cin.ignore();
	getline(cin, input);
	for (int index = 0; index < 5; index++)
	{
		if (input == movies[index].getTitle())
		{
			manage.deleteDVD(movies[index]);
			break;
		}
	}

	displayMenu(movies);
}

// this function updates information of an existing DVD entered.
void updateDVD(DVD movies[])
{
	DVD_Manager manage;
	string input;

	cout << "Enter DVD title that needs updating: ";
	cin.ignore();
	getline(cin, input);
	for (int index = 0; index < 5; index++)
	{
		if (input == movies[index].getTitle())
		{
			manage.updateDVD(movies[index]);
			break;
		}
	}

	displayMenu(movies);
}

// this function will display the whole DVD collection
void showDVDs(DVD movies[])
{
	for (int index = 0; index < 5; index++)
	{
		cout << "-------------------------" << endl;
		cout << "DVD #" << index + 1 << endl;
		cout << "-------------------------" << endl << endl;
		cout << "Title: " << movies[index].getTitle() << endl;
		cout << "Movie Length: " << movies[index].getMovieLength() << " minutes" <<  endl;
		cout << "Year released: " << movies[index].getYear() << endl;
		cout << "Main Actor: " << movies[index].getActor1() << endl;
		cout << "Main Actor 2: " << movies[index].getActor2() << endl << endl;
	}

	displayMenu(movies);
}