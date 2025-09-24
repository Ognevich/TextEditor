#include "AppControler.hpp"
#include "MyLogger.hpp"

int main(int argc, char* argv[]) {

	


	Logger::getInstance("app.log");
	AppControler app;

	char* testArgv[] = { (char*)"TextEditor.exe", (char*)"file.txt" };
	int testArgc = 2;

	app.startProgram(testArgc, testArgv);

	return 0;
}