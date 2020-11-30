#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <ctime>
#include "MainButton.h"
#include "GameButton.h"

class GameBoard
{
public:
	GameBoard(int countButtonOnSquare);
	~GameBoard();

	std::vector <GameButton> gameButton;
	std::vector <int> gameBoardToOnclick;
	std::vector <int> gameBoardYouOnclick;
	int countButtonOnSquare;

	std::string isOnclick(int x, int y);
	void drawHide(sf::RenderWindow &window);
	void drawToMemory(sf::RenderWindow &window);
	void drawWhatYouClick(sf::RenderWindow &window);
	void clearBoard(int countButtonOnSquare);
	void randBoard(int countButtonToRemember);
	bool checkWin();
};

