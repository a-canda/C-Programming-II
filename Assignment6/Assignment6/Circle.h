#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
private:
	// member variables
	double radius;
	const double PI = 3.14;

public:
	// setter
	void SetRadius(double r);

	// getter
	double GetRadius() const;
	double CalculateArea() const;
	double CalculateCircumference() const;
	double GetDiameter() const;
};

#endif

