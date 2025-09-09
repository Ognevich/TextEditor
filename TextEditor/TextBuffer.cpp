#include "TextBuffer.hpp"


TextBuffer::TextBuffer()
{
	this->numRows = 30;
	this->numCols = 80;
}

void TextBuffer::initBuffer()
{
	for (int i = 0; i < numRows; i++) {
		buffer.push_back(std::string(numCols, ' '));
	}

	constantBuffer = buffer;
}

void TextBuffer::addLine(const std::string& line)
{
	this->buffer.push_back(line);
}

void TextBuffer::deleteLine(int index)
{
	if (index-1 < 0 || index-1 >= buffer.size()) {
		LOG_ERROR("index out of range");
		return;
	}

	buffer[index - 1] = std::string(numCols, ' ');
}

void TextBuffer::editLineByIndex(int index, std::string newInfo)
{
	if (index < 0 || index >= buffer.size()) {
		LOG_ERROR("index out of range");
		return;
	}

	buffer[index] = newInfo;

}

void TextBuffer::clearBuffer()
{
	buffer.clear();
}

int TextBuffer::getBufferSize()
{
	return buffer.size();
}

void TextBuffer::setBufferLines(std::vector<std::string> buffer)
{
	this->buffer = buffer;
}

void TextBuffer::setConstantBufferLines(std::vector<std::string> buffer)
{
	this->constantBuffer = buffer;
}

std::vector<std::string> TextBuffer::getBufferLines()
{
	return this->buffer;
}

std::vector<std::string> TextBuffer::getConstantBufferLines()
{
	return this->constantBuffer;
}

int TextBuffer::getBufferRows()
{
	return this->numRows;
}

int TextBuffer::getBufferCols()
{
	return this->numCols;
}

bool TextBuffer::isBufferDontEquals()
{
	if (constantBuffer.size() != buffer.size()) {
		return true;
	}

	for (int i = 0; i < buffer.size(); i++) {
		if (buffer[i] != constantBuffer[i]) {
			return true;
		}
	}

	return false;

}
