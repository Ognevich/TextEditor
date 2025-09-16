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

void Renderer::setCurrentRow(int row)
{
    this->currentRow = row;
}