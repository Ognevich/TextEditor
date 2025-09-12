#ifndef _KEYBOARD_CONTROL_HPP_
#define _KEYBOARD_CONTROL_HPP_
#include <windows.h>
#include <iostream>

enum class cursorMovement {
	MOVE_CURSOR_DOWN,
	MOVE_CURSOR_UP,
	MOVE_CURSOR_LEFT,
	MOVE_CURSOR_RIGHT,
	DEFAULT
};

class KeybControl {
	
	cursorMovement cursorMov;

public:

	KeybControl();

	cursorMovement checkArrowPressed();


};

#endif