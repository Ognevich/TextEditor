#include "KeyboardControl.hpp"

KeybControl::KeybControl()
{
	cursorMov = CursorMovementState::DEFAULT;
    editState = EditorState::DEFAULT;
}

CursorMovementState KeybControl::checkArrowPressed()
{
    if (GetAsyncKeyState(VK_DOWN) & 0x0001) {
        return CursorMovementState::MOVE_CURSOR_DOWN;
    }
    if (GetAsyncKeyState(VK_UP) & 0x0001) {
        return CursorMovementState::MOVE_CURSOR_UP;
    }
    if (GetAsyncKeyState(VK_LEFT) & 0x0001) {
        return CursorMovementState::MOVE_CURSOR_LEFT;
    }
    if (GetAsyncKeyState(VK_RIGHT) & 0x0001) {
        return CursorMovementState::MOVE_CURSOR_RIGHT;
    }
    return CursorMovementState::DEFAULT;
}

EditCommand KeybControl::checkEditCommand()
{
    if (isComboPressed(VK_CONTROL, 'E')) {
        LOG_INFO("Switch to EDIT_STATE");
        return EditCommand::SWITCH_TO_EDIT;
    }
    if (isComboPressed(VK_CONTROL, 'N')) {
        LOG_INFO("Switch to MOVE_STATE");
        return EditCommand::SWITCH_TO_MOVE;
    }

    return EditCommand::NONE;
}

bool KeybControl::isComboPressed(int key1, int key2)
{
    return (GetAsyncKeyState(key1) & 0x8000) && (GetAsyncKeyState(key2) & 0x8000);
}

