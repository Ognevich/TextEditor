

#include "AppControler.hpp"

AppControler::AppControler()
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
        handleInput(cursor.getRows(), cursor.getCols());
        break;
    case EditorState::DEFAULT:
        break;
    }
}

KeyCommand AppControler::mapInputToCommand(INPUT_RECORD& input, char& outChar)
{
    if (input.EventType == KEY_EVENT && input.Event.KeyEvent.bKeyDown) {
        char c = input.Event.KeyEvent.uChar.AsciiChar;
        WORD vk = input.Event.KeyEvent.wVirtualKeyCode;

        if (c >= 32 && c <= 126) {
            outChar = c;
            return KeyCommand::CHAR_INPUT;
        }

        switch (vk) {
        case VK_BACK: return KeyCommand::BACKSPACE;
        case VK_RETURN: return KeyCommand::ENTER;
        default: return KeyCommand::NONE;

        }
    }
    return KeyCommand::NONE;
}

void AppControler::handleInput(int row, int col)
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD events;
    INPUT_RECORD inputRecord;

    if (PeekConsoleInput(hInput, &inputRecord, 1, &events) && events > 0) {
        ReadConsoleInput(hInput, &inputRecord, 1, &events);

        char typedChar = '\0';
        KeyCommand cmd = mapInputToCommand(inputRecord, typedChar);

        switch (cmd)
        {
        case KeyCommand::CHAR_INPUT:
            buffer.insertChar(row, col, typedChar);
            cursor.setColsRight(col + 1);
            break;
        case KeyCommand::BACKSPACE:
            buffer.deleteChar(row, col);
            cursor.setColsLeft(col - 1);
            break;
        case KeyCommand::ENTER:
            buffer.insertNewLine(row, col);
            cursor.setRows(row );
            break;
        case KeyCommand::NONE:
            break;
        default:
            break;
        }
    }
}
