#include "Renderer.hpp"

Renderer::Renderer() : currentRow(0) {}

void Renderer::RenderAllBuffer(TextBuffer& buffer) {
    std::vector<std::string> lines = buffer.getBufferLines();
    int totalRows = buffer.getBufferSize();
    int visibleRows = buffer.getBufferRows();

    int start = std::min(currentRow, std::max(0, totalRows - visibleRows));
    int end = std::min(totalRows, start + visibleRows);

    for (int i = start; i < end; i++) {
        std::cout << lines[i] << std::endl;
    }
}

void Renderer::RenderBufferLine(TextBuffer& buffer, int lineIndex) {
    std::vector<std::string> lines = buffer.getBufferLines();
    if (lineIndex < 0 || lineIndex >= lines.size()) return;

    std::cout << lines[lineIndex] << std::endl;
}

void Renderer::setCurrentRow(int row) {
    this->currentRow = row;
}

void Renderer::setRenderRow(int renderRow)
{
    this->renderRow = renderRow;
}

int Renderer::getRenderRow()
{
    return renderRow;
}
