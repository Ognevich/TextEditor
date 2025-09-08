#include "TextBuffer.hpp"


void TextBuffer::addLine(const std::string& line)
{
	this->lines.push_back(line);
}

void TextBuffer::deleteLine(int index)
{
	if (index < 0 || index >= lines.size()) {
		LOG_ERROR("index out of range");
		return;
	}

	lines.erase(lines.begin() + index);
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
