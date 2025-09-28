#ifndef _FILE_CONTROLER_HPP_
#define _FILE_CONTROLER_HPP_
#include <iostream>
#include <vector>
#include <string>
#include "Config.hpp"

class TextBuffer {
private:

	int numRows;
	int numCols;

	std::vector<std::string> constantBuffer;
	std::vector<std::string> buffer;

public:

	TextBuffer();

	void initBuffer();

	void addLine(const std::string & line);
	void insertChar(int row, char symbol);
	void insertNewLine(int row, int col);
	bool deleteChar(int row, int col);
	void deleteLine(int index);
	void editLineByIndex(int index, std::string text);
	void clearBuffer();

	int getBufferSize();
	std::vector<int> getChangedLines(int startRow, int visibleCount);

	void setBufferLines(std::vector<std::string> buffer);
	void setConstantBufferLines(std::vector<std::string> buffer);

	std::vector<std::string> getBufferLines();
	std::vector<std::string> getConstantBufferLines();

	int getBufferRows();
	int getBufferCols();
	std::vector<int> getChangedRows();

	bool isBufferDontEquals();
};

#endif
