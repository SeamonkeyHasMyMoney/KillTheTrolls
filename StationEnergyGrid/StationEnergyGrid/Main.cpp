#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Game.h"
#include <iostream>

void printBoard(Board board) 
{
	std::bitset<BOARD_SIZE> b = board.getBoard();
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		if (i%BOARD_DIM == 0)
		{
			std::cout << "\n";
		}
		std::cout << b[i] << " ";
	}
}

int main()
{
	//sf::RenderWindow window(sf::VideoMode(200, 200), "Hello World!");
	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);

	//while (window.isOpen())
	//{
	//	sf::Event event;
	//	while (window.pollEvent(event))
	//	{
	//		if (event.type == sf::Event::Closed)
	//			window.close();
	//	}
	//	window.clear();
	//	window.draw(shape);
	//	window.display();
	
	//Board board;

	//int i = board.placeLine(1);
	//i = board.placeLine(9);
	//i = board.placeLine(19);
	//i = board.placeLine(11);
	//
	//std::cout << i << "\n";

	//printBoard(board);
	Game game;
	game.run();

	return 0;
}