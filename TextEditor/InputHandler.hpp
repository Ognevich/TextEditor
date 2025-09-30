#ifndef _INPUT_HANDLER_HPP_
#define _INPUT_HANDLER_HPP_
#include <windows.h>
#include "TextBuffer.hpp"
#include "Cursor.hpp"
#include "KeyboardControl.hpp"
#include "DisplayCollisions.hpp"

class InputHandler {

private:
	KeybControl keybControl;
    TextBuffer* buffer;
    Cursor* cursor;
    DisplayCollisions collisions;
public:

    InputHandler(TextBuffer& buf, Cursor& cur);

    KeyCommand mapInputToCommand(INPUT_RECORD& input, char& outChar);
    void handleInput();

    void dispatchCommand(KeyCommand cmd, char typedChar, int row, int col);

    void handleCharInput(int row, int col, char c);
    void handleBackspace(int row, int col);
    void handleEnter(int row, int col);
    void handleSpace(int row, int col);

    void disableConsoleEnter();
};


#endif