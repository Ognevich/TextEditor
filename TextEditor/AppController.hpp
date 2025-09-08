#ifndef _APP_CONTROLER_HPP_
#define _APP_CONTROLER_HPP_
#include "ProgramStates.hpp"
#include "TextBuffer.hpp"
#include "FileSystem.hpp"
#include "Logger.hpp"
#include "Windows.h"
#include "ClearScreen.hpp"
#include "Renderer.hpp"
#include "Cursor.hpp"

class AppControler {
private:
	ProgramStates programState;
	TextBuffer buffer;
	Cursor cursor;
	Renderer render;
public:

	AppControler();


	void init();
	void startProgram();
	void run();


};

#endif
