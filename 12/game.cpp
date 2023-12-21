#include "game.h"

bord::bord()
{
	Matrix.push_back(row(MATRIX_X, 0));
	Matrix.push_back(row(MATRIX_X, 0));
	Matrix.push_back(row(MATRIX_X, 0));
}

bool bord::add(int y, int x, int playerNumber)
{
	if (playerNumber == 1 && Matrix[y][x] == 0)
	{
		Matrix[y][x] = 1;
		return true;
	}
	if (playerNumber == 2 && Matrix[y][x] == 0)
	{
		Matrix[y][x] = 2;
		return true;
	}
	return false;
}
bool bord::haveWiner()
{
	/* Check rows */
	if (Matrix[0][0] == Matrix[0][1] && Matrix[0][2] == Matrix[0][1] && Matrix[0][1] != 0)
		return true;
	else if (Matrix[1][0] == Matrix[1][1] && Matrix[1][2] == Matrix[1][1] && Matrix[1][1] != 0)
		return true;
	else if (Matrix[2][0] == Matrix[2][1] && Matrix[2][2] == Matrix[2][1] && Matrix[2][1] != 0)
		return true;

	/* Check cols */
	else if (Matrix[0][0] == Matrix[1][0] && Matrix[2][0] == Matrix[1][0] && Matrix[1][0] != 0)
		return true;
	else if (Matrix[0][1] == Matrix[1][1] && Matrix[2][1] == Matrix[1][1] && Matrix[1][1] != 0)
		return true;
	else if (Matrix[0][2] == Matrix[1][2] && Matrix[2][2] == Matrix[1][2] && Matrix[1][2] != 0)
		return true;

	/* Check diagonals */
	else if (Matrix[0][0] == Matrix[1][1] && Matrix[2][2] == Matrix[1][1] && Matrix[1][1] != 0)
		return true;
	else if (Matrix[2][2] == Matrix[1][1] && Matrix[0][0] == Matrix[1][1] && Matrix[1][1] != 0)
		return true;

	else
		return true;
}
unit bord::getUnit(int y, int x)
{
	return Matrix[y][x];
}

////////////////////////////////////////////////////////////game logic /

Game::Game() : playerNumber(1)
{
}

int Game::getPlayerNumber()
{
	return playerNumber;
}
void Game::cursorGoUp()
{
	if (y < MATRIX_Y)
	{
		y++;
	}
	else
	{
		return;
	}
}
void Game::cursorGoLeft()
{
	if (x > 0)
	{
		x--;
	}
	else
	{
		return;
	}
}
void Game::cursorGoRight()
{
	if (x < MATRIX_X)
	{
		x++;
	}
	else
	{
		return;
	}
}
void Game::cursorGoDawn()
{
	if (y > 0)
	{
		y--;
	}
	else
	{
		return;
	}
}
void Game::addSimvol()
{
	if (Bord.add(x, y, playerNumber)){
		if (playerNumber == 1)
		{
			playerNumber = 2;
		}
		else if (playerNumber == 2)
		{
			playerNumber = 1;
		}
	}
}

int Game::getX(){
	return x;
}
int Game::getY(){
	return y;
}
unit Game::getBordUnit(int y, int x)
{
	return Bord.getUnit(y, x);
}

Game::~Game()
{
}