#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Gameboard.h"
#include <iostream>
#include <Windows.h>

using namespace std;
using namespace sf;

int main()
{
	FreeConsole();

	Texture ground;
	if (!ground.loadFromFile("christmas-dark.png"))
	{
		string exception = "Lack of file christmas-dark.png";
		throw exception;
	}
	else
	{
		cout << "Included file christmas-dark.png" << endl;
	}

	ground.setRepeated(true);
	Sprite background;
	background.setTextureRect({ 0, 0, 600, 600 });
	background.setPosition(Vector2f(0, 0));
	background.setTexture(ground);

	SoundBuffer buffer;
	if (!buffer.loadFromFile("win.wav"))
	{
		return -1;
	}
	else
	{
		cout << "Zaladowano plik win.waw";
	}

	SoundBuffer buffer2;
	if (!buffer2.loadFromFile("lose.wav"))
	{
		return -1;
	}
	else
	{
		cout << "Zaladowano plik lose.waw";
	}

	Sound win;
	Sound lose;

	win.setBuffer(buffer);
	lose.setBuffer(buffer2);

	Gameboard new_game;
	RenderWindow window(VideoMode(600, 600, 32), "Tic Tac Toe");
	window.setFramerateLimit(15);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (new_game.Check() == 0)
				{
					
					if (new_game.Use_mouse(event.mouseButton.x, event.mouseButton.y))
					{
						new_game.Computer();
						if (new_game.Check() == 1) lose.play();
						else if (new_game.Check() == 2) win.play();
					}
				}
			}
		}
		window.draw(background);
		new_game.Display(window);
		window.display();
	}
	return 0;
}