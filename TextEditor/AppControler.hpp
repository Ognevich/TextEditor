#ifndef _APP_CONTROLER_HPP_
#define _APP_CONTROLER_HPP_
#include "ProgramStates.hpp"
#include "TextBuffer.hpp"
#include "FileSystem.hpp"
#include <Windows.h>
#include "ClearScreen.hpp"
#include "Renderer.hpp"
#include "Cursor.hpp"
#include "InputHandler.hpp"
#include "KeyboardControl.hpp"

class AppControler {
private:
	ProgramStates programState;
	FileSystemStates fileSystemState;

	FileSystem fileSystem;
	TextBuffer buffer;
	Cursor cursor;
	Renderer render;

	KeybControl keybControl;
	InputHandler inputHandler;
	EditorState currentEditorState;

	ClearScreen cls;

	void init(int argc, char* argv[]);
	void update();
	void shutdown();
public:

	AppControler();

	void startProgram(int argc, char *argv[]);
	void run();

	void editCommandState(EditCommand cmd);
	void editCurrentEditorState();

};

#endif
