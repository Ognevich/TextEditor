#include "Cursor.hpp"

Cursor::Cursor()
{
    this->rows = 0;
    this->cols = 0;
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

void Cursor::setCols(int newCols)
{
    this->cols = newCols;
}

