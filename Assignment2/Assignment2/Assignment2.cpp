/*
Aaron Canda
Programming Assignment 2

This program uses pointers to dynamically allocate a double array and a string array.
It will allocate these two arrays big enough to hold the user's input number of students.
The two arrays are then passed to another function that will sort the two arrays in ascending
order. The average function will find the average. Finally the displayGrades function will
display the sorted array into a table, followed by the average found.*/

//#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//function prototypes
void getGrades(double*, string*, int);
void displayGrades(double*, string*, int, double);
void sort(double*, string*, int);
double average(double*, int);

int main() {
	double* testScores = nullptr;
	string* students = nullptr;
	double averageScore;
	int numStudents, smth;
	
	cout << "How many students are there? ";
	cin >> smth;

	//validation of number of students
	while (smth < 0) {
		cout << "Invalid number of students." << endl;
		cout << "Cannot have a negative amount." << endl;
		cout << "How many students are there? ";
		cin >> smth;
	}
	numStudents = smth;

	//dynamic memory allocation of arrays
	testScores = new double[numStudents];
	students = new string[numStudents];

	getGrades(testScores, students, numStudents);

	sort(testScores, students, numStudents);

	averageScore = average(testScores, numStudents);

	displayGrades(testScores, students, numStudents, averageScore);

	// free memory space from allocated memory
	delete[] testScores;
	delete[] students;
	testScores = nullptr;
	students = nullptr;
	
	system("pause");
	return 0;
}

/* this function retrieves the names and grades for each student.
Validation will be required when a user inputs a negative grade value.
*/
void getGrades(double* scores, string* names, int size) {

	string studentName;
	double grade;

	cout << endl << "Enter the students' names and test scores below." << endl;
	for (int count = 0; count < size; count++) {
		cout << "Name of student " << (count + 1) << ": ";
		cin >> studentName;
		
		cout << studentName << "'s test score: ";
		cin >> grade;
		while (grade < 0) {
			cout << "Invalid test score." << endl;
			cout << "Score cannot be negative." << endl;
			cout << studentName << "'s test score: ";
			cin >> grade;
		}
		names[count] = studentName;
		scores[count] = grade;
	}

}
/* This function displays the names and grades for each student as a sorted list/table.
The average is displayed following the ascending list.
*/
void displayGrades(double* score, string* names, int size, double avg) {

	cout << setprecision(2) << fixed << endl;
	
	cout << "Student" << setw(20) << "Score" << endl;
	cout << "_____________________________" << endl;
	for (int index = 0; index < size; index++) {
		cout << names[index] << "\t" << setw(20) << score[index] << endl;
	}

	cout << endl;
	cout << "Average Score: " << avg << endl << endl;
}
/* This function sorts the names and grades in ascending order.
The selection sort algorithm is used to sort the names and grades.*/
void sort(double* score, string* names, int size) {
	int minIndex, minValue;

	for (int start = 0; start < (size - 1); start++)
	{
		minIndex = start;
		minValue = score[start], names[start];
		for (int index = start + 1; index < size; index++) {
			if (score[index] < minValue) {
				minValue = score[start], names[start];
				minIndex = index;
			}
		}
		swap(score[minIndex], score[start]);
		swap(names[minIndex], names[start]);
	}
}
/* this function finds the average of grades input by the user*/
double average(double* score, int numStudents) {
	double avg, total = 0;
	for (int index = 0; index < numStudents; index++) {
		total += score[index];
	}
	
	avg = total / numStudents;

	return avg;
}
