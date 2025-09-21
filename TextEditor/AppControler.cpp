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
    inputHandler.disableConsoleEnter();
	//Cursor::hideCursor();
	
}

void AppControler::update() {
    auto changedRows = buffer.getChangedRows();

    for (int idx : changedRows) {
        render.renderRow(idx, buffer, cursor);
    }

    cursor.moveCursor(cursor.getRows(), cursor.getCols());

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

