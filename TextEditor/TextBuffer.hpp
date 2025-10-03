#ifndef TEXTBUFFER_HPP
#define TEXTBUFFER_HPP

#include <vector>
#include <string>

class TextBuffer {
private:
    std::vector<std::string> buffer;
    int numRows;  
    int numCols;  

public:
    TextBuffer(int rows, int cols);

    void initBuffer();

    void insertChar(int row, int col, char symbol);
    void deleteChar(int row, int col);
    void deleteLine(int index);

    std::string getLine(int index) const;
    std::vector<std::string> getBuffer() const;
    int getBufferSize() const;

    int getBufferRows() const; 
    int getBufferCols() const; 
};

#endif