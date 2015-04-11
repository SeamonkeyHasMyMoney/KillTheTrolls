#ifndef RANDOM_PLAYER_H
#define RANDOM_PLAYER_H

#include "Player.h"
class Board;

class RandomPlayer : public Player
{
public:
	RandomPlayer();
	int doMove(Board board);
};

#endif