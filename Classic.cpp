/* Ata Kaleli – 2385474
I read and accept the submission rules and the notes specified in each question.This is my own work that is done by myself only
*/

#include<iostream>
using namespace std;

#include"Classic.h"

Classic::Classic() {
	this->board = new char* [3];
	for (int i = 0;i < 3;i++) {
		this->board[i] = new char[3];
	}
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			this->board[i][j] = '-';
		}
	}
}

void Classic:: print() {
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			cout << this->board[i][j] << " ";
		}
		cout << "\n";
	}
}

int Classic:: checkHorizontal() {
	int xCount = 0;
	int oCount = 0;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (this->board[i][j] == 'X')
				xCount++;
			else if (this->board[i][j] == 'O')
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

int Classic::checkVertical() {
	int xCount = 0;
	int oCount = 0;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (this->board[j][i] == 'X')
				xCount++;
			else if (this->board[j][i] == 'O')
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

int Classic::checkRightCross() {
	int xCount = 0;
	int oCount = 0;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (i == j) {
				if (this->board[i][j] == 'X')
					xCount++;
				else if (this->board[i][j] == 'O')
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

int Classic::checkLeftCross() {
	int xCount = 0;
	int oCount = 0;
	int count = 0;
	for (int i = 2;i >= 0;i--) {
		if (this->board[count][i] == 'X')
			xCount++;
		else if (this->board[count][i] == 'O')
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

int Classic::checkWinner() {
	if (checkHorizontal() == 1 || checkLeftCross() == 1 || checkRightCross() == 1 || checkVertical() == 1)
		return 1;
	else if (checkHorizontal() == 0 || checkLeftCross() == 0 || checkRightCross() == 0 || checkVertical() == 0)
		return 0;
	else
		return -1;
}

void Classic::setElement(int i, int j, char element) {
	this->board[i][j] = element;
}

char Classic:: getElement(int i, int j) {
	return this->board[i][j];
}

int Classic:: operator!() { // operator overloaing of '!', if a small board and up as tie, I used this function
	int xTotal = 0;
	int oTotal = 0;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (this->board[i][j] == 'X') {
				xTotal += i * 3 + j + 1;
			}
			else if (this->board[i][j] == 'O') {
				oTotal += i * 3 + j + 1;
			}

		}
	}
	if (xTotal > oTotal) {
		cout << "X wins!" << endl;
		return 1;

	}
	else {
		cout << "O wins!" << endl;
		return 0;
	}
}

