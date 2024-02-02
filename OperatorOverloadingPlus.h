/* Ata Kaleli – 2385474
I read and accept the submission rules and the notes specified in each question.This is my own work that is done by myself only
*/

#ifndef OPERATOROVERLODINGPLUS_H
#define OPERATOROVERLODINGPLUS_H

#include"Randomness.h"
#include"Classic.h"
#include"RandomBoardCheckWinner.h"


Randomness operator-(Randomness r1, Randomness r2) { // third round, operator overloading of '-' sign

	Randomness result;
	Classic tempBoard[3][3];
	result.addBoard(tempBoard);// I created a temporary randomness board to hold my data


	for (int i = 0;i < 3;i++) {//in this loop, I set the values to my tempBoard based on the given consitions
		for (int j = 0;j < 3;j++) {
			for (int k = 0;k < 3;k++) {
				for (int l = 0;l < 3;l++) {
					char r1Hold = r1.randomnessBoards[i][j]->getElement(k, l);
					char r2Hold = r2.randomnessBoards[i][j]->getElement(k, l);
					if (r1Hold == 'X' && r2Hold == 'X')
						tempBoard[i][j].setElement(k, l, 'X');
					else if (r1Hold == 'X' && r2Hold == 'O')
						tempBoard[i][j].setElement(k, l, 'O');
					else if (r1Hold == 'O' && r2Hold == 'X')
						tempBoard[i][j].setElement(k, l, 'O');
					else if (r1Hold == 'O' && r2Hold == 'O')
						tempBoard[i][j].setElement(k, l, 'O');
					else if (r1Hold == '-' && r2Hold == 'O')
						tempBoard[i][j].setElement(k, l, 'O');
					else if (r1Hold == '-' && r2Hold == 'X')
						tempBoard[i][j].setElement(k, l, 'X');
					else if (r1Hold == 'O' && r2Hold == '-')
						tempBoard[i][j].setElement(k, l, 'O');
					else if (r1Hold == 'X' && r2Hold == '-')
						tempBoard[i][j].setElement(k, l, 'X');
					else if (r1Hold == '-' && r2Hold == '-')
						tempBoard[i][j].setElement(k, l, '-');
				}
			}
		}
	}

	randomBoardCheckWinner(3, r1, tempBoard);// after setting values to my temp boards, I called randomBoardChechWinner function to get who is the winner of the randomBoard round

	return result;
}






























#endif // !OPERATOROVERLODINGPLUS_H

