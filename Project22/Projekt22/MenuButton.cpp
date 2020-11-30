#include "MenuButton.h"



MenuButton::MenuButton(std::string text, int positionX, int positionY, int sizeX, int sizeY)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		std::string exteption = "File arial.ttf does not exist";
		std::cin.get();
		throw exteption;
	}
	this->text.setPosition(0, 0);
	
	this->text.setString(text);
	this->text.setCharacterSize(32);
	this->text.setFillColor(sf::Color::White);
	this->text.setPosition(positionX - (this->text.getCharacterSize() * text.size() / 4), positionY - (this->text.getCharacterSize() / 2));
	
	rectangle.setPosition(positionX - (sizeX / 2), positionY - (sizeY / 2));
	rectangle.setSize(sf::Vector2f(sizeX, sizeY));
	rectangle.setFillColor(sf::Color(211, 211, 211));

	this->positionX = positionX;
	this->positionY = positionY;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
}


MenuButton::~MenuButton()
{
}

void MenuButton::draw(sf::RenderWindow &window)
{
	window.draw(this->rectangle);
	text.setFont(this->font);
	window.draw(this->text);
}

bool MenuButton::isOnClick(int x, int y)
{
	if (rectangle.getPosition().x < x && rectangle.getPosition().y < y)
	{
		if (rectangle.getPosition().x + rectangle.getPoint(2).x >= x &&
			rectangle.getPosition().y + rectangle.getPoint(2).y >= y)
			return true;
	}
	return false;
}
