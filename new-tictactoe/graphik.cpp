#include "graphik.h"
#include <vector>

inline const int HEIGHT = 16;
inline const int LENGHT = 30;
inline const int BOX_HEIGHT = 16;

Graphik::Graphik()
{
}
Graphik::~Graphik()
{}
void Graphik::startGame()
{
    clear();
    printBord();
}
void Graphik::printBord()
{
    gameWin = newwin(HEIGHT, LENGHT, 0, 0);
    box(gameWin, 0, 0);
    do
    {
        box(gameWin, 0, 0);
        getch();
        for (int x = 0; x < LENGHT; x++)
        {
            for (int y = 0; y < HEIGHT - 1; y++)
            {
                if (x % 10 == 0)
                {
                    mvwaddch(gameWin, y, x, ACS_VLINE);
                }
                if (y % 5 == 0)
                {
                    mvwaddch(gameWin, y, x, ACS_HLINE);
                }
            }
        }
        wrefresh(gameWin);
    } while (true);
}
void Graphik::exitGame()
{
}
void Graphik::input()
{
}
void Graphik::printPlayer()
{
}
void Graphik::printWiner()
{
}