#ifndef GAME_H
#define GAME_H

#include <vector>

namespace
{
	using unit = int;
	using row = std::vector<unit>;
	using matrix = std::vector<row>;
	inline const int MATRIX_X = 3;
	inline const int MATRIX_Y = 3;

}

class bord
{
public:
	bord();
	void add(int y, int x, int playerNumber);
	bool haveWiner();
	unit getUnit(int y, int x);

private:
	matrix Matrix;
};

class Game
{
public:
	Game();
	int getPlayerNumber();
	void cursorGoUp();
	void cursorGoLeft();
	void cursorGoRight();
	void cursorGoDawn();
	void addSimvol();
	unit getBordUnit(int y, int x);

	~Game();

private:
	bord Bord;
	int x;
	int y;
	int playerNumber;
};

#endif