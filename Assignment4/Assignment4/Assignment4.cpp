
#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Player {
	string name;
	int number,
		points;
};

void GetPlayerInfo(Player&);
void ShowPlayerInfo(const Player);
int GetTotalPoints(const Player[], int);
void ShowHighest(Player[], int);

int main() 
{
	const int SIZE = 2;
	Player team[SIZE];
	for (int index = 0; index < SIZE; index++) {
		cout << "Player #" << index + 1 << endl;
		GetPlayerInfo(team[index]);
	}

	cout << setw(20) << "Name" << setw(10) << "Number"
		<< setw(10) << "Points Scored" << endl;
	for (int index = 0; index < SIZE; index++) {
		ShowPlayerInfo(team[index]);
	}

	cout << "Total points scored: " << GetTotalPoints(team, SIZE) << endl;

	ShowHighest(team, SIZE);

	cout << endl;

	system("pause");
	return 0;
}

void GetPlayerInfo(Player& player) {
	cout << "Enter player name: ";
	getline(cin, player.name);
	cout << "Enter player's number: ";
	cin >> player.number;
	
	// validation for player number (cannot be negative)
	while (player.number < 0) {
		cout << "Error: Player's number cannot be negative! Please try again." << endl;
		cout << "Enter player's number: ";
		cin >> player.number;
	}

	cout << "Enter points scored: ";
	cin >> player.points;

	// validation for points scored (cannot be negative)
	while (player.points < 0) {
		cout << "Error: You cannot enter a negative score! Please try again." << endl;
		cout << "Enter points scored: ";
		cin >> player.points;
	}
	cout << endl;
	cin.ignore();
}

void ShowPlayerInfo(Player player) {
	cout << setw(20) << player.name << setw(10) << player.number
		<< setw(10) << player.points << endl;
}

int GetTotalPoints(Player team[], int size) {
	int total = 0;
	for (int index = 0; index < size; index++) {
		total += team[index].points;
	}
	return total;
}

void ShowHighest(Player team[], int size) {
	int highest = team[0].points;
	int index = 0;
	for (int count = 1; count < size; count++) {
		if (team[count].points > highest) {
			highest = team[count].points;
			index = count;
		}
	}

	cout << team[index].name << " scored the most points!" << endl;
}