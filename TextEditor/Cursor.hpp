#ifndef _CURSOR_HPP_
#define _CURSOR_HPP_
#ifdef _WIN32
#include <windows.h>
#endif

#include <string>
#include <iostream>
#include "KeyboardControl.hpp"
#include "MyLogger.hpp"
#include "Config.hpp"
#include "DisplayCollisions.hpp"

class Cursor {

private:
	int rows;
	int cols;
    KeybControl keybControl;
    DisplayCollisions dispCollisions;

public:
	
	Cursor();

	int getRows();
	int getCols();
    void moveCursor(int row, int col);

    void setCursorPos(int rows, int colc);
	void setRows(int newRows);
	void setColsRight(int newCols);
    void setColsLeft(int newCols);

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

    template <typename T>
    void userMoveCursor(T& buffer);

    void MoveCursorDown();
    void MoveCursorUp();
    void MoveCursorLeft();
    void MoveCursorRight();

    void clearCursorBuffer();
};

template<typename T>
inline void Cursor::userMoveCursor(T& buffer)
{
    CursorMovementState cursorMov = keybControl.checkArrowPressed();

    switch (cursorMov)
    {
    case CursorMovementState::MOVE_CURSOR_DOWN:
        if (!dispCollisions.checkDownDisplayCollision(rows, buffer.getBufferSize()))
            MoveCursorDown();
        break;

    case CursorMovementState::MOVE_CURSOR_UP:
        if (!dispCollisions.checkTopDisplayCollision(rows))
            MoveCursorUp();
        break;

    case CursorMovementState::MOVE_CURSOR_LEFT:
        if (!dispCollisions.checkLeftSideDisplayCollision(cols))
            MoveCursorLeft();
        break;

    case CursorMovementState::MOVE_CURSOR_RIGHT:
        if (!dispCollisions.checkRightSideDisplayCollision(cols))
            if (dispCollisions.isSymbolRight(cols, rows, buffer.getBufferLines()))
                MoveCursorRight();
        break;

    case CursorMovementState::DEFAULT:
        break;
    }
}

#endif

