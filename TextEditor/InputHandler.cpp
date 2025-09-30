#include "InputHandler.hpp"

InputHandler::InputHandler(TextBuffer& buf, Cursor& cur)
{
    buffer = &buf;
    cursor = &cur;
}

KeyCommand InputHandler::mapInputToCommand(INPUT_RECORD& input, char& outChar)
{
    if (input.EventType == KEY_EVENT && input.Event.KeyEvent.bKeyDown) {
        char c = input.Event.KeyEvent.uChar.AsciiChar;
        WORD vk = input.Event.KeyEvent.wVirtualKeyCode;

        if (c == ' ')
            return KeyCommand::SPACE_KEY;

        if (c >= 33 && c <= 126) {
            outChar = c;
            cursor->setCursorEmptyState(Cursor::CursorEmptyState::NONE);
            return KeyCommand::CHAR_INPUT;
        }

        switch (vk) {
        case VK_BACK:   return KeyCommand::BACKSPACE;
        case VK_RETURN: return KeyCommand::ENTER;
        default:        return KeyCommand::NONE;
        }
    }
    return KeyCommand::NONE;
}

void InputHandler::handleInput()
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD events;
    INPUT_RECORD inputRecord;

    if (PeekConsoleInput(hInput, &inputRecord, 1, &events) && events > 0) {
        ReadConsoleInput(hInput, &inputRecord, 1, &events);

        char typedChar = '\0';
        KeyCommand cmd = mapInputToCommand(inputRecord, typedChar);

        int row = cursor->getRows();
        int col = cursor->getCols();

        dispatchCommand(cmd, typedChar,row, col);
    }
}

void InputHandler::dispatchCommand(KeyCommand cmd, char typedChar,int row, int col)
{
    switch (cmd)
    {
    case KeyCommand::CHAR_INPUT:
        handleCharInput(row, col, typedChar);
        break;
    case KeyCommand::BACKSPACE:
        handleBackspace(row, col);
        break;
    case KeyCommand::ENTER:
        handleEnter(row, col);
        break;
    case KeyCommand::SPACE_KEY:
        handleSpace(row, col);
        break;
    default:
        break;
    }
}

void InputHandler::handleCharInput(int row, int col, char c)
{
    buffer->insertChar(row, col + 1,c);

    cursor->setColsRight(col + 1);
}

void InputHandler::handleBackspace(int row, int col)
{
    int previousColPos = col - 1;
    if (!collisions.checkLeftSideDisplayCollision(col)) {
        buffer->deleteChar(row, previousColPos);
        cursor->setCursorPos(row, previousColPos);
    }

}

void InputHandler::handleEnter(int row, int col)
{
    buffer->insertNewLine(row, col);
    cursor->setCursorPos(row + 1,0);
}


void InputHandler::handleSpace(int row, int col)
{
    buffer->insertChar(row, col + 1, ' ');
    cursor->setColsRight(col + 1);
    cursor->moveCursor(row, col + 1);
}

void InputHandler::disableConsoleEnter()
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    if (hInput == INVALID_HANDLE_VALUE) return;

    DWORD prevMode;
    if (!GetConsoleMode(hInput, &prevMode)) return;

    DWORD newMode = prevMode;

    newMode &= ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);

    SetConsoleMode(hInput, newMode);
}
