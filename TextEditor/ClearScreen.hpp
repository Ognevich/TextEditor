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
        COORD cursorPosition = { 0, 0 };
        SetConsoleCursorPosition(hConsole, cursorPosition);
#else
        std::cout << "\033[H";
        std::cout.flush();
#endif
    }
};

#endif