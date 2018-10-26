// KnightsTour.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdexcept>
#include "Index.h"
#include "Board.h"
using namespace std;

//static const int KnightsMoves[8][2] = {
//		{2, -1},
//		{1, -2},
//		{-1, -2},
//		{-2, -1},
//		{-2, 1},
//		{-1, 2},
//		{1, 2},
//		{2, 1}
//};	//	end of KnightsMoves

/*Changes the board (sets a visited square to 1)
 *and changes the knight's position
 */
void moveKnight(Index &k, Board &b, int moveNo, int turnNo) {
	const int KnightsMoves[8][2] = { 
		{2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1} 
	};	//	end of KnightsMoves

	cout << "moveNo = " << moveNo << endl;

	int moveRow = k.getRow() + KnightsMoves[moveNo][0];
	int moveCol = k.getCol() + KnightsMoves[moveNo][1];
	cout << "moveRow = " << moveRow << "   moveCol = " << moveCol << endl;

	k.setRow(moveRow); k.setCol(moveCol);	//	change the knight's position and 
	b.setSquare(turnNo, moveRow, moveCol);		//	change the look of the board
}

int main()
{
	Board myBoard;
	Index knight(3, 4);
	myBoard.setSquare(1, knight.getRow(), knight.getCol());

	myBoard.printBoard();

	//TODO: Implement countOfSquares, passing it to moveKnight each time
	//todo: allow for moves to be tested (without having an exception thrown)
		//	more efficient than having too many exceptions, especially for brute force solution

	//int countOfSquares = 0;
	//int d[] = { 0, 4, 1, 5, 2, 6, 3, 7 };

	//for (int i = 0; i < 8; ++i) {
	//	try
	//	{
	//		moveKnight(knight, myBoard, d[i], 1);
	//	}
	//	catch (exception &e)
	//	{
	//		cout << e.what() << endl;
	//	}	//	end catch
	//	myBoard.printBoard();
	//}	//	end for
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
