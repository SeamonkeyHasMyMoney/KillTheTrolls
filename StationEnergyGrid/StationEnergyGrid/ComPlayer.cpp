#include "ComPlayer.h"
#include "Board.h"
#include <iostream>

ComPlayer::ComPlayer()
{
}

int ComPlayer::doMove(Board board)
{
	std::vector<int> moves = getMoves(board);

	int bestScore = -1;
	int bestMove = moves[0];
	for each(int move in moves)
	{
		Board tempBoard = board;
		int score = tempBoard.placeLine(move);
		if (score > bestScore)
		{
			bestScore = score;
			bestMove = move;
		}
	}
	return bestMove;
}

std::vector<int> ComPlayer::getMoves(Board board)
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
