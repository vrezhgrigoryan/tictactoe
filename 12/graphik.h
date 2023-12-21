#ifndef GRAPHIK_H
#define GRAPHIK_H

#include <ncurses.h>

#include "game.h"

class Graphik
{
public:
    Graphik();
    ~Graphik();
    void startGame();
    void printBord();
    void exitGame();
    void input();
    void printPlayer();
    void printWiner();
    WINDOW *gameWin;
    int activX;
    int activY;
    void    drawVerticalLines();
    void    drawHorizontalLines();
private:
	Game game;
};

#endif