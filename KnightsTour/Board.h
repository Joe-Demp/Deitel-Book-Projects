#pragma once
#include "Index.h"
using namespace std;

#ifndef BOARD_H
#define BOARD_H
class Board
{
public:
	Board();
	~Board();

	void setSquare( int, int, int );
	int getSquare(int, int) const;

	void printBoard() const;

	static const int BOARD_DIM = 8;
private:
	int board[BOARD_DIM][BOARD_DIM];

	bool checkRange(int, int) const;
};
#endif

