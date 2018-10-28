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

Board::Board(int b[][BOARD_DIM])
{
	for (int i = 0; i < BOARD_DIM; ++i) {
		for (int j = 0; j < BOARD_DIM; ++j)
			board[i][j] = b[i][j];
	}	//	end outer for
}	//	end overloaded constructor

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

bool Board::checkMove(Index &p, int d_row, int d_col) const
{
	int row_move = p.getRow() + d_row;
	int col_move = p.getCol() + d_col;

	//	Eliminates visiting the same square twice,
	//		may have to move this code later
	if (getSquare(row_move, col_move) != 0)
		return false;

	return checkRange(row_move, col_move);
}

bool Board::checkRange(int row, int col) const
{
	if (row >= 0 && row < BOARD_DIM
		&& col >= 0 && col < BOARD_DIM)
		return true;

	return false;
}	//	end
