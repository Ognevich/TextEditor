#include "TextBuffer.hpp"

void TextBuffer::addLine(const std::string& line)
{
	this->lines.push_back(line);
}
