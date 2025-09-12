#ifndef _CURSOR_HPP_
#define _CURSOR_HPP_
#ifdef _WIN32
#include <windows.h>
#endif

#include <string>
#include <iostream>
#include "KeyboardControl.hpp"
#include "MyLogger.hpp"

class Cursor {

private:
	int rows;
	int cols;
    KeybControl keybControl;

public:
	
	Cursor();

	int getRows();
	int getCols();
    void moveCursor(int row, int col);

	void setRows(int newRows);
	void setCols(int newCols);
    static void showCursor()
    {

#ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(hConsole, &cursorInfo);
        cursorInfo.bVisible = TRUE;
        SetConsoleCursorInfo(hConsole, &cursorInfo);
#else
        std::cout << "\033[?25h";
        std::cout.flush();
#endif

    }

    static void hideCursor()
    {
#ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        if (GetConsoleCursorInfo(hConsole, &cursorInfo)) {
            cursorInfo.bVisible = FALSE;
            SetConsoleCursorInfo(hConsole, &cursorInfo);
        }
#else
        std::cout << "\033[?25l";
        std::cout.flush();
#endif
    }

    void userMoveCursor();
    void MoveCursorDowm();
    void MoveCursorUp();
    void MoveCursorLeft();
    void MoveCursorRight();
};

#endif

