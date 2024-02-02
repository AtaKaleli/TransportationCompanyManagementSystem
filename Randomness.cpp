/* Ata Kaleli – 2385474
I read and accept the submission rules and the notes specified in each question.This is my own work that is done by myself only
*/

#include<iostream>
using namespace std;

#include"Randomness.h"
#include"Classic.h"


Randomness::Randomness() {
	this->randomnessBoardHolder = new char* [3];
	for (int i = 0;i < 3;i++) {
		this->randomnessBoardHolder[i] = new char[3];
	}
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			this->randomnessBoardHolder[i][j] = '-';
		}
	}
	this->randomOwin = 0;
	this->randomXwin = 0;
}
void Randomness::setRandomnessBoardHolder(int i, int j, char element) {
	this->randomnessBoardHolder[i][j] = element;
}

char Randomness::getRandomnessBoardHolder(int i, int j) {
	return this->randomnessBoardHolder[i][j];
}

void Randomness::setRandomOwin() {
	this->randomOwin++;
}
int Randomness::getRandomOwin() {
	return this->randomOwin;
}
void Randomness::setRandomXwin() {
	this->randomXwin++;
}
int Randomness::getRandomXwin() {
	return this->randomXwin;
}

void Randomness::addBoard(Classic c[3][3]) {//this function takes an array of Classic boards and helps me to add these boards in to the ultimate board
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			this->randomnessBoards[i][j] = &c[i][j];
		}
	}
}
void Randomness::print() {//this is the print that prints the randomness boards in a 3x3 view

	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			for (int k = 0;k < 3;k++) {
				for (int l = 0;l < 3;l++) {
					cout << this->randomnessBoards[i][k]->getElement(j, l) << " ";
				}
				cout << "\t";
			}
			cout << "\n";
		}
		cout << "\n";
	}
}
void Randomness::printRandomnessBoardHolder() {
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			cout << this->randomnessBoardHolder[i][j] << " ";
		}
		cout << "\n";
	}
}

/*
those are my check functions for randomness object
*/

int Randomness::checkHorizontal() {
	int xCount = 0;
	int oCount = 0;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (this->randomnessBoardHolder[i][j] == 'X')
				xCount++;
			else if (this->randomnessBoardHolder[i][j] == 'O')
				oCount++;
		}
		if (xCount == 3)
			return 1;//x is winner for this board
		else if (oCount == 3)
			return 0;//o is winner for this board
		else {
			xCount = 0;
			oCount = 0;
		}
	}
	return -1;//nobody wins for this board
}
int Randomness::checkVertical() {
	int xCount = 0;
	int oCount = 0;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (this->randomnessBoardHolder[j][i] == 'X')
				xCount++;
			else if (this->randomnessBoardHolder[j][i] == 'O')
				oCount++;
		}
		if (xCount == 3)
			return 1;//x is winner for this board
		else if (oCount == 3)
			return 0;//o is winner for this board
		else {
			xCount = 0;
			oCount = 0;
		}
	}
	return -1;//nobody wins for this board
}
int Randomness::checkRightCross() {
	int xCount = 0;
	int oCount = 0;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (i == j) {
				if (this->randomnessBoardHolder[i][j] == 'X')
					xCount++;
				else if (this->randomnessBoardHolder[i][j] == 'O')
					oCount++;
			}
		}
	}
	if (xCount == 3)
		return 1;//x is winner for this board
	else if (oCount == 3)
		return 0;//o is winner for this board
	else
		return -1;//nobody wins for this board
}
int Randomness::checkLeftCross() {
	int xCount = 0;
	int oCount = 0;
	int count = 0;
	for (int i = 2;i >= 0;i--) {
		if (this->randomnessBoardHolder[count][i] == 'X')
			xCount++;
		else if (this->randomnessBoardHolder[count][i] == 'O')
			oCount++;
		count++;
	}
	if (xCount == 3)
		return 1;//x is winner for this board
	else if (oCount == 3)
		return 0;//o is winner for this board
	else
		return -1;//nobody wins for this board

}

int Randomness::checkWinner() {
	if (checkHorizontal() == 1 || checkLeftCross() == 1 || checkRightCross() == 1 || checkVertical() == 1)
		return 1;
	else if (checkHorizontal() == 0 || checkLeftCross() == 0 || checkRightCross() == 0 || checkVertical() == 0)
		return 0;
	else
		return -1;
}