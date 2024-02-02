/* Ata Kaleli – 2385474
I read and accept the submission rules and the notes specified in each question.This is my own work that is done by myself only
*/


#ifndef RANDOMBOARDCHECKWINNER_H
#define RANDOMBOARDCHECKWINNER_H

void randomBoardCheckWinner(int round, Randomness r1, Classic boards[3][3]) { // this functions takes the round number, a randomness board and an array of classic boards

	r1.addBoard(boards);
	cout << "GameRound: " << round << endl;

	for (int i = 0;i < 3;i++) {//here, I have the result of the 3rd round as a r1 board, I directy check the winner of classic boards
		for (int j = 0;j < 3;j++) {
			if (boards[i][j].checkWinner() == 1) {
				r1.setRandomnessBoardHolder(i, j, 'X');
			}
			else if (boards[i][j].checkWinner() == 0) {
				r1.setRandomnessBoardHolder(i, j, 'O');
			}
			else {
				r1.setRandomnessBoardHolder(i, j, '-');
			}
		}
	}
	r1.printRandomnessBoardHolder();
	if (r1.checkWinner() == 1) {//here, I successfully set the random x or random o fuctions, which increments the win of x or o, but I could not achieve these values in the main.
		cout << "Player1 wins the Randomness Board!" << endl;
		r1.setRandomXwin();

	}
	else if (r1.checkWinner() == 0) {
		cout << "Player2 wins the Randomness Board!" << endl;
		r1.setRandomOwin();
	}

}


#endif // !RANDOMBOARDCHECKWINNER
