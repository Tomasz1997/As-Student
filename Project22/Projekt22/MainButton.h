#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class MainButton
{
public:
	MainButton();
	MainButton(int positionX, int positionY, int sizeX, int sizeY);
	~MainButton();

	sf::RectangleShape rectangle;

	int positionX;
	int positionY; 
	int sizeX;
	int sizeY;
};

