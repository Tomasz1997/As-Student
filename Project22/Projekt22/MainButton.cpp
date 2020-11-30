#include "MainButton.h"


MainButton::MainButton() 
{
}

MainButton::MainButton(int positionX, int positionY, int sizeX, int sizeY)
{
	rectangle.setPosition(positionX, positionY);
	rectangle.setSize(sf::Vector2f(sizeX, sizeY));

	this->positionX = positionX;
	this->positionY = positionY;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
}


MainButton::~MainButton()
{
}
