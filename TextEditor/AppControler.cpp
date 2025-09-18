

#include "AppControler.hpp"

AppControler::AppControler()
    : inputHandler(buffer, cursor)
{
	programState = ProgramStates::DEFAULT;
    currentEditorState = EditorState::DEFAULT;
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
        cursor.moveCursor(cursor.getRows(), cursor.getCols());
    }
    buffer.setConstantBufferLines(buffer.getBufferLines());
}


void AppControler::run() {
    render.RenderAllBuffer(buffer);

    while (programState != ProgramStates::STOP_PROGRAM) {
        update();
        //buffer.editLineByIndex(5, "hello");
        EditCommand cmd = keybControl.checkEditCommand();
        editCommandState(cmd);
        editCurrentEditorState();
    }
}

void AppControler::editCommandState(EditCommand cmd)
{
    switch (cmd) {
    case EditCommand::SWITCH_TO_MOVE:
        currentEditorState = EditorState::MOVE_STATE;
        break;
    case EditCommand::SWITCH_TO_EDIT:
        currentEditorState = EditorState::EDIT_STATE;
        break;
    case EditCommand::NONE:
        break;
    }
}

void AppControler::editCurrentEditorState()
{
    switch (currentEditorState) {
    case EditorState::MOVE_STATE:
        cursor.clearCursorBuffer();
        cursor.userMoveCursor(buffer);
        break;
    case EditorState::EDIT_STATE:
        inputHandler.handleInput(cursor.getRows(), cursor.getCols());
        break;
    case EditorState::DEFAULT:
        break;
    }
}

