#include "graphik.h"
#include <vector>
#include <string>

inline const int HEIGHT_BORD = 16;
inline const int LENGHT_WIN = 30;
inline const int HEIGHT_WIN = 20;
inline const int BOX_HEIGHT = 16;
inline const int PRINT_PLEYER_NUMBER_X = 2;

Graphik::Graphik()
{
	gameWin = newwin(HEIGHT_WIN, LENGHT_WIN, 0, 0);
    box(gameWin, 0, 0);
}
Graphik::~Graphik()
{}
void Graphik::startGame()
{
	do{
    	werase(gameWin);
    	printBord();
		wrefresh(gameWin);

	}while(true);
}
void Graphik::printBord()
{
        box(gameWin, 0, 0);
        getch();
        for (int x = 0; x < LENGHT_WIN; x++)
        {
            for (int y = 0; y < HEIGHT_BORD - 1; y++)
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
void Graphik::exitGame()
{
}
void Graphik::input()
{
			switch(getch()){
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
		std::string playerNumberMesig = "PLAYER: ";
		std::string playerNumber = std::to_string(game.getPlayerNumber());
		mvwprintw(gameWin,HEIGHT_BORD+1 , PRINT_PLEYER_NUMBER_X , "%s",playerNumberMesig.c_str());
		mvwprintw(gameWin,HEIGHT_BORD +1 ,PRINT_PLEYER_NUMBER_X + sizeMesig , "%s", playerNumber.c_str());
}
void Graphik::printWiner()
{
}