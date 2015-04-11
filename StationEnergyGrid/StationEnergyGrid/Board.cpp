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
	std::cout << "\n";
	std::cout << "\n";
}

std::bitset<BOARD_SIZE> winMask;
std::bitset<BOARD_SIZE> endMask;

Board::Board()
{
	bitBoard.reset();
	winMask.set(1);
	winMask.set(9);
	winMask.set(11);
	winMask.set(19);

	for (int i = 1; i < BOARD_SIZE; i += 2)
	{
		endMask.set(i);
	}
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

bool Board::noMoves()
{
	return(bitBoard == endMask);
}

bool Board::pointScored(int pos)
{
	//Horizontal
	if ((pos / BOARD_DIM) % 2 == 0)
	{
		if ((pos - BOARD_DIM*2 > 0 && ((winMask << ((pos - 1) - BOARD_DIM*2)) & bitBoard) == (winMask << ((pos - 1) - BOARD_DIM*2))) ||
			(pos + BOARD_DIM < BOARD_SIZE && ((winMask << (pos - 1)) & bitBoard) == (winMask << (pos - 1))))
			return true;
	}
	//Vertical
	else
	{
		if (((pos + 2) < BOARD_SIZE && (pos%BOARD_DIM < (BOARD_DIM -1)) && ((winMask << (pos)) & bitBoard) == (winMask << (pos))) ||
			((pos - 2) > 0 && (pos%BOARD_DIM > 0) && ((winMask << pos - BOARD_DIM - 2) & bitBoard) == (winMask << pos - BOARD_DIM - 2)))
			return true;
	}
	return false;
}

void Board::clear()
{
	bitBoard.reset();
}