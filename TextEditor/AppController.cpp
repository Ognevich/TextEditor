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


	std::vector<std::string> lines = fileSystem.LoadFromFile("testBuffer.txt");

	while (1) {

		buffer.addLine("first line");

		cursor.setRows(0);
		cursor.setCols(4);

		render.RenderBufferWithCursor(cursor, buffer);

		ClearScreen::clear(buffer.getBufferSize());
	}

}
