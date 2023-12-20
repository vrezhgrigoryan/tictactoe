#include "menu.h"

Menu::Menu() : Winisopen(true), cursorY(CURSOR_START_Y)
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    menuWindow = newwin(MENU_HEIGHT, MENU_LENGHT, 0, 0);
    box(menuWindow, 0, 0);
}
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
    mvwprintw(menuWindow, START_Y, MENU_X, "START");
    mvwprintw(menuWindow, EXIT_Y, MENU_X, "EXIT");
    mvwprintw(menuWindow, cursorY, CURSOR_START_X, "<-");
}
void Menu::input()
{
    switch (getch())
    {
    case KEY_UP:
        if (cursorY == START_Y)
        {
            cursorY = EXIT_Y;
        }
        else
        {
            cursorY--;
        }
        break;
    case KEY_DOWN:
        if (cursorY == EXIT_Y)
        {
            cursorY = START_Y;
        }
        else
        {
            cursorY++;
        }
        break;
    case 10:
        switch (cursorY)
        {
        case START_Y:
            start();
            break;
        case EXIT_Y:
            exit();
            break;
        }
        break;
    }
}

void Menu::start()
{
    delwin(menuWindow);
    Winisopen = false;
    graphik.startGame();
}

void Menu::exit()
{
    
}

Menu::~Menu()
{
    if (Winisopen)
    {
        delwin(menuWindow);
    }
    endwin();
}