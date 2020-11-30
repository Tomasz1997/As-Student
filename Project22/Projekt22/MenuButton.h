#pragma once
#include "MainButton.h"

class MenuButton : MainButton
{
public:
	MenuButton(std::string text, int positionX, int positionY, int sizeX, int sizeY);
	~MenuButton();

	sf::Font font;
	sf::Text text;


	void draw(sf::RenderWindow &window);
	bool isOnClick(int x, int y);
};

