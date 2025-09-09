#ifndef _CURSOR_HPP_
#define _CURSOR_HPP_
#ifdef _WIN32
#include <windows.h>
#endif

class Cursor {

private:
	int rows;
	int cols;

public:
	
	Cursor();

	int getRows();
	int getCols();

	void setRows(int newRows);
	void setCols(int newCols);

    static void showCursor()
    {

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

    static void hideCursor()
    {
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

