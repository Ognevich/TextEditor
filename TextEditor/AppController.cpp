#include "AppController.hpp"

AppControler::AppControler()
{
	programState = ProgramStates::DEFAULT;
}

void AppControler::startProgram()
{
	init();
	run();
}


void AppControler::init()
{
	buffer.initBuffer();
}

void AppControler::run() {

	FileSystem fileSystem;


	//std::vector<std::string> lines = fileSystem.LoadFromFile("testBuffer.txt");

	cursor.setRows(0);
	cursor.setCols(4);
	ClearScreen::hideCursor();

	while (1) {

		buffer.editLineByIndex(1,"first line");

		render.RenderBufferWithCursor(cursor, buffer);

		ClearScreen::clear();
	}

}
