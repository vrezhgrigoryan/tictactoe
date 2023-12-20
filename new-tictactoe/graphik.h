#ifndef GRAPHIK_H
#define GRAPHIK_H

#include <ncurses.h>

class Graphik
{
public:
    Graphik();
    void startGame();
    void printBord();
    void exitGame();
    void input();
    void printPlayer();
    void printWiner();

    ~Graphik();

private:
    Game game;
    WINDOW *gameWin;
};

#endif