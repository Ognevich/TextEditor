#include "TextBuffer.hpp"

TextBuffer::TextBuffer(int rows, int cols)
    : numRows(rows), numCols(cols) {
}

void TextBuffer::initBuffer() {
    buffer.clear();
    for (int i = 0; i < numRows; i++) {
        buffer.push_back(std::string());
    }
}

void TextBuffer::addLine(const std::string& line) {
    buffer.push_back(line);
}

void TextBuffer::insertChar(int row, int col, char symbol) {
    if (row < 0 || row >= buffer.size()) return;
    if (col < 0 || col > buffer[row].size()) return;

    buffer[row].insert(buffer[row].begin() + col, symbol);
}

void TextBuffer::deleteChar(int row, int col) {
    if (row < 0 || row >= buffer.size()) return;
    if (col < 0 || col >= buffer[row].size()) return;

    buffer[row].erase(buffer[row].begin() + col);
}

void TextBuffer::deleteLine(int index) {
    if (index < 0 || index >= buffer.size()) return;
    buffer.erase(buffer.begin() + index);
}

std::string TextBuffer::getLine(int index) const {
    if (index < 0 || index >= buffer.size()) return "";
    return buffer[index];
}

std::vector<std::string> TextBuffer::getBufferLines() const {
    return buffer;
}

int TextBuffer::getBufferSize() const {
    return buffer.size();
}

int TextBuffer::getBufferRows() const {
    return numRows;
}

int TextBuffer::getBufferCols() const {
    return numCols;
}
