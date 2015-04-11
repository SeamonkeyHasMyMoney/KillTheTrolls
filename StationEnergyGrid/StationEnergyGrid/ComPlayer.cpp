#include "ComPlayer.h"
#include "Board.h"

ComPlayer::ComPlayer()
{
}

int ComPlayer::doMove(Board board)
{
	return minimax(board, 0, 4, true, 4);
}

int ComPlayer::minimax(Board board, int scoreSum, int depth, bool maximizingPlayer, int maxDepth)
{
	if (depth <= 0 || board.noMoves())
	{
		return scoreSum;
	}
	std::vector<int> moves = getMoves(board);
	if (maximizingPlayer)
	{
		int bestScore = -100;
		int bestMove;
		for each(int move in moves)
		{
			bestMove = move;
			int score = board.placeLine(move);
			scoreSum += score;
			int retScore = minimax(board, scoreSum, depth - 1, !maximizingPlayer, maxDepth);
			bestScore = retScore > bestScore ? retScore : bestScore;
			if (retScore > bestScore)
			{
				bestScore = retScore;
				bestMove = move;
			}
		}
		if (depth == maxDepth)
		{
			return bestMove;
		}
		else
		{
			return bestScore;
		}
	}
	else
	{
		int bestScore = +100;
		for each(int move in moves)
		{
			int score = board.placeLine(move);
			scoreSum -= score;
			int retScore = minimax(board, scoreSum, depth - 1, !maximizingPlayer, maxDepth);
			bestScore = retScore < bestScore ? retScore : bestScore;
		}
		return bestScore;
	}
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
