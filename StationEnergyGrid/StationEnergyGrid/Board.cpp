#include "Board.h"
#include <iostream>

void printBoard(std::bitset<BOARD_SIZE> b)
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		if (i%BOARD_DIM == 0)
		{
			std::cout << "\n";
		}
		std::cout << b[i] << " ";
	}
}

const std::bitset<BOARD_SIZE> winMask(std::string
(
	"010000000"
	"101000000"
	"010000000"
	"000000000"
	"000000000"
	"000000000"
	"000000000"
	"000000000"
	"000000000"
));

Board::Board()
{
	bitBoard.reset();
}

int Board::placeLine(int pos)
{
	if (pos % 2 == 1 && bitBoard[pos] == 0)
	{
		bitBoard.set(pos);

		if (pointScored(pos)) 
		{
			return 1;
		}
		return 0;
	}
	return -1;
}

std::bitset<BOARD_DIM*BOARD_DIM> Board::getBoard()
{
	return bitBoard;
}

bool Board::pointScored(int pos)
{
	//Horizontal
	if ((pos / BOARD_DIM) % 2 == 0)
	{
		std::bitset<BOARD_SIZE> btemp;
		if (pos - BOARD_DIM > 0)
		{
			btemp = (winMask << ((pos - 1) - BOARD_DIM));
			printBoard(btemp);
			if ((btemp & bitBoard) == btemp)
				return true;
		}
		std::cout << "\n\n";
		if (pos + BOARD_DIM < BOARD_SIZE)
		{
			btemp = (winMask << ((pos - 1) - BOARD_DIM));
			printBoard(btemp);
			if ((btemp & bitBoard) == btemp)
				return true;
		}
		if ((pos - BOARD_DIM > 0 && ((winMask << ((pos - 1) - BOARD_DIM)) & bitBoard) == (winMask << ((pos - 1) - BOARD_DIM))) ||
			(pos + BOARD_DIM < BOARD_SIZE && ((winMask << (pos - 1)) & bitBoard) == (winMask << (pos - 1))))
			return true;
	}
	//Vertical
	else
	{
		if (((pos + 2) < BOARD_SIZE && ((winMask << (pos)) & bitBoard) == (winMask << (pos))) ||
			((pos - 2) > 0 && ((winMask << pos - BOARD_DIM - 2) & bitBoard) == (winMask << pos - BOARD_DIM - 2)))
			return true;
	}
	return false;
}