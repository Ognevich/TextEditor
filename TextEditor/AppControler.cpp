#include "AppControler.hpp"

AppControler::AppControler()
    : inputHandler(buffer, cursor, render), buffer(BUFFER_ROWS, BUFFER_COLS)
{
	programState = ProgramStates::DEFAULT_;
    fileSystemState = FileSystemStates::DEFAULT;
    currentEditorState = EditorState::DEFAULT_;
}

void AppControler::startProgram(int argc, char* argv[])
{
	init(argc, argv);
	run();
    shutdown();
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
    }
}

void AppControler::update() {
    render.RenderBufferLine(buffer, render.getRenderRow());
    cursor.moveCursor(cursor.getRows(), cursor.getCols());
}

void AppControler::shutdown()
{
    if (fileSystemState != FileSystemStates::FILE_SYSTEM_FAILED) {
        if (currentEditorState == EditorState::STOP_EDITOR_STATE_WITH_SAVING)
            fileSystem.saveToFile(fileSystem.getFilePath(),buffer.getBufferLines());
        else
            return;
    }
}

void AppControler::run() {
    if (fileSystemState != FileSystemStates::FILE_SYSTEM_FAILED) {
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
    case EditCommand::SWITCH_TO_STOP_WITH_SAVING:
        currentEditorState = EditorState::STOP_EDITOR_STATE_WITH_SAVING;
        break;
    case EditCommand::SWITCH_TO_STOP_WITHOUT_SAVING:
        currentEditorState = EditorState::STOP_EDITOR_STATE_WITHOUT_SAVING;
        break;
    case EditCommand::NONE:
        break;
    }
}

void AppControler::editCurrentEditorState()
{
    switch (currentEditorState) {
    case EditorState::MOVE_STATE:
        //cursor.clearCursorBuffer();
        cursor.userMoveCursor(buffer);
        break;
    case EditorState::EDIT_STATE:
        inputHandler.handleInput();
        break;
    case EditorState::STOP_EDITOR_STATE_WITH_SAVING:
        programState = ProgramStates::STOP_PROGRAM;
        break;
    case EditorState::STOP_EDITOR_STATE_WITHOUT_SAVING:
        programState = ProgramStates::STOP_PROGRAM;
        break;
    case EditorState::DEFAULT_:
        break;
    }
}

