#include "TextBuffer.hpp"


TextBuffer::TextBuffer()
{
	this->numRows = 30;
	this->numCols = 80;
}

void TextBuffer::initBuffer()
{
	for (int i = 0; i < numRows; i++) {

		lines.push_back(std::string(numCols, ' '));

	}
}

void TextBuffer::addLine(const std::string& line)
{
	this->lines.push_back(line);
}

void TextBuffer::deleteLine(int index)
{
	if (index-1 < 0 || index-1 >= lines.size()) {
		LOG_ERROR("index out of range");
		return;
	}

	lines[index - 1] = std::string(numCols, ' ');
}

void TextBuffer::editLineByIndex(int index, std::string newInfo)
{
	if (index-1 < 0 || index-1 >= lines.size()) {
		LOG_ERROR("index out of range");
		return;
	}

	lines[index - 1] = newInfo;

}

void TextBuffer::clearBuffer()
{
	lines.clear();
}

int TextBuffer::getBufferSize()
{
	return lines.size();
}


void TextBuffer::printBufferContent()
{
	for (int i = 0; i < lines.size(); i++) {
		std::cout << i+1 << "\t" << lines[i] << std::endl;
	}
}

void TextBuffer::setBufferLines(std::vector<std::string> lines)
{
	this->lines = lines;
}

std::vector<std::string> TextBuffer::getBufferLines()
{
	return this->lines;
}
