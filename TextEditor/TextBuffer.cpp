#include "TextBuffer.hpp"


TextBuffer::TextBuffer()
{
	this->numRows = BUFFER_ROWS;
	this->numCols = BUFFER_COLS;
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
	for (int i = 0; i < buffer.size(); i++) {
		buffer[i] = line;
	}
	buffer[buffer.size() - 1] = line;
}

void TextBuffer::deleteLine(int index)
{
	if (index-1 < 0 || index-1 >= buffer.size()) {
		return;
	}

	buffer[index - 1] = std::string(numCols, ' ');
}

void TextBuffer::editLineByIndex(int index, const std::string newInfo)
{
	if (index < 1) return; 

	int idx = index - 1; 

	while (buffer.size() <= idx) {
		buffer.push_back(std::string(numCols, ' '));
	}

	buffer[idx] = newInfo;
}

void TextBuffer::clearBuffer()
{
	buffer.clear();
}

int TextBuffer::getBufferSize()
{
	return buffer.size();
}

std::vector<int> TextBuffer::getChangedLines(int startRow, int visibleCount)
{
	std::vector<int> changed;
	int total = buffer.size();

	if (startRow < 1) startRow = 1;

	for (int i = 0; i < visibleCount; i++) {
		int globalIndex = startRow - 1 + i;

		std::string current = (globalIndex < total) ? buffer[globalIndex] : std::string(numCols, ' ');
		std::string prev = (globalIndex < (int)constantBuffer.size()) ? constantBuffer[globalIndex] : std::string(numCols, ' ');

		if (current != prev) {
			changed.push_back(globalIndex + 1);
		}
	}

	return changed;
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
