#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Menu.h"
#include "GameBoard.h"

class Game
{
public:
	Game();
	~Game();

	enum GameState;
	GameState currentGameState;
	Menu menuButtons;
	
	sf::SoundBuffer bufferTheme;
	sf::SoundBuffer bufferCorect;
	sf::SoundBuffer bufferIncorect;

	sf::Sound music;
	sf::Sound winMusic;
	sf::Sound loseMusic;

	int error;

	void runGame();
	void runMenu();
	void runLevel();
	bool level(int lvl);
};

