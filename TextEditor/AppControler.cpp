
#include "AppControler.hpp"

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
	//Cursor::hideCursor();
	
}

void AppControler::update() {
    int totalRows = buffer.getBufferSize();
    int visibleRows = buffer.getBufferRows();

    int startRow = (totalRows - visibleRows + 1 > 0) ? (totalRows - visibleRows + 1) : 1;

    int count = (visibleRows < totalRows - startRow + 1) ? visibleRows : (totalRows - startRow + 1);

    auto changedRows = buffer.getChangedLines(startRow, count);

    for (int idx : changedRows) {
        int screenRow = idx - startRow;
        cursor.moveCursor(screenRow, 0);
        render.RenderBufferLine(buffer, idx);
    }
    buffer.setConstantBufferLines(buffer.getBufferLines());
}


void AppControler::run() {
    buffer.editLineByIndex(31, "first line");
    buffer.editLineByIndex(35, "someInfo");
    render.RenderAllBuffer(buffer);

    while (programState != ProgramStates::STOP_PROGRAM) {
        update();
        cursor.userMoveCursor();
    }
}
