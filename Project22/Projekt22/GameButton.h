#pragma once
#include "MainButton.h"

class GameButton : MainButton
{
public:
	GameButton(int positionX, int positionY, int sizeX, int sizeY);
	~GameButton();

	void drawShow(sf::RenderWindow &window);
	void drawHide(sf::RenderWindow &window);
	void drawError(sf::RenderWindow &window);
	bool isOnclick(int x, int y);
};

