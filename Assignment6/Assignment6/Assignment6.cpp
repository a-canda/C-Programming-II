/*
Aaron Canda
Programming II
Assignment 6

This assignment creates a circle object. The program will ask the user
to enter in a radius to set the value through the use of the set method.
The program then uses other methods such as the getRadius, getDiameter, calculateArea,
calculateCircumference to display the radius, diameter, area and circumference of the circle. */


//#include "pch.h"
#include <iostream>
#include <iomanip>
#include "Circle.h"
using namespace std;

int main()
{
	double radius;

	//class circle
	Circle circle;

	//information for user
	cout << "To display circle information, please..." << endl;
	cout << "Enter the radius of a circle: ";
	cin >> radius;
	cout << endl;

	//set value for radius
	circle.SetRadius(radius);

	cout << fixed << setprecision(2);

	//display information
	cout << "Radius " << setw(17) << circle.GetRadius() << endl;
	cout << "Area " << setw(20) << circle.CalculateArea() << endl;
	cout << "Circumference " << setw(10) << circle.CalculateCircumference() << endl;
	cout << "Diameter " << setw(15) << circle.GetDiameter() << endl;

	system("pause");
	return 0;
}

