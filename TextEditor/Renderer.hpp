#ifndef _RENDERER_HPP_
#define _RENDERER_HPP_
#include "Cursor.hpp"
#include "TextBuffer.hpp"
#include <iostream>
#undef max
#undef min
#include <algorithm>

class Renderer {
public:

	Renderer();

	void RenderAllBuffer(TextBuffer & buffer);
	void RenderBufferLine(TextBuffer& buffer, int lineIndex);
	void renderRow(int idx, TextBuffer& buffer, Cursor& cursor);

	void setCurrentRow(int row);


private:
	int currentRow;
};

#endif