#ifndef _FILE_CONTROLER_HPP_
#define _FILE_CONTROLER_HPP_
#include <iostream>
#include <vector>
#include <string>
#include "Logger.hpp"

class TextBuffer {
private:

	int numRows;
	int numCols;
	std::vector<std::string> lines;

public:

	TextBuffer();

	void initBuffer();

	void addLine(const std::string & line);
	void deleteLine(int index);
	void editLineByIndex(int index, std::string text);
	void clearBuffer();

	int getBufferSize();

	void printBufferContent();
	void setBufferLines(std::vector<std::string> lines);
	std::vector<std::string> getBufferLines();

};

#endif
