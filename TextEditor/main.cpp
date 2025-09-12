#include "AppControler.hpp"
#include "MyLogger.hpp"

int main() {

	Logger::getInstance("app.log");

	AppControler app;

	app.startProgram();

	return 0;
}