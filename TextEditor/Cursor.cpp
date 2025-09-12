#include "Cursor.hpp"

Cursor::Cursor()
{
    this->rows = 0;
    this->cols = 10;
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
        MoveCursorDowm();
        break;
    }
    case cursorMovement::MOVE_CURSOR_UP:
    {
        MoveCursorUp();
        break;
    }
    case cursorMovement::MOVE_CURSOR_LEFT:
    {
        MoveCursorLeft();
        break;
    }
    case cursorMovement::MOVE_CURSOR_RIGHT:
    {
        MoveCursorRight();
        break;
    }
    case cursorMovement::DEFAULT:
        break;
    default:
        break;
    }


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

