#ifndef MENU_H
#define MENU_H

#include "graphik.h"

inline const int MENU_HEIGHT = 5;
inline const int MENU_LENGHT = 12;
inline const int MENU_X = 2;
inline const int START_Y = 1;
inline const int EXIT_Y = 2;
inline const int CURSOR_START_X = 7;
inline const int CURSOR_START_Y = START_Y;

class Menu
{
public:
	Menu();
	void run_menu();
	~Menu();

private:
	void print_menu();
	void input();
	void start();
	void exit();

private:
	WINDOW *menuWindow;
	int cursorY;
	Graphik graphik;
	bool Winisopen;
};

#endif
