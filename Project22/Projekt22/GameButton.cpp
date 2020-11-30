#include "GameButton.h"

GameButton::GameButton(int positionX, int positionY, int sizeX, int sizeY)
{
	rectangle.setPosition(positionX, positionY);
	rectangle.setSize(sf::Vector2f(sizeX, sizeY));

	this->positionX = positionX;
	this->positionY = positionY;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
}

GameButton::~GameButton()
{
}

void GameButton::drawShow(sf::RenderWindow &window)
{
	this->rectangle.setFillColor(sf::Color::Cyan);
	window.draw(this->rectangle);
}

void GameButton::drawHide(sf::RenderWindow &window)
{
	this->rectangle.setFillColor(sf::Color(211, 211, 211));
	window.draw(this->rectangle);
}

void GameButton::drawError(sf::RenderWindow &window)
{
	this->rectangle.setFillColor(sf::Color(255, 0, 42));
	window.draw(this->rectangle);
}

bool GameButton::isOnclick(int x, int y)
{
	if (rectangle.getPosition().x < x && rectangle.getPosition().y < y)
	{
		if (rectangle.getPosition().x + rectangle.getPoint(2).x >= x &&
			rectangle.getPosition().y + rectangle.getPoint(2).y >= y)
			return true;
	}
	return false;
}
