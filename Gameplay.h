/* Ata Kaleli – 2385474
I read and accept the submission rules and the notes specified in each question.This is my own work that is done by myself only
*/

#ifndef GAMEPLAY_H
#define GAMEPLAY_H


void gameplay(int round, Ultimate* u1, Classic boards[3][3]) { // this function takes the round number, an ultimate board and an array of Classic Boards

	u1->addBoard(boards);
	cout << "GameRound: " << round << endl;

	int ultimateRound = 0;
	while (ultimateRound != 3) {

		u1->print();
		int boardCoordinate1, boardCoordinate2;//these are the coordinates of ultimate board. If user enter 0 0, this means the classic board that is in the index 0 0 will be played.
		cout << "Enter the coordinate of the classic board that you want to play: ";
		cin >> boardCoordinate1 >> boardCoordinate2;
		while (boardCoordinate1 < 0 || boardCoordinate1>2 || boardCoordinate2 < 0 || boardCoordinate2>2 || u1->getUltimateBoardHolder(boardCoordinate1, boardCoordinate2) != '-') {
			if (boardCoordinate1 < 0 || boardCoordinate1>2 || boardCoordinate2 < 0 || boardCoordinate2>2) {//error if user enters a coordinate out of range.
				cout << "Please enter coordinates between 0-2: ";
			}
			else if (u1->getUltimateBoardHolder(boardCoordinate1, boardCoordinate2) != '-') {//error if user enters a board coordinate that is not empty.
				cout << "You can not play in this place! Please re-enter the coordinates: ";
			}
			cin >> boardCoordinate1 >> boardCoordinate2;
		}
		
		int round = 0;

		while (round != 9) {

			int p1Coordinate1;//represents player1 coordinate1
			int p1Coordinate2;//represents player1 coordinate2
			int p2Coordinate1;//represents player2 coordinate1
			int p2Coordinate2;//represents player2 coordinate2

			cout << "Enter coordinate to place X: ";
			cin >> p1Coordinate1 >> p1Coordinate2;
			while (p1Coordinate1 < 0 || p1Coordinate1>2 || p1Coordinate2 < 0 || p1Coordinate2>2 || boards[boardCoordinate1][boardCoordinate2].getElement(p1Coordinate1, p1Coordinate2) != '-') {
				if (p1Coordinate1 < 0 || p1Coordinate1>2 || p1Coordinate2 < 0 || p1Coordinate2>2) {//error if user enters a coordinate out of range.
					cout << "Please enter coordinates between 0-2: ";
				}
				else if (boards[boardCoordinate1][boardCoordinate2].getElement(p1Coordinate1, p1Coordinate2) != '-') {//error if user enters a coordinate that is not empty.
					cout << "You can not put element in this place! Please re-enter the coordinates: ";
				}
				cin >> p1Coordinate1 >> p1Coordinate2;
			}

			boards[boardCoordinate1][boardCoordinate2].setElement(p1Coordinate1, p1Coordinate2, 'X');//here,If there is no problem with coordinates, I set the element 'X' in to the board

			u1->print();
			round++;


			if (boards[boardCoordinate1][boardCoordinate2].checkWinner() == 1) {//here after setting X to board, I check whether the game ends or not.
				cout << "Player1 wins the Classic Board!" << endl;
				u1->setUltimateBoardHolder(boardCoordinate1, boardCoordinate2, 'X');//If player1 wins the game, I set the ultimateBoard 'X' in the entered board coordinates.
				break;
			}

			if (round == 9) {//here, if nobody wins and the total round equals to 9, to board is over.
				int drawWinner;
				drawWinner = !boards[boardCoordinate1][boardCoordinate2];//when small board end up as a tie, I used operator overloading of '!'
				if (drawWinner == 1)//this means X won the board
					u1->setUltimateBoardHolder(boardCoordinate1, boardCoordinate2, 'X');
				else////this means O won the board
					u1->setUltimateBoardHolder(boardCoordinate1, boardCoordinate2, 'O');

				continue;
			}

			cout << "Enter coordinate to place O: ";//same process with X
			cin >> p2Coordinate1 >> p2Coordinate2;
			while (p2Coordinate1 < 0 || p2Coordinate1>2 || p2Coordinate2 < 0 || p2Coordinate2>2 || boards[boardCoordinate1][boardCoordinate2].getElement(p2Coordinate1, p2Coordinate2) != '-') {
				if (p2Coordinate1 < 0 || p2Coordinate1>2 || p2Coordinate2 < 0 || p2Coordinate2>2) {//error if user enters a coordinate out of range.
					cout << "Please enter coordinates between 0-2: ";
				}
				else if (boards[boardCoordinate1][boardCoordinate2].getElement(p2Coordinate1, p2Coordinate2) != '-') {//error if user enters a coordinate that is not empty.
					cout << "You can not put element in this place! Please re-enter the coordinates: ";
				}
				cin >> p2Coordinate1 >> p2Coordinate2;
			}

			boards[boardCoordinate1][boardCoordinate2].setElement(p2Coordinate1, p2Coordinate2, 'O');
			u1->print();
			round++;

			if (boards[boardCoordinate1][boardCoordinate2].checkWinner() == 0) {
				cout << "Player2 wins the Classic Board!" << endl;
				u1->setUltimateBoardHolder(boardCoordinate1, boardCoordinate2, 'O');
				break;
			}


		}
		if (u1->checkWinner() != -1) {//here, I checked the ultimate board, whether any player wins the game or not

			if (u1->checkWinner() == 1) {
				cout << "Player1 wins the Ultimate Board!" << endl;
				u1->setWinsOfX();
				break;
			}
			else if (u1->checkWinner() == 0) {
				cout << "Player2 wins the Ultimate Board!" << endl;
				u1->setWinsOfO();
				break;
			}
		}
		else {

			if (ultimateRound != 8)
				ultimateRound++;
			else
				cout << "Nobody wins the Ultimate Board! Draw!" << endl;
		}
	}
}

#endif // !GAMEPLAY_H

