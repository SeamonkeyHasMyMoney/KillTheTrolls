#include "RandomPlayer.h"
#include "Board.h"
#include "SFML\System.hpp"
#include "SFML\Window.hpp"

RandomPlayer::RandomPlayer()
{
}

int RandomPlayer::doMove(Board board)
{
	int n = 100000000;
	int move = -1;
	int res = -1;
	if (!board.noMoves())
	{
		std::vector<int> moves = getMoves(board);
		std::random_shuffle(moves.begin(), moves.end());
		move = moves[0];
	}
	return move;
}

std::vector<int> RandomPlayer::getMoves(Board board)
{
	std::vector<int> moves;
	std::bitset<BOARD_SIZE> bitBoard = board.getBoard();
	for (int i = 1; i < BOARD_SIZE; i += 2)
	{
		if (!bitBoard[i])
		{
			moves.push_back(i);
		}
	}
	return moves;
}
