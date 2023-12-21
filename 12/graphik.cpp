#include "graphik.h"
#include <vector>
#include <string>

inline const int HEIGHT_BORD = 15;
inline const int LENGHT_WIN = 30;
inline const int HEIGHT_WIN = 20;
inline const int PRINT_PLEYER_NUMBER_X = 2;

Graphik::Graphik()
{
}
Graphik::~Graphik()
{
}
void Graphik::startGame()
{
	clear();
	do
	{
		box(gameWin, 0, 0);
		if (game.Bord.haveWiner())
		{
			wclear(gameWin);
			mvwprintw(gameWin, 4, PRINT_PLEYER_NUMBER_X, "PLAYER %d's WIN:", game.getPlayerNumber());
			wrefresh(gameWin);
			break;
		}
		printPlayer();
		printBord();
		input();
		wrefresh(gameWin);
	} while (true);
}
void Graphik::printBord()
{
	drawHorizontalLines();
	drawVerticalLines();
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (game.getBordUnit(i, j) == 1)
			{
				mvwaddch(gameWin, 3 + i * 5, 5 + j * 10, 'X');
			}
			else if (game.getBordUnit(i, j) == 2)
			{
				mvwaddch(gameWin, 3 + i * 5, 5 + j * 10, 'Y');
			}
		}
	}
}

void Graphik::drawVerticalLines()
{
	for (int i = 0; i < 3; ++i)
	{
		mvwvline(gameWin, 1, i * LENGHT_WIN / 3, 0, HEIGHT_BORD - 1);
	}
}

void Graphik::drawHorizontalLines()
{
	for (int i = 0; i <= 3; ++i)
	{
		mvwhline(gameWin, i * (HEIGHT_WIN - 5) / 3, 1, 0, LENGHT_WIN - 2);
	}
}

void Graphik::exitGame()
{
}

void Graphik::input()
{
	switch (getch())
	{
	case 'w':
		game.cursorGoUp();
		break;
	case 'a':
		game.cursorGoLeft();
		break;
	case 'd':
		game.cursorGoRight();
		break;
	case 's':
		game.cursorGoDawn();
		break;
	case 10:
		game.addSimvol();
		break;
	}
}

void Graphik::printPlayer()
{
	size_t sizeMesig = 8;
	std::string playerNumber = std::to_string(game.getPlayerNumber());
	mvwprintw(gameWin, HEIGHT_BORD + 1, PRINT_PLEYER_NUMBER_X, "PLAYER %s's TURN:", playerNumber.c_str());
}
void Graphik::printWiner()
{
}