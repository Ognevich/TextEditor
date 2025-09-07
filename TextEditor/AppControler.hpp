#ifndef _APP_CONTROLER_HPP_
#define _APP_CONTROLER_HPP_
#include "ProgramStates.hpp"
#include "Logger.hpp"

class AppControler {
private:
	ProgramStates programState;

public:

	AppControler();

	void Run();


};


#endif
