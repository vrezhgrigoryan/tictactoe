#include "menu.h"
#include <vector>
#include <iostream>

Menu::Menu() : Winisopen(true), cursorY(CURSOR_START_Y)
{

    this->activeItems = {"start", "exit"};
    this->current = &this->activeItems[0];

    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    menuWindow = newwin(MENU_HEIGHT, MENU_LENGHT, 0, 0);
    box(menuWindow, 0, 0);
}
Menu::~Menu(){};
void Menu::run_menu()
{
    while (true)
    {
        werase(menuWindow);
        box(menuWindow, 0, 0);
        print_menu();
        input();
        wrefresh(menuWindow);
    }
}

void Menu::print_menu()
{

}
void Menu::input()
{

    int key = getch();
    if (key == KEY_UP)
    {
        current = &activeItems[0];
    }
    else if (key == KEY_DOWN)
    {
        current = &activeItems[1];
    }
    else if(key == 10)
    {
        if (*current == "start")
        {
            start();
        }
        else {
            abort();
        }        
    }
    for (int i = 0; i < activeItems.size(); i++)
    {
        if (&activeItems[i] == current)
        {
            mvwprintw(menuWindow, i + 1, 2, "----->");
            mvwprintw(menuWindow, i + 1, 9, "%s", current->c_str());
        }
        else
        {
            mvwprintw(menuWindow, i + 1, 2, "%s", activeItems[i].c_str());
        }
    }
}

void Menu::start()
{
    // delwin(menuWindow);
    // Winisopen = false;
    graphik.startGame();
}

void Menu::exit()
{
    
}

// Menu::~Menu()
// {
//     if (Winisopen)
//     {
//         delwin(menuWindow);
//     }
//     endwin();
// }