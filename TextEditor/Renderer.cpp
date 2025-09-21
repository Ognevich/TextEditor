#include "Renderer.hpp"


Renderer::Renderer()
{
    this->currentRow = 0;
}

void Renderer::RenderAllBuffer(TextBuffer& buffer)
{
    std::vector<std::string> lines = buffer.getBufferLines();

    for (int i = currentRow; i < buffer.getBufferRows() + currentRow; i++) {
        std::string line = lines[i];
        std::cout << line << std::endl;
    }
}

void Renderer::RenderBufferLine(TextBuffer& buffer, int lineIndex)
{
    std::vector<std::string> lines = buffer.getBufferLines();
    std::string line = lines[lineIndex - 1];

    std::cout << line << std::endl;
}

void Renderer::renderRow(int idx, TextBuffer& buffer, Cursor& cursor)
{
    int totalRows = buffer.getBufferSize();
    int visibleRows = buffer.getBufferRows();
    int startRow = std::max(0, totalRows - visibleRows);

    int screenRow = idx - startRow - 1;

    cursor.moveCursor(screenRow, 0);
    RenderBufferLine(buffer, idx);
}

void Renderer::setCurrentRow(int row)
{
    this->currentRow = row;
}