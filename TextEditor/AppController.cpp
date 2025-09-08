#include "AppController.hpp"

AppControler::AppControler()
{
	programState = ProgramStates::DEFAULT;
}

void AppControler::Run() {

	FileSystem fileSystem;
	TextBuffer buffer;


	std::vector<std::string> lines = fileSystem.LoadFromFile("testBuffer.txt");

	while (1) {

		ClearScreen::clear();

		buffer.clearBuffer();

		buffer.setBufferLines(lines);

		buffer.printBufferContent();

		buffer.deleteLine(3);
		buffer.deleteLine(2);
		buffer.deleteLine(4);


	}

}
