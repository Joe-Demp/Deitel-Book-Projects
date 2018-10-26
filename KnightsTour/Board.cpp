#include "pch.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "Board.h"
using namespace std;

Board::Board()
{
	//	sets up an empty board
	for (int i = 0; i < BOARD_DIM; ++i) {
		for (int j = 0; j < BOARD_DIM; ++j)
			board[i][j] = 0;
	}	//	end for
}	//	end constructor

Board::~Board()
{
}	//	empty destructor

void Board::setSquare(int value, int row, int col)
{
	if ( checkRange(row, col) )
		board[row][col] = value;
	else
		throw new out_of_range("Tried to set a square out of range");
}

int Board::getSquare(int row, int col) const
{
	if ( checkRange(row,col) ) 
		return board[ row ][ col ];

	return -1;
}

void Board::printBoard() const
{
	for (int row = 0; row < BOARD_DIM; ++row) {
		cout << "\t";
		for (int col = 0; col < BOARD_DIM; ++col) {
			cout << "[" << setw(2) << board[row][col] << "]";
		}	//	end inner for
		cout << endl;
	}	//	end outer for
}	//	end printBoard

bool Board::checkRange(int row, int col) const		//	NOTE: since const methods call this function, it must also be const
{
	if (row < BOARD_DIM && col < BOARD_DIM
		&& row >= 0 && col >= 0)
		return true;

	return false;
}
