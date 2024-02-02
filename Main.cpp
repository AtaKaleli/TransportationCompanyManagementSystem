/* Ata Kaleli – 2385474
I read and accept the submission rules and the notes specified in each question.This is my own work that is done by myself only
*/


#include<iostream>
#include<time.h>
using namespace std;

#include"Classic.h"
#include"Ultimate.h"
#include"Randomness.h"
#include"RandomBoardCheckWinner.h"
#include"Gameplay.h"
#include"OperatorOverloadingPlus.h"
#include"OperatorOverloadingMinus.h"



int main() {


	srand(time(NULL));
	
	Ultimate* u1=new Ultimate;//creating an ultimate board for round1
	Ultimate* u2=new Ultimate;//creating an ultimate board for round2
	Classic boards1[3][3];//creating an array of classic boards for round1
	Classic boards2[3][3];//creating an array of classic boards for round2

	//I played the game rounds in the gameplay function
	gameplay(1, u1, boards1);//here, I called gameplay function for the 1st round
	gameplay(2, u2, boards2);//and called the gameplay function again for the 2nd round
	
	int player1wins = u1->getWinsOfX() + u2->getWinsOfX();//those are the number of wins of the players, if any player reach win of 2, s/he won the game
	int player2wins = u1->getWinsOfO() + u2->getWinsOfO();
	
	if (player1wins == 2)
		cout << "Player1 wins the game!" << endl;
	else if (player2wins == 2)
		cout << "Player2 wins the game!" << endl;
	else {// this is the case where player1 and player2 cant reach the score of 2, so I need for for 3rd round with operator overloading here
		Randomness r1;//here I created two randomness object, then I add the 1st and 2nd round boards into these randomness objects
		Randomness r2;
		
		r1.addBoard(boards1);
		r2.addBoard(boards2);
		Randomness result;
		Classic tempBoard[3][3];
		result.addBoard(tempBoard);//after that, I created another randomness object called result to hold the return value of overloaded functions.
		int randomnessEfect = rand() % 2;//if randomnessEfect equals to 1, I used '+' operator overloading , if it is 0, I used '-' operator overloading for the 3rd round of the game
		if(randomnessEfect==1)
			result = r1 + r2;
		else if(randomnessEfect==0)
			result = r1 - r2;
		
		int player1RandomWin = result.getRandomXwin();//here, normally, I have to achive the result of the 3rd game, but I have problem to achieve this result.
		int player2RandomWin = result.getRandomOwin();//I achieved getRandomWin result in the "randomBoardCheckWinner" function, but I cant reach these values in the main.
		
		
		player1wins += player1RandomWin;// so that even any player won the 3rd round, as getRandomWin functions does not work in the main, player1 and 2 wins remains same.
		player2wins += player2RandomWin;
		
		if (player1wins == 2)
			cout << "Player1 wins the game!" << endl;
		else if (player2wins == 2)
			cout << "Player2 wins the game!" << endl;
		else {
			int randomWinner = rand() % 2;
			if(randomWinner==1)
				cout << "Player1 wins the game!" << endl;
			else if(randomWinner==0)
				cout << "Player2 wins the game!" << endl;
		}
		
		
	}


	
	delete u1;
	delete u2;
	


	return 0;
}
	














































































	/*
	int gameRound = 0;//buna gerek yok
	int winOfX=0;
	int winOfO=0;

	while (gameRound!=3) {// buna gerek yok


		cout << "Info:  \n";
		cout << "gameROund: " << gameRound << " winofx: " << winOfX << " winofo: " << winOfO << "\n" << endl;

		//u1[gameRound].addBoard(boards);
		// bütün u1 lerden gameround u sýl
		int ultimateRound = 0;
		while (ultimateRound != 9) {
			
			u1[gameRound].print();
			int boardCoordinate1, boardCoordinate2;//these are the coordinates of ultimate board. If user enter 0 0, this means the classic board that is in the index 0 0 will be played.
			cout << "Enter the coordinate of the classic board that you want to play: ";
			cin >> boardCoordinate1 >> boardCoordinate2;
			while (boardCoordinate1 < 0 || boardCoordinate1>2 || boardCoordinate2 < 0 || boardCoordinate2>2 || u1[gameRound].getUltimateBoardHolder(boardCoordinate1, boardCoordinate2) != '-') {
				if (boardCoordinate1 < 0 || boardCoordinate1>2 || boardCoordinate2 < 0 || boardCoordinate2>2) {//error if user enters a coordinate out of range.
					cout << "Please enter coordinates between 0-2: ";
				}
				else if (u1[gameRound].getUltimateBoardHolder(boardCoordinate1, boardCoordinate2) != '-') {//error if user enters a board coordinate that is not empty.
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

				boards[boardCoordinate1][boardCoordinate2].setElement(p1Coordinate1, p1Coordinate2, 'X');

				u1[gameRound].print();
				round++;


				if (boards[boardCoordinate1][boardCoordinate2].checkWinner() == 1) {
					cout << "Player1 wins the Classic Board!" << endl;
					u1[gameRound].setUltimateBoardHolder(boardCoordinate1, boardCoordinate2, 'X');
					break;
				}

				if (round == 9) {//here, if nobody wins and the total round equals to 9, to board is over.
					int drawWinner;
					drawWinner = !boards[boardCoordinate1][boardCoordinate2];
					if (drawWinner == 1)//this means X won the board
						u1[gameRound].setUltimateBoardHolder(boardCoordinate1, boardCoordinate2, 'X');
					else////this means O won the board
						u1[gameRound].setUltimateBoardHolder(boardCoordinate1, boardCoordinate2, 'O');

					continue;
				}

				cout << "Enter coordinate to place O: ";
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
				u1[gameRound].print();
				round++;

				if (boards[boardCoordinate1][boardCoordinate2].checkWinner() == 0) {
					cout << "Player2 wins the Classic Board!" << endl;
					u1[gameRound].setUltimateBoardHolder(boardCoordinate1, boardCoordinate2, 'O');
					break;
				}


			}
			if (u1[gameRound].checkWinner() != -1) {

				if (u1[gameRound].checkWinner() == 1) {
					cout << "Player1 wins the Ultimate Board!" << endl;
					u1[gameRound].setWinsOfX();
					break;
				}
				else if (u1[gameRound].checkWinner() == 0) {
					cout << "Player2 wins the Ultimate Board!" << endl;
					u1[gameRound].setWinsOfO();
					break;
				}
			}
			else
				ultimateRound++;

		}
		
		
		
		
		
		//bunu fonksýyon dýsýnda bakabýlýrsýn

		
		for(int i=0;i<=gameRound;i++){
			winOfX+=u1[gameRound].getWinsOfX();
			
		}
		for(int i=0;i<=gameRound;i++){
			winOfO+=u1[gameRound].getWinsOfO();

		}

		if (winOfX == 2) {
			cout << "Player 1 wins the game!!!" << endl;
			break;
		}
			
		else if (winOfO == 2) {
			cout << "Player 2 wins the game!!!" << endl;
			break;
		}
			
		else {
			if (winOfO == 1 && winOfX == 1) { //randomness effect, operator overloading of + and -

			}
			else {
				gameRound++;
			}
		}
	}


	*/


	
	//return 0;
//}