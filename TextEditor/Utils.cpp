#include "Utils.hpp"

std::string Utils::createSpaceLine(int appendSymbols)
{
	std::string spaceLine;

	for (int i = 0; i < appendSymbols; i++) {
		spaceLine += ' ';
	}
	return spaceLine;
}
