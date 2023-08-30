#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include "Buffers.h"
#include "Display.h"
#include "Calculation.h"

// making save file for seeds
// strict render                        [Checked]
// generation counter
// options for iteration, manual, auto
// Abnormality in iteration             [Checked]

int main() {
    int ScrnWidth = 115;
    int ScrnHeight = 26;
    int** grid = _gridInit(ScrnWidth, ScrnHeight);
    displayGrid(grid, ScrnWidth, ScrnHeight);

    short BufferWidth = 115;
    short BufferHeight = 26;

    CHAR_INFO backBuffer[BufferWidth * BufferHeight];
    CHAR_INFO frontBuffer[BufferWidth * BufferHeight];

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize = {BufferWidth, BufferHeight};
    SetConsoleScreenBufferSize(consoleHandle, bufferSize);

    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.bVisible = FALSE;
    cursorInfo.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

    noiseGenerator(grid, ScrnWidth, ScrnHeight, 50);
    while (true) {
        RenderFrame(backBuffer, frontBuffer, grid, BufferWidth, BufferHeight);
        iteration(grid, ScrnWidth, ScrnHeight);
        
        Sleep(120);
    }

    return 0;
}