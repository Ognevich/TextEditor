#ifndef _APP_CONTROLER_HPP_
#define _APP_CONTROLER_HPP_
#include "ProgramStates.hpp"
#include "TextBuffer.hpp"
#include "FileSystem.hpp"
#include <Windows.h>
#include "ClearScreen.hpp"
#include "Renderer.hpp"
#include "Cursor.hpp"
#include "KeyboardControl.hpp"

class AppControler {
private:
	ProgramStates programState;
	TextBuffer buffer;
	Cursor cursor;
	Renderer render;

	KeybControl keybControl;
	EditorState currentEditorState;

	void init();
	void update();

public:

	AppControler();

	void startProgram();
	void run();

	void editCommandState(EditCommand cmd);
	void editCurrentEditorState();
	
	KeyCommand mapInputToCommand(INPUT_RECORD& input, char& outChar);
	void handleInput(int row, int col);
};

#endif
