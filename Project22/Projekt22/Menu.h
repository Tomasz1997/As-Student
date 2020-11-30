#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "MenuButton.h"

class Menu
{
public:
	Menu();
	~Menu();

	std::vector <MenuButton> button;

	void addButton(std::string text, int positionX, int positionY, int sizeX, int sizeY);
	int isOnclick(int x, int y);
	void draw(sf::RenderWindow &window);
};

