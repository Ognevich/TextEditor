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

	buffer.editLineByIndex(1, "first line");
	buffer.editLineByIndex(5, "adfadfadfadfirst line");
	buffer.addLine("daf");

	render.setCurrentRow(1);

	render.RenderAllBuffer(buffer);
	while (1) {

		buffer.addLine("daf");

		if (buffer.isBufferDontEquals()) {
			buffer.setConstantBufferLines(buffer.getBufferLines());
			render.RenderAllBuffer(buffer);
		}

		ClearScreen::clear();
	}

}
