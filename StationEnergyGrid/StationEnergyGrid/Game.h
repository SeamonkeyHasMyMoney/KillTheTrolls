#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Player.h"

class Game {
public:

	Game();
	Game(Player* player1, Player* player2);

	void run();

private:

	void renderBoard(sf::RenderWindow& window);

	Board board;
	Player* player1;
	Player* player2;

	int score1;
	int score2;
};

#endif