#include "GameBoard.h"



GameBoard::GameBoard(int countButtonOnSquare)
{
	for (int i = 0; i < countButtonOnSquare; i++)
	{
		for (int j = 0; j < countButtonOnSquare; j++)
		{
			GameButton button(i * 55 + 50, j * 55 + 50, 50, 50);
			gameButton.push_back(button);
		}
	}

	for (int i = 0; i < countButtonOnSquare * countButtonOnSquare; i++)
	{
		gameBoardToOnclick.push_back(0);
		gameBoardYouOnclick.push_back(0);
	}
	this->countButtonOnSquare = countButtonOnSquare;

	srand(time(NULL));
}

GameBoard::~GameBoard()
{
}

std::string GameBoard::isOnclick(int x, int y)
{
	for (int i = 0; i < gameButton.size(); i++)
	{
		if (gameButton[i].isOnclick(x, y))
		{
			if (gameBoardToOnclick[i] == 1)
			{
				gameBoardYouOnclick[i] = 1;
				return "GOOD";
			}
			else
			{
				gameBoardYouOnclick[i] = 2;
				return "ERROR";
			}
		}
	}
	return "OUT";
}

void GameBoard::drawHide(sf::RenderWindow &window)
{
	for (int i = 0; i < gameButton.size(); i++)
	{
		gameButton[i].drawHide(window);
	}
}

void GameBoard::drawToMemory(sf::RenderWindow &window)
{
	for (int i = 0; i < gameButton.size(); i++)
	{
		if(gameBoardToOnclick[i] == 0) gameButton[i].drawHide(window);
		else if(gameBoardToOnclick[i] == 1) gameButton[i].drawShow(window);
	}
}

void GameBoard::drawWhatYouClick(sf::RenderWindow &window)
{
	for (int i = 0; i < gameButton.size(); i++)
	{
		if (gameBoardYouOnclick[i] == 0) gameButton[i].drawHide(window);
		else if (gameBoardYouOnclick[i] == 1) gameButton[i].drawShow(window);
		else if (gameBoardYouOnclick[i] == 2) gameButton[i].drawError(window);
	}
}

void GameBoard::randBoard(int countButtonToRemember)
{
	int randButton;
	for (int i = 0; i < countButtonOnSquare; i++)
	{
		do
		{
			 randButton = rand() % (countButtonOnSquare * countButtonOnSquare);
		} while (gameBoardToOnclick[randButton] != 0);
		gameBoardToOnclick[randButton] = 1;
	}
}

void GameBoard::clearBoard(int countButtonOnSquare)
{
	gameButton.erase(gameButton.begin(), gameButton.end());

	for (int i = 0; i < countButtonOnSquare; i++)
	{
		for (int j = 0; j < countButtonOnSquare; j++)
		{
			GameButton button(i * 55 + 50, j * 55 + 50, 50, 50);
			gameButton.push_back(button);
		}
		gameBoardToOnclick.push_back(0);
		gameBoardYouOnclick.push_back(0);
	}
	this->countButtonOnSquare = countButtonOnSquare;
}

bool GameBoard::checkWin()
{
	for (int i = 0; i < this->countButtonOnSquare * this->countButtonOnSquare; i++)
	{
			if (gameBoardToOnclick[i] == 1 && gameBoardYouOnclick[i] != 1)
			{
				return false;
			}
	}
	return true;
}
