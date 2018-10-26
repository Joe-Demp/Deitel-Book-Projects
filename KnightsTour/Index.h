#pragma once

#ifndef INDEX_H
#define INDEX_H

class Index
{
public:
	Index( int = -1, int = -1 );

	void setRow(int);
	int getRow() const;

	void setCol(int);
	int getCol() const;
private:
	int row;
	int col;
};

#endif
