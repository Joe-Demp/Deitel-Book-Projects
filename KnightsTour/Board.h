#pragma once
#include "Index.h"
using namespace std;

#ifndef BOARD_H
#define BOARD_H
class Board
{
public:
	static const int BOARD_DIM = 8;		//	the dimensions of the board (number of squares down one side)
	Board();							//	initialises a BOARD_DIM * BOARD_DIM board, with each entry = 0
	Board(int[][BOARD_DIM]);			//	initialises a board with values from an array (must be same size as
	~Board();

	void setSquare( int, int, int );	//	sets the value of a square on the board
	int getSquare(int, int) const;

	void printBoard() const;					//	prints the board to the console
	bool checkMove(Index &, int, int) const;	//	checks if a new move (passed as an index) is a valid one

private:
	int board[BOARD_DIM][BOARD_DIM];

	bool checkRange(int, int) const;	//	checks if a coordinate passed to it lies on the board
};
#endif

