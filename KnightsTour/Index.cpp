#include <stdexcept>
#include "pch.h"
#include "Index.h"

Index::Index( int r, int c)
{
	setRow(r);
	setCol(c);
}	//	end constructor

void Index::setRow(int y)
{
	row = y;
}

int Index::getRow() const
{
	return row;
}

void Index::setCol(int x)
{
	col = x;
}

int Index::getCol() const
{
	return col;
}
