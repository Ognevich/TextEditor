#ifndef _APP_CONTROLER_HPP_
#define _APP_CONTROLER_HPP_
#include "ProgramStates.hpp"
#include "TextBuffer.hpp"
#include "FileSystem.hpp"
#include "Logger.hpp"
#include "Windows.h"
#include "ClearScreen.hpp"

class AppControler {
private:
	ProgramStates programState;

public:

	AppControler();

	void Run();


};

#endif
