#ifndef _DISPLAY_COLLISIONS_HPP_
#define _DISPLAY_COLLISIONS_HPP_
#include "Config.hpp"
#include "MyLogger.hpp"
#include <vector>
#include <string>

class DisplayCollisions {

public:

	bool checkLeftSideDisplayCollision(int currentColPos);
	bool checkRightSideDisplayCollision(int currentColPos);
	bool checkTopDisplayCollision(int currentRowPos);

	bool checkDownDisplayCollision(int currentRowPos, int bufferSize);

	bool isSymbolRight(int currentColPos,int currentRowPos, std::vector<std::string> buffer);
};

#endif
