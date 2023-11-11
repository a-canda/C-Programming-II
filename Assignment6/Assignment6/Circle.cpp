//#include "pch.h"
#include "Circle.h"
using namespace std;

void Circle::SetRadius(double r) {
	if (r > 0) {
		radius = r;
	}
	else {
		radius = 0;
	}

}

// getters
double Circle::GetRadius() const {
	return radius;
}
//CalculateArea()
double Circle::CalculateArea() const {
	double area = PI * radius * radius;
	return area;
}
double Circle::GetDiameter() const {
	double diameter = radius * 2;
	return diameter;
}
//CalculateCircumference()
double Circle::CalculateCircumference() const {
	double circumference = 2 * PI * radius;
	return circumference;
}