#ifndef RANDOM_PLAYER_H
#define RANDOM_PLAYER_H

#include "Player.h"
#include <vector>
class Board;

class RandomPlayer : public Player
{
public:
	RandomPlayer();
	int doMove(Board board);
	std::vector<int>getMoves(Board board);
};

#endif