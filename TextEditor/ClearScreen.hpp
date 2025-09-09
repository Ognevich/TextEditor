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


    static void showCursor() {
#ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(hConsole, &cursorInfo);
        cursorInfo.bVisible = TRUE;
        SetConsoleCursorInfo(hConsole, &cursorInfo);
#else
        std::cout << "\033[?25h";
        std::cout.flush();
#endif
    }

    static void hideCursor() {
#ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        if (GetConsoleCursorInfo(hConsole, &cursorInfo)) {
            cursorInfo.bVisible = FALSE;
            SetConsoleCursorInfo(hConsole, &cursorInfo);
        }
#else
        std::cout << "\033[?25l";
        std::cout.flush();
#endif
    }
};

#endif