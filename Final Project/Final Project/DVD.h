#pragma once
#ifndef DVD_H
#include <string>
using namespace std;

class DVD
{
private:
	string title;
	int movieLength;
	int year;
	string actor1;
	string actor2;

public:
	// constructors
	DVD();
	DVD(string t);

	// mutators
	void setTitle(string t);
	void setMovieLength(int m);
	void setYear(int y);
	void setActor1(string a);
	void setActor2(string a);

	// accessors
	string getTitle() const;
	int getMovieLength() const;
	int getYear() const;
	string getActor1() const;
	string getActor2() const;
};

#endif

