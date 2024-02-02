/* Ata Kaleli – 2385474
I read and accept the submission rules and the notes specified in each question.This is my own work that is done by myself only
*/

#include<iostream>
using namespace std;

#include"Ultimate.h"
#include"Classic.h"

Ultimate::Ultimate() {
	this->ultimateBoardHolder = new char* [3];
	for (int i = 0;i < 3;i++) {
		this->ultimateBoardHolder[i] = new char[3];
	}
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			this->ultimateBoardHolder[i][j] = '-';
		}
	}
	this->winsOfO = 0;
	this->winsOfX = 0;
}

void Ultimate::setUltimateBoardHolder(int i, int j, char element) { // this is a 3x3 board, where I set X's or O's in it based on the game result of the Classic Board
	this->ultimateBoardHolder[i][j] = element;
}

char Ultimate::getUltimateBoardHolder(int i, int j) {
	return this->ultimateBoardHolder[i][j];
}

void Ultimate::setWinsOfX() {
	this->winsOfX++;
}

int Ultimate::getWinsOfX() {
	return this->winsOfX;
}

void Ultimate::setWinsOfO() {
	this->winsOfO++;
}

int Ultimate::getWinsOfO() {
	return this->winsOfO;
}

void Ultimate::printUltimateBoardHolder() {//additional print function to see the overall result of the ultimate board,I did not use it in my project, but it can be used to provide better view of the game
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			cout << this->ultimateBoardHolder[i][j] << " ";
		}
		cout << "\n";
	}
}

void Ultimate::addBoard(Classic c[3][3]) {//this function takes an array of Classic boards and helps me to add these boards in to the ultimate board
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			this->gameBoard[i][j] = &c[i][j];
		}
	}
}
void Ultimate::print() {//this is the print that prints the ultimate board in a 3x3 view

	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			for (int k = 0;k < 3;k++) {
				for (int l = 0;l < 3;l++) {
					cout << this->gameBoard[i][k]->getElement(j, l) << " ";
				}
				cout << "\t";
			}
			cout << "\n";
		}
		cout << "\n";
	}
}

/*
those check functions checks the classic board and return values based on the result
*/

int Ultimate::checkHorizontal() {
	int xCount = 0;
	int oCount = 0;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (this->ultimateBoardHolder[i][j] == 'X')
				xCount++;
			else if (this->ultimateBoardHolder[i][j] == 'O')
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
int Ultimate::checkVertical() {
	int xCount = 0;
	int oCount = 0;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (this->ultimateBoardHolder[j][i] == 'X')
				xCount++;
			else if (this->ultimateBoardHolder[j][i] == 'O')
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
int Ultimate::checkRightCross() {
	int xCount = 0;
	int oCount = 0;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (i == j) {
				if (this->ultimateBoardHolder[i][j] == 'X')
					xCount++;
				else if (this->ultimateBoardHolder[i][j] == 'O')
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
int Ultimate::checkLeftCross() {
	int xCount = 0;
	int oCount = 0;
	int count = 0;
	for (int i = 2;i >= 0;i--) {
		if (this->ultimateBoardHolder[count][i] == 'X')
			xCount++;
		else if (this->ultimateBoardHolder[count][i] == 'O')
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

int Ultimate::checkWinner() {
	if (checkHorizontal() == 1 || checkLeftCross() == 1 || checkRightCross() == 1 || checkVertical() == 1)
		return 1;
	else if (checkHorizontal() == 0 || checkLeftCross() == 0 || checkRightCross() == 0 || checkVertical() == 0)
		return 0;
	else
		return -1;
}
