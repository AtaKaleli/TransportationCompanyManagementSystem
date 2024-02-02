/* Ata Kaleli – 2385474
I read and accept the submission rules and the notes specified in each question.This is my own work that is done by myself only
*/

#ifndef ULTIMATE_H
#define ULTIMATE_H

class Classic;

class Ultimate {
private:
	Classic* gameBoard[3][3];
	char** ultimateBoardHolder;
	int winsOfX;
	int winsOfO;
public:
	Ultimate();
	void setUltimateBoardHolder(int i, int j, char element);
	char getUltimateBoardHolder(int i, int j);
	void setWinsOfX();
	int getWinsOfX();
	void setWinsOfO();
	int getWinsOfO();
	void printUltimateBoardHolder();
	void addBoard(Classic c[3][3]);
	void print();
	int checkHorizontal();
	int checkVertical();
	int checkRightCross();
	int checkLeftCross();
	int checkWinner();
};


#endif // !ULTIMATE_H

