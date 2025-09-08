#ifndef _CLEAR_SCREEN_HPP_
#define _CLEAR_SCREEN_HPP_

#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

class ClearScreen {
public:
    static void clear(int size) {
#ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hConsole == INVALID_HANDLE_VALUE) return;

        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(hConsole, &cursorInfo);
        cursorInfo.bVisible = FALSE;
        SetConsoleCursorInfo(hConsole, &cursorInfo);

        CONSOLE_SCREEN_BUFFER_INFO csbi;
        if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;
        COORD cursorPos = csbi.dwCursorPosition;

        DWORD count;
        for (int i = 0; i < size; ++i) {
            COORD linePos = { 0, short(cursorPos.Y + i) }; 
            FillConsoleOutputCharacter(hConsole, ' ', csbi.dwSize.X, linePos, &count);
            FillConsoleOutputAttribute(hConsole, csbi.wAttributes, csbi.dwSize.X, linePos, &count);
        }
        SetConsoleCursorPosition(hConsole, cursorPos);

#else
        for (int i = 0; i < size; ++i) {
            std::cout << "\033[1A"   
                << "\033[2K";  
        }
        std::cout.flush();
#endif
    }
};

#endif