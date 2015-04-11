#include "Game.h"
#include <SFML/Graphics.hpp>


Game::Game()
{

}

Game::Game(Player* player1, Player* player2)
{
	this->player1 = player1;
	this->player2 = player2;
}

void Game::run()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "Hello World!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(shape);
		window.display();
	}
}

void Game::renderBoard()
{

}