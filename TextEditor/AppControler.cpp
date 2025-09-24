#include "AppControler.hpp"

AppControler::AppControler()
    : inputHandler(buffer, cursor)
{
	programState = ProgramStates::DEFAULT_;
    fileSystemState = FileSystemStates::DEFAULT;
    currentEditorState = EditorState::DEFAULT_;

}

void AppControler::startProgram(int argc, char* argv[])
{
	init(argc, argv);
	run();
}


void AppControler::init(int argc,char* argv[])
{
    fileSystem.initFileSystem(argv[1]);

    if (!fileSystem.startFileInitialization(argc)) {
        fileSystemState = FileSystemStates::FILE_SYSTEM_FAILED;
        LOG_ERROR("File system failed");
        return;
    }
    else {
        fileSystemState = FileSystemStates::FILE_SYSTEM_WORKING;
        LOG_INFO("File system started");
        system("cls");
        buffer.initBuffer();
        inputHandler.disableConsoleEnter();
        //Cursor::hideCursor();
    }
	
}

void AppControler::update() {
    auto changedRows = buffer.getChangedRows();

    for (int idx : changedRows) {
        render.renderRow(idx, buffer, cursor);
    }

    cursor.moveCursor(cursor.getRows(), cursor.getCols());

    buffer.setConstantBufferLines(buffer.getBufferLines());
}

void AppControler::shutdown()
{
    if (fileSystemState != FileSystemStates::FILE_SYSTEM_FAILED) {
        fileSystem.saveToFile(fileSystem.getFilePath(), buffer.getBufferLines());
    }
}


void AppControler::run() {
    if (fileSystemState != FileSystemStates::FILE_SYSTEM_FAILED) {
        render.RenderAllBuffer(buffer);
        while (programState != ProgramStates::STOP_PROGRAM) {
            update();
            EditCommand cmd = keybControl.checkEditCommand();
            editCommandState(cmd);
            editCurrentEditorState();
        }
    }
    return;
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
    case EditCommand::SWITCH_TO_STOP:
        currentEditorState = EditorState::STOP_EDITOR_STATE;
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
    case EditorState::STOP_EDITOR_STATE:
        programState = ProgramStates::STOP_PROGRAM;
        break;
    case EditorState::DEFAULT_:
        break;
    }
}

