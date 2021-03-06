#include <stdio.h>
#include <conio.h>
#include <windows.h>

inline void GotoXy(int x, int y)
{
    COORD p = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}//GotoXy()

void hidecursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void main()
{
    hidecursor();

    int x = 40;
    int y = 10;
    int ch = 0;

    GotoXy(x, y);
    printf("*");

    while (ch != 27)
    {
        ch = _getch();
        GotoXy(x, y);
        printf(" ");
        if (ch == 'a')
            x = x - 1;
        else if (ch == 's')
            y = y + 1;
        else if (ch == 'd')
            x = x + 1;
        else if (ch == 'w')
            y = y - 1;
        GotoXy(x, y);
        printf("*");
    }
}