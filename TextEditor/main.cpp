#include "AppControler.hpp"
#include "MyLogger.hpp"
#include "FileSystem.hpp"

int main(int argc, char* argv[]) {

	


	Logger::getInstance("app.log");

	FileSystem fileSystem;
	AppControler app;

	app.startProgram(argc);

	return 0;
}