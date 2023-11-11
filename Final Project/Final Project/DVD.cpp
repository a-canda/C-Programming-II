//#include "pch.h"
#include "DVD.h"

// constructors
DVD::DVD()
{
	title = "(Empty)";
	movieLength = 0;
	year = 0;
	actor1 = "0";
	actor2 = "0";
}

DVD::DVD(string t)
{
	title = t;
	movieLength = 0;
	year = 0000;
	actor1 = "";
	actor2 = "";
}

// mutators
void DVD::setTitle(string t)
{
	title = t;
}

void DVD::setMovieLength(int m)
{
	movieLength = m;
}

void DVD::setYear(int y)
{
	year = y;
}

void DVD::setActor1(string a)
{
	actor1 = a;
}

void DVD::setActor2(string a)
{
	actor2 = a;
}

// accessors

string DVD::getTitle() const
{
	return title;
}

int DVD::getMovieLength() const
{
	return movieLength;
}

int DVD::getYear() const
{
	return year;
}

string DVD::getActor1() const
{
	return actor1;
}

string DVD::getActor2() const
{
	return actor2;
}