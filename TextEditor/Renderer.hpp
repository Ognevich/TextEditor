#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "TextBuffer.hpp"
#include <iostream>

class Renderer {
private:
    int currentRow; 
    int renderRow;

public:
    Renderer();

    void RenderBufferLine(const TextBuffer& buffer, int lineIndex);

    void setCurrentRow(int row);

    void setRenderRow(int renderRow);
    int getRenderRow();

};

#endif
