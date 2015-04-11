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
	std::srand(std::time(NULL));

	ComPlayer *player1 = new ComPlayer;
	RandomPlayer *player2 = new RandomPlayer;
	/*Board board;
	bool player1Turn = true;

	int score1 = 0;
	int score2 = 0;

	while (window.isOpen())
	{ 
		if (!board.noMoves())
		{
			if (player1Turn)
			{
				int move = player1.doMove(board);
				int correct = board.placeLine(move);
				if (correct == 0)
				{
					player1Turn = false;
				}
				else if (correct > 0)
				{
					score1++;
				}
				std::cout << "Player score 1: " << score1 << "\n";
			}
			else
			{
				int move = player2.doMove(board);
				int correct = board.placeLine(move);
				if (correct == 0)
				{
					player1Turn = true;
				}
				else if (correct > 0)
				{
					score2++;
				}
				std::cout << "Player score 2: " << score2 << "\n";
			}
		}
		else if (score1 || score2)
		{
			std::cout << "*** Final score ***\n";
			std::cout << "Player1: " << score1 << "\n";
			std::cout << "Player2: " << score2 << "\n";
			score1 = 0;
			score2 = 0;
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(shape);
		window.display();
	}*/

	//Board board;

	//int i = board.placeLine(1);
	//i = board.placeLine(9);
	//i = board.placeLine(19);
	//i = board.placeLine(11);
	//
	//std::cout << i << "\n";

	//printBoard(board);
	Game game(player1, player2);
	game.run();

	return 0;
}