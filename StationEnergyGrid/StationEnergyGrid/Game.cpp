#include "Game.h"



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
	sf::RenderWindow window(sf::VideoMode(800, 800), "Station Energy Grid");
	renderBoard(window);
}

void Game::renderBoard(sf::RenderWindow& window)
{
	std::bitset<BOARD_SIZE> bitset = board.getBoard();
	//bitset.set(2);
	std::vector<sf::RectangleShape> shapes;

	int sizeWidth = 5;
	int sizeLength = 195;
	int posX = 795;
	int posY = 795;

	for (int i = 1; i < bitset.size(); i+=2)
	{
		sf::RectangleShape shape;
		if ((i / 9) % 2 == 0) //horisontal
		{
			if (((i - 2) / 9) % 2 == 1) // fult, last one was vertical
			{
				posX = 795;
				//posY -= sizeLength;
			}
			posX -= sizeLength;
			
			shape = sf::RectangleShape(sf::Vector2f(sizeLength, sizeWidth));
			if (bitset[i]) // bit set
				shape.setFillColor(sf::Color::Green);
			else
				shape.setFillColor(sf::Color::White);
			shape.setPosition(posX, posY);
			shapes.push_back(shape);
		}
		else
		{
			shape = sf::RectangleShape(sf::Vector2f(sizeWidth, sizeLength));
			if (((i - 2) / 9) % 2 == 0) // fult, last one was hosizontal
			{
				posX = 795;
				posY -= sizeLength;
			}
			else
				posX -= sizeLength;
		}
		if (bitset[i]) // bit set
			shape.setFillColor(sf::Color::Green);
		else
			shape.setFillColor(sf::Color::White);
		shape.setPosition(posX, posY);
		shapes.push_back(shape);
	}



	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		for (auto shape : shapes)
			window.draw(shape);
		window.display();
	}
}