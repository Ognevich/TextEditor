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

void Cursor::setRows(int newRows)
{
    this->rows = newRows;
}

void Cursor::setCols(int newCols)
{
    this->cols = newCols;
}
