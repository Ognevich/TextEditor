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
