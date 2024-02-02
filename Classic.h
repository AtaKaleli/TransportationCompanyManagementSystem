/* Ata Kaleli – 2385474
I read and accept the submission rules and the notes specified in each question.This is my own work that is done by myself only
*/

#ifndef CLASSIC_H
#define CLASSIC_H



class Classic {
private:
	char** board;
public:
	Classic();
	void print();
	int checkHorizontal();
	int checkVertical();
	int checkRightCross();
	int checkLeftCross();
	int checkWinner();
	void setElement(int i, int j, char element);
	char getElement(int i, int j);
	int operator!();
};

#endif // !CLASSIC_H
