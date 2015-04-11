#include "RandomPlayer.h"
#include "Board.h"
#include "SFML\System.hpp"
#include "SFML\Window.hpp"

RandomPlayer::RandomPlayer()
{
}

int RandomPlayer::doMove(Board board)
{
	int n = 1000;
	int move = -1;
	int res = -1;
	if (!board.noMoves())
	{
		do
		{
			move = rand() % BOARD_SIZE;
			n--;
			res = board.placeLine(move);
		} while (res < 0 && n > 0);
	
		if (n == 0)
		{
			for (int i = 1; i < BOARD_SIZE; i += 2)
			{
				if (board.placeLine(i) >= 0)
				{
					move = i;
					break;
				}
			}
		}
	}
	return move;
}