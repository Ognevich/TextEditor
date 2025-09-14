#include "DisplayCollisions.hpp"

bool DisplayCollisions::checkLeftSideDisplayCollision(int currentColPos)
{

    if (currentColPos - 1 < START_CURSOR_POS) {
        LOG_INFO("Left side Collision is working");
        return true;
    }
    return false;
}

bool DisplayCollisions::checkRightSideDisplayCollision(int currentColPos)
{
    if (currentColPos + 1 > BUFFER_COLS) {
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
