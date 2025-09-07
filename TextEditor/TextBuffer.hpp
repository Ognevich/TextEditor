#ifndef _FILE_CONTROLER_HPP_
#define _FILE_CONTROLER_HPP_
#include <vector>
#include <string>

class TextBuffer {
private:

	std::vector<std::string> lines;

public:

	void addLine(const std::string & line);


};

#endif
