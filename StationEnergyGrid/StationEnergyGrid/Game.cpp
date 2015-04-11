#include "Game.h"
#include <Windows.h>
#include <iostream>

void printBoard2(Board board)
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

	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
}

Game::Game()
{

}

Game::Game(Player* player1, Player* player2)
{
	this->player1 = player1;
	this->player2 = player2;
	score1 = 0;
	score2 = 0;
}

void Game::run()
{
	std::srand(std::time(0));
	sf::RenderWindow window(sf::VideoMode(800, 800), "Station Energy Grid");
	bool player1Turn = true;

	int player1wins = 0;
	int player2wins = 0;
	int numberOfGames = 0;

	while (window.isOpen())
	{
		if (!board.noMoves())
		{
			if (player1Turn)
			{
				int move = player1->doMove(board);
				int correct = board.placeLine(move);
				if (correct == 0)
				{
					player1Turn = false;
				}
				else if (correct > 0)
				{
					score1++;
					std::cout << "Player1: " << score1 << "\n";
				}
			}
			else
			{
				int move = player2->doMove(board);
				int correct = board.placeLine(move);
				if (correct == 0)
				{
					player1Turn = true;
				}
				else if (correct > 0)
				{
					score2++;
					std::cout << "Player2: " << score2 << "\n";
				}
			}
		}
		else if (score1 || score2)
		{
			std::cout << "*** Final score ***\n";
			std::cout << "Smarter: " << score1 << "\n";
			std::cout << "Random: " << score2 << "\n";
			if (score1 > score2)
			{
				player1wins++;
			}
			else if (score2 > score1)
			{
				player2wins++;
			}
			score1 = 0;
			score2 = 0;
			numberOfGames++;

			std::cout << "*** Statistics ***\n";
			std::cout << "Smarter: " << player1wins << "/" << numberOfGames << "\n";
			std::cout << "Random: " << player2wins << "/" << numberOfGames << "\n";
			board.clear();
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		renderBoard(window);
		window.display();
	}
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
	for (auto shape : shapes)
		window.draw(shape);
}