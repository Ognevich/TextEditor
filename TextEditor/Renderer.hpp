#ifndef _RENDERER_HPP_
#define _RENDERER_HPP_
#include "Cursor.hpp"
#include "TextBuffer.hpp"

class Renderer {
public:

	void RenderBufferWithCursor(Cursor & cursor, TextBuffer & buffer);


};

#endif