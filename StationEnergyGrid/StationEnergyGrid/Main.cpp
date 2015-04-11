#include <SFML/Graphics.hpp>
#include <time.h>
#include "Board.h"
#include "Game.h"
#include <iostream>
#include "ComPlayer.h"
#include "RandomPlayer.h"

void printBoard(Board board) 
{
	std::bitset<BOARD_SIZE> b = board.getBoard();
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		if (i%BOARD_DIM == 0)
		{
			std::cout << "\n";
		}
		std::cout << b[i] << " ";
	}
}

int main()
{

	ComPlayer *player1 = new ComPlayer;
	RandomPlayer *player2 = new RandomPlayer;
	

	Game game(player1, player2);
	game.run();


	return 0;
}