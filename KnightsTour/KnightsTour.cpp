// KnightsTour.cpp : This file simulates the Knight's Tour Problem
/*The Knight, starting on a corner square of the chessboard, must be moved around
	visiting each square of the board only once.

	Problem taken from "C++ How to Programme" by Deitel & Deitel, Chapter 7

	by Joseph Dempsey, October-November 2018
*/
//

#include "pch.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include "Index.h"
#include "Board.h"
using namespace std;

/*The moves that the knight could potentially make, as 'vectors' from his starting position
*/
static const int KnightsMoves[8][2] = {
		{2, -1},
		{1, -2},
		{-1, -2},
		{-2, -1},
		{-2, 1},
		{-1, 2},
		{1, 2},
		{2, 1}
};	//	end of KnightsMoves

/*Changes the board (sets a visited square to the number of the current turn)
 *and changes the knight's position
 */
void moveKnight(Index &k, Board &b, int moveNo, int turnNo) {
	//cout << "moveNo = " << moveNo << endl;

	int moveRow = k.getRow() + KnightsMoves[moveNo][0];
	int moveCol = k.getCol() + KnightsMoves[moveNo][1];

	k.setRow(moveRow); k.setCol(moveCol);	//	change the knight's position and 
	b.setSquare(turnNo, moveRow, moveCol);		//	change the look of the board
}	//	end moveKnight

int main()
{
	Board myBoard;
	Index knight(0, 0);
	myBoard.setSquare(1, knight.getRow(), knight.getCol());
	srand(time(NULL));	//	seeding the random function

	myBoard.printBoard();
	cout << endl;

	//TODO: Implement countOfSquares, passing it to moveKnight each time
	//todo: allow for moves to be tested (without having an exception thrown)
		//	more efficient than having too many exceptions, especially for brute force solution

	int countOfSquares = 1;
	int moveNumber;
	int moveRow, moveColumn;
	//int d[] = { 0, 4, 1, 5, 2, 6, 3, 7 };

	//for (int i = 0; i < 10; ++i) 
	while (countOfSquares < 10){
		try
		{
			moveNumber = rand() % 8;	//	generate a random number between 0 and 7
			moveRow = KnightsMoves[moveNumber][0];
			moveColumn = KnightsMoves[moveNumber][1];

			if ( myBoard.checkMove(knight, moveRow, moveColumn))
				moveKnight(knight, myBoard, moveNumber, ++countOfSquares);
		}
		catch (exception &e)
		{
			cout << e.what() << endl;
		}	//	end catch
	}	//	end for
	myBoard.printBoard();
}	//	end main

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
