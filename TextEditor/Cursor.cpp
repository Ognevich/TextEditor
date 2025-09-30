#include "Cursor.hpp"

Cursor::Cursor()
{
    this->rows = START_CURSOR_POS;
    this->cols = START_CURSOR_POS;
    cursorEmptyState = CursorEmptyState::NONE;
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
    LOG_DEBUG(std::string("Cursor pos: ") + " row " + std::to_string(rows) + " col " + std::to_string(cols));
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



void Cursor::cursorUpDownHanlder(DisplayCollisions::VerticalSymbolState state, int bufferLineSize, int direction)
{
    switch (state)
    {
    case DisplayCollisions::VerticalSymbolState::HAS_SYMBOL:
        cursorEmptyState = CursorEmptyState::NONE;
        setCursorPos(rows + direction, cols);
        break;

    case DisplayCollisions::VerticalSymbolState::HAS_SYMBOL_LEFT:
        cursorEmptyState = CursorEmptyState::NONE;
        setCursorPos(rows + direction, bufferLineSize - 1);
        break;

    case DisplayCollisions::VerticalSymbolState::NO_SYMBOL:
        if (cursorEmptyState == CursorEmptyState::USED) {
            setCursorPos(rows, cols);
        }
        else {
            setCursorPos(rows + direction, 0);
            cursorEmptyState = CursorEmptyState::USED;
        }

        break;

    case DisplayCollisions::VerticalSymbolState::NONE:
    default:
        break;
    }

    LOG_INFO(std::string("Move ") +
        (direction > 0 ? "down " : "up ") +
        std::to_string(getCols()) + " " + std::to_string(getRows()));
}


void Cursor::MoveCursorDown(DisplayCollisions::VerticalSymbolState state, int bufferLineSize)
{
    cursorUpDownHanlder(state, bufferLineSize, +1);
}

void Cursor::MoveCursorUp(DisplayCollisions::VerticalSymbolState state, int bufferLineSize)
{
    cursorUpDownHanlder(state, bufferLineSize, -1);
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

void Cursor::setCursorEmptyState(CursorEmptyState newState)
{
    this->cursorEmptyState = newState;
}

