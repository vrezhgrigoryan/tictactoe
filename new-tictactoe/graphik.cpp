#include "graphik.h"

#include <vector>

inline const int HEIGHT = 10;
inline const int LENGHT = 26;
inline const int BOX_HEIGHT = 16;

Graphik::Graphik(){
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    gameWin = newwin(HEIGHT, LENGHT, 0, 0);
    box(gameWin, 0, 0);

}
void Graphik::startGame()
{
}
void Graphik::printBord()
{
   
 

    box(gameWin, 0, 0);
    for (int x = 0; x < HEIGHT; x++)
    {
        for (int y = 0; y < LENGHT - 1; y++)
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
}
void Graphik::exitGame(){

}
void Graphik::input(){

}
void Graphik::printPlayer(){

}
void Graphik::printWiner(){
    
}