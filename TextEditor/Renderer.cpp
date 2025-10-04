#include "Renderer.hpp"

Renderer::Renderer() {
    renderRow = 0;
    currentRow = 0;
}

void Renderer::RenderBufferLine(const TextBuffer& buffer, int lineIndex) {

    const auto& lines = buffer.getBuffer();
    if (lineIndex < 0 || lineIndex >= static_cast<int>(lines.size())) return;

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
