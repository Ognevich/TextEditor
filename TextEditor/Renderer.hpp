#ifndef _RENDERER_HPP_
#define _RENDERER_HPP_
#include "Cursor.hpp"
#include "TextBuffer.hpp"
#include <iostream>

class Renderer {
public:

	Renderer();

	void RenderAllBuffer(TextBuffer & buffer);
	void RenderBufferLine(TextBuffer& buffer, int lineIndex);

	void setCurrentRow(int row);


private:
	int currentRow;
};

#endif