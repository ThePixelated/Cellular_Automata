#include <iostream>
#include <windows.h>

void ClearBuffers(CHAR_INFO backBuffer[], CHAR_INFO frontBuffer[], short int BufferWidth, short int BufferHeight) {
    for (int i = 0; i < BufferWidth * BufferHeight; ++i) {
        backBuffer[i].Char.AsciiChar = ' ';
        backBuffer[i].Attributes = 0;
        frontBuffer[i].Char.AsciiChar = ' ';
        frontBuffer[i].Attributes = 0;
    }
}

void SwapBuffers(CHAR_INFO backBuffer[], CHAR_INFO frontBuffer[], HANDLE consoleHandle, short int BufferWidth = 119, short int BufferHeight = 30) {
    COORD bufferSize = {BufferWidth, BufferHeight};
    COORD bufferCoord = {0, 0};

    SMALL_RECT writeRegion = {2, 2, BufferWidth + 1, BufferHeight + 1};

    WriteConsoleOutput(consoleHandle, backBuffer, bufferSize, bufferCoord, &writeRegion);
    std::swap(backBuffer, frontBuffer);
}

void DrawToBackBuffer(CHAR_INFO backBuffer[], CHAR_INFO frontBuffer[], int x, int y, char ch, WORD attributes, short int BufferWidth, short int BufferHeight) {
    if (x >= 0 && x < BufferWidth && y >= 0 && y < BufferHeight) {
        backBuffer[y * BufferWidth + x].Char.AsciiChar = ch;
        backBuffer[y * BufferWidth + x].Attributes = attributes; 
    }
}

void RenderFrame(CHAR_INFO backBuffer[], CHAR_INFO frontBuffer[], int** grid, short int BufferWidth, short int BufferHeight) {
    ClearBuffers(backBuffer, frontBuffer, BufferWidth, BufferHeight);

    for (int y = 0; y < BufferHeight; ++y) {
        for (int x = 0; x < BufferWidth; ++x) {   
            char placeHold;
            
            if (!grid[y][x]) placeHold = char(219);
            else placeHold = char(32);

            DrawToBackBuffer(backBuffer, frontBuffer, x, y, placeHold, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY, BufferWidth, BufferHeight);
        }
    }

    SwapBuffers(backBuffer, frontBuffer, GetStdHandle(STD_OUTPUT_HANDLE), BufferWidth, BufferHeight);
}

void corner_coorBuff(int ScreenWidth, int ScreenHeight) {
    COORD corner_coor;
    corner_coor.X = ScreenWidth;
    corner_coor.Y = ScreenHeight;

    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), corner_coor);
}