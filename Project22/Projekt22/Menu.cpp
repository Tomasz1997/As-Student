#include "Menu.h"



Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::addButton(std::string text, int positionX, int positionY, int sizeX, int sizeY)
{
	MenuButton newButton(text, positionX, positionY, sizeX, sizeY);
	button.push_back(newButton);
}

int Menu::isOnclick(int x, int y)
{
	for (int i = 0; i < button.size(); i++)
	{
		if (button[i].isOnClick(x, y)) return i;
	}
	return -1;
}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < button.size(); i++)
	{
		button[i].draw(window);
	}
}
