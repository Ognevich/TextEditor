#include "Cursor.hpp"

Cursor::Cursor()
{
    this->rows = START_CURSOR_POS;
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

void Cursor::setCursorPos(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    moveCursor(rows, cols);

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



void Cursor::MoveCursorDown()
{
    setCursorPos(rows + 1, cols);
    LOG_INFO("Move down" + std::to_string(getCols()) + " " + std::to_string(getRows()));
}

void Cursor::MoveCursorUp(DisplayCollisions::VerticalSymbolState state, int bufferLineSize)
{
    switch (state)
    {
    case DisplayCollisions::VerticalSymbolState::HAS_SYMBOL:
        setCursorPos(rows - 1, cols);
        LOG_INFO("Move up" + std::to_string(getCols()) + " " + std::to_string(getRows()));
        break;
    case DisplayCollisions::VerticalSymbolState::HAS_SYMBOL_LEFT:
        setCursorPos(rows - 1, bufferLineSize - 1);
        LOG_INFO("Move up" + std::to_string(getCols()) + " " + std::to_string(getRows()));
        break;
    case DisplayCollisions::VerticalSymbolState::NO_SYMBOL:
        setCursorPos(rows - 1, 0);
        LOG_INFO("Move up" + std::to_string(getCols()) + " " + std::to_string(getRows()));
        break;
    case DisplayCollisions::VerticalSymbolState::NONE:
        break;
    default:
        break;
    }
}

void Cursor::MoveCursorLeft()
{
    setCursorPos(rows, cols - 1);
    LOG_INFO("Move left" + std::to_string(getCols()) + " " + std::to_string(getRows()));
}

void Cursor::MoveCursorRight()
{
    setCursorPos(rows, cols + 1);
    LOG_INFO("Move right" + std::to_string(getCols()) + " " + std::to_string(getRows()));
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

