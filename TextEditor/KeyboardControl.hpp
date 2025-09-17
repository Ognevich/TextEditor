#ifndef _KEYBOARD_CONTROL_HPP_
#define _KEYBOARD_CONTROL_HPP_
#include <windows.h>
#include <iostream>
#include "MyLogger.hpp"

enum class CursorMovementState {
	MOVE_CURSOR_DOWN,
	MOVE_CURSOR_UP,
	MOVE_CURSOR_LEFT,
	MOVE_CURSOR_RIGHT,
	DEFAULT
};

enum class EditorState {
	MOVE_STATE,
	EDIT_STATE,
	DEFAULT
};

enum class EditCommand {
	NONE,
	SWITCH_TO_MOVE,
	SWITCH_TO_EDIT
};

enum class KeyCommand {
	NONE,
	CHAR_INPUT,
	BACKSPACE,
	ENTER
};


class KeybControl {
	
	CursorMovementState cursorMov;
	EditorState editState;

public:

	KeybControl();

	CursorMovementState checkArrowPressed();
	EditCommand checkEditCommand();

	bool isComboPressed(int key1, int key2);


};

#endif