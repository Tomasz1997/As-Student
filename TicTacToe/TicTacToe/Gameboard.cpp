#include "Gameboard.h"


enum Gameboard::sign
{
	circle = -1,
	cross = 1,
	blank = 0,
	draw = 2,
};

Gameboard::Gameboard()
{
	board = new int *[3];
	for (int i = 0; i < 3; i++)
	{
		board[i] = new int [3];
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = blank;
		}
	}
	turn = circle;
}

Gameboard::~Gameboard()
{
	for (int i = 0; i < 3; i++)
	{
		delete board[i];
	}
	delete [] board;
}

void Gameboard::Display(RenderWindow & window)
{
	RectangleShape line1(Vector2f(600, 5));
	line1.setPosition(200, 0);
	line1.rotate(90);

	RectangleShape line2(Vector2f(600, 5));
	line2.setPosition(400, 0);
	line2.rotate(90);

	RectangleShape line3(Vector2f(600, 5));
	line3.setPosition(0, 200);

	RectangleShape line4(Vector2f(600, 5));
	line4.setPosition(0, 400);

	window.draw(line1);
	window.draw(line2);
	window.draw(line3);
	window.draw(line4);

	RectangleShape cross1(Vector2f(200 * sqrt(2) - 60, 20));
	cross1.rotate(45);
	cross1.setFillColor(Color::Red);

	RectangleShape cross2(Vector2f(200 * sqrt(2) - 60, 20));
	cross2.rotate(-45);
	cross2.setFillColor(Color::Red);

	CircleShape circle(60);
	circle.setPointCount(1000);
	circle.setOutlineColor(Color::Blue);
	circle.setOutlineThickness(20);
	circle.setFillColor(Color::Transparent);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == cross)
			{
				cross1.setPosition(i*200 + 20, j*200 + 20);
				window.draw(cross1);

				cross2.setPosition( i * 200 + 20, (j+1) * 200 - 20);
				window.draw(cross2);
			}
			else if (board[i][j] == Gameboard::circle)
			{
				circle.setPosition(i * 200 + 40, j * 200 + 40);
				window.draw(circle);
			}
		}
	}
	
	RectangleShape rectangle(sf::Vector2f(300, 300));
	rectangle.setPosition(150, 150);
	rectangle.setOutlineColor(Color::Black);
	rectangle.setOutlineThickness(4);

	Font font;
	font.loadFromFile("arial.ttf");

	Text text("", font, 40);
	
	text.setPosition(225 - text.getGlobalBounds().width / 2, 160);
	text.setFillColor(Color::Black);
	text.setStyle(sf::Text::Bold);

	if (Check() != blank)
	{
		window.draw(rectangle);
		if (Check() == cross)
		{
			text.setString("Cross win");
			text.setPosition(300 - text.getGlobalBounds().width / 2, 160);

			cross1.setPosition(1 * 200 + 20, 1 * 200 + 20);
			window.draw(cross1);

			cross2.setPosition(1 * 200 + 20, (1 + 1) * 200 - 20);
			window.draw(cross2);
		}
		else if(Check() == Gameboard::circle)
		{
			text.setString("Circle win");
			text.setPosition(300 - text.getGlobalBounds().width / 2, 160);
			circle.setPosition(1 * 200 + 40, 1 * 200 + 40);
			window.draw(circle);
		}
		else
		{
			text.setString("Draw");
			
			text.setPosition(300 - text.getGlobalBounds().width / 2, 160);
	
			cross1.setPosition(1 * 200 + 20, 1 * 200 + 20);
			window.draw(cross1);

			circle.setPosition(1 * 200 + 40, 1 * 200 + 40);
			window.draw(circle);

			cross2.setPosition(1 * 200 + 20, (1 + 1) * 200 - 20);
			window.draw(cross2);
		}
		window.draw(text);
	}
}

bool Gameboard::Use_mouse(int x, int y)
{
	int i = (x % 600) / 200;
	int j = (y % 600) / 200;
	
	if (board[i][j] == blank)
	{
		board[i][j] = turn;

		if (turn == circle) turn = cross;
		else turn = circle;
		return true;
	}
	return false;
}

int Gameboard::Check()
{
	int sum = 0;

	// na skos 1
	for (int i = 0; i < 3; i++)
	{
		sum += board[i][i];
	}
	if (sum == 3 * cross) return cross;
	else if (sum == 3 * circle) return circle;
	else sum = blank;

	// na skos 2
	for (int i = 0, j = 3 - 1; i < 3; i++, j--)
	{
		sum += board[i][j];
	}
	if (sum == 3 * cross) return cross;
	else if (sum == 3 * circle) return circle;
	else sum = blank;

	// poziomo
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			sum += board[i][j];
		}
		if (sum == 3 * cross) return cross;
		else if (sum == 3 * circle) return circle;
		else sum = blank;
	}

	// pionowo
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			sum += board[i][j];
		}
		if (sum == 3 * cross) return cross;
		else if (sum == 3 * circle) return circle;
		else sum = blank;
	}

	// gra skonczona?
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] != 0)
			{
				sum++;
			}
		}
	}
	if (sum == 9) return draw;
	else return blank;
}

int Gameboard::Check2(int *tab[])
{
	int sum = 0;

	// na skos 1
	for (int i = 0; i < 3; i++)
	{
		sum += tab[i][i];
	}
	if (sum == 3 * cross) return cross;
	else if (sum == 3 * circle) return circle;
	else sum = blank;

	// na skos 2
	for (int i = 0, j = 3 - 1; i < 3; i++, j--)
	{
		sum += tab[i][j];
	}
	if (sum == 3 * cross) return cross;
	else if (sum == 3 * circle) return circle;
	else sum = blank;

	// poziomo
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			sum += tab[i][j];
		}
		if (sum == 3 * cross) return cross;
		else if (sum == 3 * circle) return circle;
		else sum = blank;
	}

	// pionowo
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			sum += tab[i][j];
		}
		if (sum == 3 * cross) return cross;
		else if (sum == 3 * circle) return circle;
		else sum = blank;
	}

	// gra skonczona?
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (tab[i][j] != 0)
			{
				sum++;
			}
		}
	}
	if (sum == 9) return draw;
	else return blank;
}

int Gameboard::Computer()
{
	
	if (Check() != 0) return 0;
	
	int x;
	int y;
	int max = -10;
	int m;

	int **bufor = new int *[3];
	for (int i = 0; i < 3; i++)
	{
		bufor[i] = new int [3];
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			bufor[i][j] = board[i][j];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (bufor[i][j] == 0)
			{
				bufor[i][j] = turn;
				m = minmax(bufor, turn);
				bufor[i][j] = 0;

				if (m > max)
				{
					x = i;
					y = j;
					max = m;
				}
			}
		}
	}
	board[x][y] = turn;
	if (turn == circle) turn = cross;
	else turn = circle;
	
	return 0;
}

int Gameboard::minmax(int *bufor[], int comp_turn)
{
	int max;
	int m;

	if (Check2(bufor) == cross) return 1;
	if (Check2(bufor) == circle) return -1;
	if (Check2(bufor) == draw) return 0;

	if (comp_turn == circle)
	{
		comp_turn = cross;
		max = -10;
	}
	else
	{
		comp_turn = circle;
		max = 10;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (bufor[i][j] == blank)
			{
				bufor[i][j] = comp_turn;
				m = minmax(bufor, comp_turn);
				bufor[i][j] = blank;

				if (comp_turn == cross)
				{
					if (m > max) max = m;
				}
				else
				{
					if (m < max) max = m;
				}
			}
		}
	}
	return max;
}
