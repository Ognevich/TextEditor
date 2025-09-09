#include "AppController.hpp"
#include "Logger.hpp"

int main() {

	Logger::getInstance("app.log");
	AppControler app;

	app.startProgram();

	return 0;
}