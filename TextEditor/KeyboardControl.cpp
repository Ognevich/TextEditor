#include "KeyboardControl.hpp"

KeybControl::KeybControl()
{
	cursorMov = cursorMovement::DEFAULT;
}

cursorMovement KeybControl::checkArrowPressed()
{
    if (GetAsyncKeyState(VK_DOWN) & 0x0001) {
        return cursorMovement::MOVE_CURSOR_DOWN;
    }
    if (GetAsyncKeyState(VK_UP) & 0x0001) {
        return cursorMovement::MOVE_CURSOR_UP;
    }
    if (GetAsyncKeyState(VK_LEFT) & 0x0001) {
        return cursorMovement::MOVE_CURSOR_LEFT;
    }
    if (GetAsyncKeyState(VK_RIGHT) & 0x0001) {
        return cursorMovement::MOVE_CURSOR_RIGHT;
    }
    return cursorMovement::DEFAULT;
}