#include "Game.h"

sf::RenderWindow window(sf::VideoMode(700, 700, 32), "Memory Game");

enum Game::GameState
{
	menu,
	game,
	win,
	lose,
	end
};

Game::Game()
{
	this->currentGameState = GameState::menu;

	bufferTheme.loadFromFile("music.wav");
	bufferCorect.loadFromFile("corect.wav");
	bufferIncorect.loadFromFile("incorect.wav");

	music.setBuffer(bufferTheme);
	music.setLoop(true);
}


Game::~Game()
{
}

void Game::runGame()
{
	while (this->currentGameState != GameState::end)
	{
		switch (this->currentGameState)
		{
		case GameState::menu:
			runMenu();
			break;
		case GameState::game:
			runLevel();
			break;
		default:
			break;
		}
	}
	window.close();
}

void Game::runMenu()
{
	menuButtons.addButton("New Game", window.getSize().x / 2, 50, 250, 60);
	menuButtons.addButton("Exit", window.getSize().x / 2, 150, 250, 60);

	while (this->currentGameState == GameState::menu)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (menuButtons.isOnclick(event.mouseButton.x, event.mouseButton.y) >= 0)
				{
					switch (menuButtons.isOnclick(event.mouseButton.x, event.mouseButton.y))
					{
					case 0:
						currentGameState = GameState::game;
						break;
					case 1:
						currentGameState = GameState::end;
						break;
					default:
						break;
					}
				}
			}
		}
		window.clear(sf::Color::White);
		menuButtons.draw(window);
		window.display();
	}
}

void Game::runLevel()
{
	music.play();
	currentGameState = win;
	error = 0;
	for (int i = 1; i < 10 && currentGameState == win; i++)
	{
		std::cout << "Level: " << i << "\t Life: "<< 3-error << std::endl << std::endl;
		currentGameState = game;
		level(i);
	}
}

bool Game::level(int lvl)
{
	window.setFramerateLimit(60);
	
	winMusic.setBuffer(bufferCorect);

	loseMusic.setBuffer(bufferIncorect);

	GameBoard gameBoard(lvl * 2);
	gameBoard.clearBoard(lvl * 2);

	gameBoard.randBoard(lvl);

	clock_t start = clock();

	while (clock() - start < 2000)
	{
		window.clear(sf::Color::White);
		gameBoard.drawToMemory(window);
		window.display();
	}
	while (currentGameState == game)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				std::string winOrLose = gameBoard.isOnclick(event.mouseButton.x, event.mouseButton.y);
				if (winOrLose == "ERROR")
				{
					error++;
					loseMusic.play();
				}
				else if (winOrLose == "GOOD")
				{
					winMusic.play();
				}
			}
			window.clear(sf::Color::White);
			gameBoard.drawWhatYouClick(window);
			window.display();
			clock_t start = clock();
			while (clock() - start < 200);

			if (error == 3)
			{
				music.stop();
				currentGameState = menu;
			}
			if (gameBoard.checkWin())
			{
				currentGameState = win;
			}
		}
	}
	return true;
}