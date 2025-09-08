#include "AppController.hpp"
#include "Logger.hpp"

int main() {

	Logger::getInstance("app.log");
	AppControler app;

	app.Run();

	return 0;
}