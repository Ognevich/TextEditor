#ifndef _DISPLAY_COLLISIONS_HPP_
#define _DISPLAY_COLLISIONS_HPP_
#include "Config.hpp"
#include "MyLogger.hpp"
#include <vector>
#include <string>

class DisplayCollisions {

public:

	enum class VerticalSymbolState {
		HAS_SYMBOL,
		HAS_SYMBOL_LEFT,
		NO_SYMBOL,
		NONE
	};

	DisplayCollisions();

	bool checkLeftSideDisplayCollision(int currentColPos);
	bool checkRightSideDisplayCollision(int currentColPos);
	bool checkTopDisplayCollision(int currentRowPos);

	bool checkDownDisplayCollision(int currentRowPos, int bufferSize);

	bool isSymbolRight(int currentColPos,int currentRowPos, std::vector<std::string> buffer);
	VerticalSymbolState isSymbolVertical(int currentColPos, int cursorRowPos, std::vector<std::string> buffer);

};

#endif
