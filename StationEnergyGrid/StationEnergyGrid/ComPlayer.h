#ifndef COM_PLAYER_H
#define COM_PLAYER_H

#include "Player.h"
#include <vector>
class Board;

class ComPlayer : public Player
{
public:
	ComPlayer();
	int doMove(Board board);

private:
	int minimax(Board board, int scoreSum, int depth, bool maximizingPlayer, int maxDepth);
	std::vector<int> getMoves(Board board);
};

#endif