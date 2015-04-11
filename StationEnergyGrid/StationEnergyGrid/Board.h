#ifndef BOARD_H
#define BOARD_H

#include <bitset>

#define BOARD_DIM 9
#define BOARD_SIZE BOARD_DIM*BOARD_DIM

class Board {
public:
	Board();

	int placeLine(int pos);
	std::bitset<BOARD_SIZE> getBoard();

private:
	
	bool pointScored(int pos);

	std::bitset<BOARD_SIZE> bitBoard;
};

#endif