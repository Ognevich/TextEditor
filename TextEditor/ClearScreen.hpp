#ifndef _CLEAR_SCREEN_HPP_
#define _CLEAR_SCREEN_HPP_

#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

class ClearScreen {
public:
    static void clear() {
#ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(hConsole, &cursorInfo);
        cursorInfo.bVisible = FALSE;
        SetConsoleCursorInfo(hConsole, &cursorInfo);

        COORD cursorPosition;
        cursorPosition.X = 0;
        cursorPosition.Y = 0;
        SetConsoleCursorPosition(hConsole, cursorPosition);
#else
        std::cout << "\033[2J" << std::flush;
#endif
    }
};

#endif
