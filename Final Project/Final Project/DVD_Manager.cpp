//#include "pch.h"
#include "DVD_Manager.h"


// add DVD object
void DVD_Manager::addDVD(DVD &movie)
{
	string inputString;
	int inputInt;

	cout << endl;
	cout << "Enter DVD title: ";
	cin.ignore();
	getline(cin, inputString);
	movie.setTitle(inputString);

	cout << "Enter length (in minutes) of the movie: ";
	cin >> inputInt;
	movie.setMovieLength(inputInt);

	cout << "Enter year that the movie came out: ";
	cin >> inputInt;
	movie.setYear(inputInt);

	cout << "Enter the first main actor: ";
	cin.ignore();
	getline(cin, inputString);
	movie.setActor1(inputString);

	cout << "Enter the next main actor: ";
	getline(cin, inputString);
	movie.setActor2(inputString);
}

// delete a DVD object
void DVD_Manager::deleteDVD(DVD &movie)
{
	movie.setTitle("(Empty)");
	movie.setMovieLength(0);
	movie.setYear(0);
	movie.setActor1("");
	movie.setActor2("");
}

// update existing DVD object
void DVD_Manager::updateDVD(DVD &movie)
{
	string inputString;
	int inputInt;

	cout << "What needs updating?" << endl;
	cout << "Title" << endl << "Movie Length" << endl << "Year" << endl
		<< "Actor 1" << endl << "Actor 2" << endl;
	cout << "Please enter your selection: ";
	getline(cin, inputString);

	if (inputString == "Title" || inputString == "title" || inputString == "TITLE")
	{
		cout << endl;
		cout << "Enter new DVD title: ";
		getline(cin, inputString);
		movie.setTitle(inputString);
	}

	else if (inputString == "Movie Length" || inputString == "movie length" || inputString == "MOVIE LENGTH" || inputString == "Movie Length")
	{
		cout << endl;
		cout << "Enter the movie length (in minutes): ";
		cin >> inputInt;
		movie.setMovieLength(inputInt);
	}

	else if (inputString == "Year" || inputString == "year" || inputString == "YEAR")
	{
		cout << endl;
		cout << "Enter the year when the movie came out: ";
		cin >> inputInt;
		movie.setYear(inputInt);
	}

	else if (inputString == "Actor 1" || inputString == "actor 1" || inputString == "ACTOR 1")
	{
		cout << endl;
		cout << "Enter name of the main actor: ";
		getline(cin, inputString);
		movie.setActor1(inputString);
	}

	else if (inputString == "Actor 2" || inputString == "actor 2" || inputString == "ACTOR 2")
	{
		cout << endl;
		cout << "Enter name of the next main actor: ";
		getline(cin, inputString);
		movie.setActor2(inputString);
	}

	else
		cout << "Invalid option" << endl;

}