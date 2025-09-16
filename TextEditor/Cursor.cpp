#include "Cursor.hpp"

Cursor::Cursor()
{
    this->rows = 0;
    this->cols = START_CURSOR_POS;
}

int Cursor::getRows()
{
    return this->rows;
}

int Cursor::getCols()
{
    return this->cols;
}

void Cursor::moveCursor(int row, int col)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { (SHORT)col, (SHORT)row };
    SetConsoleCursorPosition(hConsole, pos);
}

void Cursor::setRows(int newRows)
{
    this->rows = newRows;
}

void Cursor::setColsRight(int newCols)
{
    if (dispCollisions.checkRightSideDisplayCollision(newCols))
        this->cols = BUFFER_COLS - 1;
    else
        this->cols = newCols;
}

void Cursor::setColsLeft(int newCols)
{
    if (dispCollisions.checkLeftSideDisplayCollision(newCols))
        this->cols = START_CURSOR_POS;
    else
        this->cols = newCols;
}



void Cursor::MoveCursorDowm()
{
    rows++;
    moveCursor(rows, cols);
    LOG_INFO("Arrow down is pressed");
}

void Cursor::MoveCursorUp()
{
    rows--;
    moveCursor(rows, cols);
    LOG_INFO("Arrow up is pressed");
}

void Cursor::MoveCursorLeft()
{
    cols--;
    moveCursor(rows, cols);
    LOG_INFO("Arrow left is pressed");
}

void Cursor::MoveCursorRight()
{
    cols++;
    moveCursor(rows, cols);
    LOG_INFO("Arrow right is pressed");
}

void Cursor::clearCursorBuffer()
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD events;
    INPUT_RECORD inputRecord;

    while (PeekConsoleInput(hInput, &inputRecord, 1, &events) && events > 0) {
        ReadConsoleInput(hInput, &inputRecord, 1, &events);
    }
}

