#include "AppControler.hpp"

AppControler::AppControler()
{
	programState = ProgramStates::DEFAULT;
	LOG_INFO("App Controler Started");
}

void AppControler::Run() {

	while (programState != ProgramStates::STOP_PROGRAM) {
		
	}

}
