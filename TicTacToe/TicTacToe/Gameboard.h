#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
using namespace sf;

class Gameboard
{
public:
	Gameboard();
	~Gameboard();
	enum sign;
	sign turn;
	int **board;
	void Display(RenderWindow & window);
	bool Use_mouse(int x, int y);
	int Check();
	int Check2(int *tab[]);
	int Computer();
	int minmax(int *bufor[], int comp_turn);
};

