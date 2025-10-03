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

    void cursorUpDownHanlder(DisplayCollisions::VerticalSymbolState state, int bufferLineSize, int direction);
    void MoveCursorDown(DisplayCollisions::VerticalSymbolState state, int bufferLineSize);
    void MoveCursorUp(DisplayCollisions::VerticalSymbolState state, int bufferLineSize);
    void MoveCursorLeft();
    void MoveCursorRight();

    template <typename T>
    void moveDown(T& buffer);

    template <typename T>
    void moveUp(T& buffer);

    template <typename T>
    void moveLeft(T& buffer);

    template <typename T>
    void moveRight(T& buffer);

    void clearCursorBuffer();

    // for situations when cursor move to empty symbols
    enum class CursorEmptyState {
        NONE,
        ALLOW_ONCE,
        USED
    };
    void setCursorEmptyState(CursorEmptyState newState);


private:
    int rows;
    int cols;
    KeybControl keybControl;
    DisplayCollisions dispCollisions;

    CursorEmptyState cursorEmptyState;
};

template<typename T>
inline void Cursor::userMoveCursor(T& buffer)
{
    CursorMovementState cursorMov = keybControl.checkArrowPressed();

    switch (cursorMov)
    {
    case CursorMovementState::MOVE_CURSOR_DOWN:
        moveDown(buffer);
        break;
    case CursorMovementState::MOVE_CURSOR_UP:
        moveUp(buffer);
        break;
    case CursorMovementState::MOVE_CURSOR_LEFT:
        moveLeft(buffer);
        break;
    case CursorMovementState::MOVE_CURSOR_RIGHT:
        moveRight(buffer);
        break;
    case CursorMovementState::DEFAULT:
        break;
    }
}

template<typename T>
inline void Cursor::moveDown(T& buffer)
{
    if (!dispCollisions.checkDownDisplayCollision(rows, buffer.getBufferSize())) {
        DisplayCollisions::VerticalSymbolState state =
            dispCollisions.isSymbolVertical(cols, rows + 1, buffer.getBuffer());

        int lineSize = buffer.getLine(rows + 1).size();

        MoveCursorDown(state, lineSize);
    }
}

template<typename T>
inline void Cursor::moveUp(T& buffer)
{
    if (!dispCollisions.checkTopDisplayCollision(rows)) {
        DisplayCollisions::VerticalSymbolState verticalState = dispCollisions.isSymbolVertical(cols, rows - 1, buffer.getBuffer());
        int lineSize = buffer.getLine(rows - 1).size();
        MoveCursorUp(verticalState, lineSize);
    }
}

template<typename T>
inline void Cursor::moveLeft(T& buffer)
{
    if (!dispCollisions.checkLeftSideDisplayCollision(cols))
        MoveCursorLeft();
}

template<typename T>
inline void Cursor::moveRight(T& buffer)
{
    if (!dispCollisions.checkRightSideDisplayCollision(cols))
        if (dispCollisions.isSymbolRight(cols, rows, buffer.getBuffer()))
            MoveCursorRight();
}

#endif

