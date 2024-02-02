/* Ata Kaleli – 2385474
I read and accept the submission rules and the notes specified in each question.This is my own work that is done by myself only
*/

#ifndef RANDOMNESS_H
#define RANDOMNESS_H


class Classic;

class Randomness {
private:
	Classic* randomnessBoards[3][3];
	char** randomnessBoardHolder;
	int randomXwin;
	int randomOwin;
public:
	Randomness();
	void setRandomnessBoardHolder(int i, int j, char element);
	char getRandomnessBoardHolder(int i, int j);
	void setRandomOwin();
	int getRandomOwin();
	void setRandomXwin();
	int getRandomXwin();
	friend Randomness operator+(Randomness r1, Randomness r2);//operator overload of '+' symbol
	friend Randomness operator-(Randomness r1, Randomness r2);//operator overload of '-' symbol
	void addBoard(Classic c[3][3]);
	void print();
	void printRandomnessBoardHolder();
	int checkHorizontal();
	int checkVertical();
	int checkRightCross();
	int checkLeftCross();
	int checkWinner();
};





















#endif // !RANDOMNESS_H