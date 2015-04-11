#ifndef PLAYER_H
#define PLAYER_H

class Board;

class Player {
public:	
	virtual int doMove(Board board) = 0;
};

#endif