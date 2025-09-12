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

void Cursor::userMoveCursor()
{
    cursorMovement cursorMov;

    cursorMov = keybControl.checkArrowPressed();

    switch (cursorMov)
    {
    case cursorMovement::MOVE_CURSOR_DOWN:
    {   
        rows++;
        moveCursor(rows, cols);
        LOG_INFO("Arrow down is pressed");
        break;
    }
    case cursorMovement::MOVE_CURSOR_UP:
    {
        rows--;
        moveCursor(rows, cols);
        LOG_INFO("Arrow up is pressed");
        break;
    }
    case cursorMovement::MOVE_CURSOR_LEFT:
    {
        cols--;
        moveCursor(rows, cols);
        LOG_INFO("Arrow left is pressed");
        break;
    }
    case cursorMovement::MOVE_CURSOR_RIGHT:
    {
        cols++;
        moveCursor(rows, cols);
        LOG_INFO("Arrow right is pressed");
        break;
    }
    case cursorMovement::DEFAULT:
        break;
    default:
        break;
    }


}

