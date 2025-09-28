#include "DisplayCollisions.hpp"

DisplayCollisions::DisplayCollisions()
{
}

bool DisplayCollisions::checkLeftSideDisplayCollision(int currentColPos)
{

    if (currentColPos <= START_CURSOR_POS) {
        LOG_INFO("Left side Collision is working");
        return true;
    }
    return false;
}

bool DisplayCollisions::checkRightSideDisplayCollision(int currentColPos)
{
    if (currentColPos >= BUFFER_COLS) {
        LOG_INFO("Right side Collision is working");
        return true;
    }
    return false;
}

bool DisplayCollisions::checkTopDisplayCollision(int currentRowPos)
{
    
    if (currentRowPos - 1 < 0) {
        LOG_INFO("UP Collision is working");
        return true;
    }
    return false;
}

bool DisplayCollisions::checkDownDisplayCollision(int currentRowPos, int bufferSize)
{
    if (currentRowPos + 2 > bufferSize) {
        LOG_INFO("DOWN Collision is working");
        return true;
    }
    return false;
}

bool DisplayCollisions::isSymbolRight(int currentColPos, int currentRowPos, std::vector<std::string> buffer)
{
    if (currentColPos + 1 >= buffer[currentRowPos].size())
        return false;
    return true;
}

DisplayCollisions::VerticalSymbolState DisplayCollisions::isSymbolVertical (int currentColPos, int cursorRowPos, std::vector<std::string> buffer)
{
    int bufferLineSize = buffer[cursorRowPos].size();

    if (bufferLineSize < 1) {
        return VerticalSymbolState::NO_SYMBOL;
    }
    if (bufferLineSize - 1 >= currentColPos) {
        return VerticalSymbolState::HAS_SYMBOL;
    }
    if (bufferLineSize - 1 < currentColPos) {
        return VerticalSymbolState::HAS_SYMBOL_LEFT;
    }
    return VerticalSymbolState::NONE;
}

          



